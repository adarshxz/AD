#include <iostream>
#include <vector>

// Finds the majority element using Boyer-Moore Voting Algorithm: O(n) time, O(1) space
// A majority element appears strictly more than n / 2 times in the array.
bool findMajorityElement(const std::vector<int>& nums, int& majority) {
    if (nums.empty()) return false;

    // Step 1: Find candidate
    int candidate = nums[0];
    int count = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Verify candidate
    int actualCount = 0;
    for (int num : nums) {
        if (num == candidate) {
            actualCount++;
        }
    }

    if (actualCount > static_cast<int>(nums.size() / 2)) {
        majority = candidate;
        return true;
    }

    return false;
}

int main() {
    int n;
    std::cout << "--- Majority Element (Boyer-Moore Voting Algorithm) ---\n";
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid array size! Must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::cout << "\nInput Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    int majorityElement;
    if (findMajorityElement(nums, majorityElement)) {
        std::cout << "Majority Element (> " << n / 2 << " times): " << majorityElement << std::endl;
    } else {
        std::cout << "No majority element found (no element appears more than " << n / 2 << " times)." << std::endl;
    }

    return 0;
}
