#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotate_matrix(vector<vector<int>> &matrix){

    vector<vector<int>> wrong_ans = {{-1}, {-1},{-1}};
    if(matrix.empty() || matrix[0].empty()){
        return wrong_ans;
    }

    else{

        int matrix_rows = matrix.size();
        int matrix_cols = matrix[0].size();

        vector<vector<int>> ans(
            matrix_cols, vector<int>(matrix_rows, 0)
        );
        // for transformation through observation we hav e
        // [curr row][current col] --> [current col][total columns - current row - 1]

        for(int row = 0; row<matrix_rows; row++){

            for(int col = 0; col< matrix_cols; col++){

                // conversion 
                ans[col][matrix_rows -row -1] = matrix[row][col];
            }
        }

        return ans;
    }

    return wrong_ans;
}


int main(void){
    vector<vector<int>> test_matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    // printing test matrix
    cout<<"Current matrix is: "<<endl;
    int test_matrix_rows = test_matrix.size();
    int test_matrix_cols = test_matrix[0].size();
    for(int row = 0; row<test_matrix_rows; row++){

        for(int col = 0; col<test_matrix_cols; col++){
            cout<<" "<<test_matrix[row][col]; 
        }
        cout<<endl;
    }

    cout<<"Matrix after 90 degree rotation: "<<endl;

    vector<vector<int>> rotated_matrix = rotate_matrix(test_matrix);
    int rotated_matrix_rows = rotated_matrix.size();
    int rotated_matrix_cols = rotated_matrix[0].size();

    for(int row = 0; row<rotated_matrix_rows; row++){

        for(int col = 0; col<rotated_matrix_cols; col++){
            cout<<" "<<rotated_matrix[row][col]; 
        }
        cout<<endl;
    }

}