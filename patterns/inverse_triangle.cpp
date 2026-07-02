#include <iostream>
using namespace std;
/*
Reverse triangle pattern.

Outer loop controls rows.
Inner loop prints stars.

Number of stars printed on a row
is equal to the current row value.

row decreases from user to 1,
so stars also decrease each row.

Example:

*****
****
***
**
*

*/

void print_reverse_triangle(int user){

    while(user<=0){
        cout<<"Please enter a positive value: ";
        cin>>user;
        cout<<endl;
    }

    int row = user;
    while(row>0){
        int col = 0;
        while(col<row){
            cout<<"* ";
            
            col++;
        }
        row--;
        cout<<endl;
    }

}

int main(void){
    int user_input;
    cout<<"Enter number of rows: ";
    cin>>user_input;
    cout<<endl;
    print_reverse_triangle(user_input);
    return 0;
}