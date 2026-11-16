#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// for any row in a matrix we need to find the maximum sum of that row 

// sum of row 1  = 10
// sum of row 2 = 20
// sum of row 3 = -1 
// max sum is 20 for row 2 

int row_sum(vector<vector<int>> &matrix, int row){
    if(matrix.empty() || matrix[0].empty()){
        return -1;
    }

    else{
        int sum = 0;
        int col = matrix[0].size();

        for(int col_index = 0; col_index<col; col_index++){
            sum += matrix[row][col_index];
        }

        return sum;
    }
}

int max_val(vector<int> &nums){
    int max = INT_MIN;
    int nums_size = nums.size();
    int max_indx = -1;
    for(int index = 0; index<nums.size(); index++){
        if(nums[index] > max){
            max = nums[index];
            max_indx = index;
        }
    }
    return max_indx;
}

int find_max_row(vector<vector<int>> &matrix){
    int matrix_row = matrix.size();
    int matrix_col = matrix[0].size();

    vector<int> row_sums;

    int matrix_row_sum = -1;
    for(int rows = 0; rows<matrix_row; rows++){
        matrix_row_sum = row_sum(matrix, rows);
        row_sums.push_back(matrix_row_sum);
    }

    int max_row = max_val(row_sums);
    return max_row;

}

int main(void){
    vector<vector<int>> test_matrix = {{1,2,3}, {-1,1,0}, {2,5,4}}; // max row is 2 (0 indexed) with sum = 11
    int matrix_rows = test_matrix.size();
    int matrix_cols = test_matrix[0].size();
    // print the matrix
    for(int row = 0; row<matrix_rows;row++){
        for(int col = 0; col<matrix_cols;col++){

            cout<<" "<<test_matrix[row][col];
        }
        cout<<endl;
    }
    int answer = find_max_row(test_matrix);

    cout<<"Row with max sum should be 2"<<endl;
    cout<<"Algorithm answer: "<<answer;

    return 0;
}