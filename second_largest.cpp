#include <iostream>
#include <vector>
#include <climits>

// Finds the second largest distinct element in an array/vector.
// Returns false if no such element exists (e.g. fewer than 2 distinct elements).
bool findSecondLargest(const std::vector<int>& arr, int& secondLargest) {
    if (arr.size() < 2) {
        return false;
    }

    int largest = INT_MIN;
    secondLargest = INT_MIN;
    bool foundLargest = false;
    bool foundSecond = false;

    for (int num : arr) {
        if (!foundLargest || num > largest) {
            if (foundLargest) {
                secondLargest = largest;
                foundSecond = true;
            }
            largest = num;
            foundLargest = true;
        } else if (num < largest && (!foundSecond || num > secondLargest)) {
            secondLargest = num;
            foundSecond = true;
        }
    }

    return foundSecond;
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid array size! Please enter a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int secondLargest;
    if (findSecondLargest(arr, secondLargest)) {
        std::cout << "Second largest distinct element: " << secondLargest << std::endl;
    } else {
        std::cout << "No second largest distinct element found (e.g., all elements are identical)." << std::endl;
    }

    return 0;
}
