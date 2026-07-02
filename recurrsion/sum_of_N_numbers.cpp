#include <iostream>
using namespace std;

void print_sum_N(int num, int sum){
    if(num<0){cout<<sum;return;}
    print_sum_N(num - 1, sum + num);
}

int main(void){
    int user;
    cout<<"Enter number to find sum from 0 -> N: ";
    cin>>user;
    cout<<endl;

    print_sum_N(user,0);
}
