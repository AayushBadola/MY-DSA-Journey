#include <iostream>
using namespace std;

int main(void){
    // for any pointer we are storing the memory address where the data is stored
    // we can also create a pointer which stores the memory address of the pointer which stores the memory address of the data 

    // in visualization its 
    /*

    [pointer main address] ------> [Value memory address ]------>[actual data]
        pointer to main            (main): pointer to data          data

    */

    int value = 12;
    int *main_pointer = &value;
    int **pointer = &main_pointer;
    
    cout<<"address of Value: "<<&value<<endl;
    cout<<"Value stored in main pointer: "<<main_pointer<<endl;
    cout<<"Address of main_pointer: "<<&main_pointer<<endl;
    cout<<"Value stored in pointer: "<<pointer;
}