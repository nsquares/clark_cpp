#include <iostream>
using namespace std;

int main(){
/*
int dayNum=0;
int weekTotal=0;
int grandTotal=0;

for(int tenWeek=0; tenWeek<10; tenWeek++){
	weekTotal=0;

	for (int sevenDays=0; sevenDays<7; sevenDays++){
		
		cout<<"give one day worth of calls: \n";
		cin>> dayNum;
		weekTotal += dayNum;
	}
	cout<<"Week "<<tenWeek<<" you this many calls: "<<weekTotal<<endl;
	
	grandTotal += weekTotal;

}
cout<<"grand total of 10 weeks is "<<grandTotal<<endl;

*/
int userNum;
cout<< "(1) Fried Rice";
cout<<"Give me the number of you dish: ";
cin>>userNum;

switch(userNum){
	case 1:{
	cout<<"Someone ordered Fried Rice"<<endl; //sent to the kitchen
	break;
	}
}

	return 0;

}
