#include<iostream>
using namespace std;
/*same concept as "number_traingle_1" just change row<user to row<=user
and since the values on 
row 1 -> 1
row 2 -> 2
row 3 -> 3 
 we only need to print out the row number

 user input = 5

1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 

*/
void print_num_pattern(int user){
    
    while(user<=0){
        cout<<"Please Enter positive value: ";
        cin>>user;
        cout<<endl;
    }

    int row = 0;
    while(row<=user){
        int col =0;
        while(col<row){
            cout<<row<<" ";
            col++;
        }
        row++;
        cout<<endl;
    }
}

int main(void){
    int user_input;
    cout<<"Enter number of rows";
    cin>>user_input;
    cout<<endl;

    print_num_pattern(user_input);
    return 0;

}