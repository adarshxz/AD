#include <iostream>
#include <string>
#include <cctype>

// Returns integer value of a Roman numeral character, or -1 if invalid
int romanCharValue(char ch) {
    switch (std::toupper(static_cast<unsigned char>(ch))) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return -1;
    }
}

// Converts a Roman numeral string to an integer
// Returns -1 if the string contains invalid characters
int romanToInt(const std::string& s) {
    int total = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        int currentVal = romanCharValue(s[i]);
        if (currentVal == -1) {
            return -1; // Invalid character
        }

        // If next character represents a larger value, subtract current value
        if (i + 1 < n) {
            int nextVal = romanCharValue(s[i + 1]);
            if (nextVal > currentVal) {
                total -= currentVal;
                continue;
            }
        }

        total += currentVal;
    }

    return total;
}

int main() {
    std::cout << "--- Roman Numeral to Integer Converter ---\n";
    std::cout << "Enter a Roman numeral (e.g., XIV, MMXXIV, MCMXCIV): ";

    std::string roman;
    if (std::cin >> roman) {
        int result = romanToInt(roman);
        if (result == -1) {
            std::cerr << "Error: Invalid Roman numeral character encountered!" << std::endl;
            return 1;
        }

        std::cout << "Roman Numeral: " << roman << "\n";
        std::cout << "Integer Value: " << result << std::endl;
    }

    return 0;
}
