#include <iostream>
using namespace std;

// for any 2d array we have the capability to make them using basic cpp syntax
// matrix[ROW][COL]

// we can also represent a 2D array/ matrix using a single linear array 
// for representation we need to map the individual row-col values to the normal linear array 

/*

for 2D array = C * i + j
C -> total cols 
i -> ith row 
j -> jth col 

linear array index = C*i + j

*/


int main(void){
    // 2D ARRAY 
    int arr[3][3];  // a 3X3 matrix

    // taking input
    for(int row_indx = 0; row_indx<3; row_indx++){
        
        for(int col_indx = 0; col_indx<3; col_indx++){
            cout<<"Enter value for row "<<row_indx<<" col "<<col_indx<<" ";
            cin>>arr[row_indx][col_indx];
        }
    }

    // giving output using auto
    for(int row = 0; row<3; row++){
        for(int col = 0; col<3; col++){

            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }

    

}
