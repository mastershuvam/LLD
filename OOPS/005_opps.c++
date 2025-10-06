//Dynamic Memory Allocation in OOPS


#include <iostream>
using namespace std;


class Student{
    private: //acces modifier

    string student_Name;
    int student_Age;
    string student_Grade;


    public: //acces modifier

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
    //getter method
    string getName(){
        return student_Name;
    }
    int getAge(){
        return student_Age;
    }
    string getGrade(){
        return student_Grade;
    }

};

int main(){
    Student *s1 = new Student(); //object creation in heap memory

    /*
    you can access () or -> both operator 
        example (*s1). or s1-> 
    */

    (*s1).setName("Rohit");
    (*s1).setAge(21);
    (*s1).setGrade("A");

    cout<<"Student 1 details: "<<s1->getName()<<" "<<s1->getAge()<<" "<<s1->getGrade()<<endl;

}