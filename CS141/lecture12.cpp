//program design, review essentially of everything in the course at mid-term
//gradebook.cpp


#include <iostream>
#include <fstream>
using namespace std;

void build(); //write
void print(); //read
void update(); //read and write
void search(); //read with an if statement

int main(){

    char choice;

    cout<<"Welcome to gradebook. (b)uild, (p)rint, (u)pdate, (s)earch: ";
    cin>>choice;

    //string fname, lname;
    //int ID; //clarkson ID

    int totalTest;
    int totalHW; 
    int totalLab;

    switch(choice){
        case 'b':
            build();
            break;
        case 'p':
            print();
            break;
        case 'u':
            update();
            break;
        case 's':
            search();
            break;
        default:
            cout<<"invalid input\n";
    }


    //build, print, apend, search

    //one program and use menu (User Interface) (no loop)

    //program structure
    /*
    main - menu
    func - calculate average
    func - write one record
    func - read one record    
    */

    return 0;
}

void build()
{
    ofstream ostr; //write
    char filename[80];
    string fname,lname;
    int ID;
    char answer;

    cout<< "filename: ";
    cin>>filename;
    ostr.open(filename);

    do{
        cout<<"First and last names: ";
        cin>>fname>>lname;
        cout<<"ID: ";
        cin>>ID;

        ostr<<fname<<" "<<lname<<" "<<ID;
        ostr<<" 0 0 0\n";

        cout<<"'y' to continue ";
        cin>>answer;

    } while(answer=='y');

    ostr.close();
}

void print(){
    ifstream istr; // read
    char filename[80]; //cstring (array of char)
    string fname,lname;
    int ID;
    int test,hw,lab;

    cout<< "filename: ";
    cin>>filename;
    istr.open(filename);
    if (istr.fail()){
        cout<<"cant open "<<filename;
        return;
    }

    while(istr>>fname){  //could also use !istr.eof()
        istr>>lname>>ID>>test>>hw>>lab;
        cout<<fname<<" "<<lname<<" "<<ID<<" "<<test<<" "<<hw<<" "<<lab<<endl;
    }

    istr.close();
    return;
}


void update(){ //remember that you cannot read and write into the same file all at the same time

    ifstream istr; // read
    ofstream ostr; //write

    char filename[80]; //cstring (array of char)
    string fname,lname;
    int ID;
    int test,hw,lab;
    char choice;
    int score;

    cout<< "filename for input: "; //read from
    cin>>filename;
    istr.open(filename);
    if (istr.fail()){
        cout<<"cant open "<<filename;
        return;
    }

    cout<< "filename for update: ";   //write in
    cin>>filename;
    ostr.open(filename);
    if (ostr.fail()){
        cout<<"cant open "<<filename;
        return;
    }

    cout<<"What are you updating? h,l, or t: ";
    cin>>choice;


    while(istr>>fname){  //could also use !istr.eof()
        istr>>lname>>ID>>test>>hw>>lab;
        cout<<fname<<" "<<lname<<endl;
        cout<<"new score? ";
        cin>>score;
        switch(choice){
            case 'h':
                hw=score;
                break;
            case 'l':
                lab=score;
                break;
            case 't':
                test=score;
                break;
        }

        ostr<<fname<<" "<<lname<<" "<<ID<<" "<<test<<" "<<hw<<" "<<lab<<endl;
        cout<<fname<<" "<<lname<<" "<<ID<<" "<<test<<" "<<hw<<" "<<lab<<endl;
    }

    istr.close();
    ostr.close();
    return;


}


void search(){

    ifstream istr;
    char filename[80]; //cstring (array of char)
    string fname,lname;
    int ID;
    int test,hw,lab;

    int target;


    cout<< "filename: ";
    cin>>filename;
    



    
    istr.open(filename);
    if (istr.fail()){
        cout<<"cant open "<<filename;
        return;
    }


    cout<<"What ID? ";
    cin>>target;


    while(istr>>fname){  //could also use !istr.eof()
        istr>>lname>>ID>>test>>hw>>lab;
        if(ID==target){
            cout<<fname<<" "<<lname<<" "<<ID<<" "<<test<<" "<<hw<<" "<<lab<<endl;
        } 
    }

    istr.close();
    return;

}