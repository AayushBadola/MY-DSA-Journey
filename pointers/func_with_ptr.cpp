#include <iostream>
using namespace std;

// a function takes in the argument then creates its own copy of it and then does the operations on THAT 
// copy not the actual value 
// so in the end what we are doing it updating a copy of num in function but the actual num stored in memory
// it remains unchanged 

void update_val(int num){
    num++;
}

// for the actual updation we will pass the actual address of num (using the &num) so we are actually
// pointing at the memory which holds the value num

void update_actual_val(int &num){
    num--;
}

int main(void){
    int original = 10;
    cout<<"Original value in main: "<<original<<endl;

    // updating value 
    update_val(original);

    cout<<"Value after updation for pass by value(function updates a copy): "<<original<<endl;

    update_actual_val(original);// we are passing a refrence to the value so function know what value to update
    // basically function will update the VALUE not create the copy 

    cout<<"Value after updation for pass by refrence: "<<original<<endl;

    
    return 0;
}