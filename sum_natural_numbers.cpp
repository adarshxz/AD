#include <iostream>

int main() {
    int limit;

    std::cout << "Enter a positive integer: ";
    std::cin >> limit;

    int sum = 0;
    for (int number = 1; number <= limit; ++number) {
        sum += number;
    }

    std::cout << "Sum from 1 to " << limit << " is " << sum << std::endl;
    return 0;
}
