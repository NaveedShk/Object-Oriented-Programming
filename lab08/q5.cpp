#include <iostream>
using namespace std;

class Vehicle {
public:
    string make;
    string model;
    int year;
    Vehicle(const string& make, const string& model, int year) : make(make), model(model), year(year) {}
};

class Car : public Vehicle {
public:
    int doors;
    int fuelEfficiency;
    Car(int doors, int fuelEfficiency, const string& make, const string& model, int year)
        : doors(doors), fuelEfficiency(fuelEfficiency), Vehicle(make, model, year) {}
};

class ElectricCar : public Car {
public:
    int batteryLife;
    ElectricCar(int batteryLife, int doors, int fuelEfficiency, const string& make, const string& model, int year)
        : batteryLife(batteryLife), Car(doors, fuelEfficiency, make, model, year) {}

    void display() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year
             << ", Doors: " << doors << ", Fuel Efficiency: " << fuelEfficiency
             << ", Battery Life: " << batteryLife << endl;
    }
};

int main() {
    ElectricCar myCar(900, 2, 80, "Buggati", "D-0989", 2024);
    myCar.display();

    return 0;
}
