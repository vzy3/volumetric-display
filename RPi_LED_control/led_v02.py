# display two different strips
import board
import neopixel
import time

pixel_pin18 = board.D18
pixel_pin21 = board.D21
num_pixels = 18
#ORDER = neopixel.RBGW
start = time.time()

while (time.time()-start) < 10:
    pixels = neopixel.NeoPixel(pixel_pin21, num_pixels, brightness=0.05, auto_write=False)
    for i in range(18):
        pixels[i] = [255-i*10, i*10,255 ]
    pixels.show()

    pixels = neopixel.NeoPixel(pixel_pin18, num_pixels, brightness=0.05, auto_write=False)
    for i in range(18):
        pixels[i] = [255-i*10, i*10,0 ]
    pixels.show()
