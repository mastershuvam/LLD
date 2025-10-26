//Factory Design Pattern
//Factory Method 

#include <iostream>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

// normal burger types
class VegBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Veg Burger " << endl;
    }
};
class ChickenBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Chicken Burger " << endl;
    }
};

// premium burger types
class PremiumVegBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Veg Burger " << endl;
    }
};

class PremiumChickenBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Chicken Burger " << endl;
    }
};

class SpecialBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Special Burger " << endl;
    }
};

// abstract factory
class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual ~BurgerFactory() {}
};

// normal burger factory
class NormalBurgerFactory : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "veg") {
            return new VegBurger();
        } else if (type == "chicken") {
            return new ChickenBurger();
        } else {
            cout << "Invalid burger type for Normal category!" << endl;
            return nullptr;
        }
    }
};

// premium burger factory
class PremiumBurgerFactory : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "veg") {
            return new PremiumVegBurger();
        } else if (type == "chicken") {
            return new PremiumChickenBurger();
        } else if (type == "special") {
            return new SpecialBurger();
        } else {
            cout << " Invalid burger type for Premium category!" << endl;
            return nullptr;
        }
    }
};

int main() {
    BurgerFactory* factory = nullptr;
    string category, type;

    cout << "Enter category (Normal / Premium): ";
    cin >> category;

    cout << "Enter burger type (veg / chicken / special): ";
    cin >> type;

    // convert to proper case (optional)
    if (category == "Normal" || category == "normal") {
        factory = new NormalBurgerFactory();
    } else if (category == "Premium" || category == "premium") {
        factory = new PremiumBurgerFactory();
    } else {
        cout << "❌ Invalid category!" << endl;
        return 0;
    }

    Burger* burger = factory->createBurger(type);

    if (burger != nullptr) {
        burger->prepare();
        delete burger;
    }

    delete factory;
    return 0;
}
