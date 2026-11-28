#include <iostream>

int main() {
    int first, second;

    std::cout << "Enter two integers: ";
    std::cin >> first >> second;

    const int temporary = first;
    first = second;
    second = temporary;

    std::cout << "After swapping: " << first << " " << second << std::endl;
    return 0;
}
