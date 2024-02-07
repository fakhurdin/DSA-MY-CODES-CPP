#include <iostream>
#include <unordered_map>
using namespace std;

string smallestWindowSubstring(string S, string P) {
    if (S.empty() || P.empty() || S.length() < P.length()) {
        return "-1";
    }

    unordered_map<char, int> patternFreq, windowFreq;
    int required = 0;
    for (char c : P) {
        patternFreq[c]++;
        required++;
    }

    int left = 0, right = 0, formed = 0;
    int minLength = INT_MAX, minLeft = 0;
    while (right < S.length()) {
        char currentChar = S[right];
        windowFreq[currentChar]++;

        if (patternFreq.find(currentChar) != patternFreq.end() && windowFreq[currentChar] <= patternFreq[currentChar]) {
            formed++;
        }

        while (formed == required && left <= right) {
            if (minLength > right - left + 1) {
                minLength = right - left + 1;
                minLeft = left;
            }

            char leftChar = S[left];
            windowFreq[leftChar]--;
            if (patternFreq.find(leftChar) != patternFreq.end() && windowFreq[leftChar] < patternFreq[leftChar]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    if (minLength == INT_MAX) {
        return "-1";
    }

    return S.substr(minLeft, minLength);
}

int main() {
    string S = "timetopractice";
    string P = "toc";

    string result = smallestWindowSubstring(S, P);
    cout << "Output: " << result << endl;

    return 0;
}

