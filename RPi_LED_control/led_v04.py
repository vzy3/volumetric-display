import board
import neopixel

pixel_pin12 = board.D21
#pixel_pin21 = board.D21
num_pixels = 18
#ORDER = neopixel.RBGW

while True:
    pixels12 = neopixel.NeoPixel(pixel_pin12, num_pixels, brightness=0.05, auto_write=False)
    for i in range(18):
        pixels12[i] = [0, 255-i*10, i*10,0]
    pixels12.show()

# pixels21 = neopixel.NeoPixel(pixel_pin21, num_pixels, brightness=0.05, auto_write=False)
# for i in range(18):
#     pixels21[i] = [255-i*10, i*10, 0]
# pixels21.show()
