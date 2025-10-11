/* 
---------Hybrid Inheritance--------

        [Person]        <-- Base class
        /     \
   [Student]  [Employee]  <-- Hierarchical (Person থেকে Student ও Employee)
         \       /
        [WorkingStudent]  <-- Multiple (Student + Employee)



*/

#include<iostream>
using namespace std;

class Persion{
    protected:
    string name;
    int age;

    public:
    Persion(){

    }
    Persion(string name, int age){
        this->name = name;
        this->age = age;
    }

    void show_persion(){
        cout<<"Hi my name is "<<name<<endl;
    }

};


class Student:public virtual Persion{
    protected:
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
        show_persion();
        cout<<"I am "<<age<<" years old"<<endl;
        cout<<"My student id is "<<student_id<<endl;
        cout<<"I am enrolled in "<<course<<endl;
        cout<<"I pay "<<fee<<" as my course fee"<<endl;
    }
};


class Employee:public virtual Persion{
    protected:
    int empid;
    string designation;
    int salary;
    string company;

    public:
    Employee(string name, int age, int empid, string designation, int salary,string company):Persion(name, age){
        this->empid = empid;
        this->designation = designation;
        this->salary = salary;
        this->company = company;
    }

    void show_company(){
        cout<<"I work at "<<company<<endl;
    }

    void display(){
        show_persion();
        cout<<"I am "<<age<<" years old"<<endl;
        cout<<"My employee id is "<<empid<<endl;
        show_company();
        cout<<"I work as a "<<designation<<endl;
        cout<<"I earn "<<salary<<" as my monthly salary"<<endl;
    }   
};


class WorkingStudent : public Student, public Employee{
    int work_hours;

    public:
    WorkingStudent(string name, int age, int student_id, string course, int fee,
                   int empid, string designation, int salary, int work_hours, string company)
        : Persion(name, age),
          Student(name, age, student_id, course, fee),
          Employee(name, age, empid, designation, salary, company)
        {
            this->work_hours = work_hours;
        }

    void show_WorkingStudent(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Student ID: "<<student_id<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Fee: "<<fee<<endl;
        show_company();
        cout<<"Employee ID: "<<empid<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"I work "<<work_hours<<" hours a week"<<endl;
    }
};


int main(){

    WorkingStudent ws("Alice", 22, 101, "Computer Science", 15000, 201, "Intern", 20000, 20, "TechCorp");
    ws.show_WorkingStudent();



    return 0;
}
