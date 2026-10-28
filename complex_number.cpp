#include <iostream>
#include <cmath>

// Complex class demonstrating Operator Overloading in C++
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor with default parameters
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator (Addition)
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator (Subtraction)
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload * operator (Multiplication: (a+bi)(c+di) = (ac - bd) + (ad + bc)i)
    Complex operator*(const Complex& other) const {
        double r = (real * other.real) - (imag * other.imag);
        double i = (real * other.imag) + (imag * other.real);
        return Complex(r, i);
    }

    // Overload == operator (Equality)
    bool operator==(const Complex& other) const {
        const double EPSILON = 1e-9;
        return (std::abs(real - other.real) < EPSILON) &&
               (std::abs(imag - other.imag) < EPSILON);
    }

    // Calculates magnitude (absolute value) |z| = sqrt(real^2 + imag^2)
    double magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }

    // Overload << operator for direct stream output (std::cout << complexNum)
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.0);

    std::cout << "--- Complex Numbers & Operator Overloading in C++ ---\n\n";
    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n\n";

    // Arithmetic operations using overloaded operators
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    std::cout << "c1 + c2 = " << sum << "\n";
    std::cout << "c1 - c2 = " << diff << "\n";
    std::cout << "c1 * c2 = " << prod << "\n\n";

    // Magnitude
    std::cout << "|c1| = " << c1.magnitude() << "\n";
    std::cout << "|c2| = " << c2.magnitude() << "\n\n";

    // Equality check
    Complex c3(3.0, 4.0);
    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << "\n";
    std::cout << "c1 == c3: " << (c1 == c3 ? "true" : "false") << "\n";

    return 0;
}
