#include <iostream>
#include <map>
using namespace std;

// for any array there exist sub arrays like this [(1|2|0|3), (4|1|1), (6),(3|3)] the sum we want = 6
// here the longest sub array is 4|1|1 giving the sum as 6 so we want to return it 
// the sub array must be continous

// THIS CASE CONTAINS ONLY POSITIVE NUMBERS

// ###################### BRUTE FORCE ############################
// we find all the sub arrays and we find the sum of all the subarrays and see the sum = target 


int longest_sub_sum_K_brute(int arr[], int size, int target){
    //containing the maximum length of string 
    int max_len = 0;
    // generating all subarrays
    for(int indx1 = 0; indx1<size; indx1++){
        for(int indx2 = indx1;indx2<size;indx2++){
            int sum = 0;
            for(int inbtw = indx1; inbtw<=indx2; inbtw++){
                sum+=arr[inbtw];

            }
            if(sum==target){max_len =  max(max_len,indx2-indx1 + 1);} // checking if current length is bigger than 
                                                                      // previous max length 
        }
    }
    return max_len;
}

// ##################### BETTER APPROACH #####################
// here we can see for the array [1|2|3|1|1|1|1|4|2|3]
// when we generate the sub array we can just find the sum as we are generating them 
// so we do 
// sub arrays :
// [1] -> sum = 1
// [1|2] -> sum = previous sum + new number = 1 + 2 = 3
// [1|2|3] - > sum = previous sum + new num = (3) + 3 = 6
// [1|2|3|1] -> prev sum + new num = (6) + 1 = 7
// and so on 


int longest_sub_sum_k_better(int arr[], int size, int target){
    int max_len = 0;
    for(int indx1 = 0; indx1<size;indx1++){
        int sum = 0;
        for(int indx2 = indx1;indx2<size;indx2++){
            sum+= arr[indx2];
            if(sum == target){max_len = max(max_len, (indx2 - indx1 + 1));}
        }
        
    
    }
    return max_len; // no combination found for target
}

// ###################### BETTER BETTER APPROACH #####################3
// for this we will use hashing 
// for array [1|2|3|1|1|1|1|4|2|3]
// we know the longest sub array for 3 is [1|1|1] we can treat it as K 
// we also know for sub array [1|2|3|1|1|1] we hake 1,1,1 as k 
// so we can say [1|2|3|(1|1|1)]
// we can replace 1|1|1 as K -> [1|2|3|K]
// SAY WE KNOW THIS SUB ARRAY'S SUM AS X 
// so [1|2|3|K] = X -> so 1,2,3 is (X-K)
// we can now find subrray which is X-K and just after it we will be able ot find our subrray 

// now to hash we do 
// [1|2|3|1|1|1|1|4|2|3]
//  |
// we have element 1 and sum = 1 , len = 0 (since we didnt reach our target element sum)
// [1|2|3|1|1|1|1|4|2|3]
//    |
// now element is 2 and we have total sum as prev sum = 1 + 2 = 3 (target 1 found) -> len = 2
// [1|2|3|1|1|1|1|4|2|3]
//      |
// now sum is prev sum = 3 + 3 = 6
// WE SEE THAT THERE IS 3 and before it we (storing hashmap as value in array -> sum till that value)
// so it becaomes (1->1), (2->3), (3->6)
// was there a value that is 3 before sum = 6 ? -> YES THERE WAS AT VALUE = 2 
// so there exist a sub array containing sum = 3
// [1|2|3|1|1|1|1|4|2|3]
//        |
// now sum is 7 
// what we need is to divide it in parts that is 4,3 is there a sub array sum contianing 4 ? -> NO -> sum = 7
// [1|2|3|1|1|1|1|4|2|3]
//          |
// we now have sum = 8 we bifurcate it to 5,3 is there a sub array with sum = 3 ? -> NO -> sum = 8
// [1|2|3|1|1|1|1|4|2|3]
//            |
// now we re at sum = 9 we bifurcate it to 6,3 was there a 6 in sub array ? -> YES -> at value 3 and index 2
// so we basically got our subarray at index 2 -> what index we are at right now that is 5
// so the length is (5- index where sum was 6) => (5-2) = 3 ! we got the length as 3 

