#include <iostream>
#include <iomanip>

int main() {
    double a, b;
    char op;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Enter expression (e.g., 3.5 + 2): ";
    std::cin >> a >> op >> b;

    double result;
    bool valid = true;
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                std::cerr << "Error: Division by zero" << std::endl;
                return 1;
            }
            result = a / b; break;
        default:
            std::cerr << "Invalid operator. Use +, -, *, or /." << std::endl;
            return 1;
    }

    std::cout << a << " " << op << " " << b << " = " << result << std::endl;
    return 0;
}
