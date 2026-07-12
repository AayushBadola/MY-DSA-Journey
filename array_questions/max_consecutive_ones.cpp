// for any array = [1|1|0|1|1|1|0|1|1]
// we can see             | | |    3 consecutive 1s so max ones is 3 

// we can do this count = 0 
// if we reach 1 we increase count and increase and the moment we reach a 0 we change the counter to 0 
// and just before reaching 0 we take the count and replace it to a new variable called max_1s 
// this is to store the maximum number of 1st counted other wise for 1|1|1|0 when we count 3 it gets back to 0

#include <iostream>
using namespace std;

int consecutive_1s(int arr[], int size){
    int count = 0;
    int max_count = 0;

    for(int indx = 0;indx<size;indx++){
        if(arr[indx] == 1){
            count++;
        }
        else if(arr[indx] != 1){
            count = 0;
        }
        if(max_count<count){
            max_count = count;
        }
    }
    return max_count;
}

int main(void){
    // for testing this method we will use 2 array
    // array1 will be the one we assumed above 
    // and array2 will be a mixed array containing 1->9
    int arr1[9] = {1,1,0,1,1,1,0,1,1};
    int arr2[9] = {1,0,4,1,4,5,1,1,6};

    cout<<"For Array 1 : ";
    for(auto val: arr1){
        cout<<val<<" " ;  
    }
    cout<<endl;
    int consec_1s_arr1 = consecutive_1s(arr1,9);
    cout<<"Consecutive 1s in array 1: "<<consec_1s_arr1<<endl;

    cout<<"For Array 2 : ";
    for(auto val : arr2){
        cout<<val<<" ";
    }
    cout<<endl;

    int consec_1s_arr2 = consecutive_1s(arr2,9);
    cout<<"Consecutive 1s in array2 : "<<consec_1s_arr2<<endl;

}