from __future__ import print_function
import time

from image_app_core import start_server_process, get_control_instruction, put_output_image

import cv2
import numpy as np

import pi_camera_stream
from pid_controller import PIController
from robot import Robot


class ColorTrackingBehavior(object):
    """Behavior to find and get close to a colored object"""
    def __init__(self, robot):
        self.robot = robot
        # Tuning values
        self.low_range = (25, 70, 25)
        self.high_range = (80, 255, 255)
        self.correct_radius = 120
        self.center = 160
        # Current state
        self.running = False

    def process_control(self):
        instruction = get_control_instruction()
        if instruction == "start":
            self.running = True
        elif instruction == "stop":
            self.running = False
        elif instruction == "exit":
            print("Stopping")
            exit()

    def find_object(self, original_frame):
        """Find the largest enclosing circle for all contours in a masked image.
        Returns: the masked image, the object coordinates, the object radius"""
        frame_hsv = cv2.cvtColor(original_frame, cv2.COLOR_BGR2HSV)
        masked = cv2.inRange(frame_hsv, self.low_range, self.high_range)

        # Find the contours of the image (outline points)
        contour_image = np.copy(masked)
        contours, _ = cv2.findContours(contour_image, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
        # Find enclosing circles
        circles = [cv2.minEnclosingCircle(cnt) for cnt in contours]
        # Filter for the largest one
        largest = (0, 0), 0
        for (x, y), radius in circles:
            if radius > largest[1]:
                largest = (int(x), int(y)), int(radius)
        return masked, largest[0], largest[1]

    def make_display(self, frame, processed):
        """Create display output, and put it on the queue"""
        # Make a dualscreen view - two images of the same scale concatenated
        display_frame = np.concatenate((frame, processed), axis=1)
        encoded_bytes = pi_camera_stream.get_encoded_bytes_for_frame(display_frame)
        put_output_image(encoded_bytes)

    def process_frame(self, frame):
        # Find the largest enclosing circle
        masked, coordinates, radius = self.find_object(frame)
        # Now back to 3 channels for display
        processed = cv2.cvtColor(masked, cv2.COLOR_GRAY2BGR)
        # Draw our circle on the original frame, then display this
        cv2.circle(frame, coordinates, radius, [255, 0, 0])
        self.make_display(frame, processed)
        # Yield the object details
        return coordinates, radius

    def run(self):
        # Set pan and tilt to middle, then clear it.
        self.robot.set_pan(0)
        self.robot.set_tilt(0)
        # start camera
        camera = pi_camera_stream.setup_camera()
        # speed pid - based on the radius we get.
        speed_pid = PIController(proportional_constant=0.8, 
            integral_constant=0.1, windup_limit=100)
        # direction pid - how far from the middle X is.
        direction_pid = PIController(proportional_constant=0.25, 
            integral_constant=0.1, windup_limit=400)
        # warm up and servo move time
        time.sleep(0.1)
        # Servo's will be in place - stop them for now.
        self.robot.servos.stop_all()
        print("Setup Complete")
        # Main loop
        for frame in pi_camera_stream.start_stream(camera):
            (x, y), radius = self.process_frame(frame)
            self.process_control()
            if self.running and radius > 20:
                # The size is the first error
                radius_error = self.correct_radius - radius
                speed_value = speed_pid.get_value(radius_error)
                # And the second error is the based on the center coordinate.
                direction_error = self.center - x
                direction_value = direction_pid.get_value(direction_error)
                print("radius: %d, radius_error: %d, speed_value: %.2f, direction_error: %d, direction_value: %.2f" %
                    (radius, radius_error, speed_value, direction_error, direction_value))
                # Now produce left and right motor speeds
                self.robot.set_left(speed_value - direction_value)
                self.robot.set_right(speed_value + direction_value)
            else:
                self.robot.stop_motors()
                if not self.running:
                    speed_pid.reset()
                    direction_pid.reset()

print("Setting up")
behavior = ColorTrackingBehavior(Robot())
process = start_server_process('color_track_behavior.html')
behavior.run()
