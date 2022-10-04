//phase 1 review and phase 2 (4/29/2021)
#include <iostream>

using namespace std;

/*

-half of the course is about big ideas
    -data structures
    -control structures
    -problem solving

-other half is picky details like <> and &


how to write a big program
-20% of the effort is in actually coding
-design
-document
-user interface

-start with the user and with the data

Part 1: Top-Down
Part 2: Bottom Up


-good program is:
-correct
-clear
-compact
-elegant (no hacks)
-speed


counting = integer
decimals = double, float
hybrid like 3.25 could be two ints or a double
    -could use a struct to have two ints together
-true/false = bool
-char
-string or cstring

-array = all the same type (or vector if size is unknown)

-class or struct to mix data types

-class will have private and public member data or member functions


-cin to ask data

-ifstream ofstream

-while loop has a test at the top
-do while loop has a test at the bottom
-for loop for counting

-data = bits (all bits and ones and zeros)

8 bits = 1 byte

char = 1 byte

int = 4 bytes

double = 8 bytes

sizeof() function

-same pattern of bits can mean different things depending on data type you tell it

-variable names cannot start with a number, cannot have blanks or special characters
-also cannot be a "reserved word" like int or main 



-division with ints will throw away remainders
-% captures the remainder

-strings arithmetic like + is concatenate
+ is a overload friend operator in string class

-statements execute the next line until ; or just use compound like {} (compound statement)


-scope
-a block {} can contain local variables

-a global variable is declared outside of main

-you can declare local variables not at the top of the block like if u using a constructor at the end of a for loop for example




functions:
#include <cmath> for sin cos tan functions you know



how to write a function
-determine type and number of parameters
-determine the type of return value
-declare function at top and document so compiler understands while reading the main
-define function at bottom of the program


-parameters that are passed are the values of the expressions, variables, or constants

-you dont have to name the parameters at declaration but its a matter of human readability

-you have to name the parameters at definition no matter what


-overloading:
two functions almost identical (like the same function name) but with different number of parameters
-constructors use overloading a lot
-overloading operators like < or > or + 


call by reference:
-reference parameters (pass the address of variables instead) are used to return more than one values 
-or you can return a struct or class
-cannot use a constant or math expressions 

-you can use const the keyword to make sure that the function does not change the value of the ref parameter passed


files:
#include <fstream>

ifstream instream;
ofstream ostream;

instream.open("file.txt");
instream.close();
instream.fail();

instream >> variable (be careful because blanks are not taken and \n)
(extraction operator)



instream.eof(); //throws true right after it has stepped outside of the file at the end

getline()

.get()

------------------------------------------------------------------------------------------------------------------------------------------------------------------- (stopped on slide 41)

4/29/2021 (in-class)


>> 
-reads characters until it hits whitespace
-grabs characters and converts to correct type you are looking for
-stops when it hits whitespace (blank, tab, newline)
-fails big time if you give it the wrong type of character

cin.get()
-grabs one character as a character, no ints 
-grabs whitespace as character


getline()
-two forms, member function of a instream or function with instream as first parameter
-member function reads into cstring
-this function stops when it hits newline, grabs newline and throws it away
>> does not grab and throw away newline so get() to get rid of it for next getline()


formatting

mystream

cout.setf(        );
ios::left
ios::right
ios::showpoint
cout.width(69)


grep left *//*.cpp
general



#include <cctype>
c2=toupper(c1);


array-----------
cant cout 
cant expand

int a[3]={1,10,100};

-can send an entire array through parameter to a func and ref as well
-and single array elements
-you dont need to tell the function how many elements in the array, has to pass number through another parameter
-or use a sentienal value at the end of the array

-for example
cstring has \0 at the end as a sentinel value

so greeting[80] actually can only have 79 and then \0



strcpy(target, source)

can get in trouble when the two string sizes are different and dont match



#include <vector>
vector is a class and is smarter than an array

vector<double> measurements;

-dont know how many elements or size of array
-any kind of data type
-user defined types are structs and classes
-.push_back() to add stuff at the end
-.size()


strings are a class and are like vectors to chars or cstring
.length()



structs
-mix variables/ data types together to be one new user defined data type


struct name{

type variable;
type variable;

};
-you can assign, pass as parameter, return as a value or return more than one variable in a function, put into an array or another struct

-collection of attributes of one thing


-no objects, classes, vectors, strings, or streams in regular C


-had to manage memory back then
-everything was visible
-couldnt hide complexity


myobject.setname("Thorpe");

-imperative = go do something like a command

oop is like sending messages between objects


class Name{
private:
    type name;


public:
    //constructor
    Class(parameters);
    Class();

};

Class::Class(){} //default constructor

Class::Class(parameters){

}

Class object(parameters)


-make all data private
-class name is capitalized

constructors (create new objects of that type, possiblly initializing them)
accessors (return information about the object)
    -print
mutators (change the information inside the object)
    -read, set



object.variable

type Class::member_function_name(parameters){
    variable
}


:: is the "scope resolution operator"






friends-------- (accessing two or more different objects of the same class) cant be a member function

friend type function_name(arguments);

type function_name(arguments) {} //arguments are typical two different objects of the same class, dont friend mulitple different classes, go take CS 142


-use this when it reads better
-symmetry


//member function
checkout.later(due);

//friend
later(checkout, due);



cannot cout a struct or cin

-no include libaraies specifically
-no linux commands
-no flags









*/




int main(){





    return 0;
}