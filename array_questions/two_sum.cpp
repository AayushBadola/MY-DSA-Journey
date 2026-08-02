#include <iostream>
#include <utility>
#include<map>
using namespace std;
// a 2 sum problem expects us to find teh combination of elements which sum to exactly our target value 

// for any array [2|6|5|8|11] we need sum as 14
// then we can say the combination is 6 and 8

// ############################################# BRUTE FORCE #################################################
// for brute force we can generate every possible combination and then check what combination equals to the target sum 
// for any array [2|6|5|8|11]
// we can do these
// 2+6 = 8
// 2+5 = 7
// 2+8 = 10
// 2+11 = 13

// 6+2 = 8
// 6+5 = 11
// 6 + 8 = 14
// and so on till we generate all combinations and pick 6+8 at the END since its euqla to our target 

pair<int,int> two_sum_brute(int arr[], int size, int target){
        int sum = 0;
        int pos1 = 0;
        int pos2 = 0;
        for(int indx1 = 0;indx1<size;indx1++){
            for(int indx2= indx1 + 1; indx2<size;indx2++){
                sum = arr[indx1] + arr[indx2];
                pos1 = indx1;
                pos2 = indx2;
                if(sum == target){
                    return {pos1, pos2};
                }
            }

        }
        return {-1, -1};
}


// ########################################### BETTER APPROACH ##########################################
// for better approcah we will use hashing and some basic mathematics 

// lets build it backwards 
// say we need a result K
// mathematics say if we have X then next number should be K - X 
// so we will do this 
// [2|6|5|8] our "K" = 14 (6 + 8)

// we will store these in hash and as we are storing we will ask ask does 14-2 = 12 already exist or not ? nope ? -> continue

// [2|6|5|8]
//  |  value = 2 store it as (0,2) search does 14-2 = 12 exist ? -> NO -> move right {hash-> (0,2)}

// [2|6|5|8]
//    | value = 6 , store it as (1,6) seach does 14-6= 8 exist ? -> NO - > move right {hash-> (0,2)| (1,6)}

// [2|6|5|8]
//      | value = 5 , store as (2,5) search does 14-5=9 exist ? -> NO -> move right {hash-> (0,2) | (1,6) | (2,5)}

// [2|6|5|8]
//        | value = 8, store it as (3,8) search does 1  -8 = 6 exist ? -> YES at what location ? -> (1,6) so we return index 1 and index 3

pair<int,int> two_sum_better(int arr[], int size, int target){
    map<int,int> value_storage;
    for(int indx = 0; indx<size; indx++){
        int curr_val = arr[indx];
        int remaining_val = target - curr_val;
        // check if value doesnt already exist in map 

        if(value_storage.find(remaining_val) != value_storage.end()){
            return {indx, value_storage.find(remaining_val)->second};  // as in map "find" return the iterator which is {value,index} so we call the iterator -> second so we get the index value of it 
        }

        value_storage[curr_val] = indx;
    }

    return {-1,-1}; // showcase value not found 
}


// ##################################################### OPTIMAL SOLUTION #######################################################
// For optimal approach we will need a condition 
// this solution is for sorted array for unsorted the better one is the optimal one 

// lets assume 2 pointers , p1 at start and p2 at end 
// since its sorted we know by moving the pointers right sum increases and moving it left sum decreases 

// [2|6|5|8]
//  |     |
// p1     p2   current sum -> p1 + p2 = 10 -> less then 14 -> move p1 to right

// [2|5|6|8]
//    |   |   CURRENT SUM = P1 + p2  = 7 -> less then 14 -> move p1 to right
//    p1  p2

// [2|5|6|8]
//      | |   current sum = p1 + p2 = 14-> target found -> return p1 and p2 


pair<int,int> two_sum_best(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    if(right <=0){return {-1,-1};}

    while(left<right){
        int curr_sum = arr[left] + arr[right];
        if(curr_sum < target){
            left ++;
        }
        else if(curr_sum>target){
            right--;
        }
        else{return {left,right};}
    }
    return {-1,-1};
}

// ################################ MAIN FUCNTION ######################################
int main(void){
    int test_arr[5] = {2, 5, 6, 8, 11};
    pair<int,int> pos = two_sum_brute(test_arr,5,14);
    cout<<"The combination of elements making '14' by BRUTE FORCE: "<<test_arr[pos.first]<<" and "<<test_arr[pos.second]<<endl;

    pair<int,int> pos_better = two_sum_better(test_arr,5,14);
    cout<<"The combination of elements making '14' by BETTER METHOD: "<<test_arr[pos_better.first]<<" and "<<test_arr[pos_better.second]<<endl;

    pair<int,int> pos_best = two_sum_best(test_arr,5,14);
    cout<<"The combination of elements making '14' by BEST METHOD: "<<test_arr[pos_best.first]<<" and "<<test_arr[pos_best.second]<<endl;
}
