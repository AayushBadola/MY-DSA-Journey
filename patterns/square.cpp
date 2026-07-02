#include <iostream>
using namespace std;

int main(void){
    int user;
    cout<<"Enter value for number of row in square for pattern: "<<endl;
    cin>>user;

    // for square patterns use nested while loops
    // in nested while loops do while(i<number){while(j<number)}
    int row = 0;
    while(row<user){
        int col = 0;
        while(col<user){
            cout<<"* ";
            col++;
        }
        cout<<endl;
        row++;
    }

}