#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_PATH "pattern.txt" 

int main() {

    struct stat st;
    char *prev_content = NULL;

    while (1) {
        if (stat(FILE_PATH, &st) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }

        char *content = (char *)malloc(st.st_size + 1); // Allocate memory for file content
        if (content == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        int fd = open(FILE_PATH, O_RDONLY); // Open the file for reading
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        ssize_t bytes_read = read(fd, content, st.st_size); // Read the file content
        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        close(fd); // Close the file descriptor
        content[bytes_read] = '\0'; // Null-terminate the content to treat it as a string

        // Check if the content has changed
        if (prev_content != NULL && strcmp(prev_content, content) != 0) {
            if(strcmp("cup of water", content) == 0){
                printf("play cup of water\n");
                system("/home/pi/volumetric_display/Arduino_LED_control/cup.sh");
            }else if(strcmp("gradient ball", content) == 0){
                printf("play gradient ball\n");
                system("/home/pi/volumetric_display/Arduino_LED_control/ball.sh");
            }else if(strcmp("flower with leaves", content) == 0){
                printf("play flower with leaves\n");
                system("/home/pi/volumetric_display/Arduino_LED_control/flower.sh");
            }else if(strcmp("firework", content) == 0){
                printf("play firework\n");
                system("/home/pi/volumetric_display/Arduino_LED_control/firework.sh");
            }else{
                printf("input not match\n");
            }
            
        }

        // Free the previously allocated memory
        free(prev_content);
        prev_content = content;

        usleep(100000); // Sleep for 100 milliseconds to avoid busy-waiting
    }

    return 0;
}

