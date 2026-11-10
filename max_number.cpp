#include <iostream>

int main() {
    int first, second;

    std::cout << "Enter two integers: ";
    std::cin >> first >> second;

    if (first > second) {
        std::cout << "Largest number: " << first << std::endl;
    } else {
        std::cout << "Largest number: " << second << std::endl;
    }

    return 0;
}
