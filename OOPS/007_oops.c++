//Distractor in C++


#include<iostream>
using namespace std;

class Student{
    string name;
    int * id; //dynamic memory allocation

    public:
    //parameterized constructor
    Student(string n, int i){
        name = n;
        id = new int; //dynamic memory allocation
        *id = i;

        cout<<"Constructor called: "<<name<<" "<< *id <<endl;
    }

    //distructor
    ~Student(){
        cout<<"Distructor called: "<<name<<" "<<*id<<endl;
    }
};


int main(){
    Student s1("Rohit", 101); //parameterized constructor called
    Student s2("Sohan", 102); //parameterized constructor called

    Student * s3 = new Student("Mohan", 103); //parameterized constructor called
    delete s3; //distructor called
}


