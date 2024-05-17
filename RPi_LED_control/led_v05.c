#include <stdlib.h>
#include <stdio.h>
#include <pigpio.h>
#include <time.h>

#define NSEC_PER_SEC  1000000000 /* The number of nsecs per sec. */

struct timespec t;

int main (int argc, char** argv)
{
  int dtt[] = {300, 12000, 700, 600, 55000}; // data transfer time, {T0H, T0L, T1H, T1L, RES}
  int PinValue = 0;  // hi/low indication of output Pin
  unsigned int current_sec, start_sec;
  gpioInitialise();
  clock_gettime(CLOCK_MONOTONIC ,&t); // setup timer t
  start_sec = t.tv_sec;
  current_sec = 0;

  gpioSetMode(26, PI_OUTPUT); 

  while( current_sec < 10 ) {   // run the loop for 10 sec
     gpioWrite(26, PinValue); 
     clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t, NULL); // delay a bit...
     
     printf ( "naosec = %ld \n", t.tv_nsec);
     //printf ( "sec = %ld \n", t.tv_sec);
     
     PinValue = PinValue ^ 1;  // Flip the value of the output pin
     t.tv_nsec += dtt[PinValue];   // add in initial period

     while (t.tv_nsec >= NSEC_PER_SEC) {   // This accounts for 1 sec rollover
        t.tv_nsec -= NSEC_PER_SEC;
        t.tv_sec++;
        current_sec = t.tv_sec - start_sec;  // how many seconds since we started?
     }
  }
  printf ("stopped at %d seconds\n", current_sec);
  //gpioTerminate();  // exit piGPIO
  return 0 ;
}

