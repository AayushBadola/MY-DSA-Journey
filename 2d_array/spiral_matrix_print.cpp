#include <iostream>
#include <vector>
using namespace std;

vector<int> spiral_print(vector<vector<int>> &matrix) {
    vector<int> ans;

    if (matrix.empty() || matrix[0].empty()) {
        return ans;
    }

    int matrix_rows = matrix.size();
    int matrix_cols = matrix[0].size();

    int starting_row = 0;
    int starting_col = 0;
    int ending_row = matrix_rows - 1;
    int ending_col = matrix_cols - 1;

    while (starting_row <= ending_row &&
           starting_col <= ending_col) {

        // 1. Print starting row: left to right
        for (int col = starting_col; col <= ending_col; col++) {
            ans.push_back(matrix[starting_row][col]);
        }
        starting_row++;

        // 2. Print ending column: top to bottom
        for (int row = starting_row; row <= ending_row; row++) {
            ans.push_back(matrix[row][ending_col]);
        }
        ending_col--;

        // 3. Print ending row: right to left
        if (starting_row <= ending_row) {
            for (int col = ending_col; col >= starting_col; col--) {
                ans.push_back(matrix[ending_row][col]);
            }
            ending_row--;
        }

        // 4. Print starting column: bottom to top
        if (starting_col <= ending_col) {
            for (int row = ending_row; row >= starting_row; row--) {
                ans.push_back(matrix[row][starting_col]);
            }
            starting_col++;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> test_matrix = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    vector<int> pattern = spiral_print(test_matrix);

    for (int val : pattern) {
        cout << " " << val;
    }

    return 0;
}   