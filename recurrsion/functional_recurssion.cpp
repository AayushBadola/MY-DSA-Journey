// functional recurrsion is when we dont want to print we dont want to call the funciton recurrsively 
// and print values we WANT THEM TO RETURN A VALUE 
#include <iostream>
using namespace std;
int sum_to_n(int num){
    if(num == 0){return 0;}
    return num + sum_to_n(num - 1);
}
int main(void){
    int user_num;
    cout<<"Enter value till which you want sum: ";
    cin>>user_num;
    cout<<endl;

    int result = sum_to_n(user_num);
    cout<<"The sum is: "<<result;
    return 0;

}