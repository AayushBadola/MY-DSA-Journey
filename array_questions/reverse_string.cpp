#include <iostream>
using namespace std;

int get_string_len(char string[]){
    int length = 0;

    for(int indx = 0; string[indx] != '\0'; indx++){   
        length++;

    }
    return length;

}

void reverse_string(char string[]){
    int string_start = 0;
    int string_end = get_string_len(string) - 1;
    while(string_start < string_end){
        swap(string[string_start],string[string_end]);
        string_start++;
        string_end--;
    }


}


int main(void){
    char string[20];
    cout<<"Enter a name or word: ";
    cin>>string;
    cout<<endl;

    cout<<"Current string: ";
    for(char val : string){
        cout<<val<<" ";
    }
    cout<<endl;

    reverse_string(string);
    cout<<"Reversed string: ";
    for(char val: string){
        cout<<val<<" ";
    }


}