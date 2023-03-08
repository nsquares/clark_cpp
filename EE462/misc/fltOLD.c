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


  char ft[32];  //file type
  
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





  else{
    strcpy(ft,"else error");
  }


  //strcat() does some weird stuff or its the undefined char array sizes, this works for sure:
  write(1, argv[1], strlen(argv[1]));
  write(1, ": ", 2);
  write(1, ft, strlen(ft));
  write(1, "\n", 1);
  return 0;
}
