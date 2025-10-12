//vector of pointers and virtual functions

#include <iostream>
#include <vector>
using namespace std;

class Animal {
    public:
    virtual void speak(){
        cout<<"Animal speaks"<<endl;
    }
};

class Dog : public Animal {
    public:
    void speak(){
        cout<<"Dog barks"<<endl;
    }
};

class Cat : public Animal {
    public:
    void speak(){
        cout<<"Cat meows"<<endl;
    }
};

int main(){
    vector<Animal*>v;

    v.push_back(new Animal());
    v.push_back(new Dog());
    v.push_back(new Cat());


    for(auto x:v){
        x->speak();
    }

    //free the memory
    
    for(auto x:v){
        delete x;
    }
}
