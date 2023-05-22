/* Sahil Raj */

// REFERENCE: https://youtu.be/i_5pvt7ag7E

#include <iostream>
using namespace std;

class Employee {

    private:
    int eid;

    public:
    string name;

    // static data member can be accessed without creating an object
    static int workingHours;

    // overwritting default constructor
    Employee() {
        cout<<"constructor called"<<endl;
    }

    // parameterized constructor
    Employee(int eid, string name) {
        this->eid = eid;
        this->name = name;
    }

    // overwritting default copy constructor
    Employee(Employee &temp) {
        this->eid = temp.eid;
        this->name = temp.name;
    }

    // getter
    int getId() {
        return this->eid;
    }

    // setter
    void setId(int id) {
        this->eid = id;
    }

    // static functions can only access static members
    static int getWorkingHours() {
        return workingHours;
    }

    // overwritting default destructor
    ~Employee() {
        cout<<"destructor called"<<endl;
    }

};

// static data members should be initialized globally
int Employee::workingHours = 8;

int main() {
    
    // static allocation
    Employee e1(1, "Sahil");
    // e1.name = "Sahil";
    // e1.setId(1);
    cout << e1.getId() << endl;

    // dynamic allocation
    Employee *e2 = new Employee(2, "Anish");
    // e2->name = "Anish";
    // e2->setId(2);
    // cout << (*e2).name << endl;
    cout << e2->name << endl;

    // using copy constructor
    // default constructor does a 'shallow copy' meaning that both the objects will point to the same location
    Employee e3(e1);
    // Employee e3 = e1;
    cout << e3.name << endl;

    // using static data members of the class
    cout << Employee::workingHours << endl;
    // cout << e1.workingHours << endl; // not recommended

    // using static function
    cout << Employee::getWorkingHours() << endl;

    // destructor of static objects gets called automatically
    // destructor of dynamic objects gets called manually
    delete e2;

    return 0;
}