#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

std::string postfixToInfix(const std::string& postfix) {
    std::stack<std::string> stack;
    for (char c : postfix) {
        if (!isOperator(c)) {
            stack.push(std::string(1, c)); // Operand, push onto stack
        } else {
            std::string operand2 = stack.top();
            stack.pop();
            std::string operand1 = stack.top();
            stack.pop();
            stack.push("(" + operand1 + " " + c + " " + operand2 + ")");
        }
    }
    return stack.top();
}

int main() {
    std::string postfixExpr = "ab+cd-*";
    std::string infixExpr = postfixToInfix(postfixExpr);
    std::cout << "Infix expression: " << infixExpr << std::endl;

    return 0;
}

