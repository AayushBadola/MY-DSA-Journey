#include <iostream>
using namespace std;

void print_1_to_n(int num, int initial){
    
    if(initial>num){return;}
    cout<<initial<<endl;
    print_1_to_n(num, initial+1);
}

int main(void){
    int user;
    cout<<"Enter the number till where we want to print: ";
    cin>>user;
    cout<<endl;

    print_1_to_n(user,1);
}