#include <iostream>
using namespace std;

class LoanCalculator {
    static const float interest_rate; 
    float total_amount; 
    int duration_months; 

public:
    LoanCalculator() {};
    LoanCalculator(float amount, int months) { 
        this->total_amount = amount;
        this->duration_months = months;
    }

    // setters
    void set_amount(float amount) {
        this->total_amount = amount;
    }

    void set_duration_months(int months) {
        this->duration_months = months;
    }

    // getters
    int get_duration_months() {
        return duration_months;
    }

    float get_total_amount() {
        return total_amount;
    }

    float calculate_monthly_payment() {
        float monthly_payment;
        float monthly_interest;
        monthly_payment = total_amount / duration_months;
        monthly_interest = monthly_payment * (interest_rate / 100);
        return monthly_payment + monthly_interest;
    }
};

const float LoanCalculator::interest_rate = 0.25; // interest rate is set as 0.25%

int main() {
    cout << "Name: Sheikh Naveed Azeemi \nRoll no: 23K-0003\n" << endl;

    LoanCalculator loan1(20000, 12);
    cout << "\n--> You have to pay " << loan1.calculate_monthly_payment() << " every month for " << loan1.get_duration_months() << " months to repay your loan.\n" << endl;

    LoanCalculator loan2;
    float amount;
    int months;
    cout << "Enter the amount of loan taken: ";
    cin >> amount;
    cout << "Enter the number of months for which loan is taken: ";
    cin >> months;
    loan2.set_amount(amount);
    loan2.set_duration_months(months);
    cout << "\n--> You have to pay " << loan2.calculate_monthly_payment() << " every month for " << loan2.get_duration_months() << " months to repay your loan.\n" << endl;

    return 0;
}
