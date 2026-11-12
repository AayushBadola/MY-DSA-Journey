#include <iostream>
using namespace std;

// the end of string is denoted by '/0' 
// string = Aayush 
// in memory its [A|a|y|u|s|h] \0

int get_string_len(char string[]){
    int length = 0;

    for(int indx = 0; string[indx] != '\0'; indx++){   
        length++;

    }
    return length;

}

int main(void){
    char string[20];
    cout<<"Enter a name or word: ";
    cin>>string;
    cout<<endl;
    cout<<"Give word with length : "<<get_string_len(string);

    return 0;
}