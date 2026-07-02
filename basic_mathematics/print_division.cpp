// for any number there is a number that divides that number such that remainder is 0
// so for 10 -> 1,2,5,10 
#include <iostream>
using namespace std;
int main(void){
    int user;
    cout<< "Enter number to find numbers that divide it : ";   
    cin>>user;
    cout<<endl;

    for(int num = 1; num<=user; num++){
        if(user%num == 0){cout<<num<<endl;}
    }
    return 0;
}