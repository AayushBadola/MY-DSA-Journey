#include <iostream>
#include<cmath>
using namespace std;

// refer print_division 
// this method is optimiztion of print_division 
//for 36 -> we get 1 X 36, 2 X 18, 3 X 12 , 4X9, 6X 6, 9X4 , 12X3, 18X2 , 36 X 1
// after root n times that is root 36 number repeat iself so we do root n inside loop 

int main(void){
    int user;
    cout<<"Enter number to print factors: ";
    cin>>user;
    cout<<endl;

    for(int factor = 1; factor<=sqrt(user);factor++){
        if(user%factor == 0){cout<<factor<<endl;}
    }

    return 0;
}