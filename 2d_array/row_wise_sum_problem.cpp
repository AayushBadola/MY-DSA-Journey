#include <iostream>
#include <vector>
using namespace std;

//we need to find the sum of each ROW

int row_sum(vector<vector<int>> &matrix, int target_row){
    int row = target_row;
    int col = matrix[0].size();
    int sum = 0 ;
    for(int col_index = 0; col_index<col; col_index++){
        sum += matrix[row][col_index];
    }   

    return sum;
}

int main(void){
    vector<vector<int>> test_matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    int test_row = 0 ;// sum = 6

    int matrix_row_sum = row_sum(test_matrix, test_row);
    cout<<"Sum of row: ";
    for(int indx = 0; indx<test_matrix[0].size(); indx++){
        cout<<" "<<test_matrix[0][indx];
    }
    cout<<endl;
    cout<<"Sum: "<<matrix_row_sum;

    return 0;
}