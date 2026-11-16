#include <iostream>
#include <vector>
using namespace std;

// given a matrix 
/*
[1  2]
[3  4]

we need to print 

[1, 3, 2, 4]

going from top to bottom of col 1 {1,3}
then going from top to bottom of col 2 {2,4}

*/


void wave_pattern(vector<vector<int>> &matrix){
    if(matrix.empty() || matrix[0].empty()){
        return;
    }

    else{
        int matrix_rows = matrix.size();
        int matrix_cols = matrix[0].size();
        
        for(int col = 0; col<matrix_cols; col++){
            if(col&1){

                // odd index
                for(int row = matrix_rows - 1; row>=0; row--){
                    cout<<" "<<matrix[row][col];
                }
            }

            else{

                // even indexed
                for(int row = 0; row<matrix_rows; row++){
                    cout<<" "<<matrix[row][col];
                }
            }
        }
    }
}



int main(void){
    vector<vector<int>> test_matrix = {{1,4,7}, {2,5,8}, {3,6,9}};
    // the pattern should be 1,2,3 , 6,5,4, 7,8,9
    // every odd indexed col is going from bottom to top and even indexed is going from top to bottom 

    
    wave_pattern(test_matrix);

    return 0;
}