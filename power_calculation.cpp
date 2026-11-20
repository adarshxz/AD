#include <iostream>
#include <iomanip>

// Computes base^exp in O(log n) time using binary exponentiation (fast power)
double fastPower(double base, long long exp) {
    if (exp == 0) return 1.0;

    // Handle negative exponents
    long long n = exp;
    if (n < 0) {
        base = 1.0 / base;
        n = -n;
    }

    double result = 1.0;
    double currentProduct = base;

    while (n > 0) {
        if (n % 2 == 1) {
            result *= currentProduct;
        }
        currentProduct *= currentProduct;
        n /= 2;
    }

    return result;
}

// Naive O(n) iterative power for comparison
double naivePower(double base, long long exp) {
    if (exp == 0) return 1.0;

    long long n = exp;
    if (n < 0) {
        base = 1.0 / base;
        n = -n;
    }

    double result = 1.0;
    for (long long i = 0; i < n; ++i) {
        result *= base;
    }

    return result;
}

int main() {
    double base;
    long long exponent;

    std::cout << "--- Power Calculation (Fast Exponentiation) ---\n";
    std::cout << "Enter base: ";
    if (!(std::cin >> base)) {
        std::cerr << "Invalid base input!" << std::endl;
        return 1;
    }

    std::cout << "Enter exponent (integer): ";
    if (!(std::cin >> exponent)) {
        std::cerr << "Invalid exponent input!" << std::endl;
        return 1;
    }

    if (base == 0.0 && exponent <= 0) {
        std::cerr << "Error: 0 raised to non-positive exponent is undefined!" << std::endl;
        return 1;
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\nResults:\n";
    std::cout << base << " ^ " << exponent << " = " << fastPower(base, exponent) << std::endl;

    return 0;
}
