#include <iostream>
using namespace std;

// for any array for example [1,2,3,4,5,6]
// we need to do              | | swap
// [2,1,3,4,5,6]
//      | | swap

// [2,1,4,3,5,6]
//          | | swap 

// [2,1,4,3,6,5] FINAL ARRAY 

// to do that we need a loop where the pointer will skip 2 index 
// [1,2,3,4,5,6]
//  | index 1 swap with 2 (i = 0)


// [1,2,3,4,5,6]
//      | index 3 swap with 4 (i = 2)

void swap_alternate(int nums[], int size){
    
    for(int indx = 0; indx<size; indx += 2){
        swap(nums[indx], nums[indx+1]);
    } 

}

int main(void){
    int control_array[6] = {1,2,3,4,5,6};
    cout<<"Original array: "<<endl;
    for(auto val : control_array){
        cout<<val<<" ";
    }
    cout<<endl;

    swap_alternate(control_array, 6);
    
    cout<<"swapped array: "<<endl;
    for(auto val : control_array){
        cout<<val<<" ";
    }

}




