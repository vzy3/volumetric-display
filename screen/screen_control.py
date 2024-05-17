import RPi.GPIO as GPIO
import time
import sys
import pygame, pigame
from pygame.locals import *
import os
import subprocess

# display + screen buttons
os.putenv('SDL_VIDEODRV','fbcon')
os.putenv('SDL_FBDEV', '/dev/fb1')
os.putenv('SDL_MOUSEDRV','dummy')
os.putenv('SDL_MOUSEDEV','/dev/null')
os.putenv('DISPLAY','')
WHITE = (255,255,255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 50)

pygame.init()
pitft = pigame.PiTft()
lcd = pygame.display.set_mode((320, 240))
lcd.fill(BLACK)
pygame.display.update()
pygame.mouse.set_visible(True)   
font_big = pygame.font.Font(None, 25)

touch_buttons = {'cup':(80, 60), 'flower': (240, 60), 'ball':(80, 180), 'QUIT': (240, 180)}
       
for k,v in touch_buttons.items():
    pygame.draw.circle(lcd, GREEN, v, 50)
    text_surface = font_big.render('%s'%k, True, WHITE)
    rect = text_surface.get_rect(center=v)
    lcd.blit(text_surface, rect)
    
pygame.display.update()

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP)

code_run = True
robot_run= False
start_time = time.time()

def GPIO17_callback(channel):
    print("QUIT")
    global code_run
    code_run = False
GPIO.add_event_detect(17, GPIO.FALLING, callback=GPIO17_callback, bouncetime=300)

while code_run:
    for event in pygame.event.get():
        pitft.update()
        if(event.type is MOUSEBUTTONUP):
            x,y = pygame.mouse.get_pos()
            print(x,y)
            if   x<160 and y<120: # preset 1
                output = open("pattern_v01.txt","w")
                # print("cup of water")
                output.write("cup of water")
                output.close()
                # subprocess.run("/home/pi/volumetric_display/screen/screen")
                # subprocess.run(["sudo", "arduino", "--upload", "/home/pi/Arduino/led_v05/led_v05.ino", "--port", "/dev/ttyACM0"])
            elif x>160 and y<120: # preset 2
                output = open("pattern_v01.txt","w")
                # print("flower with leaves")
                output.write("flower with leaves")
                output.close()
            elif x<160 and y>120: # preset 3
                output = open("pattern_v01.txt","w")
                # print("gradient ball")
                output.write("gradient ball")
                output.close()
#                 time.sleep(5)
#                 output.truncate(0)
            elif x>160 and y>120: # quit
                print("QUIT")
                code_run = False
    if time.time()-start_time>600:
        code_run = False
        
#output = open("pattern.txt","w")
#output.write("test")
#output.close()
pygame.quit()
del(pitft)
