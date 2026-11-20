#include <iostream>
#include <vector>
#include <algorithm>

// Removes duplicates in-place from a sorted vector using the two-pointer approach.
// Returns the count of unique elements.
int removeDuplicatesSorted(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int uniqueIndex = 0; // Slow pointer

    for (size_t i = 1; i < nums.size(); ++i) { // Fast pointer
        if (nums[i] != nums[uniqueIndex]) {
            uniqueIndex++;
            nums[uniqueIndex] = nums[i];
        }
    }

    // Resize vector to only keep unique elements
    nums.resize(uniqueIndex + 1);
    return nums.size();
}

int main() {
    int n;
    std::cout << "--- Remove Duplicates from Array ---\n";
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid input! Size must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> nums(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::cout << "\nOriginal array: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";

    // Sort to apply the two-pointer in-place deduplication
    std::sort(nums.begin(), nums.end());
    std::cout << "Sorted array before deduplication: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";

    int uniqueCount = removeDuplicatesSorted(nums);

    std::cout << "\nNumber of unique elements: " << uniqueCount << "\n";
    std::cout << "Array after removing duplicates: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
