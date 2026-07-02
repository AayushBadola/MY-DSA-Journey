#include <iostream>
using namespace std;

void extract_digit(int user){
    if (user==0){cout<<0;}
    else{
        while(user > 0){
            int digit = user%10; // from 1234 it give 1234%10 = 4
            user /= 10; // now digit becomes 1234/10 = 123.4 = 123
            cout<<digit;// now display 4 and loop continues as user now becomes 123
            cout<<endl;
        }

    }
}

int main(void){
    int user_input;
    cout<<"Enter number to extract digit: ";
    cin>>user_input;
    cout<<endl;
    extract_digit(user_input);
    return 0;
}