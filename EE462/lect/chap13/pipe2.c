#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>



int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "woodrow wilson had 14 points ...";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer));

    if (pipe(file_pipes) == 0) {
        fork_result = fork();
        if (fork_result == -1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }

        if (fork_result == 0) { //child
	  printf("child PID: %d\n", getpid());
 	  //sleep(3);  // prompt appears if parent exits before the child (FH)
	  //system("echo $$ > child.txt "); //system creates a new process (different PID)
            data_processed = read(file_pipes[0], buffer, BUFSIZ);
            printf("Read %d bytes: %s\n", data_processed, buffer);
            exit(EXIT_SUCCESS);
        } else { // parent/original
	  printf("parent PID: %d\n", getpid());
            data_processed = write(file_pipes[1], some_data,
                                   strlen(some_data));
            printf("Wrote %d bytes\n", data_processed);
        }
    }
    exit(EXIT_SUCCESS);
}

