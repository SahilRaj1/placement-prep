/* Sahil Raj */

// REFERENCE: https://youtu.be/b3GccK5_KSQ

/*
    Four Pillars of Object Oriented Porgramming:
    1. Abstraction
    2. Encapsulation
    3. Inheritance
    4. Polymorphism
*/

#include <bits/stdc++.h>
using namespace std;

class Student {

    public:
    string name;
    int age = 15;

    int getAge() {
        return this->age;
    }

};

class Boy: public Student {

    public:

    string getName() {
        return this->name;
    }

};

int main() {

    Student s1;
    cout << s1.getAge() << endl;

    Boy s2;
    s2.name = "Sahil";
    cout << s2.getName() << endl;

    return 0;
}