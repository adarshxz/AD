#include <iostream>
#include <vector>

// Prints all elements of a vector
void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? ", " : "\n");
    }
}

// Sorts an array using Selection Sort algorithm
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        // Find the index of the minimum element in the unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of unsorted portion
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    std::vector<int> numbers = {64, 25, 12, 22, 11, 90, 34};

    std::cout << "--- Selection Sort in C++ ---\n\n";
    std::cout << "Original array:\n";
    printArray(numbers);

    selectionSort(numbers);

    std::cout << "\nSorted array (ascending):\n";
    printArray(numbers);

    return 0;
}
