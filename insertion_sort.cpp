#include <iostream>
#include <vector>

// Prints all elements of a vector
void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? ", " : "\n");
    }
}

// Sorts an array using Insertion Sort algorithm
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> numbers = {29, 10, 14, 37, 13, 5, 42, 8};

    std::cout << "--- Insertion Sort in C++ ---\n\n";
    std::cout << "Original array:\n";
    printArray(numbers);

    insertionSort(numbers);

    std::cout << "\nSorted array (ascending):\n";
    printArray(numbers);

    return 0;
}
