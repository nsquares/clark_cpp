// The 'consumer' program, pipe4.c, that reads the data is much simpler.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int data_processed;
    char buf[BUFSIZ + 1];
    int file_descriptor;

    printf("\n\n");
    printf("[%d] prog name is: %s\n", getpid(), argv[0]);
    printf("[%d] arg is: %s\n", getpid(), argv[1]);

    memset(buf, '\0', sizeof(buf));
    sscanf(argv[1], "%d", &file_descriptor); //so file_descriptor is the reading end of the pipe
    data_processed = read(file_descriptor, buf, BUFSIZ);

    pid_t mypid = getpid();
    printf("[%d] recived data by pipe4: \"%s\"\n", mypid, buf); //FH
    printf("[%d] read %d bytes\n", mypid, data_processed); //FH
    
    //printf("%d - read %d bytes: %s\n", getpid(), data_processed, buf);
    exit(EXIT_SUCCESS);
}

