# control with DMA

import time
import sys
import pigpio

pi_hw2 = pigpio.pi()
pi_hw2.set_mode(14, pigpio.OUTPUT)
pi_hw2.wave_clear()
pi_hw2.wave_add_serial(14, 1000000, b'0')

wave_id2 = pi_hw2.wave_create()
pi_hw2.wave_send_repeat(wave_id2)
time.sleep(10)
pi_hw2.wave_tx_stop()
pi_hw2.stop()