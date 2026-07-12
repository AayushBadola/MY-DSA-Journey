#include <iostream>
using namespace std;

// in this question we are given an array of length N 
// in that array there will be elements of N-1 so there will be one missing number 
// arr = [1|2|4|5] n = 4
// when we created the array we created it for length N= 5
// hence there is a missing number we need to find it 

// #################### BRUTE FORCE #######################


// for this we can we know the length of array which was originally created 
// so we run a loop that will go from 1-> and for each we will check i that number is in array 
// if its not that is our missing number 

// [1,2,4,5]
//  |
// 1 in loop = 1 in array 

// [1,2,4,5]
//    |
//    2 in loop = 2 in array

// [1,2,4,5]
//      |
//      3 in loop NOT in array 

// so 3 is missing 

int find_missing_brute(int arr[],int size){
    for(int indx1 = 1; indx1<=size+1;indx1++){
        int flag = 0;
        for(int indx2 = 0; indx2<size; indx2++){
            if(arr[indx2] == indx1){
                flag = 1; // number exists
                break;
            }
        }
        if(flag == 0){return indx1;}
    }
    return -1;
}

// ################ BETTER APPROACH #################
// WE WILL USE HASHING
// we can create a hash array which will of size N+1 that way we can get indices till N 
// initially we will have that hash array as 0;
// as we are going through the array and finding numbers we will update the hash array's 0 to 1 
// for the index which is still 0 (except the index 0) that index will be the number that is missing 

int find_missing_better(int arr[], int size){
    int hash_arr[size+2] = {0};

    // iterate the array
    for(int indx = 0; indx<size; indx++){
        hash_arr[arr[indx]] = 1;
    }

    for(int indx = 1; indx<size+2; indx++){
        if(hash_arr[indx] == 0){return indx;}
    }

    return -1; // if no missing element
}

// #####################3 BEST APPROACH ###################
// we will use mathematics since we know the sum till N numbers is N*(N+1)/2
// we can iterate the array and find the actual sum and by formula the expected sum 
// and by doing "expected-actual" we can find the missing number

int find_missing_best(int arr[], int size){
    int expected_sum = ((size+1)*(size+2))/2;
    int actual_sum = 0;
    for(int indx= 0; indx<size;indx++){
        actual_sum+=arr[indx];
    }
    return expected_sum - actual_sum;

}

// ################## OPTIMAL SOLUTION (XOR) ###############
// basically when doing size*size there is a probability that it will cause integer overflow hence 
// we will use xor 
// therefore we use xor which does 
// NUM1 XOR NUM1 = 0
// NUM1 XOR NUM1 != 0
// basically we will do XOR(expected) = 1^2^3^4^5
// now we will basically do XOR(actual) = 1^2^4^5
// if we do xor(expected) ^ xor(actual) = (1^1)^(2^2)^(3)^(4^4)^(5^5) = 0^0^3^0^0 = 3 -> MISSING NUMBER !

int find_missing_bestest(int arr[],int size){
    int actual = 0;
    int expected = 0;
    
    for(int indx = 0;indx<size;indx++){
        actual = actual^(arr[indx]);
        expected = expected^(indx+1);

    }
    expected =  expected^(size+1);
    return expected^actual;
}



// ################## MAIN FUNCTION ################33
int main(void){
    int arr[4] = {2,4,1,5};
    cout<<"Array is : ";
    for(auto val : arr){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"WHAT ARRAY SHOULD HAVE BEEN: ";
    for(int indx = 1; indx<=5; indx++){
        cout<<indx<<" ";
    }
    cout<<endl;

    int missing_brute = find_missing_brute(arr,4);
    cout<<"Missing number is BY BRUTE FORCE: "<<missing_brute;

    cout<<endl;

    int missing_better = find_missing_better(arr,4);
    cout<<"Missing number is BY BETTER APPROACH: "<<missing_better;
    cout<<endl;

    int missing_best = find_missing_best(arr,4);
    cout<<"MIssing number is by BEST APPRAOCH: "<<missing_best;
    cout<<endl;

    int missing_bestest = find_missing_bestest(arr,4);
    cout<<"MIssing number is by BESTEST approach: "<<missing_bestest;
    cout<<endl;
}