#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string& str) {
        int left = 0;
        int right = str.length() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector< int > > palindromePairs(vector<string>& words) {
        vector< vector < int > > result;

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i != j) {
                    string concat = words[i] + words[j];
                    if (isPalindrome(concat)) {
                        result.push_back({i, j});
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<string> words1 = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<string> words2 = {"bat", "tab", "cat"};
    vector<string> words3 = {"a", ""};

    vector<vector<int>> result1 = solution.palindromePairs(words1);
    vector<vector<int>> result2 = solution.palindromePairs(words2);
    vector<vector<int>> result3 = solution.palindromePairs(words3);

    cout << "Palindrome pairs for words1: " << endl;
    for (const auto& pair : result1) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    cout << "Palindrome pairs for words2: " << endl;
    for (const auto& pair : result2) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    cout << "Palindrome pairs for words3: " << endl;
    for (const auto& pair : result3) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}

