#include <cstdlib>
#include <iostream>

int main() {
    int number;

    std::cout << "Enter an integer: ";
    std::cin >> number;

    int digits = 1;
    for (number = std::abs(number); number >= 10; number /= 10) {
        ++digits;
    }

    std::cout << "Number of digits: " << digits << std::endl;
    return 0;
}
