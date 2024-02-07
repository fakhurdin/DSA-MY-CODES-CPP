#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string firstNonRepeatingCharacter(const string& A) {
    queue<char> charQueue;
    unordered_map<char, int> charFreq;

    string result = "";

    for (char c : A) {
        charQueue.push(c);
        charFreq[c]++;

        while (!charQueue.empty() && charFreq[charQueue.front()] > 1) {
            charQueue.pop();
        }

        if (charQueue.empty()) {
            result += '#';
        } else {
            result += charQueue.front();
        }
    }

    return result;
}

int main() {
    string A = "aabc";
    string output = firstNonRepeatingCharacter(A);
    cout << "Output: " << output << endl;

    return 0;
}

