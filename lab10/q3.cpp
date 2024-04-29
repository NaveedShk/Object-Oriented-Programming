#include <iostream>
using namespace std;

class Shape {
    float area = 15;

public:
    Shape operator +(const Shape& other) {
        Shape result;
        result.area = area + other.area;
        return result;
    }

    void print() {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1, shape2;

    cout << "Area of shape 1: ";
    shape1.print();

    cout << "Area of shape 2: ";
    shape2.print();

    Shape shape3 = shape1 + shape2;
    cout << "Area of shape 3: ";
    shape3.print();

    return 0;
}
