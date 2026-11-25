#include <iostream>
#include <vector>
#include <string>

// Finds the longest common prefix among an array of strings using vertical scanning
std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) return "";

    // Iterate through character positions of the first string
    for (size_t col = 0; col < strs[0].length(); ++col) {
        char ch = strs[0][col];

        // Compare with corresponding character in all other strings
        for (size_t row = 1; row < strs.size(); ++row) {
            // If current position exceeds length of another string, or character differs
            if (col >= strs[row].length() || strs[row][col] != ch) {
                return strs[0].substr(0, col);
            }
        }
    }

    return strs[0];
}

int main() {
    int n;
    std::cout << "--- Longest Common Prefix ---\n";
    std::cout << "Enter number of words: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid input! Number of words must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<std::string> words(n);
    std::cout << "Enter " << n << " words:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    std::string prefix = longestCommonPrefix(words);

    std::cout << "\nInput words:\n";
    for (const std::string& word : words) {
        std::cout << "  - " << word << "\n";
    }

    if (!prefix.empty()) {
        std::cout << "\nLongest Common Prefix: \"" << prefix << "\" (Length: " << prefix.length() << ")\n";
    } else {
        std::cout << "\nNo common prefix found (empty string \"\").\n";
    }

    return 0;
}
