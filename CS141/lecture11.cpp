#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char *argv[]){   //how to pass stuff through the main at the command line during the call to execute like ./lect11 gsdjfgrehgieuh
// 




    //three different ways of formating
    

    // set flags in the IO system 

    //  cout.setf(ios::fixed); // not using scientific notation

    //  cout.setf(ios::showpoint); //show decimal point always

    //  cout.precision(2); //two digits after decimal point

    //ios::showpos        plus sign

    //ios::right        right justify

    //ios::left        left justify

    //boolalpha     prints true and false instead of 1 and 0



    //member functions            //the prefered way by professor

    //cout.width(10)   //minimum number of characters but only applies to the very next cout statement and then goes back to normal

    //can use these member functions with ifstream and ofstream as well, remember that



    // #include <iomanip>

    //    cout<<j<<setw(4)<<k<<endl;       //called a manipulator and adds 4 spaces between j and k

    //  cout<<setprecision(3)<<x; 





    //                         void write (ostream& );  //can pass the cout or a ofstream
    //page 348 in book
    //not on exam


    //counting the number of blanks or whitespaces

    /*
    int c=0;

    char inc;

    do{
        cin.get(inc);   //can use any stream  
        //can only read char and have to use ACSII table for other types

        //cin.put(inc);       //can also put stuff in
        //cin.putback(inc);    //can also put stuff back into stream after pulling from stream, this is good for the next cin statement because if not here, then the next cin will be waiting so user have to input their answer twice
        // can also putback something completely different then what is given
        if(inc==' ') c++;
    } while(inc != '\n');

    cout<<c<<" blanks\n";

    */



    // instream.get(c)
    //while (!instream.eof())       //boolean end of file and true when you have read past the end of the file


    // cout<< char == cout.put(char)

    // cin>> char != cin.get(char)



    // reading an entire line
    // #include <string>

    // string line;

    // getline(cin, line); //reads everything, and all ASCII



    // #include <cctype> 

    // c2 = toupper(c1);

    //check page 1042 in book

    char c;
    bool first = true;


    cin.get(c);

    while(! cin.eof()){
        if (first) c=toupper(c);
        cout<<c;
        if (isspace(c)) first=true;
        else first=false;
        cin.get(c);

    }
    




    return 0;
}