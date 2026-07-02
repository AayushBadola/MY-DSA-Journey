#include <iostream>
#include <string>
#include <climits>
using namespace std;

int max_val(string user){
    
    int max =  INT_MIN;
    int user_len = user.length();



    // finding max value needed 1-> 26 (making charecotrs values A-1,B-2 .... Z-26)
    for(int indx = 0; indx < user_len;indx++){
        if(max< int(user[indx] - 'A')){max = int(user[indx] - 'A');}
    }

    return max;
}

int main(void){
    string user;
    cout<<"Enter string to find the frequency of letter: ";
    cin>>user;
    cout<<endl;
    int user_len = user.length();

    // user can NOT enter empty string 
    while(user.empty()){
        cout<<"Please enter a NON empty string: ";
        cin>>user;
        cout<<endl;
    }

    // normalize the user string to upper
    for(int indx = 0 ;indx<user_len;indx++){
        user[indx] = toupper(user[indx]);
    }

    // creating hash array
    int len_hash_array = max_val(user) + 1;
    int hash_array[len_hash_array] = {0};

    // storing string values based on 

    //storing frequency
    for(int indx = 0; indx<user_len;indx++){
        hash_array[int(user[indx] - 'A')] += 1;
    }

    // fetching the result 
    char user_char;
    cout<<"Enter charector to check its frequency: ";
    cin>>user_char;
    cout<<endl;
    user_char = toupper(user_char);

    cout<<"Frequency of "<<user_char<<" is "<<hash_array[int(user_char) - 'A'];
}