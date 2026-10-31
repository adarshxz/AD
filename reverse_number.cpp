#include <iostream>

// Reverses the digits of an integer
long long reverseNumber(long long n) {
    long long reversed = 0;
    bool isNegative = n < 0;

    if (isNegative) {
        n = -n;
    }

    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    return isNegative ? -reversed : reversed;
}

int main() {
    long long num;
    std::cout << "Enter an integer: ";
    if (!(std::cin >> num)) {
        std::cerr << "Invalid input! Please enter a valid integer." << std::endl;
        return 1;
    }

    std::cout << "Original number: " << num << std::endl;
    std::cout << "Reversed number: " << reverseNumber(num) << std::endl;

    return 0;
}
