#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// there is a sentance that is "Hello I am Aayush" --> IT BECOMES :
// olleH I ma hsuyaA

// we need to just reverse the given string BUT making sure we make the spaces and gaps consistent 


// for a string "My name is Ansh"
// we first traverse the string


// current word
// |
// My name is Ansh
// |
// not a space increent 

// start of word
// |
// My name is Ansh
//  |
// not a space increment 


// start of word
// |
// My name is Ansh
//   |
// space found the word which we traversed gets reversed 
// 

// now we reverse the word from pointer start of word to current element - 1

// after reversal we will swith the start of word pointer to the next word that is current pointer + 1 

// if we reach "\0" reverse the word 

void reverse_word(string &s,int start, int end){
    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}

void reverse_string(string &s){
    int word_start = 0;
    for(int indx = 0; indx<= (int) s.length(); indx++){
        if(s[indx] == ' ' || indx == s.length()){
            reverse_word(s,word_start,indx - 1);
            word_start = indx+1;

        }

    }

}

int main(void){
    string test = "Hello i am Ansh"; // olleH i ma hsnA
    cout<<"Current string: "<<test<<endl;

    reverse_string(test);

    cout<<"Reversed string: "<<test<<endl;

    cout<<"Expected string: olleH i ma hsnA"<<endl;

    return 0;
}


