#include <iostream>
#include <random>
using namespace std;

// SELECTION SORT
//
// Idea:
// Divide array into 2 parts:
//
// Sorted Part | Unsorted Part
//
// Every iteration:
// 1. Find minimum element in unsorted part.
// 2. Swap it with first element of unsorted part.
//
// Example:
//
// [13|46|14|52|20|9]
//
// Minimum = 9
// Swap 9 and 13
//
// [9|46|14|52|20|13]
//
// Sorted part : [9]
// Unsorted part : [46|14|52|20|13]
//
// Repeat the process until entire array is sorted.

void selection_sort(int arr[], int arr_len){

    // after ith iteration,
    // first i elements are sorted

    for(int indx = 0; indx < arr_len - 1; indx++){

        // assume current index has minimum value
        int minimum_val_of_indx = indx;

        // search for actual minimum
        // in unsorted part
        for(int indx2 = indx + 1; indx2 < arr_len; indx2++){

            if(arr[indx2] < arr[minimum_val_of_indx]){
                minimum_val_of_indx = indx2;
            }
        }

        // put minimum element at correct position
        swap(arr[minimum_val_of_indx], arr[indx]);
    }
}

int main(void){

    int arr[5];

    // generate random values from 0 -> 99
    for(int indx = 0; indx < 5; indx++){
        arr[indx] = rand() % 100;
    }

    cout << "Array BEFORE SORTING:\n";
    for(int indx = 0; indx < 5; indx++){
        cout << arr[indx] << " ";
    }

    selection_sort(arr, 5);

    cout << "\n\nArray AFTER SORTING:\n";
    for(int indx = 0; indx < 5; indx++){
        cout << arr[indx] << " ";
    }

    return 0;
}

/*
Time Complexity:

Best Case    : O(n²)
Average Case : O(n²)
Worst Case   : O(n²)

Reason:
Selection sort always performs
(n-1) + (n-2) + ... + 1 comparisons,
even if array is already sorted.

Space Complexity:

O(1)

Properties:

✔ In-place sorting algorithm
✘ Not stable (by default)
✘ Does not adapt to sorted arrays
*/