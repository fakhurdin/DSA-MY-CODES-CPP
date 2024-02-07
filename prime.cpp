#include <iostream>
#include <vector>
using namespace std;

void primeFactorization(int n) {
    vector<int> primes; // To store prime factors

    // Find all 2's that divide n
    while (n % 2 == 0) {
        primes.push_back(2);
        n /= 2;
    }

    // Find other prime factors (odd numbers)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }

    // If n is a prime greater than 2
    if (n > 2) {
        primes.push_back(n);
    }

    // Display prime factors in descending order
    cout << "Prime factors in descending order: ";
    for (int i = primes.size() - 1; i >= 0; --i) {
        cout << primes[i];
        if (i > 0) {
            cout << " * ";
        }
    }
    cout << endl;
}

int main() {
    int n = 3960;
    cout << "Prime factorization of " << n << " is:" << endl;
    primeFactorization(n);

    return 0;
}

