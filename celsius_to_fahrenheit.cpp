#include <iostream>

int main() {
    double celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    const double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    std::cout << celsius << " C = " << fahrenheit << " F\n";
    return 0;
}
