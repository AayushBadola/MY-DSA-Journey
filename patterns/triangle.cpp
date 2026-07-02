#include <iostream>
using namespace std;
// for triangle pattern use 2 while loops nested and structure is while(row<user){while(col<row)}
void print_triangle(int user){
    int row = 0;
    while(row<=user){
        int col = 0;
        while(col<row){
            cout<<"* ";
            col++;
        }
        cout<<endl;
        row++;
    }
}

int main(void){
    int user_input;
    cout<<"Enter number of row in triangle: ";
    cin>>user_input;
    cout<<endl;

    print_triangle(user_input);
    return 0;
}