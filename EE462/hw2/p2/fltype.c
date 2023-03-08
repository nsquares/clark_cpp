//Nathan Nguyen
//file types
//using only system calls


#include <unistd.h>
#include <stdlib.h>  
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
  if(argc != 2){                                 //need exactly 1 argument
    char errMess[] = "usage: fltype <file>\n";
    write(2, errMess, sizeof(errMess));
    return -1;
  }


  char ft[32] = {0};  //file type
  
  struct stat sbuf;
  lstat(argv[1], &sbuf);
  mode_t m = sbuf.st_mode;

  if(S_ISREG(m)){
    strcpy(ft,"regular");
  }

  else if(S_ISDIR(m))
    strcpy(ft,"directory");
  else if(S_ISCHR(m))
    strcpy(ft,"character special");
  else if(S_ISBLK(m))
    strcpy(ft,"block special");
  else if(S_ISFIFO(m))
    strcpy(ft,"fifo");
  else if(S_ISLNK(m))
    strcpy(ft,"symbolic link");
  else if(S_ISSOCK(m))
    strcpy(ft,"socket");

  else{
    strcpy(ft,"else error");
  }


  char buffer[1024] = {0}; 
  //needed a \0 and this did not have it when initialied, needed "= {0};" to initialize with '\0', set this as first element

  strcat(buffer, argv[1]);
  strcat(buffer, ": ");
  strcat(buffer, ft);
  strcat(buffer, "\n");

  write(1, buffer, strlen(buffer));
  return 0;
}
