#include <iostream>
#include <vector>

// Checks whether a given positive integer is a perfect number.
// A perfect number is equal to the sum of its proper positive divisors (excluding itself).
bool isPerfectNumber(long long num) {
    if (num <= 1) return false;

    long long sum = 1; // 1 is always a proper divisor for num > 1

    for (long long i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }

    return sum == num;
}

// Finds all perfect numbers up to a given limit
std::vector<long long> findPerfectNumbers(long long limit) {
    std::vector<long long> results;
    for (long long i = 2; i <= limit; ++i) {
        if (isPerfectNumber(i)) {
            results.push_back(i);
        }
    }
    return results;
}

int main() {
    std::cout << "--- Perfect Number Checker ---\n";

    long long num;
    std::cout << "Enter a positive integer: ";
    if (std::cin >> num) {
        if (isPerfectNumber(num)) {
            std::cout << num << " is a perfect number!\n";
        } else {
            std::cout << num << " is NOT a perfect number.\n";
        }
    } else {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    std::cout << "\nFirst few known perfect numbers up to 10000:\n";
    std::vector<long long> perfects = findPerfectNumbers(10000);
    for (size_t i = 0; i < perfects.size(); ++i) {
        std::cout << perfects[i] << (i + 1 < perfects.size() ? ", " : "\n");
    }

    return 0;
}
