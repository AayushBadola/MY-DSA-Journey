
#include<iostream>
using namespace std;

// types of rotation -> left and right 
// for any given array [1,2,3,4,5]
// left rotate by 1 element means push 1 to the end [2,3,4,5,1]
// left rotate by 2 elements means push 1,2 to the end [3,4,5,1,2]

// right rotation means push last elemnts to first 

// brute force is using another array 
//################### optimal solution #########################

// for array [1,2,3,4,5] -> size 5 , rotate 2 
//                  |(3 = sze - rotation) |(4) 
// say we need to rotate it by k elemnts then we need to store those n elements and then push remaining by N-n

// so if we need to rotate by 2 
// [1,2,3,4,5] -> store 1,2 -> assign values as i-2 where i = 2 (value = 3) -> and nwo push those sotred to end

// ##################### LEFT ROTATION BY 1 ######################
void rotate_left(int arr[], int size){
    int temp = arr[0];
    for(int indx = 1; indx<size;indx++){
        arr[indx-1] = arr[indx];
    }
    arr[size - 1] = temp;
}

// #################### LEFT ROTATION BY K #######################

// ########## brute approach #######
// here we will take first k elements and put them in a temp array
// then we will shift them to left by indx-k (similar to rotation by one just change one to k )
// after shifting we now need to start putting values from temp array back to original 
// hence for that we need to start from the place where no reside the last element (N-k-1)
// so we need to start putting values from (N-K) -> N 
void rotation_k_brute(int arr[], int size, int rotate_times){
    int temp[rotate_times];
    // storing the elements 
    for(int indx = 0 ;indx<rotate_times;indx++){
        temp[indx] = arr[indx];
    }

    // shifting the elements 
    for(int indx = rotate_times; indx<size;indx++){
        arr[indx - rotate_times] = arr[indx];
    }

    // putting temp values back 
    for(int indx = size - rotate_times; indx<size;indx++){
        arr[indx] = temp[indx - (size-rotate_times)];
    }
}

// ######### optimal solution #########
//  for optimal solution we will use our observation 
// [1,2,3,4,5,6,7] -> [4,5,6,7,1,2,3]
// if we reverse 1,2,3 we get [3,2,1,4,5,6,7] -> reverse 4,5,6,7 -> [3,2,1,7,6,5,4]
// reverse this entire array [3,2,1,7,6,5,4]
// [4,5,6,7,1,2,3]

// helper reverse function 
void reverse(int arr[],  int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++;
        end--;
    }

}

void rotate_k_best(int arr[], int size, int rotate_times){
    reverse(arr,0,rotate_times-1);
    reverse(arr,rotate_times + 1, size - 1);
    reverse(arr, 0,size - 1);
}


// ########### MAIN FUNCTION ######################
int main(void){
    int main_arr[] = {1,2,3,4,5,6,7};
    int copy_arr[] = {1,2,3,4,5,6,7};
    int copy_arr_2[] = {1,2,3,4,5,6,7};
    // we will rotate main_arr by 1 
    // we will rotate copy_arr by k times 

    // both are done for left 
    cout<<"Before rotation  by 1: ";
    for(int indx = 0 ; indx<7; indx++){
        cout<<main_arr[indx]<<" ";
    }
    cout<<endl;
    rotate_left(main_arr, 7);
    cout<<"AFTER ROTATION : ";
    for(int indx = 0 ; indx<7; indx++){
        cout<<main_arr[indx]<<" ";
    }
    cout<<endl;

    // rotating copy_arr[] by k times which is entered by user
    int rotation;
    cout<<"Enter rotation times for array : ";
    cin>>rotation;
    cout<<endl;

    cout<<"Before rotation by "<<rotation<<" times : ";
    for(int indx = 0 ; indx<7; indx++){
        cout<<copy_arr[indx]<<" ";
    }
    cout<<endl;

    rotation_k_brute(copy_arr, 7,rotation);

    cout<<"AFTER rotation: ";
    for(int indx = 0 ; indx<7; indx++){
        cout<<copy_arr[indx]<<" ";
    }
    cout<<endl;

    // we will use best method on copy_arr_2
    cout<<"Before rotation using best method: ";
    for(int indx = 0 ; indx<7; indx++){
        cout<<copy_arr_2[indx]<<" ";
    }
    cout<<endl;
    int rotate_times_copy;
    cout<<"Enter how many times you wnana rotate the array: ";
    cin>>rotate_times_copy;
    cout<<endl;


    rotate_k_best(copy_arr_2, 7,rotate_times_copy);

    cout<<endl;
    cout<<"AFTER rotation using best method: ";
    for(int indx = 0 ; indx<7; indx++){
        cout<<copy_arr_2[indx]<<" ";
    }

}



