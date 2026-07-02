#include <iostream>
using namespace std;

int count_digits(int user){
    int count = 0; // count is 0 initially 
    if(user<0){user *= -1;} //  if user gives negative we turn it into positive
    if(user == 0){return 1;} // if user provides 0 we give 1  
    
    else{
        // code of digit count 
        // as we count the digits we increment count 
        // the moment number = 0 we stop teh iteration and give out the count of digits
        while(user>0){
            int digit = user %10;
            count ++;
            user = user/10;
        }
        return count;
    }
}

int main(void){
    int user_input;
    cout<<"Enter the Number: ";
    cin>>user_input;
    cout<<endl;
    int result = count_digits(user_input); // calling the count digit function
    
    cout<<"Given number: "<<user_input<<endl;
    cout<<"Number of digits in number: "<<result<<endl;

    return 0;
}