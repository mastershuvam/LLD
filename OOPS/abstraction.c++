#include <iostream>
#include <string>

using namespace std;

class Car{
    public:
    //car behaviors
        virtual void startEngine()=0;
        virtual void shiftGear(int gear)=0;
        virtual void accelerate()=0;
        virtual void brake()=0; // Uncomment if you want to add braking functionality
        virtual void stopEngine()=0;

        virtual ~Car(){} //virtual destructor for proper cleanup
};

// Concrete class inheriting from Car
class SportsCar : public Car{
    public:
    //Car characteristics
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

    // Implementing the abstract methods
    SportsCar(string b,string m){
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
    }

    void startEngine()override{
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void shiftGear(int gear)override{
        //check engine start or not
        if(!isEngineOn){
            cout << "Cannot shift gear. Engine is off." << endl;
            return;
        }
        if(gear < 0 || gear > 6){
            cout << "Invalid gear. Please select a gear between 0 and 6." << endl;
            return;
        }
        currentGear = gear;
        cout<< "Gear shifted to: "<<currentGear<<endl;
    }

    void accelerate()override{
        //check engine start or not
        if(!isEngineOn){
            cout << "Cannot accelerate. Engine is off." << endl;
            return;
        }
        if(currentGear == 0){
            cout << "Cannot accelerate. Please shift to a gear first." << endl;
            return;
        }
        // Increase speed based on current gear
        currentSpeed += 10; // Increase speed by 10 units

        if(currentSpeed > 200) {
            currentSpeed = 200; // Cap speed at 200 km/h
            cout << "Maximum speed reached for " << brand << " " << model << endl;
            return;
        }

        cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
    }

    void brake()override{
        currentSpeed -= 10; // Decrease speed by 10 units
        if(currentSpeed < 0) currentSpeed = 0; // Prevent negative speed
        cout << "Braking. Current speed: " << currentSpeed << " km/h"<<endl;
    }

    void stopEngine()override{
        isEngineOn = false;
        currentSpeed = 0; // Reset speed when engine is stopped
        currentGear = 0; // Reset gear when engine is stopped
        cout << "Engine stopped for " << brand << " " << model << endl;
    }


    ~SportsCar() override {
        cout << "Destroying SportsCar object for " << brand << " " << model << endl;
    }
};

int main() {
    string brand, model;
    cout << "Enter car brand: ";
    getline(cin, brand);
    cout << "Enter car model: ";
    getline(cin, model);

    Car* myCar = new SportsCar(brand, model);

    myCar->startEngine();

    int choice;
    while (true) {
        cout << "\nChoose an action:\n";
        cout << "1. Shift Gear\n";
        cout << "2. Accelerate\n";
        cout << "3. Brake\n";
        cout << "4. Stop Engine\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int gear;
            cout << "Enter gear (0-6): ";
            cin >> gear;
            myCar->shiftGear(gear);
        } else if (choice == 2) {
            myCar->accelerate();
        } else if (choice == 3) {
            myCar->brake();
        } else if (choice == 4) {
            myCar->stopEngine();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    delete myCar; // Clean up memory
    cout << "Program finished." << endl;

    return 0;
}
