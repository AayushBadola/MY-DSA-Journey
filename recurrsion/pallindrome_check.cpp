// a pallindrome is when :
//its 1st and last charector is same,
//its 2nd and 2nd last are same,
//its 3rd and 3rd last are same and so on and so forth 

#include <iostream>
using namespace std;


//reversal of stirng function
void reversal(int initial,string &s, int final){
    if (initial >= final/2){return;}
    else{
        swap(s[initial], s[final - initial - 1]);
        reversal(initial + 1, s, final);
    }
}

bool check_pallindrome(string user){
    int len = user.length();
    
    // copy of original 
    string copy_user = user;
    // to check pallindrome we reverse the copy and compare it with original 
    // and everytime the charector of original !=  charector of copy we make count it 
    // if count is >= 1 then we say its not a pallindrome 

    //reversal of copy 
    reversal(0 ,copy_user, len);
    
    //check if the charectors of original and copy (after reversal) are same
    int not_same_count = 0;
    for(int indx = 0; indx <len; indx++){
        if(user[indx] != copy_user[indx]){not_same_count++;}
        
    }

    if (not_same_count >= 1){return false;}
    else {return true;}
}

int main(void){
    string user_input;
    cout<<"Enter String for pallindrome check: ";
    cin>>user_input;
    cout<<endl;

    if(check_pallindrome(user_input)){cout<<"Its a pallindrome"; return 0;}
    else{cout<<"Not a pallindrome"; return -1;}

}