#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

// Finds indices of two numbers that add up to target: O(n) time, O(n) space
std::pair<int, int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex; // value -> index

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int complement = target - nums[i];

        // Check if complement is already present in the hash map
        auto it = numToIndex.find(complement);
        if (it != numToIndex.end()) {
            return {it->second, i};
        }

        // Store current element and its index
        numToIndex[nums[i]] = i;
    }

    return {-1, -1}; // No pair found
}

int main() {
    int n;
    std::cout << "--- Two Sum Problem (Hash Map O(n)) ---\n";
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n) || n < 2) {
        std::cerr << "Invalid input! Size must be at least 2." << std::endl;
        return 1;
    }

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int target;
    std::cout << "Enter target sum: ";
    if (!(std::cin >> target)) {
        std::cerr << "Invalid target input!" << std::endl;
        return 1;
    }

    std::pair<int, int> result = twoSum(nums, target);

    if (result.first != -1) {
        std::cout << "\nPair found!\n";
        std::cout << "Indices: [" << result.first << ", " << result.second << "]\n";
        std::cout << "Values:  " << nums[result.first] << " + " << nums[result.second]
                  << " = " << target << std::endl;
    } else {
        std::cout << "\nNo two elements sum up to " << target << "." << std::endl;
    }

    return 0;
}
