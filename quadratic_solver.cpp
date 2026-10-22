#include <iostream>
#include <cmath>
#include <iomanip>

// Solves a quadratic equation ax^2 + bx + c = 0
void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        std::cout << "Not a quadratic equation (a = 0)." << std::endl;
        return;
    }

    double discriminant = b * b - 4 * a * c;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Discriminant = " << discriminant << std::endl;

    if (discriminant > 0) {
        double sqrtDisc = std::sqrt(discriminant);
        double root1 = (-b + sqrtDisc) / (2 * a);
        double root2 = (-b - sqrtDisc) / (2 * a);
        std::cout << "Two distinct real roots: " << root1 << ", " << root2 << std::endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "One real double root: " << root << std::endl;
    } else {
        double realPart = -b / (2 * a);
        double imagPart = std::sqrt(-discriminant) / (2 * a);
        std::cout << "Complex conjugate roots: " << realPart << " ± " << imagPart << "i" << std::endl;
    }
}

int main() {
    double a, b, c;
    std::cout << "Enter coefficients a b c (separated by spaces): ";
    std::cin >> a >> b >> c;
    solveQuadratic(a, b, c);
    return 0;
}
