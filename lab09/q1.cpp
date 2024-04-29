#include <iostream>
#include <cmath> // Include <cmath> for std::sqrt

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float radius) : radius(radius) {}

    double area() const override { return 3.14159 * radius * radius; }
    double perimeter() const override { return 2 * 3.14159 * radius; }
    void display() const override { std::cout << "Circle\nArea: " << area() << "\nPerimeter: " << perimeter() << std::endl; }
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float length, float width) : length(length), width(width) {}

    double area() const override { return length * width; }
    double perimeter() const override { return 2 * (length + width); }
    void display() const override { std::cout << "Rectangle\nArea: " << area() << "\nPerimeter: " << perimeter() << std::endl; }
};

class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float base, float height) : base(base), height(height) {}

    double area() const override { return 0.5f * base * height; }
    double perimeter() const override {
        float side = hypotenuse(base, height);
        return base + height + side;
    }
    void display() const override { std::cout << "Triangle\nArea: " << area() << "\nPerimeter: " << perimeter() << std::endl; }

private:
    float hypotenuse(float a, float b) const { return std::sqrt(a * a + b * b); }
};

int main() {
    Shape* circle = new Circle(4.f);
    Shape* rectangle = new Rectangle(4.f, 8.f);
    Shape* triangle = new Triangle(4.f, 8.f);

    circle->display();
    rectangle->display();
    triangle->display();

    delete circle;
    delete rectangle;
    delete triangle;

    return 0;
}
