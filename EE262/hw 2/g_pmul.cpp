//Nathan Nguyen 
#include <iostream>
#include <vector>
using namespace std;

struct term{ //could have made a two dimensional array but then elements will not have names

  int coe;
  int power;
};

//translate user input of polynomial coefficients into a array 
void ask(string pnum, int* p, int size); 

//multiplies two univariate integer polynomials
int* ip_multiply(int* A, int sz_A, int* B, int sz_B);

//print polynomial to screen
void print(int* arr, int size); 

//transfer int array to term array
term* transfer2term(int* arr, int size, int termSize);



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




  int numOfZeros_A=0;
  for(int i=0; i<sz_A; i++){ //determine the number of zero-valued coefficients to determine size of term arrays
    if(A[i] == 0){
      numOfZeros_A++;
    }
  }

  int numOfZeros_B=0;
  for(int i=0; i<sz_B; i++){
    if(B[i] == 0){
      numOfZeros_B++;
    }
  }

  int sizeTermA = sz_A-numOfZeros_A;            //3
  int sizeTermB = sz_B-numOfZeros_B;            //2
  term* aterms = transfer2term(A, sz_A, sizeTermA); //transfer array of ints into array of terms(this is a struct that was defined in the beginning)
  term* bterms = transfer2term(B, sz_B, sizeTermB);
  //vector<term> productTerms; //vector because do not know if there will be terms of same power

 
  term temp;
  int productIndex=0;

  for(int j=0; j<sizeTermA; j++){ //go through poly1
    for(int k=0; k<sizeTermB; k++){ //go through poly2
      
      temp.coe = aterms[j].coe * bterms[k].coe;
      temp.power = aterms[j].power + bterms[k].power;

      productIndex = temp.power; //dont even need this variable
      productPoly[productIndex] += temp.coe; //power can reprensent the index of the array in all three arrays, a,b,and product 

      //productTerms.push_back(temp);
    }
  }

  cout<<"----------------------------------------------------------"<<endl;



  cout<<"after simple multiply"<<endl;
  for(int i=0; i<(totalDegProduct+1); i++){
    cout<<"coe: "<<productPoly[i]<<endl;
    cout<<"power: "<<i<<endl;
  }

#if 0
  
  for(int targ=0; targ<productTerms.size(); targ++){ //combine like terms loop 

    for(int rec=(targ+1); rec<productTerms.size(); rec++){
      
      if(productTerms[targ].power == productTerms[rec].power){
	
	productTerms[targ].coe += productTerms[rec].coe;
	productTerms.erase(productTerms.begin()+rec);
	
      }
    }
  }

  cout<<"after combing like terms"<<endl;
  for(int i=0; i<productTerms.size(); i++){
    cout<<"coe: "<<productTerms[i].coe<<endl;
    cout<<"power: "<<productTerms[i].power<<endl;
  }

  //then need to tranfer the productTerms to productPoly and then RETURN
  
  //find the lowest power, store into productPoly, erase it from vector, repeat

  int lowPow = productTerms[0].power;
  int coe = productTerms[0].coe;
  //should make a term current; instead of the two lines above me with two different ints
  int deleteI;
  int i_arr = 0; //independent index that goes through productPoly and does not overwrite
  for(int i=0; i<productTerms.size(); i++){
    for(int k=0; k<productTerms.size(); k++){ //find lowest power in vector
      
      if(lowPow > productTerms[k].power){
	lowPow = productTerms[k].power;
	coe = productTerms[k].coe;
	deleteI=k;
      }
    }

    for(int j=i_arr; j<=lowPow; j++){ //populate zeros
      if(j != lowPow){
	productPoly[j] = 0;
	cout<<"here "<<j<<endl;
      }
      else{
	productPoly[j] = coe;
	i_arr = lowPow+1;
      }
    }

    productTerms.erase(productTerms.begin()+deleteI);
  }
  

  #endif
 
  //need to delete arrays of terms here
  return productPoly;
}


























term* transfer2term(int* arr, int size, int termSize){

  term* terms = new term[termSize];

  int i_term=0; //independent index that goes through the aterms array
  for(int i_pow=0; i_pow<size; i_pow++){ //goes through the original array 
    if(arr[i_pow] != 0){
      cout<<"here"<<endl;
      
      terms[i_term].coe = arr[i_pow];
      cout<<"coe: "<<terms[i_term].coe<<endl;

      terms[i_term].power = i_pow;
      cout<<"power: "<<terms[i_term].power<<endl;
      
      i_term++;
    }
  }


  return terms;
}
