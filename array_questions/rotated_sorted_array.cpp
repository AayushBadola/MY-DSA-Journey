#include <iostream>
#include <vector>
using namespace std;

// for any array say {1,2,3,4,5}
// we have 3 cases 
// {1,2,3,4,5}    ARRAY IS SORTED - > 1 pair exist where (previous is bigger than next 5 is bigger than 1 ) 
// {3,4,5,1,2}    Array is rotated -> there exist 1 pair where previous is bigger than next {5,1}
// for a rotated not sorted array - > there may exist 2 or more pairs with this condition 

bool is_sorted_rotated(vector<int> nums){
    int nums_end = nums.size() - 1;

    int pair_count = 0;
    for(int indx = 1; indx<=nums_end; indx++){
        if(nums[indx - 1] > nums[indx] ){
            pair_count++;
        }
    }
    if(nums[nums_end] > nums[0]){
        pair_count++;
    }
    
    if(pair_count >1){
        return false;
    }
    else{return true;}
}

int main(void){
    vector<int> nums_sorted = {1,2,3,4,5};
    vector<int> nums_rotated = {3,4,5,1,2};
    vector<int> nums_false = {5,1,3,4,2};

    cout<<is_sorted_rotated(nums_sorted)<<endl;
    cout<<is_sorted_rotated(nums_rotated)<<endl;
    cout<<is_sorted_rotated(nums_false)<<endl;

    return 0;
}