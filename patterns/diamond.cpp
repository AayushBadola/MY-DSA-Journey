#include <iostream>
using namespace std;

void print_diamond(int user){
    if(user%2 == 0){
        // code for even to derive
        cout<<"To be tested ";
        return;
    }

    else{
        //code for odd to derive

        int ref = user/2;
        
        
        
        // normal pyramid using upper_user
        int row_upper= 0;

        while(row_upper <= ref){

        // print left spaces
        int space = 0;

        while(space < ref-row_upper-1){
            cout<<" ";
            space++;
        }

        // print stars
        int star = 0;

        while(star < 2*row_upper+1){
            cout<<"*";
            star++;
        }

        cout<<endl;

        row_upper++;
    }
    
    // code for inverted 
    int row_lower = 0;
        while(row_lower <= ref){

        // spaces increase every row
        int space = 0;

        while(space < row_lower){
            cout<<" ";
            space++;
        }

        // stars decrease every row
        int star = 0;

        while(star < 2*(ref-row_lower)-1){
            cout<<"*";
            star++;
        }

        cout<<endl;

        row_lower++;
    }
}
}

int main(void){
    int user_input;
    cout<<"Enter total number of rows";
    cin>>user_input;
    print_diamond(user_input);
}