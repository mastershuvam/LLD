/*
Multiple Inheritance
Persion(name, age)->Engineer(specialization, experience)
    (base class)      (base class)
            ->Candidate(name, age, specialization, experience, domine)
                    (derived class)
*/

#include<iostream>
using namespace std;

//parent class
class Persion{
    protected:
    string name;
    int age;

    public:
    Persion(string name, int age){
        this->name = name;
        this->age = age;
    }

    void show_persion(){
        cout<<"Hi my name is "<<name<<endl;
    }
};

//parent class
class Engineer{
    protected:
    string specialization;
    int experience;

    public:

    Engineer(string specialization, int experience){
        this->specialization = specialization;
        this->experience = experience;
    }

    void show_engineer(){
        cout<<"I am an "<<specialization<<endl;
    }
};



//child class
class Candidate :public Persion, public Engineer{

    string domine;
    
    public:
    Candidate(string name,int age, string specialization, int experience, string domine): Persion(name, age),Engineer(specialization, experience){
        //initialize all the attributes
        this->domine = domine;
    }

    void display(){

        show_persion();
        cout<<"Age: "<<age<<endl;
        show_engineer();
        //cout<<"Specialization: "<<specialization<<endl;
        cout<<"Experience: "<<experience<<endl;
        cout<<"Domine: "<<domine<<endl;
        cout<<endl;
    }
};


int main(){
    Candidate c1("Shuvam", 22, "Software Engineer", 2, "Full Stack Developer");
    c1.display();

    return 0;
}
