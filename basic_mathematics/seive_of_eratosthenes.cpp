#include <iostream>
#include <vector>
using namespace std;

int count_primes(int n) {
    int prime_count = 0;

    // Handle numbers less than or equal to 2
    if (n <= 2) {
        return 0;
    }

    // Assume all numbers are prime initially
    vector<bool> is_prime(n, true);

    // 0 and 1 are not prime numbers
    is_prime[0] = is_prime[1] = false;

    // Traverse all numbers from 2 to n-1
    for (int val = 2; val < n; val++) {

        // If the number is prime
        if (is_prime[val]) {
            prime_count++;

            // Mark all multiples of val as non-prime
            for (int indx = 2 * val; indx < n; indx += val) {
                is_prime[indx] = false;
            }
        }
    }

    // Return the total count of prime numbers
    return prime_count;
}

int main() {
    // Define the upper limit
    int n = 10;

    // Count prime numbers less than n
    int result = count_primes(n);

    // Display the result
    cout << "Number of primes less than " << n
         << ": " << result;

    return 0;
}