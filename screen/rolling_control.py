import RPi.GPIO as GPIO
import time
import sys
import pygame, pigame
from pygame.locals import *
import os

# display + screen buttons
# os.putenv('SDL_VIDEODRV','fbcon')
# os.putenv('SDL_FBDEV', '/dev/fb1')
# os.putenv('SDL_MOUSEDRV','dummy')
# os.putenv('SDL_MOUSEDEV','/dev/null')
# os.putenv('DISPLAY','')
WHITE = (255,255,255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

pygame.init()
pitft = pigame.PiTft()
lcd = pygame.display.set_mode((320, 240))
lcd.fill(BLACK)
pygame.display.update()
# pygame.mouse.set_visible(False)   
font_big = pygame.font.Font(None, 25)

touch_buttons = {'STOP':(160, 60), 'QUIT': (160, 180)}
       
for k,v in touch_buttons.items():
    pygame.draw.circle(lcd, RED, v, 50)
    text_surface = font_big.render('%s'%k, True, WHITE)
    rect = text_surface.get_rect(center=v)
    lcd.blit(text_surface, rect)
    
pygame.display.update()
# physical buttons

GPIO.setmode(GPIO.BCM)
GPIO.setup(26, GPIO.OUT)
GPIO.setup(5, GPIO.OUT)
GPIO.setup(6, GPIO.OUT)
# GPIO.setup(2, GPIO.OUT)
# GPIO.setup(3, GPIO.OUT)
GPIO.setup(4, GPIO.OUT)

GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(23, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(27, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# GPIO.output(5, GPIO.LOW)
# GPIO.output(6, GPIO.LOW)
# GPIO.output(3, GPIO.LOW)
# GPIO.output(4, GPIO.LOW)

code_run = True
robot_run= False
start_time = time.time()

# p = GPIO.PWM(26, 50) #left
# p.start(50)
# p2 = GPIO.PWM(2, 50) #right
# p2.start(50)

def GPIO17_callback(channel):
    sys.exit(0)
    
GPIO.add_event_detect(17, GPIO.FALLING, callback=GPIO17_callback, bouncetime=300)

while code_run:
    for event in pygame.event.get():
            if(event.type is MOUSEBUTTONDOWN):
                x,y = pygame.mouse.get_pos()
                print(x,y)
            elif(event.type is MOUSEBUTTONUP):
                print(x,y)
                x,y = pygame.mouse.get_pos()
                if   x>110 and x<210 and y>10 and y<110: # stop
                    print("STOP")
                elif x>110 and x<210 and y>130 and y<230: # quit
                    print("QUIT")
                    code_run = False
                        
#     if (not GPIO.input(17)) and (not GPIO.input(22)): # left servo, CW
#         GPIO.output(5, GPIO.LOW) #CW
#         GPIO.output(6, GPIO.HIGH)
#     elif (not GPIO.input(23)) and (not GPIO.input(27)): # left servo, stop
#         GPIO.output(5, GPIO.LOW) 
#         GPIO.output(6, GPIO.LOW)
#     elif (not GPIO.input(17)): # left servo, CCW
#         GPIO.output(6, GPIO.LOW) #CW
#         GPIO.output(5, GPIO.HIGH)
#     elif (not GPIO.input(22)): # right servo, CW
#         GPIO.output(3, GPIO.LOW) #CW
#         GPIO.output(4, GPIO.HIGH)
#     elif (not GPIO.input(23)): # right servo, stop
#         GPIO.output(3, GPIO.LOW) 
#         GPIO.output(4, GPIO.LOW)
#     elif (not GPIO.input(27)): # right servo, CCW
#         GPIO.output(4, GPIO.LOW) #CCW
#         GPIO.output(3, GPIO.HIGH)

    if time.time()-start_time>10:
        code_run = False
        
    # p.ChangeFrequency(frq)
    
# GPIO.output(5, GPIO.LOW)
# GPIO.output(6, GPIO.LOW)
# GPIO.output(3, GPIO.LOW)
# GPIO.output(4, GPIO.LOW)
# p.ChangeDutyCycle(0)
# p.stop()
# p2.ChangeDutyCycle(0)
# p2.stop()
pygame.quit()
del(pitft)
