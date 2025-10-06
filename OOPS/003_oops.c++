#include<iostream>
using namespace std;

//heare we are creating a class there we can store same type of data in 1 time and we use it multiple times

class student{

    private: //access modifier

    string student_Name;
    int student_Age;
    string student_Grade;

    public: //access modifier

    //setter method

    void setName(string name){
        student_Name = name;
    }
    void setAge(int age){
        student_Age = age;
    }
    void setGrade(string grade){
        student_Grade = grade;
    }

};

int main(){

    student s1,s2; //object creation

    s1.setName("Rohit");
    s1.setAge(21);
    s1.setGrade("A");

    s2.setName("Rahul");
    s2.setAge(22);
    s2.setGrade("B");


}