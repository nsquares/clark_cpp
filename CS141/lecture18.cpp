//design and implement 2: grocery store inventory

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Record{ //good practice to cap the first letter for all structs

    string name;
    double cost;
    int markup;
    int count[3]; //should use a constant here
};

const string places[3]={"counter", "shelf", "warehouse"};


bool read_file(vector<Record> &v);
void placement(vector<Record> &v); //should be a pointer instead of ref because do not want to change values here but prof did not teach pointers yet?

int main(){
/*

./lect18 | more

//how to go through infinite loops while executing








-code homework 3:
-yea, you are suppose to setwidth on the numbers, then you can use the right-justified ios::right, figured that boi out lol

-software design class:
    -how many total apples?
    -how many items on the counter?
    -what am I going to run out of?

-need to know if the file is read correctly
-menu of options (switch statements)

-create a struct which is a record:
    -name
    -cost
    -markup
    -count[3] //three places that the product can be

-vector<Record> //make a vector of structs

fucntions: (I wish this guy made general functions instead of one for every damn switch statement)
-read func
-print func
-maybe a search func?

*/

    vector<Record> invent; //inventory
    char choice;

    if (read_file(invent) == false){
        return 1;
    }
    
    cout<<"You have "<<invent.size()<<endl;

    while(true){ 
        
        cout<<"(P)lacement e(x)it: ";
        cin>>choice;
        
        switch(choice){
            case 'P':
            case 'p':
                placement(invent);
                break;
            case 'X':
            case 'x':
                return (0);
                break;      //place this for good practice
            default:
                cout<<choice<<" is not a choice\n";


        }
    }

    

    return 0; //this is not really needed because of the infinite loop above but it stays for good practice
}

bool read_file(vector<Record> &v){

    Record r;
    ifstream infile;

    infile.open("inventory.txt");

    if (infile.fail()){
        cout<<"Cannot open file\n";
        return (false);
    }

    //error message here to check if you can even open the text file or not

    while (true){
    getline(infile, r.name);
    cout<<r.name<<endl;
    if (r.name=="END"){
        infile.close();
        return (true);
    }
    else{
        infile>>r.cost>>r.markup;
        for(int i=0; i<3; i++){
            infile>>r.count[i];
        }
        infile.get(); //forgot this '\n' eater
        v.push_back(r);
    }

    }
    return(true);


}

void placement(vector<Record> &v){

    int which = -1;
    string input;



    cout<<"Which? ";
    cin>>input;                //also, need to handle if the user does not input something that exists
    for (int i=0; i<3; i++){
        if(input.substr(0,3) == places[i].substr(0,3)) which =i;
    }

    if (which == -1) {
        cout<<"No match\n";
        return;
    }


    cout.setf(ios::left);
    cout.unsetf(ios::right);
    cout.width(30);
    cout<<"Item-";
    cout.setf(ios::right);
    cout.width(6);
    cout<<places[which]<<"\n";

    int j;
    for(j=0; j<v.size(); j++){
        
    cout.setf(ios::left);
    cout.unsetf(ios::right);
    cout.width(30);
    cout<<v[j].name;

    cout.setf(ios::right);
    cout.width(6);
    cout<<v[j].count[which]<<endl;
    }

}