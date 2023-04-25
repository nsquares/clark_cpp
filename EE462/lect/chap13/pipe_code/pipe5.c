#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "[the government believes that] a tax is the best form of defense ..";
    pid_t fork_result;

    if (pipe(file_pipes) == 0) {
      printf("file_pipes[0]: %d\n", file_pipes[0]);
      printf("file_pipes[1]: %d\n", file_pipes[1]);

      
        fork_result = fork();
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }

        if (fork_result == (pid_t)0) {
	        printf("[child] file_pipes[0]: %d\n", file_pipes[0]);
		printf("[child] file_pipes[1]: %d\n", file_pipes[1]);
		//exit(1); //FH testing

		//IMP: unlike pipe3, we do not have control over od (which reads from stdin)
		//so we use the trick below 
		close(0); //close stdin; see STDIN(3)
		dup(file_pipes[0]); //duplicate reading end of pipe (as stdin); see DUP(2)		
		close(file_pipes[0]); //close reading end of pipe (in the child)
		close(file_pipes[1]); //close writing end of pipe (in the child)

		execlp("od", "od", "-bc", (char *)0); //od can read from stdin (reading end of pipe)
            exit(EXIT_FAILURE);
        }
        else {
	  printf("[orig] file_pipes[0]: %d\n", file_pipes[0]);
	  printf("[orig] file_pipes[1]: %d\n", file_pipes[1]);
	  //exit(1); //FH testing
	  
	  close(file_pipes[0]); //close reading end of pipe (in the parent/original)
            data_processed = write(file_pipes[1], some_data,
                                   strlen(some_data));
            close(file_pipes[1]); //close writing end of pipe (in the parent/original)
            printf("%d - orig wrote %d bytes\n", (int)getpid(), data_processed);
        }
    }
    exit(EXIT_SUCCESS);
}

