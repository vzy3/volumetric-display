import sys
import RPi.GPIO as GPIO
import pygame,pigame
from pygame.locals import *
import os
from time import sleep
import time

os.putenv('SDL_VIDEODRV','fbcon')
os.putenv('SDL_FBDEV', '/dev/fb1')
os.putenv('SDL_MOUSEDRV','dummy')
os.putenv('SDL_MOUSEDEV','/dev/null')
os.putenv('DISPLAY','')

code_running = True
game = False
paused = False
time_ = time.time()
FPS = 24
clock = pygame.time.Clock()

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_UP)

WHITE = (255,255,255)
BLACK = (0,0,0)

pygame.init()
pitft = pigame.PiTft()
size = width, height = 320, 240
lcd = pygame.display.set_mode(size)
lcd.fill(BLACK)
font_big = pygame.font.Font(None, 25)
pygame.mouse.set_visible(False)

touch_buttons = {'Start':(80,220),'Quit':(240,220)}
for k,v in touch_buttons.items():
    text_surface = font_big.render('%s'%k, True, WHITE)
    rect = text_surface.get_rect(center=v)
    lcd.blit(text_surface, rect)               
pygame.display.update()

while code_running:

    for event in pygame.event.get():
        
        if(event.type is MOUSEBUTTONDOWN):
            x,y = pygame.mouse.get_pos()
        elif(event.type is MOUSEBUTTONUP):
            x,y = pygame.mouse.get_pos()
            print(x,y)
            
            if not game: 
                if y > 200 and x > 160: # hit quit
                    code_running = False
                elif y > 200 and x <= 160:
                    print("start")
                    game = True
                    speed = [10,10]
                    speed2 = [20,20]

                    ball = pygame.image.load("ball.png")
                    ballrect = ball.get_rect()
                    ball2 = pygame.image.load("smol_ball.png")
                    ballrect2 = ball2.get_rect()
                    ballrect2 = ballrect2.move([200,100])

                else:
                    print("touch")
                    text_surface = font_big.render('touch at ' + str(x) + ", " + str(y), True, WHITE)
                    rect = text_surface.get_rect(center=(x,y))
                    lcd.blit(text_surface, rect)
                    pygame.display.update()
            elif y > 200:
                if x < 96: # back
                    game = False
                    lcd.fill(BLACK)
                    for k,v in touch_buttons.items():
                        text_surface = font_big.render('%s'%k, True, WHITE)
                        rect = text_surface.get_rect(center=v)
                        lcd.blit(text_surface, rect)
                    pygame.display.flip()
                elif x < 160: #fast
                    # can't adjust speed value directly using a multiplier
                    #speed = list(map(lambda s: int(s*1.3), speed))
                    #speed2= list(map(lambda s: int(s*1.3), speed2))
                    FPS = int(1.3*FPS)
                elif x < 224: #slow
                    #speed = list(map(lambda s: int(s*0.7), speed))
                    #speed2= list(map(lambda s: int(s*0.7), speed2))
                    FPS = int(0.7*FPS)
                else: # pause
                    paused = not paused
                    if paused:
                        speed = [0,0]
                        speed2 = [0,0]
                    else:
                        speed = [10,10]
                        speed2 = [20,20]
                
    if game:
        ballrect = ballrect.move(speed)
        ballrect2 = ballrect2.move(speed2)
        spd_rev1x = True
        spd_rev1y = True
        spd_rev2x = True
        spd_rev2y = True
        
        if spd_rev1x and ballrect.left < 0 or ballrect.right > width:
            speed[0] = -speed[0]
            spd_rev1x = False
        if spd_rev1y and ballrect.top < 0 or ballrect.bottom > height:
            speed[1] = -speed[1]
            spd_rev1y = False
        if spd_rev2x and ballrect2.left < 0 or ballrect2.right > width:
            speed2[0] = -speed2[0]
            spd_rev2x = False
        if spd_rev2y and ballrect2.top < 0 or ballrect2.bottom > height:
            speed2[1] = -speed2[1]
            spd_rev2y = False
        if pygame.Rect.colliderect(ballrect, ballrect2):
            speed[0] = -speed[0]
            speed[1] = -speed[1]
            speed2[0] = -speed2[0]
            speed2[1] = -speed2[1]

        lcd.fill(BLACK) # erase the work space
        lcd.blit(ball, ballrect) #combine ball surface with workspace surface
        lcd.blit(ball2, ballrect2) #combine ball2 surface with workspace surface
        
        touch_buttons_level2 = {'Back':(64,220),'Fast':(128,220), 'Slow':(192,220), 'Pause':(256,220)}
        for k,v in touch_buttons_level2.items():
            text_surface = font_big.render('%s'%k, True, WHITE)
            rect = text_surface.get_rect(center=v)
            lcd.blit(text_surface, rect)               
        pygame.display.flip() # display workspace on screen

    
    clock.tick(FPS)
    #print(FPS)
    pitft.update()            
                
    #sleep(0.1)
    #time_ = time_ + 0.1

    if (time.time() - time_ > 30) or not GPIO.input(17):
        code_running = False
    
pygame.quit()
del(pitft)
sys.exit(0)

