//operator overloading

#include <iostream>
using namespace std;


class Complex{
    int real, imag;

    public:
    Complex(int real,int imag){
        this->real = real;
        this->imag = imag;
    }

    Complex operator+(Complex const &c){
        Complex res(0,0);
        res.real = real + c.real;
        res.imag = imag + c.imag;
        return res;
    }

    void display(){
        cout<<real<<" + i"<<imag<<endl;
    }
};



int main(){
    Complex c1(2,3);
    c1.display();
    Complex c2(4,5);
    c2.display();

    Complex c3 = c1 + c2; //c1.operator+(c2);
    c3.display();
    


    return 0;
}