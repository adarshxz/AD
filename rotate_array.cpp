#include <iostream>
#include <vector>
#include <algorithm>

// Reverses elements in arr from index [start] to [end]
void reverseRange(std::vector<int>& arr, int start, int end) {
    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Rotates array to the right by k positions in-place: O(n) time, O(1) space
void rotateRight(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n <= 1) return;
    k = k % n;
    if (k < 0) k += n; // Handle negative k
    if (k == 0) return;

    reverseRange(arr, 0, n - 1);
    reverseRange(arr, 0, k - 1);
    reverseRange(arr, k, n - 1);
}

// Rotates array to the left by k positions in-place: O(n) time, O(1) space
void rotateLeft(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n <= 1) return;
    k = k % n;
    if (k < 0) k += n;
    if (k == 0) return;

    reverseRange(arr, 0, k - 1);
    reverseRange(arr, k, n - 1);
    reverseRange(arr, 0, n - 1);
}

void printArray(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main() {
    int n;
    std::cout << "--- Array Rotation (In-place Reversal Algorithm) ---\n";
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid array size! Must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int k;
    char direction;
    std::cout << "Enter number of positions to rotate (k): ";
    std::cin >> k;
    std::cout << "Rotate Left or Right? (L/R): ";
    std::cin >> direction;

    std::cout << "\nOriginal array: ";
    printArray(arr);

    if (direction == 'R' || direction == 'r') {
        rotateRight(arr, k);
        std::cout << "Array after rotating RIGHT by " << k << ": ";
    } else if (direction == 'L' || direction == 'l') {
        rotateLeft(arr, k);
        std::cout << "Array after rotating LEFT by " << k << ": ";
    } else {
        std::cerr << "Invalid direction! Use L or R." << std::endl;
        return 1;
    }

    printArray(arr);

    return 0;
}
