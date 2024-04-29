#include <iostream>

using namespace std;

class Course {
public:
    string code, name;
    int credit_hours;

    Course(string code = "", string name = "", int ch = 0) : code(code), name(name), credit_hours(ch) {}
};

class Student {
private:
    string id, name;
    Course* courses;
    int num_courses;
public:
    Student(string id, string name) : id(id), name(name), courses(nullptr), num_courses(0) {}

    void enroll(const Course& course) {
        Course* new_courses = new Course[++num_courses];
        for (int i = 0; i < num_courses - 1; i++)
            new_courses[i] = courses[i];
        new_courses[num_courses - 1] = course;
        delete[] courses;
        courses = new_courses;
    }

    void drop(const Course& course) {
        Course* new_courses = new Course[num_courses - 1];
        for (int i = 0, j = 0; i < num_courses; i++) {
            if (courses[i].code != course.code)
                new_courses[j++] = courses[i];
        }
        delete[] courses;
        courses = new_courses;
        num_courses--;
    }

    int getTotalCreditHours() {
        int ch = 0;
        for (int i = 0; i < num_courses; i++)
            ch += courses[i].credit_hours;
        return ch;
    }

    void printEnrolledCourses() {
        for (int i = 0; i < num_courses; i++) {
            cout << "Course[" << i + 1 << "]\n";
            cout << "Code: " << courses[i].code << "\n";
            cout << "Name: " << courses[i].name << "\n";
            cout << "Credit Hours: " << courses[i].credit_hours << "\n\n";
        }
    }

    ~Student() {
        delete[] courses;
    }
};

int main() {
    Course oop("MT123", "Object Oriented Programming", 3);
    Course cal("Al222", "Calculus", 3);
    Course dld("54DFG", "Digital Logic Design", 3);

    Student student("0003", "Naveed");

    student.enroll(oop);
    student.enroll(cal);
    student.enroll(dld);

    student.printEnrolledCourses();
    student.drop(cal);
    cout << "Total Credit Hours: " << student.getTotalCreditHours() << endl;

    cout << endl;
    student.printEnrolledCourses();

    return 0;
}
