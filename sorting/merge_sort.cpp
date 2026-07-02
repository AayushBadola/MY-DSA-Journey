#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void merge(vector <int> &arr, int low,int mid,int high){
    vector <int> result_arr;
    int left = low;
    int right = mid+1;
    while(left<=mid && right <= high){
        if(arr[left] <=arr[right]){result_arr.push_back(arr[left]);left++;}
        else if(arr[right] < arr[left]){result_arr.push_back(arr[right]);right++;}
    }
    while(left<=mid){
        result_arr.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        result_arr.push_back(arr[right]);
        right++;
    }

    for(int indx = low; indx<=high; indx++){
        arr[indx] = result_arr[indx - low];
    }

}

void recurr_merge_sort(vector <int> &arr, int low,int high){
    int mid = low + (high-low)/2;
    if(low>=high){return;}
    recurr_merge_sort(arr,low,mid);
    recurr_merge_sort(arr,mid+1, high);
    merge(arr,low,mid,high);
}

void merge_sort(vector<int> &arr, int n ){
    recurr_merge_sort(arr, 0, n-1);
}



int main(void){
    srand(time(NULL));
    vector<int> arr(5);
    for(int indx = 0; indx<5;indx++){
        arr[indx] = rand()%100;
    }

    cout<<"Before sorting \n";
    for(int indx = 0 ; indx<5;indx++){
        cout<<arr[indx]<<" ";
    }

    merge_sort(arr, 5);
    cout<<"\n \n";
    cout<<"After sorting \n";

    for(int indx = 0 ; indx<5;indx++){
        cout<<arr[indx]<<" ";
    }
}