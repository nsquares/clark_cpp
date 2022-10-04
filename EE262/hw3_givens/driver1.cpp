//note: add the contents of this file to the file containing your rational class

#include <iostream>
#include <fstream>
#include <cstdlib>

using std::istream;
using std::ostream;
using std::endl;
using std::cerr;
using std::cin;
using std::cout;
using std::ofstream;
using std::ifstream;
using std::string;


int main(void) {
  rational r1(10, 3);
  rational r2(8, -2);

  r1.output(cout, "r1");
  r2.output(cout, "r2");

  rational r3 = r2.neg();
  r3.output(cout, "r3");

  rational r4 = r1.neg();
  r4.output(cout, "r4");

  rational r6 = r3.add(r1);
  r6.output(cout, "r6");

  cout<<endl;
  ifstream in1;
  in1.open("inp1.txt");
  rational r5;
  cout<<"r5 will get input from ifstream (connected to inp1.txt):"<<endl;
  r5.input(in1);
  in1.close();  
  r5.output(cout, "r5");
  cout<<endl;

  rational r7 = r3.sub(r1);
  r7.output(cout, "r7");

  rational r8 = r6.mul(r7);
  r8.output(cout, "r8");

  rational r9 = r8.div(r5);
  r9.output(cout, "r9");

  cout<<"r9 < r1: "<<r9.less(r1)<<endl;
  cout<<"r4 < r5: "<<r4.less(r5)<<endl;
  cout<<"r6 < r8: "<<r6.less(r8)<<endl;
  cout<<"r1 < r3: "<<r1.less(r3)<<endl;

  cout<<endl;
  rational y1(70);
  y1.output(cout, "y1");

  cout<<endl;
  rational y2;
  y2.output(cout, "y2");
  
  cout<<"y2 will now get input from cin: "<<endl;
  y2.input(cin);
  //enter: 34/-6 (user input)
  y2.output(cout, "y2");

  
  cout<<endl;
  ofstream ofs;
  ofs.open("log1.txt", ofstream::out); //ofstream::app
  r1.output(ofs, "r1");
  r2.output(ofs, "r2");
  r3.output(ofs, "r3");
  r4.output(ofs, "r4");
  r5.output(ofs, "r5");
  r6.output(ofs, "r6");
  r7.output(ofs, "r7");
  r8.output(ofs, "r8");
  r9.output(ofs, "r9");
  y1.output(ofs, "y1");
  y2.output(ofs, "y2");
  
  ofs.close();
  
  rational r10(18, 0);
  rational r11(12, 4);

  return 0;
}

