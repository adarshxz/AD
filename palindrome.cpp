#include <iostream>
#include <string>
#include <cctype>

// Checks if a string is a palindrome (ignoring case and non-alphanumeric characters)
bool isStringPalindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
            left++;
        }
        while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
            right--;
        }

        if (std::tolower(static_cast<unsigned char>(s[left])) !=
            std::tolower(static_cast<unsigned char>(s[right]))) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

// Checks if an integer is a palindrome without converting to string
bool isNumberPalindrome(int x) {
    // Negative numbers and numbers ending with 0 (except 0 itself) are not palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + (x % 10);
        x /= 10;
    }

    // For even number of digits: x == reversedHalf
    // For odd number of digits: x == reversedHalf / 10 (middle digit doesn't matter)
    return (x == reversedHalf || x == reversedHalf / 10);
}

int main() {
    std::cout << "--- String Palindrome Check ---\n";
    std::string testStrings[] = {
        "A man, a plan, a canal: Panama",
        "racecar",
        "hello, world"
    };

    for (const auto& str : testStrings) {
        std::cout << "\"" << str << "\" -> "
                  << (isStringPalindrome(str) ? "Palindrome" : "Not a Palindrome")
                  << "\n";
    }

    std::cout << "\n--- Integer Palindrome Check ---\n";
    int testNumbers[] = {121, -121, 10, 12321, 0};

    for (int num : testNumbers) {
        std::cout << num << " -> "
                  << (isNumberPalindrome(num) ? "Palindrome" : "Not a Palindrome")
                  << "\n";
    }

    return 0;
}
