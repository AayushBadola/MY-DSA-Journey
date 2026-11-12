#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// we are given a string "abcdaa" we know "a" is occuring 3 times so its max
// we can create a hash array mapping each cell to a charector 
// a-> 0
// b->1
// c->2
// d-> 3
// and so on 
// after traversing teh array and storing the frequency of each charector in the array we will run a max  value in array algo 
// it will provide us with the max value 
// we will then find which char had tat max value

// hash array size is 26 as 26 letters in alphabet


int max_val_arr(int nums[], int size){
    int max = INT_MIN;
    int max_indx =  -1;
    for(int indx= 0;indx<size; indx++){
        if(nums[indx] > max){
            max = nums[indx];
            max_indx = indx;
            
        }
    }
    return max_indx;
}

char max_occ_char(string &s){

    int hash_arr[26] = {0};

    // making array all lower cases
    for(int indx = 0; indx<s.length();indx++){
        s[indx] = tolower(s[indx]);
    }

    // storing the frequency 
    for(int indx = 0; indx<s.length();indx++){
        hash_arr[ ( (int)s[indx] ) - 97] ++;
    }

    int char_indx = max_val_arr(hash_arr, 26);

    char max_char = 'a' + ((char) char_indx);

    return max_char;

}

int main(void){
    string test = "cdbejdbba";
    char max_occ = max_occ_char(test);
    cout<<"Max occ char is: "<<max_occ;

    return 0;
}