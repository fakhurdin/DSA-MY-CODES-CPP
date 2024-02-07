#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& str) {
    std::stack<char> parenthesesStack;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            parenthesesStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (parenthesesStack.empty()) {
                return false; // Unmatched closing parenthesis
            }

            char top = parenthesesStack.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                parenthesesStack.pop(); // Matching opening parenthesis found
            } else {
                return false; // Mismatched parentheses
            }
        }
    }

    return parenthesesStack.empty(); // Check if all parentheses were matched
}

int main() {
    std::string input;
    std::cout << "Enter a string with parentheses: ";
    std::cin >> input;

    if (isBalanced(input)) {
        std::cout << "The parentheses are balanced." << std::endl;
    } else {
        std::cout << "The parentheses are not balanced." << std::endl;
    }

    return 0;
}

