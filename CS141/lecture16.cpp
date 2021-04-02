// fancy arrays
#include <iostream>
#include <vector> //include this for vectors
#include <cstring> //has it own copy
using namespace std;

void cpy(char [], char []);


int main(){

    /*

-notes
//use these one the homework

cout.setf(ios::left);

cout.setf(ios::right);

cout.unsetf(ios::right);

-ctrings 
-strings
-vectors

-arrays contain a sequence of values all with the same name
-passing arrays as a parameter is very much like a ref parameter
-arrays cannot assign array values to itself??

-vectors are a class that is much smarter than an array, lol

-classes and objects have member functions and operators


---------vectors (an object, template class because different base types)
-declare:
vector<Base_Type> name

vector<int> int_vector;

-add an element .push_back(value);

.size(); member function



-vectors have a bunch of memory
-an int saying how much memory
-an int saying how much is used
-a way of going and getting more memory when it needs it
-member functions to initialize, find out about memory


    */

/*
    vector<int> v1;   //constructor
    vector<int> v2;


    cout<<"size of vector: "<<v1.size()<<endl;
    v1.push_back(99);
    v1.push_back(-1);
    v1.push_back(66);
    cout<<"size of vector: "<<v1.size()<<endl;

    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }

    v2=v1; //cant do this in arrays

    //v2[10]=100; //dangerous

    v2[1]=100; //this changes second number so vectors still start at zero

    //.at(10); //looks at element 10

    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }




*/


    //vector is not an array, it can be passed as a parameter; but if you want to change elements of the vector, you need to use a ref parameter.

    
    //c strings -not strings

    //last character is a \0

    //char greeting[80]  can really only hold 79 characters

    /*

char word1[20]="Hi"
    -three characters h,i,\0

char word1[20]={'h','i'}
    -only has two chars and no \0 unless you put in \0 yourself in the statement above



    */



   char a[80]="Hello World";
   char b[80];

   //strcpy(b,a); //does the same thing as  (target, source)
   cpy(a,b);
   cout<<b<<endl; ///smart enough for no for loop

//strncpy()
//strcat()
//strlen()
//strcmp()

//cin.getline() works with cstring

//how to get in trouble 
//forget the \0
//copy a big array to a small array
//forget how strcmp() works



//string is not a type, it is a class
//strings are better than cstrings (like vectors to arrays)

//see page 484-485 (member functions)

//operators << >> + [] = == !=

//string name;    //constructor

//-accessor lets you get at a value of all or part of an object

//str[i] acts like an array ref, no boundary check

//str.at(i) //same thing but with boundary check

//string hobby;
//hobby.find("ing")
//outputs: position of where ing is 


    string name, fname, lname; //constructors

    char buffer[80];
    int length;
    int i;

    cout<<"enter your name: ";
    cin.getline(buffer,80);

    name = buffer; //smart enough for cstring to string
    cout<<name<<endl;

    i=name.find(",");
    cout<<i<<endl;

    if(i==-1){ //didnt find a comma

    length=name.find(" ");
    fname=name.substr(0,length);
    lname=name.substr(length+1,name.length()-length-1);

    }
    else{ //found a comma
    lname=name.substr(0,i);
    fname=name.substr(i+2, name.length()-i-2); //skip comma and blank

    }

    cout<<fname <<" "<<lname<<endl;


    //.c_str() is a member function that generates a "c string"

    return 0;
}



void cpy(char a[], char b[]){

    int i=0;
    while(a[i] != '\0'){

        b[i]=toupper(a[i]);  //dont have to remember setf and the toupper for test
        i++;

    }

    b[i]=a[i]; //need to also copy the \0 at the very end (polaris failed but not vscode interesting)

}