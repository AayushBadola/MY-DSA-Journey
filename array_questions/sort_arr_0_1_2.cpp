#include <iostream>
using namespace std;


// ############################################### BRUTE FORCE ################################################

// for brute force just use any of the sorting algos 
// if we wanna go for brute - brute force then try using bubble sort 

// if we just need brute force try using the merge sort algo

// REFER TO -> sorting/merge_sort.cpp

// #################################################### BETTER APPROACH ############################################

// what we can do is in the array we coudn the number of 0, 
// number of 1 
// number of 2 
// and then we start over riding the values of our array based on the count values 

// say for array we do [0|1|2|0|1|2|1|2|0|0|0|1]
// number of 1 = 4
// number of 2 = 3
// number of 0 = 5

// we fill the first 5 numbers with 0
// [0|0|0|0|0|2|1|2|0|0|0|1]

// now after that we fill the next 4 number with 1s

// [0|0|0|0|0|1|1|1|1|0|0|1]

// now after that we fill the remaining 3 digits with 2 

// [0|0|0|0|0|1|1|1|1|2|2|2] voila the array is sorted 

//////////// HELPER FUNCTION 
int val_count(int arr[],int size, int target){
    
    int count = 0;
    
    for(int indx = 0; indx<size;indx++){
        if(arr[indx] == target){count++;}
    }
    return count;
}

void sort_0_1_2(int arr[], int size){
    int count_1 = val_count(arr,size,1);
    int count_2 = val_count(arr,size,2);
    int count_0 = val_count(arr,size,0);

    int indx = 0;
    while(count_0 >0){
        arr[indx] = 0;
        count_0--;
        indx++;
    }

    while(count_1>0){
        arr[indx] = 1;
        count_1--;
        indx++;
    }

    while(count_2>0){
        arr[indx] = 2;
        count_2--;
        indx++;
    }

    
}


// ##########################################33 BEST APPROACH ###################################################

//####### IT IS ALSO KNOWN AS DUTCH NATIONAL FLAG ALGORITHM 

// we need to first traverse the array as the pointer MID 
// as we go and reach each value be it 0,1,2 we put them in their correct locations that is 
// either we swap it with low (containing 0s)
// or with high -> containing 2s 
// the middle ground that is from mid-> high that is uncharted territory , the values which are unknown to us until mid goes and "sees" that value 

// so it becomes a dutch flag 

// [0 ........ low-1]      -> All 0s
// [low ...... mid-1]      -> All 1s
// [mid ...... high]       -> Unknown / Unprocessed
// [high+1 ... end]        -> All 2s

// |----0s----|----1s----|----Unknown----|----2s----|
//             ^          ^               ^
//            low        mid            high

// so as we mid sees 0 it swaps it with lwo and we increase the low by 1 
// as mid sees 1, it is already in the correct region,
// so we simply move the mid pointer forward.
// as mid sees 2, we swap it with high and decrease high by 1.
// We DO NOT move mid here because the element swapped from the
// unknown region could be either 0, 1, or 2.
// Therefore, we must inspect it again.


void sort_0_1_2_best(int arr[], int size){
    int low = 0;
    int mid =0 ;
    int high = size - 1;

    for(int indx = 0; indx<size;indx++){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }

        else if(arr[mid] == 1){
            mid++;
        }

        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}






// ########################################### MAIN FUNCTION ##############################################
int main(void){
    int arr[12] = {0,1,2,0,1,2,1,2,0,0,0,1};
    int arr_workable[12] = {0,1,2,0,1,2,1,2,0,0,0,1};
    int arr_workable2[12] = {0,1,2,0,1,2,1,2,0,0,0,1};

    cout<<"Original array: ";
    for(auto val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"Sorted array by BETTER method: ";
    sort_0_1_2(arr_workable,12);

    for(auto val : arr_workable){
        cout<<val<<" ";
    }
    cout<<endl;   

    cout<<"Sorted array by BEST method: ";
    sort_0_1_2_best(arr_workable2,12);

    for(auto val : arr_workable2){
        cout<<val<<" ";
    }
    cout<<endl;   
}