#include <iostream>
using namespace std;
/*
Reversing Number

digit = user % 10
extract last digit

reverse = reverse*10 + digit

multiply by 10 first
to make space for new digit

example:

43
↓
430
↓
432
*/

int num_reversal(int user){
    // num extraction + while looping 

    int reverse = 0;
    while(user>0){
        int digit = user%10;
        reverse = reverse * 10 + digit; 
        
        user /= 10;
        
        
        
    }
    return reverse;

}

int main(void){
    cout<<"Original : "<<1234<<endl;
    int reversal = num_reversal(1234);
    cout<<"Reverse: "<<reversal<<endl;
}