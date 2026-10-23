#include <iostream>

// Returns true if the given year is a leap year according to the Gregorian calendar
bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

int main() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;
    if (isLeapYear(year)) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        std::cout << year << " is not a leap year." << std::endl;
    }
    return 0;
}
