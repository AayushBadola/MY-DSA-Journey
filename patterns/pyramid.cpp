#include <iostream>
using namespace std;

/*
INVERTED PYRAMID

Pattern for user = 4

*******
 *****
  ***
   *

Logic:

spaces = current row
stars  = 2*(user-current_row)-1

This is the SAME structure as a normal pyramid.

Normal Pyramid:
spaces = user-row
stars  = 2*row+1

Inverted Pyramid:
spaces = row
stars  = 2*(user-row)-1

Only the formulas changed.
*/

void print_pyramid(int user){

    // row controls which line of pattern we are printing
    int row = 0;

    // print rows one by one
    while(row < user){

        // print left spaces
        // spaces increase every row
        // row 0 -> 0 spaces
        // row 1 -> 1 space
        // row 2 -> 2 spaces
        int space = 0;

        while(space < row){
            cout<<" ";
            space++;
        }

        // print stars
        // stars decrease by 2 every row
        // row 0 -> 7 stars
        // row 1 -> 5 stars
        // row 2 -> 3 stars
        int star = 0;

        while(star < 2*(user-row)-1){
            cout<<"*";
            star++;
        }

        // move cursor to next line
        cout<<endl;

        // move to next row
        row++;
    }
}

int main(void){

    int user_input;

    cout<<"Provide number of rows: ";
    cin>>user_input;

    cout<<endl;

    print_pyramid(user_input);

    return 0;
}