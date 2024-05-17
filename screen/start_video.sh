#!/bin/bash
python /home/pi/lab2/more_video_control.py & 
sudo SDL_VIDEODRIVER=fbcon SDL_FBDEV=/dev/fb1 mplayer -vo sdl -input file=/home/pi/lab1/video_fifo /home/pi/bigbuckbunny320p.mp4 
