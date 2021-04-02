//review day before second exam

#include <iostream>
using namespace std;

int main (){

/*
notes:

getline(cin,line); //read up to the \n

cin.ignore();

>> //skip whiespace, read printable characters and interprets

.get // reads one character


-function / subroutine
-argument / parameter
-function definition (with formal parameters)
-return type
-function definition

-scope!!!!!!!!!
-functions are like separate programs

provided function:
sqrt()
tan()
abs()
getline()
toupper()
-see page 187
isalpha();

//member functions that come with classes
object.open();
object.fail();


steps in writing a function
-write down what function does and comments
-decide the parameters and types and on the return value and type
-put function declaration at the top of your program (before main)
-write function def after main


-void returns nothing and can also have a return statement to end at specific places for example, is optional tho

overloading:
-"when you overload a function name, the function definitions must have different
numbers of parameters or parameters of different types"


-when there is a function call, the compiler uses the function def whose number of formal parameters and types of formal parameters match the arguments of the function call 
-(really wrote two different functions that have the same name: thats overloading)

-same name for all functions
-different number of arguments or different types of parameters

-plus side is that it is more readable and does not have worry about specifics, just read name of function

-used a lot in OOP

-same function name and function return but different parameters means overloading
    -has to be a constant return type in all different functions with same name thats overloading









value and ref parameters:
-value parameters are one-way (go inside the scope of function and cannot come out): the value of the argument gets passed to the function

-reference parameters are two-ways (go inside the scope of function and can come out in a sense or really is just directly modifiying the originial address of the variable passed through the function call)
   : the address of the argument gets passed, so any changes to that argument within the function change the value in the calling routine (like in the main)
    -pass streams as ref parameters
    -example syntax::::::::::::::

    int &refVariable




Driver: focus on function defs, have a basic main that calls fully-coded completely-intended functions 
    -Nathan Nguyen words:"just enough of a main (driver) written so that functions can be tested"
    -drivers are about creating basic driving mains



Stub: focus on the main, have a bunch of useless functions that "work"
    -"just enough of a function definition is written so that you can exercise the calling sequence in main"
        -function can do really nothing useful or is fully-written or ready for program release
    
    Nathan Nguyen words:
    -"just enough of function defs (stubs) written so the main can be tested"
    -stubs are about creating stub functions

-return multiple values means use a ref parameters












files:

-cin is a stream connected to the keyboard
-cout is a stream connected to the screen


-------formated and do more than cin and cout
-ifstream is a stream connected to read from a file
-ofstream is a stream connected to write to a file

-#include <fstream>

ifstream in;

in.open("filename.txt")

in>> variable;
in.fail();
in.close();



dealing with single characters------------
>>
    -throws out whitespace
cin.get(next);
    -grabs next character (all whitespace)
cout.put(next);
    -puts next character at a time

-grabs ASCII, no ints

-member functions

char name[80];
cin.getline(name, 80); //takes cstring

string name;
getline(cin,name); //takes string





-------formatting for output streams
flags: cout.setf(ios::fixed) //set flags like show decimal points or not
member functions: cout.precision(3);


-----both are the same below in terms of function and speed, nothing different but readablity
special case: cout.width(n) only applies to next output

manipulators: cout<<setw(4)<<num;


-all of these apply to ofstream 



predefined character functions
-if you have a single character (from cin.get(a)) you can do

isalpha(a) //checks if it is abcdefghijklmnop or cap you know
toupper(a)
tolower(a)




end of file--------------------
1. by count

2. when >> returns false
while (infile>>data){
    //do something
}

3. eof

instream.get(c);
while(!instream.eof()){
    //do something
}

//dont use a do while loop for eof



quiz----
-a file is data stored on a disk

-ifstream is for reading
-ofstream is for writing

-stream.open();
.fail();
.close();

-you can open a bunch of unique files all at the same time really

















































*/


    return 0;
}