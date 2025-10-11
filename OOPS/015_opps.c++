//Multipath Inheritance

/*

--------Multipath Inheritance---------

             [Person]
                |
        -------------------
        |                 |
     [Teacher]        [Researcher]
            \           /
             \         /
             [Professor]


*/

#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
    int age;

    public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};


class Teacher:public virtual Person{
    protected:
    string subject;
    int experience;

    public:
    Teacher(string name, int age, string subject, int experience):Person(name, age){
        this->subject = subject;
        this->experience = experience;
    }

};


class Researcher:public virtual Person{
    protected:
    string domain;
    int publications;

    public:
    Researcher(string name, int age, string domain, int publications):Person(name, age){
        this->domain = domain;
        this->publications = publications;
    }

};


class Professor:public Teacher, public Researcher{
    protected:
    int salary;

    public:
    Professor(string name, int age, string subject, int experience, string domain, int publications, int salary)
        : Person(name, age), Teacher(name, age, subject, experience), Researcher(name, age, domain, publications) {
        this->salary = salary;
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"Experience: "<<experience<<endl;
        cout<<"Domain: "<<domain<<endl;
        cout<<"Publications: "<<publications<<endl;
        cout<<"Salary: "<<salary<<endl;
    }

};


int main(){
    Professor prof("Dr. Smith", 45, "Computer Science", 20, "Artificial Intelligence", 50, 100000);
    prof.display();

}