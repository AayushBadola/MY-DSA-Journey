#include <iostream>
#include <map>
using namespace std;

// MAP HASHING
// key   -> number
// value -> frequency of number
//
// example:
// 1 3 1 5 1
//
// map stores:
// 1 -> 3
// 3 -> 1
// 5 -> 1

int main(void){

    int array_len;
    cout<<"Enter how many numbers we have to store: ";
    cin>>array_len;
    cout<<endl;

    // create array and take input
    int array[array_len];

    cout<<"Populate the array :) ";
    cout<<endl;

    for(int indx = 0; indx < array_len; indx++){
        cout<<"Enter value "<<indx+1<<" : ";
        cin>>array[indx];
        cout<<endl;
    }

    // frequency store
    // key   -> number
    // value -> frequency
    map<int,int> frequency_store;

    // store frequencies
    // if key does not exist
    // map creates it with value 0
    // then increments it
    for(int indx = 0; indx < array_len; indx++){
        frequency_store[array[indx]]++;
    }

    // ask user which frequency to fetch
    int user_val;
    cout<<"Enter value to find the frequency: ";
    cin>>user_val;
    cout<<endl;

    // lookup frequency
    cout<<"Frequency of "<<user_val
        <<" is : "<<frequency_store[user_val];

    return 0;
}

/*
Time Complexity

Building Map : O(n log n)
Query        : O(log n)

Space Complexity

O(k)

k = number of unique elements

Why Map?

- No need to know range beforehand
- Works with large numbers
- Works with negative numbers

Example:

1000000
-500
999999999

Array hashing becomes difficult
Map handles it naturally
*/