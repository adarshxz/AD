#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Reverses a string
std::string reverseString(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}

// Counts vowels in a string (case-insensitive)
int countVowels(const std::string& s) {
    int count = 0;
    std::string vowels = "aeiouAEIOU";
    for (char c : s) {
        if (vowels.find(c) != std::string::npos) count++;
    }
    return count;
}

// Counts words in a string
int countWords(const std::string& s) {
    int count = 0;
    bool inWord = false;
    for (char c : s) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    return count;
}

// Converts a string to uppercase
std::string toUpperCase(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}

// Converts a string to lowercase
std::string toLowerCase(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

int main() {
    std::string text = "Hello World from C++";

    std::cout << "--- String Operations in C++ ---\n\n";
    std::cout << "Original   : " << text << "\n";
    std::cout << "Reversed   : " << reverseString(text) << "\n";
    std::cout << "Uppercase  : " << toUpperCase(text) << "\n";
    std::cout << "Lowercase  : " << toLowerCase(text) << "\n";
    std::cout << "Vowels     : " << countVowels(text) << "\n";
    std::cout << "Words      : " << countWords(text) << "\n";
    std::cout << "Length     : " << text.length() << " characters\n";

    return 0;
}
