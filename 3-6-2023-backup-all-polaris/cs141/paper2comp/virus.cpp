//day before exam 2 cs141
//nathan nguyen

//I created a program that can read and write .cpp files (really any kind of file)
//all it can do right now is copy files or create a copy of a file that the user types in

/*
-need the name of the file to read 
-need a name for the output file that the program will write to and create out of thin air at the same time

-process is using getline() function or read line by line and then write it into the output file line by line at the same time

-real process is read a line, write a line, read a line, write a line.................. then eof or end of file

 */


#include <iostream>
#include <fstream>
using namespace std;

//void readFile(string text, ifstream &in);
//void writeFile(string text, ofstream &out);

int main(){

  char filename[80];
  char outfilename[80];
  string temp;

  cout<<"Give me a file to infect: \n";  //add the .cpp at the end bro
  cin>>filename;

  cout<<"give me a new and unique file name: \n";   //add the .cpp at the end too here bro
  cin>>outfilename;


  ifstream in;
  ofstream out;

  in.open(filename);
  if(in.fail()){
    cout<<"opening file failed"<<endl;
    return 0;
  }

  out.open(outfilename);

  while (!in.eof()){
    getline(in,temp);
    out<<temp<<endl;
    cout<<temp<<endl;
  }
  //cout<<temp<<endl;
  in.close();
  out.close();


  return 0;
}
