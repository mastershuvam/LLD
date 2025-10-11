/*
 Hierarchical Inheritance

            Person
              |
    ----------------------    
    |         |          |
student     Employee     teacher


*/

#include<iostream>
using namespace std;


class Persion{
    protected:
    string name;
    int age;

    public:
    Persion(string name, int age){
        this->name = name;
        this->age = age;
    }
};


class Student:public Persion{
    int student_id;
    string course;
    int fee;

    public:
    Student(string name, int age, int student_id, string course, int fee):Persion(name, age){
        this->student_id = student_id;
        this->course = course;
        this->fee = fee;
    }

    void display(){
        cout<<"Hi my name is "<<name<<endl;
        cout<<"I am "<<age<<" years old"<<endl;
        cout<<"My student id is "<<student_id<<endl;
        cout<<"I am enrolled in "<<course<<endl;
        cout<<"I pay "<<fee<<" as my course fee"<<endl;
    }
};


class Employee:public Persion{
    int empid;
    string designation;
    int salary;

    public:
    Employee(string name, int age, int empid, string designation, int salary):Persion(name, age){
        this->empid = empid;
        this->designation = designation;
        this->salary = salary;
    }

    void display(){
        cout<<"Hi my name is "<<name<<endl;
        cout<<"I am "<<age<<" years old"<<endl;
        cout<<"My employee id is "<<empid<<endl;
        cout<<"I work as a "<<designation<<endl;
        cout<<"I earn "<<salary<<" as my monthly salary"<<endl;
    }

};

class Teacher:public Persion{
    string subject;
    int experience;
    int salary;

    public:
    Teacher(string name, int age, string subject, int experience, int salary):Persion(name, age){
        this->subject = subject;
        this->experience = experience;
        this->salary = salary;
    }  

    void display(){
        cout<<"Hi my name is "<<name<<endl;
        cout<<"I am "<<age<<" years old"<<endl;
        cout<<"I teach "<<subject<<endl;
        cout<<"I have "<<experience<<" years of experience"<<endl;
        cout<<"I earn "<<salary<<" as my monthly salary"<<endl;
    }
};


int main(){
    Student("Shuvam", 24, 101, "C++", 5000).display();
    cout<<endl;

    Employee("John", 30, 201, "Software Engineer", 80000).display();
    cout<<endl;

    Teacher("Alice", 35, "Mathematics", 10, 50000).display();
    cout<<endl;
}


