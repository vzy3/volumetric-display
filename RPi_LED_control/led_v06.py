# control with DMA

import time
import sys
import pigpio

pi_hw = pigpio.pi()
pi_hw.set_mode(26, pigpio.OUTPUT)
pi_hw.wave_clear()
pi_hw.wave_add_serial(26, 1000000, b'000000000')

wave_id = pi_hw.wave_create()
pi_hw.wave_send_repeat(wave_id)
time.sleep(10)
pi_hw.wave_tx_stop()
pi_hw.stop()