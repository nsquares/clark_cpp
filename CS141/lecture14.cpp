//arrays 

#include <iostream>
using namespace std;

int main(){

    /*

    -the test was all about the big picture so I didnt need to check if the input file opened or not (in.fail())

array time:

-arrays in c start at zero lol

-cant run over the size of the array or past the end("stack overflow lol") (this will dip into next chunk of memory or address after the array address (or outside of the array address really) so values or bits of data can be anything)

-cannot expand or contract the array

-you can use a variable for array size but THIS CLASS will only use a constant
    -its somewhat hard to make them dynamic so dont try in this class so hard to make them dynamic

-cant assign an array but can assign individual elements which is painful

-cant print (it prints the address in memory that the array is stored in)



    */


   const int NUM = 3;
   int count[NUM];


//method 3 of writing an array:
//could also write int loc[] = {1,2,3};                   // cpp can figure out what size to allocate but coder has to keep track of this in his head
    //this might be good for characters where we dont know how long the user input might be

//method 2:
    string loc[NUM] = {"counter", "shelf", "warehouse"};
    
//method 1:
    //loc[0]="counter";
    //loc[1]="shelf";
    //loc[2]="warehouse";


    //int a[5]; //gives values of unknown according to professor 

    //int a[5]={1,2}; //gives three more zeros or blanks if strings in the array after the two assigned values
    
    //same thing as
    //int a[5]={1,2,0,0,0};



    /*

    (range-based for loop) //not on the test

    // j is actually the elements of the array and not the indexs

    for (string j : arr) //not on the test but needs a more updated version of g++ compiler (check slides / download it)
    //this finds the end of the array by itself 
        cout<<whatever

    */


   for (int i=0;i<NUM;i++){  
       cout<<"how many items in a place "<<loc[i]<<"? "<<endl;
       cin>>count[i];
       cout<<count[i]<<endl;
   }





   int biggest = -1; //safe number because it is less than zero
   int index = -1; //because the loop starts at zero

//int biggest = count[0];
//int index = 0;            //could do this as well instead

   for (int i =0;i<NUM;i++){
       if(count[i]>biggest){

           biggest=count[i];
           index=i;            //can be used to find the location in array
       }

   }


    return 0;
}