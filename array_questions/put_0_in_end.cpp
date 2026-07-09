#include <iostream>
using namespace std;

// in an unsorted array [1|0|2|3|2|0|9|0|3]
// without chaning the relative order of non zero number we put 0s to the end
// [1,2,3,2,9,3,0,0,0]


// ########### BRUTE FORCE #############
// for the array [1|0|2|3|2|0|9|0|3]
// we can create a temp array where as we iterate the original we store the non zero in temp 
// after storing values in temp we now iterate the original adn temp and put the non zero back
// to every index from 0-> how many values are store in array 

// if original is [1|0|2|3|2|0|9|0|3]
// we store [1,2,3,2,9,3] and iterate it such that we store these values in original 

//  FROM TEMP       REMAINING IN ORIGINAL AFTER REPLACING 0->5 INDEX WITH TEMP VALUES
// [1|2|3|2|9|3]            [9|0|3]
// now we just need to iterate from the value 9(in second part) -> end and replace with them 0

void zero_to_end_brute(int arr[], int size){
    int temp[size];
    // storing non zero values in temp with the same reative order
    int temp_indx = 0;
    for(int indx = 0; indx<size; indx++){
        if(arr[indx] != 0){
            temp[temp_indx] = arr[indx];
            temp_indx++;
        }
    }

    // replacing the original elemnts with non zero ones 
    
    for(int indx= 0; indx<temp_indx;indx++){
        arr[indx] = temp[indx];
    }

    // putting the last elemnts as 0 (which are not overwritten by temp)
    for(int indx = temp_indx; indx<size;indx++){
        arr[indx] =  0;
    }
}

// #################### OPTIMAL SOLUTION ######################

// main idea is while we are iterating in array we will move the elements 
// so we dont have to have a space of O(n) 
// we need to t update the original array without any new array or space to be taken


// we can take 2 POINTERS one pointer on non zero and one on zero 
// and as we go we keep swapping he 0 with non zero 
// at the end the 0 will be at the end 

// EXMAPLE 
// [1|2|0|3|0|2|9]
//      | |
//     p1 p2 

// p1 will always we at a 0 
// is p2 a non zero ? -> swap p1 and p2 values

// [1|2|3|0|0|2|9]
//      | |
//     p1 p2
// AFTER SWAP INCREASE POINTER P2 and p1 takes the former place of p2

// [1|2|3|0|0|2|9]
//        | | 
//       p1 p2     is p2 non zero ? -> NO -> increase p2 

// [1|2|3|0|0|2|9]
//        |   |
//       p1   p2   is p2 non zero ? -> YES -> SWAP 

// [1|2|3|2|0|0|9]
//        |   |
//        p1  p2     AFTER SWAP we increase p2 and p1 takes the former place of p2

// [1|2|3|2|0|0|9]
//            | |
//           p1 p2    is p2 non zero ? -> SWAP -> increase p2 -> out of bounds -> STOP 

// we got our result [1|2|3|2|9|0|0]


// helper function to find 1st occurance of 0
int first_occurance(int arr[], int size, int num){
    for(int indx = 0; indx<size;indx++){
        if(arr[indx] == num){return indx;}
    }

    return -1;
}

void zero_to_end_best(int arr[], int size){
    int point1 = first_occurance(arr,size,0); // initiate pointer which will stay at values 0
    if(point1 == -1){return;}
    int point2 = point1 + 1; // initiate non zero pointer
    while(point2 <size){
        
        // check if point 2 is non zero 
        if(arr[point2] != 0){
            swap(arr[point1], arr[point2]); // swap non zero with 0
            point1++; // take teh first occurance of 0 in new arr
            point2++;
        }
        else if(arr[point2] == 0){
            point2++;
        }

        

    }
}

// ################ MAIN FUNCTION #################

int main(void){
    int arr[9] = {1,0,2,3,2,0,9,0,3};
    int arr_2[9] = {1,0,2,3,2,0,9,0,3};

    cout<<"Array BEFORE moving 0 to end: ";
    for(int indx = 0 ;indx<9;indx++){
        cout<<arr[indx]<<" ";
    }
    cout<<endl;

    zero_to_end_brute(arr,9);
    cout<<"Array AFTER moving 0 to end: ";
    for(int indx = 0 ;indx<9;indx++){
        cout<<arr[indx]<<" ";
    }
    cout<<endl;


    // pushing 0 to end using best approach 

    cout<<"Array BEFORE moving 0 to end: ";
    for(int indx = 0 ;indx<9;indx++){
        cout<<arr_2[indx]<<" ";
    }
    cout<<endl;

    zero_to_end_best(arr_2,9);
    cout<<"Array AFTER moving 0 to end: ";
    for(int indx = 0 ;indx<9;indx++){
        cout<<arr_2[indx]<<" ";
    }
    cout<<endl;
}
