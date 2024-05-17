#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

FILE *fptr;

int main(){
    time_t initial_time = time(NULL);
    struct stat info;
 
    while ((time(NULL) - initial_time) < 30) {
        char pattern[100];
        char curr[100];
        
        if (info.st_size != 0) {
            fptr = fopen("pattern.txt", "r");
            fgets(pattern, 100, fptr);
            fgets(curr, 100, fptr);
        }

        if ((strstr(pattern, "ball") != NULL) && (strcmp(curr, pattern)==0)) {
            fgets(curr, 100, fptr);
            system("/home/pi/volumetric_display/Arduino_LED_control/ball.sh");
        } else if ((strstr(pattern, "flower") != NULL) && (strcmp(curr, pattern)==0)) {
            fgets(curr, 100, fptr);
            system("/home/pi/volumetric_display/Arduino_LED_control/flower.sh");
        } else if ((strstr(pattern, "cup") != NULL) && (strcmp(curr, pattern)==0)) {
            fgets(curr, 100, fptr);
            system("/home/pi/volumetric_display/Arduino_LED_control/start_led.sh");
        } else if ((strstr(pattern, "heart") != NULL) && (strcmp(curr, pattern)==0)) {
            fgets(curr, 100, fptr);
            system("/home/pi/volumetric_display/Arduino_LED_control/start_led.sh");
        } 
//        else {
//            printf("oops");
//        }
    }
}
