/*TASK 2
SIMPLE CALCULATOR
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Calculator {
private:
    double memory;  // Store the result in memory

public:
    Calculator() : memory(0.0) {}  // Initialize memory to 0

    // Function to add multiple numbers
    double add(vector<double>& numbers) {
        double sum = 0;
        for (double num : numbers) {
            sum += num;
        }
        return sum;
    }

    // Function to subtract multiple numbers
    double subtract(vector<double>& numbers) {
        double result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            result -= numbers[i];
        }
        return result;
    }

    // Function to multiply multiple numbers
    double multiply(vector<double>& numbers) {
        double product = 1;
        for (double num : numbers) {
            product *= num;
        }
        return product;
    }

    // Function to divide two numbers
    double divide(double a, double b) {
        if (b == 0) {
            cout << "Error! Division by zero.\n";
            return 0;
        }
        return a / b;
    }

    // Function to compute the square root
    double squareRoot(double a) {
        if (a < 0) {
            cout << "Error! Square root of a negative number.\n";
            return 0;
        }
        return sqrt(a);
    }

    // Function to compute the exponential (a raised to the power of b)
    double exponential(double a, double b) {
        return pow(a, b);
    }

    // Function to compute the percentage (a percent of b)
    double percentage(double a, double b) {
        return (a / 100) * b;
    }

    // Function to perform memory addition (M++)
    void addToMemory(double value) {
        memory += value;
    }

    // Function to clear memory (AC)
    void clearMemory() {
        memory = 0.0;
        cout << "Memory cleared.\n";
    }

    // Function to get the current memory value
    double getMemory() const {
        return memory;
    }

    // Function to perform the chosen operation on multiple numbers
    double performOperation(vector<double>& numbers, int op) {
        switch (op) {
        case 1:
            return add(numbers);
        case 2:
            return subtract(numbers);
        case 3:
            return multiply(numbers);
        default:
            cout << "Invalid operation!\n";
            return 0;
        }
    }
};

int main() {
    Calculator calc;
    double num1, num2, result;
    vector<double> numbers;  // To store multiple numbers
    int operation, count;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "\nMemory: " << calc.getMemory() << endl;
        cout << "Choose an operation:\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Square Root\n";
        cout << "6. Exponential (^)\n";
        cout << "7. Percentage (%)\n";
        cout << "8. Add result to memory (M++)\n";
        cout << "9. Clear memory (AC)\n";
        cout << "Enter your choice: ";
        cin >> operation;

        if (operation == 8) {
            // Add to memory
            cout << "Enter a value to add to memory: ";
            cin >> num1;
            calc.addToMemory(num1);
            cout << "Updated memory: " << calc.getMemory() << endl;
        } else if (operation == 9) {
            // Clear memory
            calc.clearMemory();
        } else if (operation == 4 || operation == 5 || operation == 6 || operation == 7) {
            // For single operations like division, square root, exponential, percentage
            if (operation == 5) {
                cout << "Enter the number for square root: ";
                cin >> num1;
                result = calc.squareRoot(num1);
            } else if (operation == 6) {
                cout << "Enter the base: ";
                cin >> num1;
                cout << "Enter the exponent: ";
                cin >> num2;
                result = calc.exponential(num1, num2);
            } else if (operation == 7) {
                cout << "Enter the percentage value: ";
                cin >> num1;
                cout << "Enter the total value: ";
                cin >> num2;
                result = calc.percentage(num1, num2);
            } else {
                cout << "Enter the dividend: ";
                cin >> num1;
                cout << "Enter the divisor: ";
                cin >> num2;
                result = calc.divide(num1, num2);
            }
            cout << "Result: " << result << endl;
            calc.addToMemory(result);
        } else {
            // For operations that handle multiple values (addition, subtraction, multiplication)
            cout << "How many numbers do you want to input? ";
            cin >> count;

            numbers.clear();  // Clear previous numbers
            for (int i = 0; i < count; ++i) {
                cout << "Enter number " << i + 1 << ": ";
                cin >> num1;
                numbers.push_back(num1);
            }

            result = calc.performOperation(numbers, operation);
            cout << "Result: " << result << endl;
            calc.addToMemory(result);
        }

        // Ask if the user wants to perform another operation
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;
    }

    cout << "Thanks for using the calculator!\n";
    return 0;
}
