#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    string revString(string s) {
        return {s[1], s[0]};
    }

public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int reserve = 0;
        int count = 0;

        for (auto i : words) {
            mp[i]++;
        }

        for (auto j : mp) {
            string word = j.first;

            if (word[0] == word[1]) {
                count += mp[word] - (mp[word] & 1);
                reserve += mp[word] & 1;
            } else {
                string revWord = revString(word);
                int match_count = min(mp[word], mp[revWord]);
                count += 2 * match_count;
                mp[word] -= match_count;
                mp[revWord] -= match_count;
            }
        }

        if (reserve >= 1) {
            count++;
        }

        return count * 2;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"oo", "vv", "uu", "gg", "pp", "ff", "ss", "yy", "vv", "cc", "rr", "ig", "jj", "uu", "ig", "gb", "zz", "xx", "ff", "bb", "ii", "dd", "ii", "ee", "mm", "qq", "ig", "ww", "ss", "tt", "vv", "oo", "ww", "ss", "bi", "ff", "gg", "bi", "jj", "ee", "gb", "qq", "bg", "nn", "vv", "oo", "bb", "pp", "ww", "qq", "mm", "ee", "tt", "hh", "ss", "tt", "ee", "gi", "ig", "uu", "ff", "zz", "ii", "ff", "ss", "gi", "yy", "gb", "mm", "pp", "uu", "kk", "jj", "ee"};

    int result = sol.longestPalindrome(words);
    cout << "Longest Palindrome: " << result << endl;

    return 0;
}

