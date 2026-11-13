#include <iostream>

int main() {
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    for (int multiplier = 1; multiplier <= 10; ++multiplier) {
        std::cout << number << " x " << multiplier << " = " << number * multiplier << std::endl;
    }

    return 0;
}
