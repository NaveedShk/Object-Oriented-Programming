#include <iostream>
using namespace std;

class Base {
private:
    int x;

public:
    Base(int x) : x(x) {}

    // Post-decrement operator
    Base& operator--(int) {
        this->x /= 4;
        return *this;
    }

    // Pre-decrement operator
    Base& operator--() {
        this->x *= 4;
        return *this;
    }

    void show() {
        cout << "Value of x: " << x << endl;
    }
};

int main() {
    Base b1(4);

    --b1; // Decrement x by 1 (post-decrement)
    b1.show();

    b1--; // Decrement x by 1 (pre-decrement)
    b1.show();

    return 0;
}
