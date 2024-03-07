#include <iostream>
#include <cctype>
using namespace std;

class StringValidator {
    string str;

public:
    StringValidator(string str) {
        this->str = str;
    }
    string is_valid() const {
        int length = str.length(); 
        for (int i = 0; i < length; i++) {
            if (!isalpha(str[i])) {
                return "no"; 
            }
        }
        return "yes";
    }
};

int main() {
    cout << "Name: Seikh Naveed Azeemi \nRoll no: 23K-0003\n" << endl;

    StringValidator s1("RealMadrid"); //valid string
    StringValidator s2("Football"); //valid string
    StringValidator s3("22 is my favourite number"); // invalid string , number is used in the beginning

    cout << "Is string 1 valid? " << s1.is_valid() << endl;
    cout << "Is string 2 valid? " << s2.is_valid() << endl;
    cout << "Is string 3 valid? " << s3.is_valid() << endl;

    return 0;
}
