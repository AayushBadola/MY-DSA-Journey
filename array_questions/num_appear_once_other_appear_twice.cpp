#include <iostream>
using namespace std;

// for the array = [1|1|2|3|3|4|4]
// here 1,3,4 appears twice so they are in safe 
// here 2 appears once so its not safe hence that is the answer 
// overall find the number appearing once problem 

// ################################### BRUTE FORCE ####################################
// take one element at a time and create a counter for it 
// as we traverse that element and find a number equal to it we increase the counter 
//  as we move to next number we reset counter to 0
// now if for any moment after the searching the entire array we find counter != 2 we return that element 

// [1|1|2|3|3|4|4]
//  | 

// see the entire array and we see there is one so we do count++
// [1|1|2|3|3|4|4]
//      |

// for 2 we see the entire array see that count = 1 so we say 2 is the number and return immediately 

int num_appear_once_brute(int arr[], int size){
    for(int indx1 = 0;indx1<size;indx1++){
        int count = 0;
        for(int indx2 = 0;indx2<size;indx2++){
            if(arr[indx1] == arr[indx2]){count++;}
        }
        if(count == 1){return arr[indx1];}
    }
    return -1; // no number appearing once

}

// ####################### BETTER APPROACH ####################

// as we go on the array we store the counts in a hash array and for any time we see a hash[number] == 1
// we return hash[num]

// helper function to find max value in arr
int max_arr(int arr[], int size){
    int max = INT_MIN;
    for(int indx = 0; indx<size;indx++){
        if(arr[indx]>max){
            max = arr[indx];
        }
    }
    return max;
}

int num_appear_once_better(int arr[], int size){
    int hash_size = max_arr(arr,size) + 1;
    int hash_arr[hash_size] = {0};
    for(int indx = 0 ;indx<size;indx++){
        hash_arr[arr[indx]] += 1;
    }

    for(int indx = 0 ; indx<hash_size;indx++){
        if(hash_arr[indx] == 1){
            return indx;
        }
    }
    return -1; // none contains element appearing once 


}

// WE CAN USE MAP AS WELL IF WE ARE GIVEN HUGE INPUTS OR NEGATIVE INPUTS THEN FOR MAP -> (NlogM)
// n-> size of arr
// m -> size of map 

// if we use unordered its O(n) -> best case
// O(N2) -> worst case (rarely happens)

// if inputs are super critical then we do normal ordered map since the tradeoff is quite low

// #################################### OPTIMAL SOLUTION ######################################

// since every number is there 2 times and one number appear once we can do XOR 

// since 1^1^2^3^3^4^4 = 0^2^0^0 = 2 we got our number 

int num_appear_once_best(int arr[], int size){
    int missing = 0;
    for(int indx = 0; indx<size;indx++){
        missing^=arr[indx];
    }
    return missing;
}


// ############################ MAIN FUNCTION ###########################

int main(void){
    // test arr same as assumed array
    int arr[7] = {1,1,2,3,3,4,4};
    cout<<"Given Array is : ";
    for(auto val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    int num_appear_one_brute = num_appear_once_brute(arr,7);
    cout<<"num appearing once by BRUTE FORCE is : "<<num_appear_one_brute<<endl;


    int num_appear_one_better = num_appear_once_better(arr,7);
    cout<<"num appearing once by BETTER VERSION is : "<<num_appear_one_better<<endl;

    int num_appear_one_best = num_appear_once_best(arr,7);
    cout<<"num appearing once by BEST VERSION is : "<<num_appear_one_best<<endl;

}

