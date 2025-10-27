//Factory Design Pattern
//Abstract Factory Method 

#include <iostream>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0;
};
// normal burger types
class VegBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Veg Burger " << endl;
    }
};

class ChickenBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Chicken Burger " << endl;
    }
};  

// premium burger types
class PremiumVegBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Premium Veg Burger " << endl;
    }
};  

class PremiumChickenBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Premium Chicken Burger " << endl;
    }
};

class SpecialBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Special Burger " << endl;
    }
};

class Bread{
    public:
    virtual void prepare()=0;
};

// normal bread types
class WheatBread : public Bread{
    public:
    void prepare() override{
        cout << "Preparing Wheat Bread " << endl;
    }
};  

class BrownBread : public Bread{
    public:
    void prepare() override{
        cout << "Preparing Brown Bread " << endl;
    }
};

// premium bread types

class MultigrainBread : public Bread{
    public:
    void prepare() override{
        cout << "Preparing Multigrain Bread " << endl;
    }
};

class GarlicBread : public Bread{
    public:
    void prepare() override{
        cout << "Preparing Garlic Bread " << endl;
    }
};

class Factory{
    public:
    virtual Burger* createBurger(string & type)=0;
    virtual Bread* createBread(string & type)=0;

    virtual ~Factory(){};
};

// normal factory

class NormalFactory : public Factory{
    public:
    Burger* createBurger(string & type) override{
        if(type == "veg"){
            return new VegBurger();
        } else if(type == "chicken"){
            return new ChickenBurger();
        } else {
            cout << "Invalid burger type for Normal category!" << endl;
            return nullptr;
        }
    }

    Bread*createBread(string & type) override{
        if(type == "wheat"){
            return new WheatBread();
        } else if(type == "brown"){
            return new BrownBread();
        } else {
            cout << "Invalid bread type for Normal category!" << endl;
            return nullptr;
        }
    }
};

// premium factory

class PremiumFactory : public Factory{
    public:
    Burger* createBurger(string & type) override{
        if(type == "veg"){
            return new PremiumVegBurger();
        } else if(type == "chicken"){
            return new PremiumChickenBurger();
        } else if(type == "special"){
            return new SpecialBurger();
        } else {
            cout << " Invalid burger type for Premium category!" << endl;
            return nullptr;
        }
    }

    Bread* createBread(string & type) override{
        if(type == "multigrain"){
            return new MultigrainBread();
        } else if(type == "garlic"){
            return new GarlicBread();
        } else {
            cout << " Invalid bread type for Premium category!" << endl;
            return nullptr;
        }
    }
};


class Application {
public:
    void run() {
        string category, burgerType, breadType;
        char choice;

        cout << "==============================" << endl;
        cout << " 🍔 Welcome to Burger Factory 🍞" << endl;
        cout << "==============================" << endl;
        cout << "Choose category:" << endl;
        cout << "1. Normal" << endl;
        cout << "2. Premium" << endl;
        cout << "Enter choice: ";
        int catChoice;
        cin >> catChoice;

        Factory* factory = nullptr;
        if (catChoice == 1)
            factory = new NormalFactory(), category = "normal";
        else if (catChoice == 2)
            factory = new PremiumFactory(), category = "premium";
        else {
            cout << "❌ Invalid category!" << endl;
            return;
        }

        cout << "\nWould you like to prepare:" << endl;
        cout << "B. Burger only" << endl;
        cout << "R. Bread only" << endl;
        cout << "A. Both burger and bread" << endl;
        cout << "Enter choice (B/R/A): ";
        cin >> choice;

        Burger* burger = nullptr;
        Bread* bread = nullptr;

        // Burger menu
        if (choice == 'B' || choice == 'b' || choice == 'A' || choice == 'a') {
            cout << "\n🍔 Burger Menu (" << category << "):" << endl;
            if (category == "normal") {
                cout << "1. Veg Burger" << endl;
                cout << "2. Chicken Burger" << endl;
            } else {
                cout << "1. Premium Veg Burger" << endl;
                cout << "2. Premium Chicken Burger" << endl;
                cout << "3. Special Burger" << endl;
            }

            cout << "Enter burger choice: ";
            int bChoice;
            cin >> bChoice;

            if (category == "normal") {
                if (bChoice == 1) burgerType = "veg";
                else if (bChoice == 2) burgerType = "chicken";
                else burgerType = "invalid";
            } else {
                if (bChoice == 1) burgerType = "veg";
                else if (bChoice == 2) burgerType = "chicken";
                else if (bChoice == 3) burgerType = "special";
                else burgerType = "invalid";
            }

            burger = factory->createBurger(burgerType);
            if (burger) burger->prepare();
        }

        // Bread menu
        if (choice == 'R' || choice == 'r' || choice == 'A' || choice == 'a') {
            cout << "\n🍞 Bread Menu (" << category << "):" << endl;
            if (category == "normal") {
                cout << "1. Wheat Bread" << endl;
                cout << "2. Brown Bread" << endl;
            } else {
                cout << "1. Multigrain Bread" << endl;
                cout << "2. Garlic Bread" << endl;
            }

            cout << "Enter bread choice: ";
            int brChoice;
            cin >> brChoice;

            if (category == "normal") {
                if (brChoice == 1) breadType = "wheat";
                else if (brChoice == 2) breadType = "brown";
                else breadType = "invalid";
            } else {
                if (brChoice == 1) breadType = "multigrain";
                else if (brChoice == 2) breadType = "garlic";
                else breadType = "invalid";
            }

            bread = factory->createBread(breadType);
            if (bread) bread->prepare();
        }

        cout << "\n✅ Order Completed! Enjoy your meal 😋" << endl;

    }
};

int main() {
    Application app;
    app.run(); // everything handled inside Application
    return 0;
}
