#include <iostream>

int main() {
    double first, second, third;

    std::cout << "Enter three numbers: ";
    std::cin >> first >> second >> third;

    const double average = (first + second + third) / 3;
    std::cout << "Average: " << average << std::endl;

    return 0;
}
