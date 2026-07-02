#include <iostream>
using namespace std;
int print_fibbonaci(int N){
    if(N<= 1){return 0;}
    else{
        return print_fibbonaci(N-1) + print_fibbonaci(N-2);
    }
}

int main(void){
    int user = 5;
    print_fibbonaci(5);

}