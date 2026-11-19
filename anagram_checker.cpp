#include <iostream>
#include <string>
#include <vector>
#include <cctype>

// Checks whether two strings are anagrams (case-insensitive, ignoring non-alphanumeric chars)
bool areAnagrams(const std::string& str1, const std::string& str2) {
    std::vector<int> charCounts(26, 0);
    int validCharsCount1 = 0;
    int validCharsCount2 = 0;

    for (char ch : str1) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            charCounts[std::tolower(static_cast<unsigned char>(ch)) - 'a']++;
            validCharsCount1++;
        }
    }

    for (char ch : str2) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            charCounts[std::tolower(static_cast<unsigned char>(ch)) - 'a']--;
            validCharsCount2++;
        }
    }

    if (validCharsCount1 != validCharsCount2) {
        return false;
    }

    for (int count : charCounts) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s1, s2;

    std::cout << "--- Anagram Checker ---\n";
    std::cout << "Enter first string: ";
    std::getline(std::cin, s1);

    std::cout << "Enter second string: ";
    std::getline(std::cin, s2);

    if (areAnagrams(s1, s2)) {
        std::cout << "\"" << s1 << "\" and \"" << s2 << "\" are ANAGRAMS." << std::endl;
    } else {
        std::cout << "\"" << s1 << "\" and \"" << s2 << "\" are NOT anagrams." << std::endl;
    }

    return 0;
}
