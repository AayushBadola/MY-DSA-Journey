#include <iostream>
using namespace std;

void print_n_times(int user){
    // calling the fucntion itself just n-1 times
    if(user <= 0){return;}
    cout<<"Hello"<<endl;
    print_n_times(user - 1);
}

int main(void){
    // print hello -1 times
    print_n_times(-1);
}