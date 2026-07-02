#include <iostream>
using namespace std;
// triangle pattern again so we use the structure of "tringle"
// we can see the patternw e need has all val in col 0 as 1 and col 1 as 2 and so on 
// so in print statement instead of "*" we did in "triangle" we replace it by col + 1 
//ALSO change condition col<row to col<=row


/*
print this pattern 
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5 
*/

void print_num_triangle(int user){
    while (user<=0){
        cout<<"we need a positive value please enter again : ";
        cin>>user;

    }

    int row = 0;
    while(row<user){
        int col = 0;
        while(col<=row){
            cout<< ++col <<" "; 
            
        }
        cout<<endl;
        row++;

    }
}

int main(void){
    int user_input;
    cout<<"Enter numebr of rows for numebr triangle: ";
    cin>>user_input;
    print_num_triangle(user_input);
    return 0;
}

