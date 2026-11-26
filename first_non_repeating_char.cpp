#include <iostream>
#include <string>
#include <vector>

// Finds the index of the first non-repeating character in a string: O(n) time, O(1) space
int firstNonRepeatingChar(const std::string& s) {
    std::vector<int> freq(256, 0);

    // First pass: count occurrences of each character
    for (char ch : s) {
        freq[static_cast<unsigned char>(ch)]++;
    }

    // Second pass: find the first character with frequency 1
    for (size_t i = 0; i < s.length(); ++i) {
        if (freq[static_cast<unsigned char>(s[i])] == 1) {
            return static_cast<int>(i);
        }
    }

    return -1; // No unique character found
}

int main() {
    std::cout << "--- First Non-Repeating Character ---\n";
    std::cout << "Enter a string: ";

    std::string s;
    if (std::cin >> s) {
        int index = firstNonRepeatingChar(s);

        if (index != -1) {
            std::cout << "First non-repeating character: '" << s[index]
                      << "' at index " << index << std::endl;
        } else {
            std::cout << "No unique non-repeating character found in the string." << std::endl;
        }
    }

    return 0;
}
