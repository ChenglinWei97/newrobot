from collections import deque
from imutils.video import VideoStream
import numpy as np
import argparse
import cv2
import imutils
import time
import struct

import serial
arduino = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(1)

for i in range(10):
	x=arduino.write(struct.pack('>B',1))
	print(x)
	print("Sending '1'")
	time.sleep(10)
	x=arduino.write(struct.pack('>B',2))
	print(x)
	print("Sending '2'")
	time.sleep(10)
