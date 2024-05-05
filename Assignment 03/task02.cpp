#include "iostream"
using namespace std;

template <class T1, class T2>
class Pet {
    T1 name;
    T2 age;

public:
    Pet(T1 n, T2 a) : name(n), age(a) {}

    void display() { 
        cout << "Name: " << name << "\nAge: " << age << endl; 
    }

    virtual void makeSound() = 0;
};

class Cat : public Pet<string, int> {
public:
    Cat(string n, int a) : Pet<string, int>(n, a) {}

    void makeSound() {
        cout << "Sound : Meow" << endl;
    }
};

class Dog : public Pet<string, int> {
public:
    Dog(string n, int a) : Pet<string, int>(n, a) {}

    void makeSound() {
        cout << "Sound: Woof" << endl;
    }
};

class Bird : public Pet<string, int> {
public:
    Bird(string n, int a) : Pet<string, int>(n, a) {}

    void makeSound() {
        cout <<"Sound: "<< "Chirp" << endl;
    }
};

int main() {
    Pet<string, int>* ptr;
    Bird bird("Stacy", 1.6);
    Cat cat("Tom", 3);
    Dog dog("Spike", 4.5);


    ptr = &dog;
    ptr->makeSound();
    ptr->display();
  
    ptr = &cat;
    ptr->makeSound();
    ptr->display();

     ptr = &bird;
     ptr->makeSound();
     ptr->display();


    return 0;
}
