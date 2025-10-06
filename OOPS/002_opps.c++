#include<iostream>
using namespace std;

//heare we are creating a class there we can store same type of data in 1 time and we use it multiple times

class student{

    public: //acces modifier

    string student_Name;
    int student_Age;
    string student_Grade;

};

int main(){

    student s1,s2; //object creation

    s1.student_Name = "Rohit";
    s1.student_Age = 21;
    s1.student_Grade = "A";

    s2.student_Name = "Rahul";
    s2.student_Age = 22;
    s2.student_Grade = "B";
}