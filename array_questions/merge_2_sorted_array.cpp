#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted(vector<int>& nums1,vector<int>& nums2){
    int nums1_size = nums1.size() - 1;
    int nums2_size = nums2.size() - 1;
    vector<int> ans;
    if(nums1.size() <= 0 && nums2.size()<= 0){
        ans.push_back(-1);
        return ans;
         }

    else if(nums1.size() <= 0 && nums2.size() >= 1){
        ans = nums2;
    }
    else if(nums1.size() >=1 && nums2.size() <= 0){
        ans = nums1;
    }
    else{
        int indx1 = 0;
        int indx2 = 0;
        while(indx1 <= nums1_size && indx2 <=nums2_size){
            if(nums1[indx1] <= nums2[indx2]){
                ans.push_back(nums1[indx1]);
                indx1++;
            }
            else if(nums2[indx2] < nums1[indx1]){
                ans.push_back(nums2[indx2]);
                indx2++;
            }
        }

        while(indx1 <= nums1_size){
            ans.push_back(nums1[indx1]);
            indx1++;
        }
        
        while(indx2<=nums2_size){
            ans.push_back(nums2[indx2]);
            indx2++;
        }
        return ans;
        
    }
    return ans;

}

int main(void){
    vector<int> nums1 = {1,3,5,8};
    vector<int> nums2 = {2,4,6,7};

    cout<<"Group 1: "<<endl;
    for(auto val: nums1){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"Group 2: "<<endl;
    for(auto val: nums2){
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> ans = merge_sorted(nums1, nums2);
    cout<<"Merged sorted vector: "<<endl;
    for(auto val: ans){
        cout<<val<<" ";
    }

    return 0;
}