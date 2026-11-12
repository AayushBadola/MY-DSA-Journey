#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

// any array containing values [1|2|3|4] we need to convert them to 1234 
// and with another array say  [2|3|4] we need to add that to the above array 

// so the calculation becomes 1234 + 234 = 1468 and we return an array which is [1|4|6|8]
// CASE 2 
// if there are 2 arrays such that [9|9|9] + [1|1|1] then we need 999 + 111 = 1110 - > [1|1|1|0]

// ######################### APPROACH ##################################
// since using normal mathematics we need to use basic addition 
// we need to start adding from behind while having a carry number if the sum is greater than 9 
// then we add that carry to the next number 

// example dry run 
//    9a    9b   9c
//  + 9d    9e   9f
//----------------
// 9c + 9f = 18 -> carry 1 (18 divide 10)                  | 18%10 == 8*(10^0)
// 9b + 9e + CARRY(1) = 19 (19 divide 10 is 1 so carry 1 ) | 19%10 == 9*(10^1) ---> 98
// 9a + 9d + CARRY(1) = 19 (reached end of both numbers)   | 19 (end of both nums) --> 1998


vector<int> add_arr(vector<int> nums1, vector<int> nums2){
    int sum = 0;
    int nums1_pointer = nums1.size() - 1;
    int nums2_pointer = nums2.size() - 1;
    int carry = 0;
    int power10 = 0;
    vector<int> ans;

    // having same length
    while(nums1_pointer >=0 && nums2_pointer >= 0 ){
        int val1 = nums1[nums1_pointer];
        int val2 = nums2[nums2_pointer];

        sum = val1 + val2 + carry;
        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        nums1_pointer--;
        nums2_pointer--;

    }

    // if nums1 length is more
    while(nums1_pointer>=0){
        int sum = nums2[nums2_pointer] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        nums1_pointer--;
    }

    //if nums2 length is more
    while(nums2_pointer>=0){
        int sum = nums2[nums2_pointer] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        nums2_pointer--;
    }    

    while(carry!=0){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }

    return ans;

}

int main(void){
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,2,3,4};

    cout<<"Array 1: ";
    for(int val:nums1){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"Array 2: ";
    for(int val:nums2){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"Combined sum array: ";
    
    vector<int> ans = add_arr(nums1,nums2);
    reverse(ans.begin(), ans.end());
    for(int val: ans){
        cout<<val<<" ";
    }   


}
