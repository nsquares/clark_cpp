#include <iostream>
//using namespace std;

int main (){
    int temperature=464;
    int pressure=54646;

    if ( (temperature>=100) || (pressure>=200) ) {
        std::cout<<"Warning"<<std::endl;
    }
    else {
        std::cout<<"OK"<<std::endl;
    }



    return 0;
}