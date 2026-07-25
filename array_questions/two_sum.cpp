#include <iostream>
#include <utility>
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




// ################################ MAIN FUCNTION ######################################
int main(void){
    int test_arr[5] = {2, 6, 5, 8, 11};
    pair<int,int> pos = two_sum_brute(test_arr,5,14);
    cout<<"The combination of elements making '14' by BRUTE FORCE: "<<test_arr[pos.first]<<" and "<<test_arr[pos.second]<<endl;
}
