#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

int main(){
    int rgb, x, y, file;
    char line[256];
    file = open("pic.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (file < 0){
        printf("%s\n", strerror(errno));
    }
    write(file, "P3 500 500 255 ", 15);
    for (x = 0; x <= 500; x++){
        for (y = 0; y <= 500; y++){
        	int x2 = x / 2;
        	int y2 = y / 2;
          int temp = (int)floor((cos(3 * x2) * cos(3 * x2) + sin(5 * y2) + sin(5 * y2)) * 255);
   				rgb = abs(temp) % 255;
         	sprintf(line, "%d %d %d ", rgb, x, y); 
         	write(file, line, strlen(line));
        }
    }
    close(file);
    
    return 0;
}