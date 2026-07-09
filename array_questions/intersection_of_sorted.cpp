#include <iostream>
#include <vector>
using namespace std;
// for any 2 arrays [1a,1b,4a,5a,8a] and [1a,4a,4b,7a,9a]
// we can see 1a is common to arr1 and arr 2 so it gets added to intersection
// [1a]
// we see 1b is not common so no add 
// 4a is common so add [1a,4a]
// 5a is not common so no add
// 8a is not common so no add 

// My observation 
// (just a hunch)
//we can just use one array which is shortest and compare it to the other one 
// if both are same length then compare one or the other 

// ############# BRUTE FORCE #############
// create an array which will contain only 0s -> intersect array
// we start with 1st element in 1st array
// check the entire 2nd array for 2nd array = 1 
// if 1 is there we change the 1st position of intersect rray 

//        arr 1                       arr2
// [1|2|2|3|3|4|5|6]            [2|3|3|5|6|7]
//  |
// for 1 we check entire array there is no 1 in 2nd array 
// [0|0|0|0|0|0|0|0|0|0|0|0] we create this array to know if a number has been visited 

//        arr 1                       arr2
// [1|2|2|3|3|4|5|6]            [2|3|3|5|6|7]
//    |

// search for 2 in arr2 -> found 2 so 
//[1|0|0|0|0|0|0|0|0|0|0|0] 2 has been taken 

vector <int> intersection_arr(int arr1[],int size1,int arr2[], int size2){
    int visited_arr[size2] = {0};
    vector <int> res;
    for(int indx1 =0 ; indx1<size1;indx1++){
        for(int indx2 = 0; indx2<size2;indx2++){
            if(arr1[indx1] == arr2[indx2] && visited_arr[indx2] == 0){
                res.push_back(arr1[indx1]);
                visited_arr[indx2] = 1;
                break;    
            }
            if(arr2[indx2] > arr1[indx1]){break;}
        }
    }
    return res;
}

// ############# OPTIMAL SOLUTION ################
// here we will use 2 pointer approach 
// we will compare both the arrays as we are going 
// we keep 1pointer at start of arr1 and one at start of arr2 

// since array is sorted if value at 1st dont match value at 2nd 
// if value1 is less than value 2 we increase pointer 1
// if value 1 is greater than value 2 we increase pointer 2 
// if both are same we add 


vector <int> intersection_best(int arr1[], int size1, int arr2[], int size2){
    vector <int> intersect_arr;
    int arr_point1 = 0;
    int arr_point2 = 0;

    while(arr_point1 < size1 && arr_point2< size2){
        if(arr1[arr_point1] == arr2[arr_point2]){
            intersect_arr.push_back(arr1[arr_point1]);
            arr_point1++;
            arr_point2++;
        }
        else if(arr1[arr_point1] > arr2[arr_point2]){
            arr_point2++;
        }
        else if(arr1[arr_point1] < arr2[arr_point2]){
            arr_point1++;
        }

        
    }
    return intersect_arr;
}

// ############### main function #############
int main(void){
    int arr1[] = {1,2,2,3,3,4,5,6};
    int arr2[] = {2,3,3,4,5,7};
    // their intersection should be 2,3,3,4,5

    cout<<"ARRAY 1: ";
    for(auto val:arr1){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"ARRAY 2: ";
    for(auto val : arr2){
        cout<<val<<" ";
    }
    cout<<endl;

    vector <int> result = intersection_best(arr1, 8, arr2,6);
    vector <int> result2 = intersection_arr(arr1,8,arr2,6);

    cout<<"INTERSECTED ARRAY BEST APPROACH: ";
    for(auto val: result){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"INTERSECTED ARRAY BRUTE FORCE APPROACH: ";
    for(auto val: result2){
        cout<<val<<" ";
    }
    cout<<endl;
}