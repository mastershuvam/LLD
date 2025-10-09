// Inheritance and Access Modifiers in C++

/*
...............................Access Modifiers in Inheritance...........................

Base Class Access Modifier + Inheritance Type = Derived Class Member Access

public + public = public
public + protected = protected
public + private = private
protected + public = protected
protected + protected = protected
protected + private = private
private + public = private
private + protected = private
private + private = private
-----------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

class Human {
    int region;  // private by default

protected: // Accessible in derived classes
    string name;
    int age;
    float height;
    int weight;

public:
    // Setter function with validation (encapsulation)
    void setAge(int age) {
        if (age > 0) {
            this->age = age;
        } else {
            cout << "Age cannot be negative" << endl;
            this->age = 0;
        }
    }
};


// Derived class with protected inheritance
class Student : protected Human {
    int id;
    char section;

public:
    // Parameterized constructor
    Student(string name, int id, char section, int age, float height, int weight) {
        this->name = name;
        setAge(age);  // Using base class function
        this->height = height;
        this->weight = weight;
        this->id = id;
        this->section = section;
    }

    // Display function showing student details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "Id: " << id << endl;
        cout << "Section: " << section << endl;
        cout << endl;
    }
};


// Derived class with private inheritance
class Teacher : private Human {
    int id;
    string subject;

public:
    // Parameterized constructor
    Teacher(string name, int id, string subject, int age, float height, int weight) {
        this->name = name;
        setAge(age);  // Using base class function
        this->height = height;
        this->weight = weight;
        this->id = id;
        this->subject = subject;
    }

    // Display function showing teacher details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
        cout << "Id: " << id << endl;
        cout << "Subject: " << subject << endl;
        cout << endl;
    }
};

/*
---------------------------------- OOP Concepts Used ----------------------------------

1️. Abstraction:

   - In the main() function, we can only access the public interfaces (like display()) 
     of Student and Teacher classes.
   - The internal details (data members and logic inside setAge()) are hidden from the user.
   - Hence, the user interacts only with necessary information — abstraction is achieved.

2️. Encapsulation:

   - Data members (name, age, height, weight) are protected/private inside the Human class.
   - Access to these members is controlled via public functions like setAge().
   - This hides data and ensures safe modification — encapsulation is achieved.

3️. Inheritance:

   - Student inherits from Human using protected inheritance.
   - Teacher inherits from Human using private inheritance.
   - Each derived class can access and reuse the Human class members and methods.

-----------------------------------------------------------------------------------------
*/

int main() {
    Student s1("Shuvam", 101, 'A', -1, 5.9, 70);
    s1.display();

    Teacher t1("Rohit", 201, "Math", 30, 5.8, 75);
    t1.display();
}
