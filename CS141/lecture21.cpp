//phonebook development (review essentially for exam)
//and lecture 22


/* Prof. Documentation: (spring 2021)
Design decisions: 
-Data for one phone entry is stored in a class, Phone_entry
-Data for the entire phone book is stored in a vector, held within main
-User interface will be by menu (switch)
-Menu options will include add; edit; find; delete; print; sort
-The phonebook will be stored in a file "phone.txt" and will be automatically read when the program starts, and written when it teminated normally

*/




#include <iostream>
#include <vector>         //we are using vectors
#include <fstream>    //will need to open and close and read and write files
#include <iomanip>  //this is for the setw()
using namespace std;

class Phone_entry{
private:
    string lname;
    string fname;
    int number;

    //there can be private functions that member functions only can use

public:
    //accessors
    void print_one() const; //dont change the values of the member variables
    
    void write_one(ofstream &) const;

    bool match(string);
    

    //constructors
    Phone_entry(string, string, int);
    Phone_entry(); //need to have a default if not putting in variable values immediately at instance declaring

    //modifers / mutators
    void new_number(int); //we are not destroying the purpose of private data, we have more control


    //friends
    bool friend operator < (Phone_entry, Phone_entry);
};

bool operator < (Phone_entry p1, Phone_entry p2){ //dont need to say friend again
    return (p1.lname<p2.lname); 
    //they did make a friend operator in the string class, wtf


    //string is a class, lname is an object of the type of class 
    // (alphabetical order)


}

void Phone_entry::new_number(int n){
    number=n;
}

bool Phone_entry::match(string ln){
    if(ln==lname){
        return true;
    }
    else return false;
}




Phone_entry::Phone_entry(){  //cant be const because the whole point is to change or set values
    lname="uninitialized";
    fname="dont use";
    number= -1;
}


Phone_entry::Phone_entry(string l, string f, int n){

    lname = l;
    fname = f;
    number = n;

    //no return because no type, not even a void
}


void Phone_entry::print_one() const{ //we are inside the class because ::

    cout<<left<<setw(20)<<lname<<left<<setw(20)<<fname<<setw(8)<<number;

}

void Phone_entry::write_one(ofstream &of) const{ //we are inside the class because ::

    of<<left<<setw(20)<<lname<<left<<setw(20)<<fname<<setw(8)<<number;

}





















void read_book(vector<Phone_entry> &b);  

void add_entry(vector<Phone_entry> &book);

void print_book(const vector<Phone_entry> &book);
void write_book(const vector<Phone_entry> &book);



int get_entry(vector<Phone_entry> &b);

void lookup_entry(vector<Phone_entry> &b);

void edit_entry(vector<Phone_entry> &b);

void sort_book(vector<Phone_entry> &b);


int main (){

/*
-study up on for final-------
-functions
-files

-not going to ask all the set flags in ios, you know, heavy details, on the exam
-more like what is the difference between a ref parameter and a value parameter 





-top-down design vs bottom-up 


-Last name 
-First name
(address)
-phone numbers (4 digits)
cell number (10 digits) (too big for an int probably)
PO box
Dorm

functions----------
-search + retrieve
-add
-delete
-sort
-edit (faster than deleting and adding over and over)
-print
-check for duplicates



user interface-------------- (switch)
-menu
            -cs242 has a lot of user interface and point and click stuff in java lol
    
*/

    vector <Phone_entry> book;  

    char response;
    
    read_book(book); //read the book in at startup

    while (true){
        cout<<"A E F D L P S X or H for help \n";
        cin>>response;
        response = toupper(response);
        switch (response)
        {
        case 'A':
            add_entry(book);
            break;
        case 'E':
            edit_entry(book);
            break;
        case 'L':
            lookup_entry(book);
            break;
        case 'P':
            print_book(book);
            break;
        case 'S':
            sort_book(book);
            break;
        case 'X':
            write_book(book);
            //print_book(book);
            return(0);
        default:
            cout<<"Options are: Add, Edit, Find, Delete, Lookup, Print, Sort, eXit, or Help\n";
        }
    }
    print_book(book);

//all of this under me is not running because of switch statment and infinite while loop 
/*  btw, teacher deleted all this under me in the beginning of lecture, thats why



    Phone_entry p1; 
    Phone_entry p("Security","Campus",6666); //create an instance of the class and put variables in the object immediately, thats the benefit of constructors
 
 
   // p.lname="Security";
   // p.fname="Campus";
 //   p.number=6666;



    book.push_back(p);
    book.push_back(p1);
    
    print_book(book);
*/

    return 0;
}


void sort_book(vector<Phone_entry> &b){ 
    int top;
    int i;
    Phone_entry temp;

    int count=b.size();

    top=0;

    while(top<count){
        for (i=count-1;i>top;i--){
            if(b[i-1]<b[i]){      //we need a friend
                temp=b[i];
                b[i]=b[i-1];
                b[i-1]=temp;
            }
        }
        top++;
    }
}




void edit_entry(vector<Phone_entry> &b){
    int i = get_entry(b);
    int num;

    if(i>-1){
        cout<<"New number ";
        cin>>num;
        b[i].new_number(num);
    }
}



void lookup_entry(vector<Phone_entry> &b){
    int i;
    i = get_entry(b);
    if (i>-1){
        b[i].print_one();
        cout<<endl;
    }
}







int get_entry(vector<Phone_entry> &b){
    string ln;
    cout<<"Last Name ";
    cin>>ln;
    for(int i=0;i<b.size();i++){
        if (b[i].match(ln)) //invoke the member function match and pass ln
        return i;
    }
    cout<<"No match for "<<ln<<endl;
    return -1;
}









void write_book(const vector<Phone_entry> &book){
    
    ofstream ostr;
    ostr.open("phone.txt");




    for (int i=0; i<book.size(); i++){   //we have created a driver
        book[i].write_one(ostr); //invoke the write one
        ostr<<endl;
    }
    ostr.close();
}




void print_book(const vector<Phone_entry> &book){

//cout.width()
    cout<<setw(20)<<left<<"Last"<<setw(20)<<left<<"First"<<setw(8)<<"Numbers"<<endl;
    cout<<"***************************************************************************"<<endl;


    for (int i=0; i<book.size(); i++){   //we have created a driver
        book[i].print_one(); //invoke the print one
        cout<<endl;
    }

}





void read_book(vector<Phone_entry> &b){ //will need to add stuff to the vector

    ifstream instr;

    string l,f;
    int n;


    instr.open("phone.txt");
    bool cont=true;
    while(cont){
        instr>>l>>f>>n;
        if (instr.eof()){
            cont=false;
        }
        else{
            Phone_entry e(l,f,n);  //the purpose of and the POWER of a constructor
            b.push_back(e);
        }
    }

    instr.close();

}  

void add_entry(vector<Phone_entry> &book){
    string l,f;
    int n;
    cout<<"Enter last name, first name, number ";
    cin>>l>>f>>n; 
    Phone_entry e(l,f,n);  //take those variables and this will create a new object of type phone_entry, new object will be named "e", will have the appropriate values of l,f,n
    book.push_back(e);


}

