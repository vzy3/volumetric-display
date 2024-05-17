import sys
import RPi.GPIO as GPIO
import time

code_running = True
start_time = time.time()
time_now = 0
time_pre = 0
period = 1000

GPIO.setmode(GPIO.BCM)
GPIO.setup(14, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def GPIO17_callback(channel):
    global time_pre
    global time_now
    global period
    time_pre = time_now
    time_now = time.time()
    period = time_now - time_pre
    print(period)
    
GPIO.add_event_detect(14, GPIO.FALLING, callback=GPIO17_callback, bouncetime=10)

while True:
    pass
    