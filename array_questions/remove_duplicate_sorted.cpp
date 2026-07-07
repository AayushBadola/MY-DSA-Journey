// for any given sorted array that contains some duplicate elements we need to modify it such that 
// it will only contain unique elemnts 

// [1|1|2|4|4|7|9|9] -> [1|2|4|7|9]

#include <iostream>
using namespace std;

// for brute force we can do a set data structure that only stores unique elements
// for inserting an element its logN since there are N elements its NlogN
// for(i<size){set.insert(arr[i])}

// ################# OPTIMAL APPROACH ##################
// for optimal approach we need to use 2 pointers
// here one pointer will be at start and another will be infront of the 1st 
// so the pointer 1 will see the element and pointer 2 sees that if the element is not queal to 1st
// dont change
// if its equal to 1st then move right and if that is not equal to first then update the value in position 2 
//to the value of unique element 
// [1|1|2|2|2|3|3|3] 
//  | |       it sees both are same so move to right 

// [1|2|2|2|2|3|3|3]
//  |   |     not same as 1st pointer so update position 2 to value 2 

// [1|2|2|2|2|3|3|3]  move pointer 1 ahead 
//    | |            same values move ahead pointer to right 

// [1|2|2|2|2|3|3|3] 
//    |   |         same again so move pointer

// [1|2|2|2|2|3|3|3] 
//    |       | not same so change value 3 to 3 
// [1|2|3|2|2|3|3|3]
//      |            | the pointer reached the end
// now the 1st 3 elements are unique so number of unique elements is 1st pointer position + 1
// 1st pointer position : 2
// totoal unique numbers : 2+1 = 3

void remove_duplicates(int arr[], int size){
    int indx1 = 0; // the 1st unique element is here 
    for(int indx2 = 1; indx2<size; indx2++){
        if(arr[indx1] != arr[indx2]){
            arr[indx1 + 1] = arr[indx2];
            indx1++;
        }    
    }
    for(int indx2 = indx1+1; indx2<size; indx2++){
        arr[indx2] = 0;
    }
    
}

int main(void){
    int arr[8] = {1,1,2,2,2,3,3,3};
    remove_duplicates(arr,8);
    cout<<"Number of unique elements are: ";
    for(int indx = 0; indx<8; indx++){
        cout<<arr[indx]<<" ";
    }
}

