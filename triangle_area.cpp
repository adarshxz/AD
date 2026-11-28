#include <iostream>

int main() {
    double base, height;

    std::cout << "Enter the triangle's base and height: ";
    std::cin >> base >> height;

    const double area = 0.5 * base * height;
    std::cout << "Area: " << area << std::endl;
    return 0;
}
