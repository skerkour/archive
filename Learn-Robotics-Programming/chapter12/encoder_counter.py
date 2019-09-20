from gpiozero import DigitalInputDevice
import math

class EncoderCounter(DigitalInputDevice):
    ticks_to_mm_const = None # you must set this up before using distance methods
    def __init__(self, pin):
        super(EncoderCounter, self).__init__(pin)
        self.pin.when_changed = self.when_changed
        self.pulse_count = 0
        self.direction = 1

    def when_changed(self):
        self.pulse_count += self.direction

    def set_direction(self, direction):
        """ This should be -1 or 1. """
        assert abs(direction)==1, "Direction %s should be 1 or -1" % direction
        self.direction = direction

    def reset(self):
        self.pulse_count = 0

    def distance_in_mm(self):
        return int(self.pulse_count * EncoderCounter.ticks_to_mm_const)

    @staticmethod
    def mm_to_ticks(mm):
        return mm / EncoderCounter.ticks_to_mm_const

    @staticmethod
    def set_constants(wheel_diameter_mm, ticks_per_revolution):
        EncoderCounter.ticks_to_mm_const = (math.pi / ticks_per_revolution) * wheel_diameter_mm
