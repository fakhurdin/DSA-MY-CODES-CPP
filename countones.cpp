#include <iostream>
using namespace std;

int countOnes(unsigned int n) {
    if (n == 0) {
        return 0;
    } else {
        // Recursively count the ones in the remaining bits after right shifting
        return (n & 1) + countOnes(n >> 1);
    }
}

int main() {
    unsigned int number = 28;
    cout << "Number of ones in the binary representation of " << number << ": " << countOnes(number) << endl;
    return 0;
}

