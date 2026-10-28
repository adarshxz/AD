#include <iostream>
#include <vector>

// Prints all elements of a vector
void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? ", " : "\n");
    }
}

// Partitions the array using Lomuto partition scheme
// Chooses the last element as the pivot, places pivot in correct sorted position,
// and places smaller elements to the left, larger to the right.
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive Quick Sort function (Divide and Conquer)
// Average / Best Time Complexity: O(n log n)
// Worst-case Time Complexity: O(n^2)
// Auxiliary Space: O(log n) call stack
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is at the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> numbers = {10, 80, 30, 90, 40, 50, 70, -5, 30};

    std::cout << "--- Quick Sort in C++ (Divide & Conquer) ---\n\n";
    std::cout << "Original array:\n";
    printArray(numbers);

    if (!numbers.empty()) {
        quickSort(numbers, 0, numbers.size() - 1);
    }

    std::cout << "\nSorted array (ascending):\n";
    printArray(numbers);

    return 0;
}
