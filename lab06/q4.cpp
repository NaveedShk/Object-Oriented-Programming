#include<iostream>
using namespace std;

float calculateAverage(int runs, int dismissed) {
    if (dismissed == 0) {
        cout << "Error: Division by zero (dismissed cannot be zero)" << endl;
        return 0.0f;
    }
    return static_cast<float>(runs) / dismissed;
}

float calculateStrikeRate(int runs, int balls) {
    if (balls == 0) {
        cout << "Error: Division by zero (balls cannot be zero)" << endl;
        return 0.0f;
    }
    return (static_cast<float>(runs) / balls) * 100;
}

int main() {
    int runs, dismissed, balls;
    cout << "Enter the total number of balls faced: ";
    cin >> balls;
    cout << "Enter the total number of runs scored: ";
    cin >> runs;
    cout << "Enter the total number of dismissals: ";
    cin >> dismissed;

    cout << "The batting average is " << calculateAverage(runs, dismissed) << endl;
    cout << "The strike rate is " << calculateStrikeRate(runs, balls);

    return 0;
}
