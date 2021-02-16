//review day for test 1

#include <iostream>
using namespace std;

int main (){

    //closed book, closed notes, closed everything
    //in-person test, paper and pencil


    /*
    -variable is a chuck of memory that has a type and a name
    -int are exact, whole numbers and need to compare
    -legal values of bool are if anything is not zero then it is true
        -false is zero
    -++ adds one after or before



    we have learned 
    -linux and nano, emacs
        -cd by it self goes to home directory
        -ls
        -mkdir
        -rm, cat, more, cp, mv
        -cat means connect a bunch of files
        -more shows you the file without opening it like print to terminal
        -cp copies while mv moves or cuts and renames filies
        -g++ foo.cpp -o foo 

    -should be writing on polaris, interesting, use emacs?


    -vairables and arithmetic (watch video of this section)
        -cannot use keywords
        -cannot start with a number
        -underscore or camelCase
        -char are single quote, string are double quote
        -const makes variables constant (self-protection)
    -cin cout
        -can turn numbers into string 
        -cannot turn string into numbers
        -can throwaway whitespace
        -cin kinda smart
        -watch arrows

    -arithmetic
        -everything works like normal 
        -but be careful with divison as it 

    -if, else, switch
        -|| or
        -&& and
        -cannot use string or int in switches
        -the next command is always executed after an if statemnet if no brackets
        
    -loops while do while
        -for loops for counting
        -do while to test at bottom and do it once for sure
        -while to test first before running
        -infinite loops might be intentional (while true)


    -hw 
        -could have used if(!(num%2))
        -this is the same as (num%2==0)


    -ascii types and scope 
        -strings are a class
        -ascii table really just shows that the same bits can be
        inerperted as many different things with the right type
    -same bit pattern does not always mean the same thing because types
    -char c 
    c-'0'

    (ascii to int) '0' means 45 in int

    -how are floats represented
    -what does unsign mean (adds more bits for counting but no more negative or positive)

    29 % 15 and then stop checking (15 is half of 29)

    */

   //(n/2)+1

//-----------------------------------------------------
    int outer, inner;
    bool divisible;

    //outer loop to go through all numbers 3 to 100
    for (outer=3;outer<100;outer++){
        divisible=false;

        for (inner=2;inner<((outer/2)+1);inner++){
            if ((outer%inner)==0) divisible=true;
        }

        if (!divisible) cout<<outer<<endl;
    }
    //inner loop to go through all numbers up to (outer /2)+1

    //test for divisibility

    //after the inner loop, if nothing went into it evenly, its prime

    //!g does the last linux command that starts with g
    //!. does the last linux command that starts with .


    



    return 0;
}