// an array doing [1|2|3|4] -> [4|3|2|1]
// we take 2 index, 1st and last swap with each other and tehn move the index 1 to 2 
// also move index last to last - 1 and sawp those 
// 1,4 -> 4,1
// 2,3 -> 3,2 
// end array becomes [4|3|2|1]
// if both index point lands of a single index say for 1,2,3,4,5 both index land of 3 we terminate
#include <iostream>
using namespace std;

void reversal(int initial, int arr[], int final){
    if(initial >= final/2){  return; }// stop when left pointer reaches the middle
                                        // because all required swaps have already happened
    else {
        swap(arr[initial], arr[final - initial - 1]); // swapping happens
        reversal(initial + 1, arr, final); // we go to the next index from left side
                                            // we dont change right since its calculate in swap everytime
    }
}

int main(void){
    
     
    int len;
    cout<<"Enter len for array: ";
    cin>>len;
    cout<<endl;

    int user_input[len];
    
    // taking user input
    for(int indx = 0;indx < len; indx++){
        cout<<"Enter Value "<<indx + 1;
        cin>>user_input[indx];
        cout<<endl;
    }
    
    cout<<"Original Array: [ ";
    // printing original array
    for(int indx = 0; indx < len; indx++){
        cout<<user_input[indx]<<" ";
    }
    cout<<"]";
    // calling the funciton to reverse the array
    reversal(0, user_input, len);

    // prining the reversed array
    cout<<"Reversed Array: [ ";
    for(int indx = 0; indx < len; indx++){
        cout<<user_input[indx]<<" ";
    }
    cout<<"]";


}