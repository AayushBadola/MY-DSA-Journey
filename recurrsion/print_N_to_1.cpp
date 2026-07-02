#include <iostream>
using namespace std;

void print_n_to_1(int num){
    if(num<1){return;}
    cout<<num<<endl;
    print_n_to_1(num - 1);

}

int main(void){
    int user_input;
    cout<<"Enteer number from where we want to print till 1 : ";
    cin>>user_input;
    cout<<endl;

    print_n_to_1(user_input);
}