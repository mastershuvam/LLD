
/*
------Single Inheritance------
        
Persion(name, age)->Student(name, age, id, marks, section)
        (base class)      (derived class)
*/

#include<iostream>
using namespace std;

//parent class
class Persion{

    protected:

    string name;
    int age;

    //parameterized constructor
    public:
    Persion(string name, int age){
        this->name = name;
        this->age = age;
    }

    void show_Persion(){
        cout<<"i am a Persion"<<endl;
    }

};

//child class
class Student: public Persion{
    int id;
    int marks;
    string section;

    //parameterized constructor
    public:
    Student(string name, int age, int id, int marks, string section): Persion(name, age){
        this->id = id;
        this->marks = marks;
        this->section = section;
    }

    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: " << marks << endl;
        cout << "Section: " << section << endl;
        cout << "Id: " << id << endl;
        cout << endl;
    }

    void show_student(){
        cout<<"i am a student"<<endl;
    }

};

int main(){
    //object creation
    Student s1("Shuvam", 20, 101, 95, "12 A");
    s1.display();
    s1.show_Persion();
    s1.show_student();

}