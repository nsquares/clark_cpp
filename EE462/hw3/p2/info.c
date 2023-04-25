//Nathan Nguyen 
//ee 462
//hw3 p2

//The values will be displayed out to the screen (standard out)

#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>

void printData(char* text);

int main(int argc, char *argv[]){

  if(argc != 1){
    char errMessage[] = "usage: info\n"; 
    write(2, errMessage, sizeof(errMessage));        
    // 2 is standard error, 1 is standard output, and 0 is standard input
    exit(-1); //needs exactly 0 arguments
  }

  int stat_val;
  pid_t pid;
  pid = fork();
  switch(pid){

  case -1:    //fork failed
    perror("fork failed");
    exit(1); 
  
  case 0:            //child process
    if(chdir("/tmp")){
      printf("failed changing dir\n");
    }   //change working directory here

    printData("[child]");
    break;

  
  default:           //parent process

    wait(&stat_val);
    if(!(WIFEXITED(stat_val))){
      printf("Child terminated abnormally\n");
    }

    printData("[original]");

    break;
  }

  exit(0);
}


void printData(char* text){

  char exePath[PATH_MAX] = {0};

  char cwd[PATH_MAX] = {0};
  if (getcwd(cwd, sizeof(cwd)) == NULL){
    printf("error calling getcwd()\n");
  }

  readlink("/proc/self/exe", exePath, sizeof(exePath));

  printf("%s PID: %d\n", text, getpid());
  printf("%s parent's PID: %d\n", text, getppid());
  printf("%s cwd: %s\n", text, cwd);
  printf("%s current executable: %s\n", text, exePath);

  //  printf("hello world\n");
}
