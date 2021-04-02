//Nathan Nguyen
// lab 10 - vectors
#include <iostream>
#include <vector>
using namespace std;

void doSort(vector<int> &v); //sorts a list of integers to be largest first and smallest las\
t

int main(){

  vector<int> vec;
  int temp;

  cout<<"Enter a list of integers to be sorted, negative number to terminate\n";
  cin>>temp;

  while(temp>=0){
    vec.push_back(temp);
    cin>>temp;
  }

  cout<<"end of input"<<endl;

  doSort(vec);

  for(int i=0; i<vec.size(); i++){
    cout<<vec[i]<<endl;
  }


  return 0;
}

void doSort(vector<int> &v){  //sorts a list of integers to be largest first and smallest la\
st

  int top = 0;
  int temp;

  if(v.size()<=1) return; //why sort when there is only one number?


  while(top<v.size()){ //'forgets' numbers near the beginning after it has been sorted to be\
 near the beginning becuase of its value, so makes sure that the inner for loop only deals w\
ith numbers that have not been sorted correctly yet

    for(int i=(v.size())-1; i>top; i-- ) { //v.size() - 1 because vectors start at zero
      //moves one number or a few as far as possible to the beginning of the list while movi\
ng from left to right of the list

      if(v[i-1]<v[i]){
        temp=v[i];
        v[i]=v[i-1];
        v[i-1]=temp;
      }
    }
    top++; //'forget' or store that the beginning number(s) have been sucessfully sorted and\
 should not be touched
  }

  return;
}
