#include <iostream>
#include <fstream>
using namespace std;


int main(){

  int someInteger;

  ifstream infile;
  ofstream outfile;

  infile.open("file1.dat");
  outfile.open("file2.dat");

  infile>>someInteger;
  outfile<<someInteger;

  infile.close();
  outfile.close();




  return 0;
}

