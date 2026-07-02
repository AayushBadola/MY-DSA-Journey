#include <iostream>
using namespace std;

// funciton to print name taking input as string
void print_name(string name, int times){
    if(times <= 0){return;}
    cout<<name<<endl;
    print_name(name, times - 1);
    
}

int main(void){
    string user_name;
    cout<<"Enter Your Name: ";
    cin>>user_name;
    cout<<endl;

    int repeat;
    cout<<"Enter how many times name to be repeated: ";
    cin>>repeat;
    cout<<endl;

    print_name(user_name, repeat);
    
}