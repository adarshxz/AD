#include <iostream>
#include <string>

// Define a Class named 'Car'
class Car {
public:
    // Attributes (member variables)
    std::string brand;
    std::string model;
    int year;

    // Constructor to initialize an object
    Car(std::string b, std::string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    // Member function (method) to display details
    void displayInfo() {
        std::cout << "Car: " << year << " " << brand << " " << model << std::endl;
    }
};

int main() {
    // Create an object of the Car class using the constructor
    Car car1("Toyota", "Corolla", 2020);
    Car car2("Ford", "Mustang", 2022);

    // Call member functions using the objects
    car1.displayInfo();
    car2.displayInfo();

    // Directly access and modify an attribute
    car1.year = 2021;
    std::cout << "\nAfter updating car1 year:\n";
    car1.displayInfo();

    return 0;
}
