#include <iostream>
#include <vector>

// Prints all elements of a vector
void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? ", " : "\n");
    }
}

// Merges two sorted subarrays arr[left..mid] and arr[mid+1..right]
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function (Divide and Conquer)
// Time Complexity: O(n log n) in all cases (best, average, worst)
// Space Complexity: O(n) auxiliary space
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> numbers = {38, 27, 43, 3, 9, 82, 10, -5, 19};

    std::cout << "--- Merge Sort in C++ (Divide & Conquer) ---\n\n";
    std::cout << "Original array:\n";
    printArray(numbers);

    if (!numbers.empty()) {
        mergeSort(numbers, 0, numbers.size() - 1);
    }

    std::cout << "\nSorted array (ascending):\n";
    printArray(numbers);

    return 0;
}
