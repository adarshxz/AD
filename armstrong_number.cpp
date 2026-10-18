#include <iostream>
#include <cmath>
#include <vector>

// Checks whether a given non-negative integer is an Armstrong (narcissistic) number
bool isArmstrongNumber(int num) {
    if (num < 0) return false;

    // Count number of digits
    int temp = num;
    int digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // 0 is typically considered an Armstrong number of 1 digit
    if (num == 0) return true;

    // Compute sum of digits raised to the power of number of digits
    temp = num;
    long long sum = 0;
    while (temp > 0) {
        int remainder = temp % 10;
        sum += std::round(std::pow(remainder, digits));
        temp /= 10;
    }

    return sum == num;
}

// Finds all Armstrong numbers within a given range [start, end]
std::vector<int> findArmstrongNumbers(int start, int end) {
    std::vector<int> results;
    for (int i = start; i <= end; ++i) {
        if (isArmstrongNumber(i)) {
            results.push_back(i);
        }
    }
    return results;
}

int main() {
    std::cout << "--- Armstrong Number Checker ---\n";
    int testCases[] = {153, 370, 371, 407, 1634, 9474, 123, 500};

    for (int n : testCases) {
        std::cout << n << " is "
                  << (isArmstrongNumber(n) ? "an Armstrong number" : "NOT an Armstrong number")
                  << "\n";
    }

    std::cout << "\n--- Armstrong Numbers Between 1 and 1000 ---\n";
    std::vector<int> armstrongList = findArmstrongNumbers(1, 1000);
    for (size_t i = 0; i < armstrongList.size(); ++i) {
        std::cout << armstrongList[i] << (i + 1 < armstrongList.size() ? ", " : "\n");
    }

    return 0;
}
