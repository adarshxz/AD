#include <iostream>
#include <vector>
#include <numeric>

// Finds the missing number using Gauss' summation formula: O(n) time, O(1) space
long long findMissingBySum(const std::vector<int>& nums, long long n) {
    long long expectedSum = n * (n + 1) / 2;
    long long actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    return expectedSum - actualSum;
}

// Finds the missing number using XOR bitwise operations: O(n) time, O(1) space, no overflow risk
int findMissingByXOR(const std::vector<int>& nums, int n) {
    int xorAll = 0;
    for (int i = 1; i <= n; ++i) {
        xorAll ^= i;
    }
    int xorArray = 0;
    for (int num : nums) {
        xorArray ^= num;
    }
    return xorAll ^ xorArray;
}

int main() {
    int n;
    std::cout << "--- Find Missing Number (1 to N) ---\n";
    std::cout << "Enter the value of N (range 1 to N): ";
    if (!(std::cin >> n) || n <= 1) {
        std::cerr << "Invalid N! N must be an integer greater than 1." << std::endl;
        return 1;
    }

    std::vector<int> nums(n - 1);
    std::cout << "Enter " << (n - 1) << " distinct integers from 1 to " << n << ": ";
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> nums[i];
    }

    long long missingSum = findMissingBySum(nums, n);
    int missingXOR = findMissingByXOR(nums, n);

    std::cout << "\nResults:\n";
    std::cout << "Missing number (via Sum formula): " << missingSum << "\n";
    std::cout << "Missing number (via Bitwise XOR): " << missingXOR << "\n";

    return 0;
}
