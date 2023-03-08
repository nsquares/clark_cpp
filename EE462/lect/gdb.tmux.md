# Using the GNU Project Debugger (gdb)
  
## Background
In this lab, you will use gdb to inspect an executable program while it is running
  

## Setup
Connect to your account on Polaris
Open tmux
Split into two windows using <Ctr>-b, %
You can switch between the panes with <Ctr>-b, o
  
## Program
Ceate a directory `~/ee462sp23/gdblab/`
Copy `/data/class/ee462sp23/dbg/fact.c` the dir above
In one of the panes, open `fact.c` in an editor

## compiling
`gcc -g -o fact fact.c`

## Starting gdb
In the other pane:
Compile with the debug flag: gcc -o fact -g fact.cpp
Test the binary: `./fact`
Start gdb: `gdb fact`
Run the commands listed below
view source listing: `list 1`
list 10
run the program: `run`
When asked, enter the number
It will terminate with the wrong answer, zero
  

## More gdb
bt
Now set a breakpoint inside main 
`b 8`
`info b`
Restart the program with `run`
(it will stop before the breakpoint)
`print n` or `p n`
`next`
`print n`
Check the next statement to be executed: where
get more context: list 9
Press `next` until it asks for a number
Enter the number 
Press `next`
(The function `factorial` is called and it returns a value)
`p result` (should print zero)
`whatis result`
`whatis &result`
`whatis main`
`whatis factorial`
`p main`
`p factorial`
`p sizeof(result)`
factorial returned the wrong value, so terminate the program
`kill`
  

## Stepping into functions
Restart with `run`
Proceed to right before line where factorial is called
(Since we know there's a bug is inside factorial, we will look at it more closely)
`step` should take you into the function ...
Verify that: `where`
`print x` (param passed)
`print result`
Local variables: `info locals`
Function arguments: `info args`
set breakpoint to the start of the loop
Observe that `where` tells you the next statement in factorial as well as in main
`next`
We are very interested in x and result:
`display x` (automatically display?)
`display result`
`info display`
`next`
Set another breakpoint before the end of factorial:
`continue`
(That will run the program until the next breakpoint)
  

## More on breakpoints 
Delete all breakpoints
`delete` (will ask to confirm?) 
Delete a specific breakpoint:
`info b`
[find the breakpoint#]
`delete <#BP>`
`d <#BP>`
Disable breakpoint:
`disable <#BP>`
Enable breakpoint:
`enable <#BP>`


## Disassemble (optional)
`disassemble main`
`disassemle factorial`
some registers:
`p $pc`  or `p $rip`
`p $rbp`
`p $rsp`
TODO: importance of the 4 registers
Restart the program and step into factorial()
`info frame` 
`info address main`
`info address factorial`


## Inspect memory (optional)
Step into factorial 
Set a breakpoint at line 21
run until this breakpoint
`x/4xbx &result`
You will see something like this:
0x7fffffffe158: 0x01    0x00    0x00    0x00
So now you know the address of the variable result
 You can monitor  a hardware location directly
`watch *0x7fffffffe158`
a hardware watchpoint will tell you every time the value there changes



  

