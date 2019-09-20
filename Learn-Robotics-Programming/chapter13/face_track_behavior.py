from __future__ import print_function
import time

from image_app_core import start_server_process, get_control_instruction, put_output_image

import cv2
import numpy as np

import pi_camera_stream
from pid_controller import PIController
from robot import Robot


class FaceTrackBehavior(object):
    """Behavior to find and point at a face."""
    def __init__(self, robot):
        self.robot = robot
        cascade_path = "/usr/share/opencv/haarcascades/haarcascade_frontalface_default.xml"
        self.cascade = cv2.CascadeClassifier(cascade_path)
        # Tuning values
        self.center_x = 160
        self.center_y = 120
        self.min_size = 20
        self.pan_pid = PIController(proportional_constant=0.1, integral_constant=0.03)
        self.tilt_pid = PIController(proportional_constant=-0.1, integral_constant=-0.03)
        # Current state
        self.running = False
    
    def process_control(self):
        instruction = get_control_instruction()
        if instruction == "start":
            self.running = True
        elif instruction == "stop":
            self.running = False
            self.pan_pid.reset()
            self.tilt_pid.reset()
            self.robot.servos.stop_all()
        elif instruction == "exit":
            print("Stopping")
            exit()

    def find_object(self, original_frame):
        """Search the frame for an object. Return the rectangle of the largest by w * h"""
        # Make it greyscale to reduce the data used
        gray_img = cv2.cvtColor(original_frame, cv2.COLOR_BGR2GRAY)
        # Detect all the objects
        objects = self.cascade.detectMultiScale(gray_img)
        largest = 0, (0, 0, 0, 0) # area, x, y, w, h
        for (x, y, w, h) in objects:
            item_area = w * h
            if item_area > largest[0]:
                largest = item_area, (x, y, w, h)
        return largest[1]
    
    def make_display(self, display_frame):
        """Create display output, and put it on the queue"""
        encoded_bytes = pi_camera_stream.get_encoded_bytes_for_frame(display_frame)
        put_output_image(encoded_bytes) 

    def process_frame(self, frame):
        # Find the largest matching object
        (x, y, w, h) = self.find_object(frame)
        # Draw a rect on the original frame, then display this
        cv2.rectangle(frame, (x, y), (x + w, y + w), [255, 0, 0])
        self.make_display(frame)
        # Yield the object details
        return x, y, w, h
    
    def run(self):
        # start camera
        camera = pi_camera_stream.setup_camera()
        # warm up time
        time.sleep(0.1)
        print("Setup Complete")
        # Main loop
        for frame in pi_camera_stream.start_stream(camera):
            (x, y, w, h) = self.process_frame(frame)
            self.process_control()
            if self.running and h > self.min_size:
                # Pan
                pan_error = self.center_x - (x + (w / 2))
                pan_value = self.pan_pid.get_value(pan_error)
                self.robot.set_pan(int(pan_value))
                # Tilt
                tilt_error = self.center_y - (y + (h / 2))
                tilt_value = self.tilt_pid.get_value(tilt_error)
                self.robot.set_tilt(int(tilt_value))
                print("x: %d, y: %d, pan_error: %d, tilt_error: %d, pan_value: %.2f, tilt_value: %.2f" %
                    (x, y, pan_error, tilt_error, pan_value, tilt_value))

print("Setting up")
behavior = FaceTrackBehavior(Robot())
process = start_server_process('color_track_behavior.html')
behavior.run()
