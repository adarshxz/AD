#include <iostream>
#include <vector>

// Calculates distinct ways to climb n stairs taking 1 or 2 steps: O(n) time, O(1) space
long long climbStairsOptimized(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long prev2 = 1; // ways(1)
    long long prev1 = 2; // ways(2)
    long long current = 0;

    for (int i = 3; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

// Tabulation approach generating all step counts up to n: O(n) time, O(n) space
std::vector<long long> climbStairsTable(int n) {
    if (n <= 0) return {};
    std::vector<long long> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp;
}

int main() {
    int n;
    std::cout << "--- Climbing Stairs (Dynamic Programming) ---\n";
    std::cout << "You can climb either 1 or 2 steps at a time.\n";
    std::cout << "Enter the number of steps (n): ";

    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid input! Number of steps must be a positive integer." << std::endl;
        return 1;
    }

    long long ways = climbStairsOptimized(n);

    std::cout << "\nDistinct ways to reach the top of " << n << " stairs: " << ways << std::endl;

    if (n <= 20) {
        std::vector<long long> table = climbStairsTable(n);
        std::cout << "\nBreakdown by step:\n";
        for (int i = 1; i <= n; ++i) {
            std::cout << "Step " << i << ": " << table[i] << " ways\n";
        }
    }

    return 0;
}
