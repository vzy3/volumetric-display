#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *fptr;

int main(){
//system("/home/pi/volumetric_display/Arduino_LED_control/start_led.sh");
system("sudo python3 /home/pi/volumetric_display/screen/screen_control.py");
//system("/home/pi/volumetric_display/screen/test");

//    fptr = fopen("pattern.txt", "r");

//    char pattern[100];
//    fgets(pattern, 100, fptr);
//    printf("%s", pattern);

//    if (strstr(pattern, "ball") != NULL) {
//        system("/home/pi/volumetric_display/Arduino_LED_control/start_led.sh");
//    }
}
