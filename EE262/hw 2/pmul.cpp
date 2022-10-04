//Nathan Nguyen, the best code I have ever fucking written at Clarkson at this point of my sophmore year, fuck Brad and all other white fucks that think they are the best software engineers because none of them could make code this compact and clean
#include <iostream>
using namespace std;


#define TEST_CODE 1


//translate user input of polynomial coefficients into a array 
void ask(string pnum, int* p, int size); 

//multiplies two univariate integer polynomials
int* ip_multiply(int* A, int sz_A, int* B, int sz_B);

//print polynomial to screen
void print(int* arr, int size); 


int main(int argc, char *argv[]){

  int totalDegree1, totalDegree2;
  
  cout<<"Degree of p1: ";
  cin>>totalDegree1;
  int* p1 = new int[totalDegree1+1]; //create a dynamic array and have p point to it
  ask("p1", p1, totalDegree1+1);
  print(p1, totalDegree1+1);


  cout<<"Degree of p2: ";
  cin>>totalDegree2;
  int* p2 = new int[totalDegree2+1];
  ask("p2", p2, totalDegree2+1);
  print(p2, totalDegree2+1);



#if TEST_CODE
  int* productPoly = ip_multiply(p1, totalDegree1+1, p2, totalDegree2+1);
  int totalDegProduct = totalDegree1 + totalDegree2;

  cout<<"Product -- [";
  for(int i=0; i<(totalDegProduct+1); i++){
    cout<<productPoly[i];
      
    if(i != totalDegProduct){ //no comma after printing last number in list
      cout<<", ";
    }
  }
  cout<<"]"<<endl;
  print(productPoly, totalDegProduct+1);
#endif





  delete[] p1, p2, productPoly;




  //REMEMBER TO DELETE ALL THE NEW KEYWORDS LIKE DELETE THE DYNAMIC ARRAYs IN THE HEAP




  return 0;
}


void ask(string pnum, int* p, int size){
  
  int coe;
  for(int i=0; i<size; i++){
    cout<<"["<<pnum<<"]"<<" coefficient of x^"<<i<<": ";
    cin>>coe;

    *(p+i) = coe; //deference p pointer and assign values to elements in the dynamic array, same as saying p[i] = coe;
  }
}

void print(int* arr, int size){
  cout<<endl;
  for(int i=0; i<size; i++){
    
    if(arr[i] != 0){  
      cout<<arr[i]<<"x^"<<i;
      
      if(i != (size-1)){
	cout<<" + ";
      }
    } 
  }
  cout<<endl<<endl;
}


int* ip_multiply(int* A, int sz_A, int* B, int sz_B){

  int totalDegProduct = (sz_A-1) + (sz_B-1); //true totalDegree and had to minus one the size to get true totalDegree of original poly
  int* productPoly = new int[totalDegProduct+1];

  //need to make sure it is all zeros
  for(int i=0; i<(totalDegProduct+1); i++){
    productPoly[i] = 0;
  }

//index of array is equivalent to the power of the term
    for(int powerA=0; powerA<sz_A; powerA++){
        for(int powerB=0; powerB<sz_B; powerB++){
            
            productPoly[powerA+powerB] += A[powerA] * B[powerB]; //coefficients multiplied and added to existing term with the same power that is already stored in productPoly (combine like terms)
        }
    }

    return productPoly;
}