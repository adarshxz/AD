#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

// Converts a decimal integer to its binary string representation
std::string decimalToBinary(long long n) {
    if (n == 0) return "0";

    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n = -n;
    }

    std::string binary = "";
    while (n > 0) {
        binary += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }

    if (isNegative) {
        binary += '-';
    }

    std::reverse(binary.begin(), binary.end());
    return binary;
}

// Converts a binary string to its decimal integer value
// Returns true on successful conversion, false if invalid binary string
bool binaryToDecimal(const std::string& binaryStr, long long& decimalValue) {
    if (binaryStr.empty()) return false;

    decimalValue = 0;
    size_t startIndex = 0;
    bool isNegative = false;

    if (binaryStr[0] == '-') {
        isNegative = true;
        startIndex = 1;
        if (binaryStr.length() == 1) return false;
    }

    for (size_t i = startIndex; i < binaryStr.length(); ++i) {
        char bit = binaryStr[i];
        if (bit != '0' && bit != '1') {
            return false; // Invalid binary digit
        }
        decimalValue = (decimalValue << 1) + (bit - '0');
    }

    if (isNegative) {
        decimalValue = -decimalValue;
    }

    return true;
}

int main() {
    std::cout << "--- Decimal to Binary Conversion ---\n";
    long long decimalTests[] = {0, 5, 13, 42, 100, 255, -29};

    for (long long dec : decimalTests) {
        std::cout << "Decimal: " << dec << " -> Binary: " << decimalToBinary(dec) << "\n";
    }

    std::cout << "\n--- Binary to Decimal Conversion ---\n";
    std::string binaryTests[] = {"0", "101", "1101", "101010", "11111111", "-11101", "10201"};

    for (const std::string& bin : binaryTests) {
        long long result = 0;
        if (binaryToDecimal(bin, result)) {
            std::cout << "Binary: " << bin << " -> Decimal: " << result << "\n";
        } else {
            std::cout << "Binary: " << bin << " -> Invalid binary input!\n";
        }
    }

    return 0;
}
