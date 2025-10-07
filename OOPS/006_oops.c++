//constructor in C++

#include<iostream>
using namespace std;

class Student{
    int id;
    string name;
    int age;
    int *marks; //dynamic memory allocation

    //default constructor

    public:
    Student(){
        //cout<<"Constructor called"<<endl;
        id = 101;
        name = "Rohit";
        age = 21;
    }

    //parameterized constructor
    
    Student(int i, string n, int a){
        id = i;
        name = n;
        age = a;
        marks = new int[3]; //dynamic memory allocation
    }
    
    //overloaded constructor
    Student(int id, string name){
        //this pointer
        this->id = id;  
        this->name = name;
        age = 18;
    }

    //Inline Constructor

    /*
    inline Student(int i, string n, int a):id(i),name(n),age(a){

    }
    */

    //coppy constructor
    Student(Student &s){
        id = s.id;
        name = s.name;
        age = s.age;
    }

    void display(){
        cout<<"Id: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<endl;
    }


};


int main(){
    Student s1; //object creation;
    s1.display();

    Student s2(102,"Sam",20); //object creation;
    s2.display();

    Student s3(103,"John"); //object creation;
    s3.display();

    Student s4(s2); //coppy constructor
    s4.display();

    Student s5 = s3; //coppy constructor
    s5.display();
}