int longest_sub_arr_k_better_better(int arr[], int size, int target){
    map<int,int> mpp;
    int max_len = 0;
    int sum = 0;
    for(int indx = 0;indx<size;indx++){
        sum += arr[indx];
        if(sum == target){
            max_len = max(max_len, indx+1);
        }
        int required = sum - target;
        if(mpp.find(required)!=mpp.end()){
            int len= indx - mpp[required];
            max_len = max(max_len,len);
        }
        mpp[sum] = indx;
        
    }
    return max_len;
} 

// ####################################### BEST APPROACH ########################################
// for this we will use 2 pointer approach 
// here we will try to find the current running sum and as sum increases it will go beyond the point of the sum we are looking for 
// as it increases we will trim from the left side 
// again we will go and then trim from the let side 
// and so on and so forth and while doing that we will try to "log" our current running max length and update it if a bigger appears 

// [1|2|3|1|1|1|1|3|3]  {sum we need is 6}
// ||                   {current sum = 1}
// pointer 1 and 2 at start position 
// [1|2|3|1|1|1|1|3|3] 
//  | |                 {current sum = 3}

// [1|2|3|1|1|1|1|3|3] 
//  |   |               {current sum = 3+3 = 6} found length {current length = 3}

// [1|2|3|1|1|1|1|3|3] 
//  |     |             {current sum = 7} GREATER THAN 6 SHORTEN FROM LEFT 

// [1|2|3|1|1|1|1|3|3] 
//    |   |             {current sum = 6} {current length = 3 not greater than previous length so not updated }

// [1|2|3|1|1|1|1|3|3] 
//    |     |           {current sum = 7} short fomr left 

// [1|2|3|1|1|1|1|3|3] 
//      |   |            {current sum = 5} move to right 

// [1|2|3|1|1|1|1|3|3] 
//      |     |          {current sum = 6} length updated to 4 

// [1|2|3|1|1|1|1|3|3] 
//      |       |       {curretn sum = 7} short fomr left 

// [1|2|3|1|1|1|1|3|3] 
//        |     |      {curretn sum = 4} increase to right 

// [1|2|3|1|1|1|1|3|3] 
//        |       |    {current sum = 7} reduce left 

// [1|2|3|1|1|1|1|3|3] 
//          |     |    {current sum = 6} current length = 4 (current length not greater than 4)

// after iterations it will reach the end so return whats the current length 


int longest_sub_arr_k_best(int arr[], int size, int target){
    int current_pointer = 0;
    int previous_pointer = 0;
    int sum = 0;
    int max_len = 0;

    while(current_pointer<size){
        int curr_len = 0;
        sum+=arr[current_pointer];
        
        if(sum>target){
            while(sum>target){
            sum-=arr[previous_pointer];
            previous_pointer++;
            }
        }        
        

        if(sum == target){
            curr_len = current_pointer - previous_pointer + 1 ;
        }

        max_len = max(max_len, curr_len);


        current_pointer++;

    }
    return max_len;
}



// ############################## MAIN FUNCITON ###########################
int main(void){
    int arr[10] = {1,2,3,1,1,1,1,4,2,3};
    cout<<"Given Array is : ";
    for(auto val : arr){
        cout<<val<<" ";
    }
    cout<<endl;

    int longest_sub_arr_brute = longest_sub_sum_K_brute(arr,10,3);
    int longest_sub_arr_better = longest_sub_sum_k_better(arr,10,3);
    int long_sub_arr_better_better = longest_sub_arr_k_better_better(arr,10,3);

    int long_sub_arr_best = longest_sub_arr_k_best(arr,10,3);
    cout<<"LONGEST SUB ARRAY BY BRUTE FORCE : "<<longest_sub_arr_brute<<endl;
    cout<<"Longest Sub array by BETTER APPROACH : "<<longest_sub_arr_better<<endl;
    cout<<"Longest Sub array by BETTER BETTER APPROACH : "<<long_sub_arr_better_better<<endl;
    cout<<"Longest Sub array by BEST APPROACH : "<<long_sub_arr_best<<endl;

}