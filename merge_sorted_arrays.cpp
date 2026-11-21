#include <iostream>
#include <vector>

// Merges two sorted vectors into a single sorted vector in O(n + m) time
std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged;
    merged.reserve(arr1.size() + arr2.size());

    size_t i = 0; // Pointer for arr1
    size_t j = 0; // Pointer for arr2

    // Compare elements from both arrays and insert the smaller one
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Append remaining elements of arr1 (if any)
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Append remaining elements of arr2 (if any)
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    int n, m;

    std::cout << "--- Merge Two Sorted Arrays ---\n";
    std::cout << "Enter size of first sorted array: ";
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Invalid input for array size!" << std::endl;
        return 1;
    }

    std::vector<int> arr1(n);
    if (n > 0) {
        std::cout << "Enter " << n << " sorted integers for first array: ";
        for (int i = 0; i < n; ++i) {
            std::cin >> arr1[i];
        }
    }

    std::cout << "Enter size of second sorted array: ";
    if (!(std::cin >> m) || m < 0) {
        std::cerr << "Invalid input for array size!" << std::endl;
        return 1;
    }

    std::vector<int> arr2(m);
    if (m > 0) {
        std::cout << "Enter " << m << " sorted integers for second array: ";
        for (int j = 0; j < m; ++j) {
            std::cin >> arr2[j];
        }
    }

    std::cout << "\nFirst Array:  ";
    printVector(arr1);
    std::cout << "Second Array: ";
    printVector(arr2);

    std::vector<int> result = mergeSortedArrays(arr1, arr2);

    std::cout << "\nMerged Sorted Array: ";
    printVector(result);

    return 0;
}
