#include <iostream>
#include <vector>

// Function to print elements of a vector
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

// Optimized Bubble Sort algorithm
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, array is sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array:\n";
    printArray(numbers);

    bubbleSort(numbers);

    std::cout << "\nSorted array (ascending order):\n";
    printArray(numbers);

    return 0;
}
