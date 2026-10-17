#include <iostream>

// Calculates factorial using an iterative approach
long long factorialIterative(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }

    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Calculates factorial using a recursive approach
long long factorialRecursive(int n) {
    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main() {
    int testValues[] = {0, 1, 5, 7, 10, -3};

    std::cout << "--- Factorial Calculation in C++ ---\n\n";

    for (int num : testValues) {
        long long iterResult = factorialIterative(num);
        long long recResult = factorialRecursive(num);

        if (iterResult == -1) {
            std::cout << "Factorial of " << num << ": Not defined (negative number)\n";
        } else {
            std::cout << "Factorial of " << num << ":\n";
            std::cout << "  Iterative result: " << iterResult << "\n";
            std::cout << "  Recursive result: " << recResult << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
