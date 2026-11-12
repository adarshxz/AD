#include <cctype>
#include <iostream>

int main() {
    char letter;

    std::cout << "Enter a letter: ";
    std::cin >> letter;

    letter = static_cast<char>(std::tolower(static_cast<unsigned char>(letter)));

    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
        std::cout << "It is a vowel." << std::endl;
    } else {
        std::cout << "It is a consonant." << std::endl;
    }

    return 0;
}
