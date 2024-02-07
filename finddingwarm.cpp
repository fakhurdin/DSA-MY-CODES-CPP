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

