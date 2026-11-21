#include <iostream>
using namespace std;

// a pointer is a virtual point/ arrow which "points" to the memory address of the value or data structure
/*

example :

x = 10{for example stored in address 110}

cout<<x 

x goes to 110 sees the value is 10 and retrurns it to cout that is prints the value at address 110

basically when we write x = 10 , 10 gets added / stored in memory space 110 
now x gets mapped to 110 address and everytime we call x it retrieves the value stored in 110 that is "10"


*/

int main(void){

    int num = 10; // we have declared a variable and that variable is num which points toward the address where "10" is stored

    // to actually retrive the address where the value is stored we need to use "&"

    cout<<"Printing the VALUE of num: "<<num<<endl;

    cout<<"Printing ADDRESS , num is pointing to: "<<&num<<endl;

    // the given address is "0x790fbff6fc" which is hexa decimal

    // a pointer a variable which STORES the address 
    //to create a pointer we need to use "*" for it 

    /*
    so if we say int *pointer = &num what basically happens is 
    the actual pointer variable is stored at different memory address and it holds teh value as "address of num"

    if we go towards that pointeror access it, it redirects us to that memory block (num)
    and then we can access the value of num 

    NEVER DECLARE A POINTER WITHOUT A VALUE AS IT MAY POINT TO AN UNKNOWN MEMORY OUTSIDE SCOPE OF OUR PROGRAM
    
    */

    cout<<"original value of num: "<<num<<endl;
    int *ptr = &num;
    // updating value via pointer
    *ptr = 100;
    cout<<"Seeing num after updating by pointer: "<<num<<endl;

    // to know what value address the pointer holds (not the address which holds the pointer)
    // we need to just use *p

    cout<<"Address which HOLD THE POINTER: "<<&ptr<<endl;
    cout<<"Address which POINTER HOLDS (address of num): "<<ptr<<endl;
    cout<<"Value of num: "<<num<<endl;
    cout<<"Value of num pointed by pointer: "<<ptr<<endl;

    return 0;

}