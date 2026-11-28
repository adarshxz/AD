#include <iostream>

int main() {
    double length, width;

    std::cout << "Enter the rectangle's length and width: ";
    std::cin >> length >> width;

    const double perimeter = 2 * (length + width);
    std::cout << "Perimeter: " << perimeter << std::endl;
    return 0;
}
