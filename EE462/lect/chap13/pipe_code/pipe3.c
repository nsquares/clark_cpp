#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "filler text ... time time has come for all good men to come to the aid of the party";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer));

    if (pipe(file_pipes) == 0) {
        fork_result = fork();
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }

        if (fork_result == 0) { //child
	  printf("pipe3 child PID: %d\n", getpid());
            sprintf(buffer, "%d", file_pipes[0]);
	    printf("[%d] prog name is: %s\n", getpid(), argv[0]);
	    printf("[%d] before replacement: buffer == %s\n", getpid(), buffer); //FH (buffer has the filedes for reading; read end of the pipe)
            execl("pipe4", "pipe4", buffer, (char *)0);
            exit(EXIT_FAILURE);
        }
        else { //parent/original 
            data_processed = write(file_pipes[1], some_data,
                                   strlen(some_data));
            printf("[%d] wrote %d bytes\n", getpid(), data_processed);
        }
    }
    exit(EXIT_SUCCESS);
}

