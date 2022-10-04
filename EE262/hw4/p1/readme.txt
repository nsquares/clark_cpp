Nathan Nguyen

I worked on this problem alone and did not look up anything to help me complete this problem.


There are multiple ways to compile and run client2.cpp that relies on the class triple.
Precondition: triple.cpp, client2.cpp, triple.h are all in the same directory

One way is to type these following commands:


g++ -c triple.cpp
g++ client2.cpp triple.o -o client2.out
./client2.out 


What the first command does is creates "triple.o" or an object file in the current directory and does not run the linker (-c in the command).
This is produced from compiling triple.h (header file) and triple.cpp (source/implementation file).

The second command compiles client2.cpp (the main / driver code) and also links it to the object file created right before.
Thus, the out file will have the definitions of the triple class when client2.cpp makes a call on the triple class.

An out file called "client2.out" is produced in the end (-o names the out file).
This can then be ran or executed by the last command in the 3 command list.


