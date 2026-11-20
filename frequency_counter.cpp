#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <string>

// Structure to hold element frequency summary
struct FrequencySummary {
    std::map<int, int> counts;
    int mostFrequentElement;
    int maxFrequency;
};

// Computes frequency of each element and finds the mode
FrequencySummary computeFrequencies(const std::vector<int>& arr) {
    FrequencySummary summary;
    summary.maxFrequency = 0;
    summary.mostFrequentElement = arr.empty() ? 0 : arr[0];

    for (int num : arr) {
        summary.counts[num]++;
        if (summary.counts[num] > summary.maxFrequency) {
            summary.maxFrequency = summary.counts[num];
            summary.mostFrequentElement = num;
        }
    }

    return summary;
}

int main() {
    int n;
    std::cout << "--- Element Frequency Counter ---\n";
    std::cout << "Enter the number of elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid input! Number of elements must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    FrequencySummary summary = computeFrequencies(arr);

    std::cout << "\n" << std::setw(10) << "Element" << std::setw(12) << "Frequency" << "   Histogram\n";
    std::cout << std::string(35, '-') << "\n";

    for (const auto& [element, count] : summary.counts) {
        std::cout << std::setw(10) << element
                  << std::setw(12) << count << "   "
                  << std::string(count, '*') << "\n";
    }

    std::cout << std::string(35, '-') << "\n";
    std::cout << "Most frequent element (Mode): " << summary.mostFrequentElement
              << " (Appears " << summary.maxFrequency << " times)\n";

    return 0;
}
