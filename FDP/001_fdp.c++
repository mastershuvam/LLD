//Factory Design Pattern
//Simple Factory with user input

#include <iostream>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

class VegBurger : public Burger {
public:
    void prepare() {
        cout << "Preparing Veg Burger" << endl;
    }
};

class ChickenBurger : public Burger {
public:
    void prepare() {
        cout << "Preparing Chicken Burger" << endl;
    }
};

class SpecialBurger : public Burger {
public:
    void prepare() {
        cout << "Preparing Special Burger" << endl;
    }
};

class BurgerFactory {
public:
    Burger* createBurger(string type) {
        if (type == "veg") {
            return new VegBurger();
        }
        else if (type == "chicken") {
            return new ChickenBurger();
        }
        else if (type == "special") {
            return new SpecialBurger();
        }
        else {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};

int main() {
    BurgerFactory factory;
    string type;

    cout << "Enter burger type (veg/chicken/special): ";
    cin >> type;  // taking input from user in CMD

    Burger* burger = factory.createBurger(type);

    if (burger != nullptr) {
        burger->prepare();
        delete burger; // memory cleanup
    }

    return 0;
}
