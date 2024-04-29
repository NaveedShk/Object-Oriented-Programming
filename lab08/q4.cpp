#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    Person(const string& n, int a) : name(n), age(a) {}
};

class Student : virtual public Person {
public:
    static int id;
    int std_id;
    char grade; 
    Student(char g, const string& n, int a) : grade(g), Person(n, a) { id++; std_id = id; }
};

class Teacher : virtual public Person {
public:
    string subject;
    int room_num;
    Teacher(const string& s, int room, const string& n, int a) : subject(s), room_num(room), Person(n, a) {}
};

class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(char g, const string& n, int a, const string& s, int room)
        : Person(n, a), Student(g, n, a), Teacher(s, room, n, a) {}

    void display() {
        cout << "Graduate Student details\n"
             << "Student name: " << name << "\n"
             << "Age: " << age << "\n"
             << "Student ID: " << std_id << "\n"
             << "Grade: " << grade << "\n"
             << "TA Details\n"
             << "Subject: " << subject << "\n"
             << "Room number: " << room_num << endl;
    }
};

int Student::id;

int main() {
    GraduateStudent grad_std('B', "Sheikh Naveed ", 18, "CAL", 9);
    grad_std.display();
    return 0;
}
