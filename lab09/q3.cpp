#include <iostream>
using namespace std;

class Employee {
private:
    int ID;
    string name;

public:
    Employee(int id, string n) : ID(id), name(n) {}
    virtual double calculatePay() const = 0;
    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
    }
    string getName() const { return name; }
    int getID() const { return ID; }
};

class PartTimeEmployee : public Employee {
private:
    float hourlyWage;
    int hours;

public:
    PartTimeEmployee(float hw, int h, int id, string n) : hourlyWage(hw), hours(h), Employee(id, n) {}
    double calculatePay() const override {
        return hourlyWage * hours;
    }
    void displayDetails() const override {
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Type: Part-Time" << endl;
        cout << "Hourly Wage: " << hourlyWage << endl;
        cout << "Hours worked: " << hours << endl;
        cout << "Total Pay: " << calculatePay() << endl;
    }
};

class FullTimeEmployee : public Employee {
private:
    float wage;

public:
    FullTimeEmployee(float w, int id, string n) : wage(w), Employee(id, n) {}
    double calculatePay() const override {
        return wage;
    }
    void displayDetails() const override {
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Type: Full-Time" << endl;
        cout << "Wage: " << wage << endl;
        cout << "Total Pay: " << calculatePay() << endl;
    }
};

int main() {
    Employee* employee = new PartTimeEmployee(20, 50, 1, "Rao");
    employee->displayDetails();
    delete employee;

    employee = new FullTimeEmployee(1000, 2, "Sheikh");
    employee->displayDetails();
    delete employee;

    return 0;
}
