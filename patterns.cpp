#include <iostream>
#include <string>

// Prints a right-angled triangle pattern of stars
void rightTriangle(int n) {
    std::cout << "Right-Angled Triangle:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

// Prints an inverted right-angled triangle pattern of stars
void invertedTriangle(int n) {
    std::cout << "\nInverted Triangle:\n";
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

// Prints a pyramid pattern of stars
void pyramid(int n) {
    std::cout << "\nPyramid:\n";
    for (int i = 1; i <= n; ++i) {
        // Print spaces
        for (int j = i; j < n; ++j) {
            std::cout << " ";
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

// Prints a number triangle pattern
void numberTriangle(int n) {
    std::cout << "\nNumber Triangle:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int rows = 5;
    std::cout << "--- Star and Number Patterns in C++ (rows = " << rows << ") ---\n\n";

    rightTriangle(rows);
    invertedTriangle(rows);
    pyramid(rows);
    numberTriangle(rows);

    return 0;
}
