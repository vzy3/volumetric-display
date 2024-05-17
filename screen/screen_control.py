import sys
import RPi.GPIO as GPIO
import pygame,pigame
from pygame.locals import *
import os
from time import sleep
import time

code_running = True

start_time = time.time()

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP)

WHITE = (255,255,255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 50)

os.putenv('SDL_VIDEODRV','fbcon')
os.putenv('SDL_FBDEV', '/dev/fb1')
os.putenv('SDL_MOUSEDRV','dummy')
os.putenv('SDL_MOUSEDEV','/dev/null')
os.putenv('DISPLAY','')
    
pygame.init()
pitft = pigame.PiTft()
lcd = pygame.display.set_mode((320, 240))
lcd.fill(BLACK)
pygame.display.update()
pygame.mouse.set_visible(True)   
font_big = pygame.font.Font(None, 25)
      
touch_buttons = {'cup':(80, 60), 'flower': (240, 60), 'ball':(80, 180), 'firework': (240, 180)}
       
for k,v in touch_buttons.items():
    pygame.draw.circle(lcd, GREEN, v, 50)
    text_surface = font_big.render('%s'%k, True, WHITE)
    rect = text_surface.get_rect(center=v)
    lcd.blit(text_surface, rect)

pygame.display.update()

code_run = True
robot_run= False
start_time = time.time()

def GPIO17_callback(channel):
    print("QUIT")
    global code_run
    code_run = False
GPIO.add_event_detect(17, GPIO.FALLING, callback=GPIO17_callback, bouncetime=300)


while code_run:
    if (time.time() - start_time) > 300:
        code_run = False

    if (not GPIO.input(17)):
        pygame.quit()
        sys.exit(0)

    pitft.update()
    # Scan touchscreen events
    for event in pygame.event.get():
        if(event.type is MOUSEBUTTONDOWN):
            x,y = pygame.mouse.get_pos()
            # print(x,y)
        elif(event.type is MOUSEBUTTONUP):
            x,y = pygame.mouse.get_pos()
            print(x,y)
            if   x<160 and y<120: # preset 1
                output = open("pattern.txt","w")
                output.write("cup of water")
                output.close()
            elif x>160 and y<120: # preset 2
                output = open("pattern.txt","w")
                output.write("flower with leaves")
                output.close()
            elif x<160 and y>120: # preset 3
                output = open("pattern.txt","w")
                output.write("gradient ball")
                output.close()
            elif x>160 and y>120: # preset 4
                output = open("pattern.txt","w")
                output.write("firework")
                output.close()

    sleep(0.1)
pygame.quit()
del(pitft)
sys.exit(0)
