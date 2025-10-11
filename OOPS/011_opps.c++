/*
------Multilevel Inheritance------

persion(name, age)->Employee(name, age, empId, company)->Manager(name, age, empId, company, department, teamSize)
        (base class)      (derived class)          (derived class)
*/

#include<iostream>
using namespace std;


class Persion{
    protected:
    string name;
    int age;


    void persion_age(int age){
        if(age<0){
            cout<<"Age cannot be negative"<<endl;
            this->age = 0;
        }
        else{
            this->age = age;
        }
    }

    public:
    Persion(string name, int age){
        this->name = name;
        persion_age(age);
    }

    void display(){
        cout<<"I am Persion"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<endl;
    }
};

class Employee: public Persion{
    protected:
    int empId;
    string company;

    //emp id alwas 3 digits
    void employee_id(int empId){
        if(empId<100 || empId>999){
            cout<<"emp id should be 3 digits"<<endl;
            this->empId = 0;
        }
        else{
            this->empId = empId;
        }
    }

    public:
    Employee(string name,int age, int empId, string company): Persion(name,age){
        this->company = company;
        employee_id(empId);

    }

    void display(){
        cout<<"I am Employee"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Emp Id: "<<empId<<endl;
        cout<<"Company: "<<company<<endl;
        cout<<endl;
    }

};

class Manager : public Employee{
    protected:
    string department;
    int teamSize;

    public:



    Manager(string name,int age, int empId, string company,string department, int teamSize): Employee(name,age,empId,company){
        this->department = department;
        this->teamSize = teamSize;
    }

    void display(){
        cout<<"I am Manager"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Emp Id: "<<empId<<endl;
        cout<<"Company: "<<company<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Team Size: "<<teamSize<<endl;
        cout<<endl;
    }
};


int main(){
    Manager m1("Ram", 21, 123, "Google", "Tech", 10);
    Employee e1("Shyam", 22, 456, "Amazon");
    Persion p1("Mohan", 23);

    p1.display();
    e1.display();
    m1.display();
}