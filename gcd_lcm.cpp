#include <iostream>
#include <cmath>

// Computes Greatest Common Divisor (GCD) using the Euclidean algorithm
long long findGCD(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);

    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Computes Least Common Multiple (LCM) using GCD
long long findLCM(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }

    a = std::abs(a);
    b = std::abs(b);

    // Divide first to prevent potential integer overflow
    return (a / findGCD(a, b)) * b;
}

int main() {
    std::pair<long long, long long> testPairs[] = {
        {12, 18},
        {48, 180},
        {7, 13},
        {25, 0},
        {-15, 20}
    };

    std::cout << "--- GCD and LCM Calculator (Euclidean Algorithm) ---\n\n";

    for (const auto& pair : testPairs) {
        long long a = pair.first;
        long long b = pair.second;
        long long gcd = findGCD(a, b);
        long long lcm = findLCM(a, b);

        std::cout << "Numbers: (" << a << ", " << b << ")\n";
        std::cout << "  GCD: " << gcd << "\n";
        std::cout << "  LCM: " << lcm << "\n\n";
    }

    return 0;
}
