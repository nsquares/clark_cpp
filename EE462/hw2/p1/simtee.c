//Nathan Nguyen
//only uses system calls

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/stat.h>


int main(int argc, char *argv[]){
  if(argc != 2){
    char errMessage[] = "usage: simtee <file>\n"; 
    write(2, errMessage, sizeof(errMessage));        // 2 is standard error, 1 is standard output, and 0 is standard input
    exit(-1); //needs exactly 1 argument
  }

  
  // create and open new file
  int fildes = open(argv[1], O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
  if(fildes == -1){
    char errMessage[] = "failed: couldn't create file or open file\n";
    write(2, errMessage, sizeof(errMessage)); 
    exit(-2);
  }
  
  //read from standard input and write to standard output and the file that was just opened
  int bufSize = 1024;
  char buffer[bufSize];        //could make this a dynamic array, create from the heap
  //  printf((char*)sizeof(buffer));   //this creates a segmentation fault, you should probably look up how to really convert int to cstring
  int nread;
  do {
    
    nread = read(0, buffer, bufSize); //read from standard input, 
    //return is the number of bytes read from the system call function

    //note that ^D is EOF or "end of file" and nread becomes 0 if EOF is read


    if(nread == -1){
      char errMessage[] = "failed: couldn't read\n";
      write(2, errMessage, sizeof(errMessage));
      exit(-3);

    }
    
    //int nwrite; //the return int of write function is the number of bytes written

    write(fildes, buffer, nread); //write to the opened file
    write(1, buffer, nread); //write to screen, std output
    //do not give bufSize or the whole buffer size, or sizeof(buffer) to these write system calls, 
    //the problem is that c does not check contents of array or the memory if its even good, so it was writing whatever it found in the instantiated char array, would read old data

  } while(nread != 0); //end reading when ^D is detected
  




  close(fildes);
  exit(0);
}
