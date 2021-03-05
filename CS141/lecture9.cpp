#include <iostream>
using namespace std;

//gets first and last names
void get2(string &first, string &second);

//convert feet and inches to meters and cm
void feet_to_meters(int ft, double in, int &meters, double &cm);

//input 24 hour notataion
void in24(int &h, int &m);

//convert
void cvrt(int h24, int m24, int &h12, int &m12, char &ampm);

//output 12hour format
void prt(int h, int m, char ampm);



int main(){
//writing a simple driver
/*
    string fname="abc";
    string sname="def";

    get2(fname,sname);
    cout<<fname<<", "<<sname<<endl;
*/
/*
    int feet, meters;
    double inches, cm;

    feet_to_meters(6,2.5,meters,cm);
    cout<<meters<<" and "<<cm<<endl;
*/

int h12,h24,m12,m24;
char ampm;

in24(h24,m24);
cvrt(h24,m24,h12,m12,ampm);
prt(h12,m12,ampm);
cout<<endl;



// i think using call by reference or reference parameters in a function is useful
//so I dont have to make so many globals 

//reference parameters allow functions to return multiple values
    //it gives a variable address to write in
        //this variable is located or was created in the main
        //thus function now has the power to modify main variables, 
            //which are outside the scope of function

//when returning multiple values, the function declared is most likely a void?????
    //every example we did was a void declared function



    return 0;
}

void get2(string &first, string &second){


    cout<<"enter first and last name separated by blank \n";

    cin>>first;
    cin>>second;
}
void feet_to_meters(int ft, double in, int &meters, double &cm){
    double totali;
    double totalc;

    totali=in+12*ft;
    totalc=totali*2.54;

    meters=totalc/100;  //since meters is int, no decimals will be carried
    cm=totalc-(100*meters); //subtract off what is already counted in meters to get remaining cm that is in the units of meters but are in decimal format
    //thus, all decimals are accounted into the cm variable

}



void in24(int &h, int &m){
    cout<<"Enter h and m separated by space in 24 format ";
    cin>>h>>m;
}


void cvrt(int h24, int m24, int &h12, int &m12, char &ampm){
    m12=m24;
    if (h24>12){
        h12=h24-12;
        ampm='P';
    }
    else if (h24==12){
        h12=h24;
        ampm='P';
    }
    else{
        h12=h24;
        ampm='A';
    }
    
}


void prt(int h, int m, char ampm){
    cout<<h<<":"<<m<<ampm<<"M";
}