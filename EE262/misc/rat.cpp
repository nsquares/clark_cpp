// Nathan Nguyen - Problem 2
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



class rational{

public:
  //constructors
  rational(int inum, int iden);
  rational(int inum); //den is automatically the value of 1
  rational();
  
  //print rational in proper form to a stream
  void output(ostream& y, string label);

  //store input values into a rational object
  void input(istream& x);

  //math operations (these do not change any private data, return is a fresh new object)
  rational add(rational); 
  rational sub(rational); 
  rational mul(rational);
  rational div(rational);

  rational neg();
  bool less(rational);

private:  
  unsigned int num; //numerator 
  unsigned int den; //denominator
  bool isNegative; //store if the rational is negative

  //common constructor code
  void commonInit(int inum, int iden);

  //return num as a negative version of itself if isNegative is true
  int getNegNum(rational irat);
  
  //reduce rational number to its most simplified form (will change num and den member variables)
  void tryReducing(rational& irat);
  
  //find greatest common divisor of two positive integers
  unsigned int gcd(unsigned int n1, unsigned int n2);
  
  //checks if denominator is zero (call this function in every function)
  void checkDenZero(int iden);
};




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


void rational::commonInit(int inum, int iden){
  checkDenZero(iden);

  if(inum < 0){
    isNegative = true;
    inum *= -1;
  }
  else if(iden < 0){
    isNegative = true;
    iden *= -1;
  }
  else {
    isNegative = false;
  }

  num = (unsigned)inum;
  den = (unsigned)iden;
  tryReducing(*this);
}

int rational::getNegNum(rational irat){
  int rnum = irat.num;
  if(irat.isNegative){
    rnum *= -1;
  }
  return rnum;
}

void rational::tryReducing(rational& irat){
  checkDenZero(irat.den);
  unsigned int divisor = gcd(irat.num, irat.den);
  irat.num = irat.num / divisor;
  irat.den = irat.den / divisor;
}

unsigned int rational::gcd(unsigned int n1, unsigned int n2){
  unsigned int tmp;
  while (n2 != 0) {
    tmp = n1;
    n1 = n2;
    n2 = tmp % n2;
  }
  return n1;
}

void rational::checkDenZero(int iden){
  if(iden == 0){
    cerr<<"Denominator can't be 0."<<endl;
    exit(-1);
  }
}

rational::rational(int inum, int iden){
  commonInit(inum, iden);
}

rational::rational(int inum){
  commonInit(inum, 1);
}

rational::rational(){
  commonInit(0,1);
}

void rational::output(ostream& y, string label){
  checkDenZero(den);
  y<<label<<": "<<getNegNum(*this)<<"/"<<den<<endl;
}

void rational::input(istream& x){
  
  int inum, iden;
  cout<<"enter numerator: ";
  x>>inum;
  cout<<"enter denominator: ";
  x>>iden;

  rational temp(inum, iden);
  *this = temp;
}

rational rational::add(rational irat){
  checkDenZero(den);
  checkDenZero(irat.den);

  int num1 = getNegNum(*this);
  int num2 = getNegNum(irat);
  int den1 = (int)den;
  int den2 = (int)irat.den;

  int rnum = (num1*den2) + (num2*den1);
  int rden = den1*den2;

  rational result(rnum, rden);
  return result;
}

rational rational::sub(rational irat){
  checkDenZero(den);
  checkDenZero(irat.den);
 
  int num1 = getNegNum(*this);
  int num2 = getNegNum(irat);
  int den1 = (int)den;
  int den2 = (int)irat.den;

  int rnum = (num1*den2) - (num2*den1);
  int rden = den1*den2;

  rational result(rnum, rden);
  return result;
}

rational rational::mul(rational irat){
  checkDenZero(den);
  checkDenZero(irat.den);

  int num1 = getNegNum(*this);
  int num2 = getNegNum(irat);
  int den1 = (int)den;
  int den2 = (int)irat.den;

  int rnum = num1*num2;
  int rden = den1*den2;

  rational result(rnum, rden);
  return result;
}

rational rational::div(rational irat){
  checkDenZero(den);
  checkDenZero(irat.den);
 
  int num1 = getNegNum(*this);
  int num2 = getNegNum(irat);
  int den1 = (int)den;
  int den2 = (int)irat.den;

  int rnum = num1*den2;
  int rden = den1*num2;

  rational result(rnum, rden);
  return result;
}

rational rational::neg(){
  checkDenZero(den);

  rational result = *this;
  result.isNegative = !result.isNegative;

  return result;
}

bool rational::less(rational irat){
  checkDenZero(den);
  checkDenZero(irat.den);

  int num1 = getNegNum(*this);
  int num2 = getNegNum(irat);
  int den1 = (int)den;
  int den2 = (int)irat.den;

  return ((num1*den2) < (num2*den1));
}
