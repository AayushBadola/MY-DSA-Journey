#include <iostream>
#include <vector>
using namespace std;

bool linear_search(vector<vector<int>> &matrix, int target){
    // check if its empty
    if(matrix.empty() || matrix[0].empty()){
        return false;
    }
    
    int row = matrix.size();
    int col = matrix[0].size();

    for(int row_indx = 0; row_indx<row; row_indx++){

        for(int col_indx = 0; col_indx<col; col_indx++){
            if(matrix[row_indx][col_indx] == target){
                return true;
            }
        }
    }
    return false;

}

int main(void){
    vector<vector<int>> test = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> test_empty = {};
    int target_1 = 6;
    int target_2 = 10; // non existant;

    if(linear_search(test,target_1)){
        cout<<"In non empty matrix TARGET EXIST !"<<endl;
        
    }

    if(!linear_search(test_empty,target_1)){
        cout<<"Testin non empty matrix it doesnt exist"<<endl;
    }

    if(!linear_search(test,target_2)){
        cout<<"Testing non existing target and it doesnt exist"<<endl;
    }


}