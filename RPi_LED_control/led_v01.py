# display one single strip
import board
import neopixel

pixel_pin = board.D18
num_pixels = 300
#ORDER = neopixel.RBGW

pixels = neopixel.NeoPixel(pixel_pin, num_pixels, brightness=0.2, auto_write=False)
for i in range(300):
    pixels[i] = [max(0,255-i), min(i,255), int(255/(i+1))]
pixels.show()
