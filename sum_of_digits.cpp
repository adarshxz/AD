#include <iostream>
#include <cstdlib>

// Computes the sum of digits iteratively
int sumOfDigitsIterative(long long n) {
    n = std::abs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Computes the sum of digits recursively
int sumOfDigitsRecursive(long long n) {
    n = std::abs(n);
    if (n == 0) return 0;
    return (n % 10) + sumOfDigitsRecursive(n / 10);
}

// Computes the digital root (repeated sum of digits until a single digit remains)
int digitalRoot(long long n) {
    n = std::abs(n);
    if (n == 0) return 0;
    int sum = sumOfDigitsIterative(n);
    while (sum >= 10) {
        sum = sumOfDigitsIterative(sum);
    }
    return sum;
}

int main() {
    long long number;
    std::cout << "Enter an integer: ";
    if (!(std::cin >> number)) {
        std::cerr << "Invalid input! Please enter a valid integer." << std::endl;
        return 1;
    }

    std::cout << "--- Results ---" << std::endl;
    std::cout << "Number: " << number << std::endl;
    std::cout << "Sum of digits (Iterative): " << sumOfDigitsIterative(number) << std::endl;
    std::cout << "Sum of digits (Recursive): " << sumOfDigitsRecursive(number) << std::endl;
    std::cout << "Digital Root: " << digitalRoot(number) << std::endl;

    return 0;
}
