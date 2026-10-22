#include <iostream>
#include <iomanip>

// Convert Celsius to Fahrenheit
double celsiusToFahrenheit(double c) {
    return (c * 9.0/5.0) + 32.0;
}

// Convert Fahrenheit to Celsius
double fahrenheitToCelsius(double f) {
    return (f - 32.0) * 5.0/9.0;
}

int main() {
    double temp;
    char unit;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Enter temperature followed by unit (C/F): ";
    std::cin >> temp >> unit;
    if (unit == 'C' || unit == 'c') {
        std::cout << temp << " C = " << celsiusToFahrenheit(temp) << " F" << std::endl;
    } else if (unit == 'F' || unit == 'f') {
        std::cout << temp << " F = " << fahrenheitToCelsius(temp) << " C" << std::endl;
    } else {
        std::cerr << "Invalid unit! Use C or F." << std::endl;
        return 1;
    }
    return 0;
}
