//more arrays and 2d array
#include <iostream>
using namespace std;

int sumUp(int num[], int n);
//add up the numbers in the function

void doSort(int num[], int count); //passing an array is like using ref parameters like you can change the value of the elements without ref &
// you can also use ref parameters with passing arrays

int main(){

/*
-remember that in cpp, you can go outside the bounds of the array without any error thrown at you
-an element of an array can be a parameter to a function 

    example: 
        sqrt(value[i]);

-you can also use elements in arrays for ref parameters

-you can also pass the entire array as a parameter




-end of a cstring is a \0 so you look for that to end you cstring looping

-"sorting" means "ordering" in com sci

-you cannot return an array yet in this class but it is possible (you want to return a pointer)

-passing a 2d array to a function is weird and different





*/
/*
    //sentinel value
    int n[]={1,2,3,-1}; //if negative, then stop, another way to detect the end of the array instead of telling how many elements in array explictly
    int j[]={4,5,6,7,-99};
    cout<<"Total "<<sumUp(n,3)<<endl;
    cout<<"Total "<<sumUp(j,4)<<endl;
*/


/*
    int n[6]={15,99,-1,23,1500,0};
    doSort(n,6);

    for(int i=0; i<6;i++){
        cout<<n[i]<<endl;
    }
*/

    const int HOLES=18; //he wrote constants above main, idk why he always do that
    const int MAXP=4;
    string names[MAXP];

    int score[MAXP][HOLES];
    int pcount;
    int hcount;

    cout<<"how many players? ";
    cin>>pcount;

    cout<<"how many holes? ";
    cin>>hcount;

    cin.get();

    for(int i =0; i<pcount;i++){
        cout<<"Names of player "<<i+1<<": ";
        getline(cin, names[i]);
    }

    for(int h=0; h<hcount;h++){
        cout<<"On hole "<<h+1<<endl;
        for(int p=0; p<pcount;p++){
            cout<<"for player "<<names[p]<<" ";
            cin>>score[p][h];
        }
    }


    cout<<"Scores\n";
    for(int p=0;p<pcount;p++){
        cout<<names[p];
        int total=0;
        for(int h=0;h<hcount;h++){
            cout<<" "<<score[p][h];
            total+=score[p][h];

        }
        cout<<" total "<<total<<endl; 
    }




    return 0;
}


//function cannot know how large the array passed is because it reads memory from left to right of the array and can go out of index
int sumUp(int num[], int n){ //actually sending a pointer?

    int total=0;
    int i=0;
    while( num[i]>=0){

        total += num[i]; //you can also put i++ in here so you use i and then ++ right after use and then the next line of code can be deleted
        i++;
    }

    return total;

}

void doSort(int num[], int count){
    int top;
    int i;
    int temp;

    if(count<=1) return;
    top=0;

    while(top<count){
        for(i=count-1; i>top; i--){
            if(num[i-1]<num[i]){
                temp=num[i];
                num[i]=num[i-1];
                num[i-1]=temp;
            }
        }
        top++;
    }
    return;
}