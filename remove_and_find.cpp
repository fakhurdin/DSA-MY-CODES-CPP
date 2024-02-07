#include <iostream>
#include <vector>
#include <stack>

std::vector<int> dailyWarmerTemp(const std::vector<int>& temperatures) {
    std::stack<int> stack;
    std::vector<int> result(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); ++i) {
        while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
            int idx = stack.top();
            stack.pop();
            result[idx] = i - idx;
        }
        stack.push(i);
    }
    return result;
}

int main() {
    std::vector<int> temperatures = {30, 40, 50, 60};
    std::vector<int> answer = dailyWarmerTemp(temperatures);

    std::cout << "Output: ";
    for (int num : answer) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
//remove
#include <iostream>
#include <stack>
#include <unordered_set>

std::string removeDuplicateLetters(const std::string& s) {
    std::stack<char> stack;
    std::unordered_set<char> seen;
    std::unordered_map<char, int> lastOccur;

    for (int i = 0; i < s.size(); ++i) {
        lastOccur[s[i]] = i;
    }

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (seen.find(c) == seen.end()) {
            while (!stack.empty() && c < stack.top() && i < lastOccur[stack.top()]) {
                seen.erase(stack.top());
                stack.pop();
            }
            stack.push(c);
            seen.insert(c);
        }
    }

    std::string result;
    while (!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }
    return result;
}

int main() {
    std::string s = "bcabc";
    std::string result = removeDuplicateLetters(s);
    std::cout << "Output: " << result << std::endl;

    return 0;
}

