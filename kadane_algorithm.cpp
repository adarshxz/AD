#include <iostream>
#include <vector>
#include <climits>

// Structure to store maximum subarray sum and its boundaries
struct SubarrayResult {
    int maxSum;
    int startIndex;
    int endIndex;
};

// Finds the maximum contiguous subarray sum using Kadane's Algorithm: O(n) time, O(1) space
SubarrayResult kadaneAlgorithm(const std::vector<int>& arr) {
    if (arr.empty()) {
        return {0, -1, -1};
    }

    int currentSum = 0;
    int maxSum = INT_MIN;
    int start = 0, tempStart = 0, end = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        currentSum += arr[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    return {maxSum, start, end};
}

int main() {
    int n;
    std::cout << "--- Maximum Subarray Sum (Kadane's Algorithm) ---\n";
    std::cout << "Enter the number of elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid array size! Must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers (can include negatives): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    SubarrayResult result = kadaneAlgorithm(arr);

    std::cout << "\n--- Results ---\n";
    std::cout << "Maximum Contiguous Subarray Sum: " << result.maxSum << "\n";
    std::cout << "Subarray Indices: [" << result.startIndex << " to " << result.endIndex << "]\n";
    std::cout << "Subarray Elements: ";
    for (int i = result.startIndex; i <= result.endIndex; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
