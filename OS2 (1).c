#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/stat.h>
#include <errno.h> 
#include <fcntl.h> 
#include<sys/types.h>


void main (int a, char *b[]) {

    int pipef[5]; 
    char cBuffer[150];
    int fsize;
    char buff[150];
    
    
    if (a != 3) {
      perror("fcopy.txt target to destination. \n");
      exit(1);
    }
    
    char* Source= b[1];
    char* Destination = b[2];

    if (pipe(pipef) < 0) {
      printf("An error occured during the creation of  the pipe! %s\n", strerror(errno));
      exit(1);
    }
    switch(fork()) {
      case -1:
        printf("An error occured during the forking of child process. %s\n", strerror(errno));
        exit(1);
     case 0: 
        close(pipef[1]);                                                       
        ssize_t no_child = read(pipef[0], cBuffer, sizeof(cBuffer));   
        close(pipef[0]);                                                        
        int tD = open(Destination, O_CREAT | O_WRONLY);                                  
        write(tD, cBuffer, no_child);                            
      default: 
        close(pipef[0]);                                              
        int fID = open(Source, O_RDONLY);                       
        ssize_t no_bytes = read(fID, buff, sizeof(buff));   
        write(pipef[1], buff, no_bytes);                           
        close(pipef[1]);                                              

    }

    
}
