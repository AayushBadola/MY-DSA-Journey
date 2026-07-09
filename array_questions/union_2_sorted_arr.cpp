#include<iostream>
#include <set>
#include <vector>
using namespace std;

// for 2 sorted arrays [1|1|2|3|3|4] AND [1|4|4|5|5|5|6]
// their union should produce [1|2|3|4|5|6] where the arr should be unique elements 
// [1|1|2|3|3|4]
// [1|4|4|5|5|56]
// --- --- --- ---
// [1|1|1|2|3|3|4|4|5|5|5|6]

// and only unique elements are needed -> [1|2|3|4|5|6]

// ############# BRUTE FORCE ############
// we can do is traverse array 1 and add each eleemnt to a set 
// then traverse array 2 and add each element to set 

// from set we add the values to another array called union_array
vector <int> union_brute(int arr1[], int size1, int arr2[],int size2){
    set<int> st;

    // getting unique values from array 1
    for(int indx = 0 ;indx<size1;indx++){
        st.insert(arr1[indx]);
    }

    // getting unique values from array 2
    for(int indx =0; indx<size2; indx++){
        st.insert(arr2[indx]);
    }
    
    // adding combined unique values form set to the array
    vector <int> union_result;
    for(int value : st){
        union_result.push_back(value);
    }

    return union_result;

}

// ####################### OPTIMAL SOLUTION #################

// for optimal solution we will view the 2 arrays parallel
// so that we can have 2 pointers one for each array and as we traverse it we add elements to 
// our result vector 

//  ARRAY 1                  ARRAY 2 
// [1|1|2|4|5]             [1|3|3|5|6]
//  |                       |
//  p1                      p2

// we see since its sorted array so if p1 <= p2 we add p1 to union 

// is 1(p1)<=1(p2) -> YES -> ADD TO UNION= [1]
// now since we have added then we increase the pointer 1 and since we only need unique elements 
// we also increase pointer 2 

//  ARRAY 1                  ARRAY 2 
// [1|1|2|4|5]             [1|3|3|5|6]
//    |                       |
//    p1                      p2
// we need unique elements but in p1 we already added 1 so increase it 

////  ARRAY 1                  ARRAY 2 
// [1|1|2|4|5]             [1|3|3|5|6]
//      |                     |
//      p1                    p2   is p1<=p2 ? -> YES -> add p1 to union = [1|2]

// we increase p1 

//  ARRAY 1                  ARRAY 2 
// [1|1|2|4|5]             [1|3|3|5|6]
//        |                   |
//        p1                  p2   is p1<=p2 ? -> NO-> ADD P2 TO UNION = [1|2|3]

// we now increase p2 to next 3 but since we already used 3 we increase it again to 5

//  ARRAY 1                  ARRAY 2 
// [1|1|2|4|5]             [1|3|3|5|6]
//        |                       |
//        p1                      p2  is p1<= p2 ? -> YES -> ADD p1 union = [1|2|3|4]

// increase p1 again 

//  ARRAY 1                  ARRAY 2 
// [1|1|2|4|5]             [1|3|3|5|6]
//          |                     |
//          p1                    p2   is p1<=p2 ? -> YES -> add p1 union = [1|2|3|4|5]


// now p1 ++ -> out of bounds stop 
// focus on p2 now is p2 = p1 ? increase 
 
//  ARRAY 1                  ARRAY 2 
// [1|1|2|4|5]             [1|3|3|5|6]
//            |                     |
//            p1                    p2 add p2 to union = [1|2|3|4|5|6]

vector <int> union_best(int arr1[], int size1, int arr2[], int size2){
    int arr1_pointer = 0;
    int arr2_pointer = 0;
    vector <int> union_result;
    while(arr1_pointer < size1 && arr2_pointer<size2){
        // add the smallest element 1st 
        if(arr1[arr1_pointer] < arr2[arr2_pointer]){
            // check if the element we are adding does NOT exist in the union result
            if(union_result.empty()|| union_result.back() != arr1[arr1_pointer]){
            union_result.push_back(arr1[arr1_pointer]);
            arr1_pointer++;
            }
            // skip the element if it is in the union result
            else {arr1_pointer++;}
        }
        else if (arr1[arr1_pointer] > arr2[arr2_pointer]){
            if(union_result.empty()|| union_result.back() != arr2[arr2_pointer]){
            union_result.push_back(arr2[arr2_pointer]);
            arr2_pointer++;
            }
            else{arr2_pointer++;}
        }

        // check only for arr1 or arr2 since this upper case is when both values are equal 
        else {
            // check if we are not adding an element whcih does already exist in result 
            if(union_result.empty()|| union_result.back() != arr1[arr1_pointer]){
                union_result.push_back(arr1[arr1_pointer]);
            arr1_pointer++;
            arr2_pointer++;
            }
            else{arr1_pointer++;arr2_pointer++;}
        }
    }

    while(arr1_pointer <size1){
        // push remaining elements of arr1 to union if they are NOT inside the result
        if(union_result.empty() || union_result.back() != arr1[arr1_pointer]){
            union_result.push_back(arr1[arr1_pointer]);
            arr1_pointer ++;
        }
        // skip the element if they are inside the union
        else{arr1_pointer++;}

        }
    while(arr2_pointer <size2){
        // push remaining elements of arr2 to union if they are NOT inside the result
        if(union_result.empty() || union_result.back() != arr2[arr2_pointer]){
            union_result.push_back(arr2[arr2_pointer]);
            arr2_pointer++;
        }
        // skip the element if they are inside the union
        else{arr2_pointer++;}
    }

    return union_result;
}


// ################ MAIN FUNCTION ##################

int main(void){
    int arr1[5] = {1,2,3,3,4};
    int arr2[5] = {1,2,2,4,5};
    // combination should be 1,2,3,4,5

    cout<<"ARRAY 1: ";
    for(int indx = 0 ;indx<5; indx++){
        cout<<arr1[indx]<<" ";
    }
    cout<<endl;

    cout<<"ARRAY 2: ";
    for(int indx = 0 ;indx<5; indx++){
        cout<<arr2[indx]<<" ";
    }
    cout<<endl;

    vector <int> union_result = union_brute(arr1,5,arr2,5);

    cout<<"UNION OF ARRAY 1 and ARRAY 2: ";
    for(int indx = 0 ;indx<union_result.size(); indx++){
        cout<<union_result[indx]<<" ";
    }
    cout<<endl;


    //####### using best approach 

    vector <int> union_result_2 = union_best(arr1,5,arr2,5);
    cout<<"UNION OF ARRAY 1 and ARRAY 2 USING BEST METHOD: ";
    for(int indx = 0 ;indx<union_result.size(); indx++){
        cout<<union_result_2[indx]<<" ";
    }
    cout<<endl;

}