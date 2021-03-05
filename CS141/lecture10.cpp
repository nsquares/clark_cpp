//files

#include <iostream> //cout and cin
#include <fstream> //formated stream

using namespace std;

int main(){

    // ifstream instream; //declare and name input format stream

    // ofstream ostream; //declare and name output format stream

    // instream.open("infile.dat");

    // ostream.open("outfile.dat"); //open it

    // instream>>variable; //like cin

    // ostream<<variable; //like cout

    // instream.close();

    // instream.fail();

/*
    int a,b,c;
    ifstream in; //in is an object of the class ifstream
    ofstream out;

    out.open("second.txt");  // dot operator is calling a member function (member function is open)
    in.open("first.txt");   //cannot put a string in here as fstream does not know what to do with string varibles becuase string is class

    while(in>>a){  //will return a false if no data
        
        out<<2*a;
    }

    //in>>a>>b>>c;
    in.close();

    //out<<a<<b<<c;    //writes a zero if no input into the output file, interesting
                    //also writes a zero if there is a letter in the file and is trying to store a zero (so make sure data types match)
    out.close();
*/

    //char filename[80]; 
    //cin>>filename;
    //in.open(filename);

    //could pass ifstream objects into function parameters but good practice to use refernce (&) parameters because of how big they are so dont create a inner scope version you know?
    //  more efficient to just use reference parameters and change the one created in the main



/*
    int number;
    string name;
    ifstream in;
    int count;
    int target;

    cout<<"What number are you looking for ";
    cin>>target;

    in.open("name.txt");

    in>>count;

    for (int i=0;i<count;i++){
        in>>number;
        in>>name;
        if(number==target){
            cout<<name<<endl;
        }
    }
    in.close();

*/

    ifstream in;
    int num;
    char name[80]; //char array

    cout<<"file name? ";
    cin>>name;

    in.open(name);

    if(in.fail()){
        cout<<"cant open "<< name<<endl;
    }
    else{
        while(in>>num){  //also throws a false if no data collected
            cout<<num*2<<endl;
        }
    }

    return 0;
}