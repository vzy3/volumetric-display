# display four different strips
import board
import neopixel
import time

pixel_pin12 = board.D12
pixel_pin18 = board.D18
pixel_pin21 = board.D21
num_pixels = 18
#ORDER = neopixel.RBGW

while(True):
    pixels12 = neopixel.NeoPixel(pixel_pin12, num_pixels, brightness=0.05, auto_write=False)
    for i in range(num_pixels):
        pixels12[i] = [0, 255-i*10, i*10]
    pixels12.show()

    pixels21 = neopixel.NeoPixel(pixel_pin21, num_pixels, brightness=0.05, auto_write=False)
    for i in range(num_pixels):
        pixels21[i] = [255-i*10, i*10, 0]
    pixels21.show()

    pixels18 = neopixel.NeoPixel(pixel_pin18, num_pixels, brightness=0.05, auto_write=False)
    for i in range(num_pixels):
        pixels18[i] = [i*10, 0, 255-i*10]
    pixels18.show()


