#include <iostream>
using namespace std;

/*
Based on: inverse_triangle.cpp

Pattern:

1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

Since the number of values printed on each
row is still equal to the current row value,
we can reuse the same row and col structure
from inverse_triangle.cpp.

The difference is that instead of printing '*',
we print numbers.

We can see:

col 0 -> 1
col 1 -> 2
col 2 -> 3

So the value depends on the column position.

Therefore replace '*' with col + 1
(using ++col in the print statement).

No change in row/column logic,
only the print statement changes.
*/

void print_inverse_num_triangle(int user){
    while(user<=0){
        cout<<"Please enter Positive values: ";
        cin>>user;
        cout<<endl;
    }

    int row = user;
    while(row>=0){
        int col = 0;
        while(col <row){
            cout<<++col<<" ";
            
        }
        row--;
        cout<<endl;
    }
}

int main(void){
    int user_input;
    cout<<"Enter number of rows to print pattern: ";
    cin>>user_input;
    cout<<endl;
    print_inverse_num_triangle(user_input);
    return 0;
}