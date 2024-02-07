#include <iostream>
using namespace std;

int main() {
    try {
        
        double numerator, denominator;
        cout << "Enter the numerator: ";
        cin >> numerator;

        cout << "Enter the denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            throw "Division by zero error";
        }

        double result = numerator / denominator;
        cout << "Result of division: " << result << endl;
    } catch (const char* error) {

        cout << "Error: " << error << endl;

    } catch (...) {

        cout << "An unknown error occurred" << endl;
    }

    return 0;
}
