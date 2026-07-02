// PRIME NUMBER USING 6k ± 1 OPTIMIZATION

// A prime number is divisible ONLY by:
// 1 and itself

// examples:
// 2, 3, 5, 7, 11, 13 ...

// non-prime examples:
// 4 -> divisible by 1, 2, 4
// 9 -> divisible by 1, 3, 9

// OBSERVATION:
//
// every prime number greater than 3
// is of the form:
//
// 6k - 1
// or
// 6k + 1
//
// however NOT every 6k ± 1 number is prime
//
// example:
// 25 = 6(4) + 1
// but 25 is NOT prime

#include <iostream>
using namespace std;

void check_prime(int user){

    // numbers <= 1 are not prime
    if(user <= 1){
        cout << "Not a prime";
        return;
    }

    // 2 and 3 are prime numbers
    else if(user <= 3){
        cout << "Prime";
        return;
    }

    // if divisible by 2 or 3
    // number cannot be prime
    else if(user % 2 == 0){
        cout << "Not a prime";
        return;
    }

    else if(user % 3 == 0){
        cout << "Not a prime";
        return;
    }

    else{

        // start checking from 5
        // and move in jumps of 6:
        //
        // 5, 11, 17, 23 ...
        //
        // for each factor check:
        // factor      -> 6k - 1
        // factor + 2  -> 6k + 1
        //
        // example:
        // 5 & 7
        // 11 & 13
        // 17 & 19

        for(int factor = 5;
            factor * factor <= user;
            factor += 6){

            // factor*factor <= user
            // is faster than:
            // factor <= sqrt(user)

            // if any factor divides user
            // then number is not prime

            if(user % factor == 0 ||
               user % (factor + 2) == 0){

                cout << "Not a prime";
                return;
            }
        }

        // if no factor found
        // then number is prime

        cout << user << " is a prime number";
        return;
    }
}

int main(void){

    int user_input;

    cout << "Enter number to check if its prime: ";
    cin >> user_input;
    cout << endl;

    check_prime(user_input);

    return 0;
}