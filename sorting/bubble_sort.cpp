#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// BUBBLE SORT
//
// Idea:
// Compare adjacent elements.
// If left element > right element,
// swap them.
//
// In one complete pass,
// the largest element "bubbles"
// to the end of the array.
//
// Example:
//
// [9|11|5|12|7]
//
// Pass 1:
//
// 9,11  -> no swap
// 11,5  -> swap
// 11,12 -> no swap
// 12,7  -> swap
//
// Result:
// [9|5|11|7|12]
//
// Notice:
// 12 reached its correct position.
//
// Therefore in next pass,
// we do not need to check the last element again.

void bubble_sort(int arr[], int len){

    // after ith iteration,
    // last i elements are sorted
    bool swapped = false;
    for(int indx1 = 0; indx1 < len - 1; indx1++){

        // compare adjacent elements
        for(int indx2 = 0;indx2 < len - indx1 - 1;indx2++){
            swapped = false;
            if(arr[indx2] > arr[indx2 + 1]){
                swap(arr[indx2],arr[indx2 + 1]);
                swapped = true;
            }

        }
        if(!swapped){return;}
    }
}

int main(void){

    // rand() generates pseudo-random numbers
    // srand(seed) changes the starting seed
    // time(NULL) gives current time in seconds
    // therefore every run gets different numbers

    srand(time(NULL));

    int arr[5];

    // generate values from 0 -> 99
    for(int indx = 0; indx < 5; indx++){
        arr[indx] = rand() % 100;
    }

    cout << "Array BEFORE SORTING:\n";
    for(int indx = 0; indx < 5; indx++){
        cout << arr[indx] << " ";
    }

    bubble_sort(arr, 5);

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

Space Complexity:

O(1)

Properties:

✔ In-place sorting algorithm
✔ Stable sorting algorithm
✔ Largest element reaches correct
  position after every pass.

Optimization:

If no swap occurs in a pass,
array is already sorted and
we can stop early.

Then:

Best Case : O(n)
*/