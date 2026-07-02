#include <iostream>
#include <climits>

using namespace std;

// for any array say [1|2|1|4|2] we have to find how many times each number appears
// we can create an array where we store how many times a number appears based on the index
// for index 1 we store 2 as 1 appears 2 times 
// similarly for 2 we store 2 as it appears 2 times
// agian for 3 we store 0
// for 4 we store 1 since it appears ONCE


// helping funtions

// finding max value in array
int array_max(int arr[], int len){
    
    int max_val = INT_MIN;
    for(int indx = 0; indx<len; indx++){
        if (max_val<arr[indx]){max_val = arr[indx];}
        
    }

    return max_val;
}   

int main(void){
    int original_len;
    cout<<"Enter length of Array: ";
    cin>>original_len;

    // orginal array with actual values
    int Original_Array[original_len];
    cout<<"Populate the ARRAY: "<<endl;


    // adding values to actual array;
    for(int indx = 0; indx<original_len; indx++){
        cout<<"Enter Value "<<indx+1<<" : ";
        cin>>Original_Array[indx];
        cout<<endl;
    }

    // create a hash array containing only 0 values 
    // and as we get a value say 1 we add 1 to index 1 
    // if we get 2 we add value 1 to index 2
    // if we get 1 agian we add 1 to index 1 giving us the stored value as 2

    // hash array's length will be the max value inside original array + 1
    int hash_array_len = array_max(Original_Array, original_len) + 1;
    int hash_array[hash_array_len] = {0};

    // populating has array with frequency 
    // for every hash INDEX = value in original ARRAY 
    // frequney + 1

    for (int indx = 0; indx<original_len;indx++){
        hash_array[Original_Array[indx]] += 1;
    }

    // fetching the result
    int user_number;
    cout<<"Enter the number to find the frequency in Array: ";
    cin>>user_number;
    cout<<endl;

    cout<<"Number "<<user_number<<" appears "<<hash_array[user_number]<<" times"<<endl;

}



