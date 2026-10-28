#include <iostream>
#include <vector>
#include <string>

// Finds the first occurrence of target in arr. Returns index if found, -1 otherwise.
int linearSearchFirst(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// Finds all occurrences of target in arr. Returns a vector of matching indices.
std::vector<int> linearSearchAll(const std::vector<int>& arr, int target) {
    std::vector<int> indices;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            indices.push_back(static_cast<int>(i));
        }
    }
    return indices;
}

int main() {
    std::vector<int> numbers = {15, 23, 7, 42, 19, 23, 88, 23, 5};

    std::cout << "--- Linear Search in C++ ---\n\n";
    std::cout << "Array elements: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << (i + 1 < numbers.size() ? ", " : "\n");
    }

    int target1 = 23;
    int target2 = 99;

    // Search for first occurrence
    std::cout << "\n1. First Occurrence Search:\n";
    int firstIdx1 = linearSearchFirst(numbers, target1);
    if (firstIdx1 != -1) {
        std::cout << "Target " << target1 << " first found at index: " << firstIdx1 << "\n";
    } else {
        std::cout << "Target " << target1 << " not found in array.\n";
    }

    int firstIdx2 = linearSearchFirst(numbers, target2);
    if (firstIdx2 != -1) {
        std::cout << "Target " << target2 << " first found at index: " << firstIdx2 << "\n";
    } else {
        std::cout << "Target " << target2 << " not found in array.\n";
    }

    // Search for all occurrences
    std::cout << "\n2. Multiple Occurrence Search:\n";
    std::vector<int> allIndices = linearSearchAll(numbers, target1);
    std::cout << "Target " << target1 << " found " << allIndices.size() << " time(s) at indices: ";
    for (size_t i = 0; i < allIndices.size(); ++i) {
        std::cout << allIndices[i] << (i + 1 < allIndices.size() ? ", " : "\n");
    }

    return 0;
}
