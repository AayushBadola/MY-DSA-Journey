// armstrong number is when the individual digits of number are powered to number of digits and added 
// and if the sum is equal to the original number then its armstrong 
// EXAMPLE 371 -> (3^3) + (7^3) + (1^3) = 371 
// EXAMPLE 9474 -> (9^4) + (4^4) + (7^4) + (4^4) = 9474

#include <iostream>
#include <cmath>
using namespace std;

bool check_armstrong(int user){
    int copy_user = user;
    int copy_user2 = user;
    int sum = 0;
    if(user<0){return false;} // armstrong number are defined for positive or 0
    if(user == 0){return true;} // 0^3 = 0

    //count numebr of digits 
    int count = 0;
    while(copy_user2>0){
            count ++;
            copy_user2 = copy_user2/10;
        }
    

    while(user > 0){
        int digit = user % 10; // extract the digits
        sum = sum + pow(digit,count); // do digit1 ^3 + digit2 ^ 3 . . . .. . .
        user = user/10; // allows us know when all the digits are extracted
        
    }
    
    if (sum == copy_user){return true;} // checks if digit1 ^ 3 + digit2 ^ 3 ...... = original num
    else{return false;} // if not equal to original its not armstrong
}

int main(void){
    int user_input;
    cout<<"Enter Number to check if its armstrong number: ";
    cin>>user_input;
    cout<<endl;
    
    if(check_armstrong(user_input)){cout<<"Number is armstrong !"; return 0;}
    else {cout<<"Number is NOT armstrong"; return 0;}
}