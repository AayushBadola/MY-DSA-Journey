// for K largest element we need to first sort and array and we can just go backward till
// we get a number which is NOT equal to arr[last element ]
// say we do merge sort we have a complexity of O(nlogn)

// we do sort array -> do arr[size - 2] we start from there 
// and if its not equal to largest we return and if it IS  then we go left till it isnt 

// that is brute force method
// there is a better method where we find it using best largest element appraoch and then
// we find the second largest with similar concept and if the number is large and less than largest 
// we store it 

#include <iostream>
using namespace std;

int largest_val(int arr[] , int size){ // copied from largest_in_array
    if(size<1){return -1;}
    int largest = INT_MIN;
    for(int indx = 0; indx < size; indx++){
        if(largest < arr[indx]){largest = arr[indx];}
    }

    return largest ;
}

int second_largest_better(int arr[], int size){
    int largest = largest_val(arr, size);
    int second_largest = INT_MIN + 1;
    for(int indx = 0; indx<size; indx++){
        if(second_largest<arr[indx] && arr[indx] < largest){
            second_largest = arr[indx];
        }
    }

    return second_largest;
}

// BEST APPROACH FOR 2ND LARGEST AND K LARGEST NUMBER IN ARRAY
int second_largest_best(int arr[], int size, int kth){
    int large_2;
    for(int indx = 0; indx<kth;indx++){
        int max_val_indx = indx;
        for(int indx2 = indx + 1; indx2< size; indx2++){
            if(arr[indx2] > arr[max_val_indx]){max_val_indx = indx2;large_2 = arr[max_val_indx];}
        }
    }

    return large_2;
    
}

int main(void){
    int arr[10] = {5,10,22,1,4,0,88}; // second largest is 22
    int second_large = second_largest_better(arr,10);
    int second_largest = second_largest_best(arr,10,2);
    cout<<second_large;
    cout<<second_largest;

}
