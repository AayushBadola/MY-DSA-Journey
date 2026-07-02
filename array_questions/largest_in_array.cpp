#include <iostream>
#include <cmath>
using namespace std;

// fro largest element we can compare each element till we get the max element 
// so if we do (loop 1 for element to compare){ loop 2 for each other element }
// and if we get the highest value we can return it 

// O(N2) TIME VERY VERY BAD 
// int largest_val(int arr[], int size){
//     int largest = arr[0];
//     for(int indx1 = 0; indx1<size - 1; indx1++){
//         for(int indx2 = indx1 + 1; indx2<size;indx2++ ){
//             if(arr[indx1] < arr[indx2]){largest = arr[indx2];}
//         }
//     }
//     return largest;
// }

// we can do better if we compare the entire array with a single small number
// we can do this one small number -> if arr num is bigger store it in largest 
// till we reach teh array we would have sotred the largest number 

int largest_val(int arr[] , int size){
    if(size<1){return -1;}
    int largest = INT_MIN;
    for(int indx = 0; indx < size; indx++){
        if(largest < arr[indx]){largest = arr[indx];}
    }

    return largest ;
}
// only one pass is neded so O(N)

int main(void){
    int arr[5] = {5,8,10,2,1} ;// should be 10
    int largest = largest_val(arr, 5);
    cout<<largest;
}