#include <iostream>

int main() {
    double principal, annual_rate, years;

    std::cout << "Enter principal, annual interest rate (%), and years: ";
    std::cin >> principal >> annual_rate >> years;

    const double interest = principal * annual_rate * years / 100.0;
    std::cout << "Simple interest: " << interest << std::endl;
    std::cout << "Total amount: " << principal + interest << std::endl;
    return 0;
}
