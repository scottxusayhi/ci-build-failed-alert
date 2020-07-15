import serial
import io
import time

TERMINATOR = "\r"

color_mapping = {
    "red": "red",
    "yellow": "yellow",
    "green": "green",
    "off": "off",
    "light_green": "c011",
    "orange": "c110",
    "yellow_green": "c101",
    "yellow_green_2": "c111",
}

RESPONSE_TERMINATOR = "\r\n"


class ArduinoLight(object):
    def __init__(self, arduino_device):
        self._device = arduino_device
        self.connect()

    def connect(self):
        print("connecting to %s ..." % self._device)
        self.conn = serial.Serial(self._device, 9600)
        print("connected, waitting for response ...")
        if self.conn.is_open:
            response = self.conn.read_until(
                ("Arduino is Ready!" + RESPONSE_TERMINATOR).encode()
            )
            print(response)

    def switch(self, color, pause=0):
        try:
            signal = (color_mapping[color] + TERMINATOR).encode()
            self.conn.write(signal)  # writ a string to port
            response = self.conn.readline()  # read a string from port
            time.sleep(pause)
            return response
        except Exception as e:
            print(e)


default_light = "/dev/cu.usbmodem143401"
lights = {}


def get_light(device):
    if device not in lights.keys():
        lights[device] = ArduinoLight(device)
    return lights[device]


if __name__ == "__main__":
    arduino = get_light(default_light)
    arduino = get_light(default_light)
    arduino = get_light(default_light)

    arduino.switch("red", pause=1)
    arduino.switch("orange", pause=1)
    arduino.switch("yellow", pause=1)
    arduino.switch("yellow_green_2", pause=1)
    arduino.switch("yellow_green", pause=1)
    arduino.switch("light_green", pause=1)
    arduino.switch("green", pause=1)

    arduino.switch("off", pause=1)
