#include <iostream>
#include <vector>

// Structure to hold both min and max results
struct MinMax {
    int min;
    int max;
};

// Finds the minimum and maximum elements in a vector
MinMax findMinMax(const std::vector<int>& arr) {
    if (arr.empty()) {
        return {0, 0};
    }

    int currentMin = arr[0];
    int currentMax = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < currentMin) {
            currentMin = arr[i];
        }
        if (arr[i] > currentMax) {
            currentMax = arr[i];
        }
    }

    return {currentMin, currentMax};
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid array size! Please enter a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> numbers(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    MinMax result = findMinMax(numbers);

    std::cout << "--- Results ---" << std::endl;
    std::cout << "Minimum element: " << result.min << std::endl;
    std::cout << "Maximum element: " << result.max << std::endl;

    return 0;
}
