#include <iostream>
#include <vector>

// Function for Iterative Binary Search
// Returns index of target if present, otherwise returns -1
int binarySearchIterative(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// Function for Recursive Binary Search
int binarySearchRecursive(const std::vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] > target) {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }

    return binarySearchRecursive(arr, mid + 1, right, target);
}

int main() {
    std::vector<int> numbers = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};

    std::cout << "Sorted Array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    int target1 = 23;
    int target2 = 50;

    // Test Iterative Binary Search
    std::cout << "--- Iterative Binary Search ---\n";
    int index1 = binarySearchIterative(numbers, target1);
    if (index1 != -1) {
        std::cout << "Element " << target1 << " found at index: " << index1 << "\n";
    } else {
        std::cout << "Element " << target1 << " not found in array.\n";
    }

    int index2 = binarySearchIterative(numbers, target2);
    if (index2 != -1) {
        std::cout << "Element " << target2 << " found at index: " << index2 << "\n";
    } else {
        std::cout << "Element " << target2 << " not found in array.\n";
    }

    // Test Recursive Binary Search
    std::cout << "\n--- Recursive Binary Search ---\n";
    int index3 = binarySearchRecursive(numbers, 0, numbers.size() - 1, target1);
    if (index3 != -1) {
        std::cout << "Element " << target1 << " found at index: " << index3 << "\n";
    } else {
        std::cout << "Element " << target1 << " not found in array.\n";
    }

    return 0;
}
