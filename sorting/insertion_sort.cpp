#include <iostream>
#include <ctime>
#include <random>

using namespace std;
// for any array [9|14|15|12|6|8|13]
// take the sub array of len 1 [9] -> is it in right place ? -> increase teh size 
// now array is [9|14] -> is the order correct -> increase the size 
// now array is [9|14|15] -> correct order -> increase size 
// now array is [9|14|15|12] -> 12 is out of order and we need it before 14 so swap 12 till it cant 
// so 12 swap 15 -> 12 swap 14 -> 12<9 ? -> no swap is stopped 
// now sorted sub array is [9|12|14|15] -> correct order so increase size 
// now array is [9|12|14|15|6] -> 6 is out of order so swap till we get 9 swap 6
// now array is [6|9|12|14|15]
// repeat till we get [6|8|9|12|14|15]

void insertion_sort(int arr[], int arr_len){
    for(int indx = 0; indx<arr_len;indx++){ // iterating through the entire array
        int odd_one_out = indx; // starting point
        while(odd_one_out>0 && arr[odd_one_out] < arr[odd_one_out - 1]){ // condition till when to swap
            swap(arr[odd_one_out], arr[odd_one_out - 1]); // swapping to get the right order
            odd_one_out -- ; // moving left to swap more till we get correct order
        }
    }
    
}
int main(void){
    srand(time(NULL));
    
    int test[5];
    for(int indx = 0 ;indx<5; indx++){
        test[indx] = rand()%100;

    }

    cout<<"BEFORE SORTING \n";
    for(int indx = 0 ; indx<5; indx++){
        cout<<test[indx]<<" ";
    }
    cout<<endl<<endl;
    insertion_sort(test,5);

    cout<<"AFTER SORTING \n";
    for(int indx = 0 ; indx<5; indx++){
        cout<<test[indx]<<" ";
    }
}

