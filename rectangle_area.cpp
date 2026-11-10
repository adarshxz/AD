#include <iostream>

int main() {
    double length, width;

    std::cout << "Enter length and width: ";
    std::cin >> length >> width;

    const double area = length * width;
    std::cout << "Area of the rectangle: " << area << std::endl;

    return 0;
}
