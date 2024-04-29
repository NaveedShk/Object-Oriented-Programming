#include <iostream>
using namespace std;

class Perimeter {
    float length, width;

public:
    Perimeter(float l, float w) : length(l), width(w) {}
    friend class PrintClass;
};

class PrintClass {
public:
    void Print(Perimeter p) const {
        double temp = p.length * 2 + p.width * 2;
        cout << "Perimeter is: " << temp << endl;
    }
};

int main() {
    Perimeter p(2, 3);
    PrintClass print;

    print.Print(p);

    return 0;
}
