#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<vector<int>> &matrix, int target){
    if(matrix.empty() || matrix[0].empty()){
        return false;
    }

    else{
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = (row*col) - 1;

        while(low<=high){
            int mid = low + (high-low)/2;
            int mid_row = mid/col;
            int mid_col = mid%col;

            if(matrix[mid_row][mid_col] == target){
                return true;
            }

            else if(matrix[mid_row][mid_col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return false;
    }
}


int main(void){
    vector<vector<int>> test = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> test_empty = {};
    int target_1 = 6;
    int target_2 = 10; // non existant;

    if(binary_search(test,target_1)){
        cout<<"In non empty matrix TARGET EXIST !"<<endl;
        
    }

    if(!binary_search(test_empty,target_1)){
        cout<<"Testin non empty matrix it doesnt exist"<<endl;
    }

    if(!binary_search(test,target_2)){
        cout<<"Testing non existing target and it doesnt exist"<<endl;
    }


}