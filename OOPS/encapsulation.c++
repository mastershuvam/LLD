/*
encapsulation means hiding the internal state and functionality of an object and only exposing a controlled interface to interact with it. This is achieved through access modifiers that restrict access to class members.

encapsulation modifiers in C++:

public
private
protected

*/


#include <iostream>
#include <string>

using namespace std;

class sportsCar{
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

        string tyreCompany;


    public:    // Implementing the abstract methods
    sportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        tyreCompany = "MRF";
    }

    //introducing geter and setter

    string getTyreCompany(){
        return tyreCompany;
    }

    int getSpeed(){
        return currentSpeed;
    }

    void setTyreCompany(string company){
        this->tyreCompany = company;
    }

    void startEngine() {
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void shiftGear(int gear){
        //check engine start or not
        if(!isEngineOn){
            cout << "Cannot shift gear. Engine is off." << endl;
            return;
        }
        currentGear = gear;
        cout << "Gear shifted to: " << currentGear << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<< "Cannot accelerate. Engine is off." << endl;
            return;
        }
        if(currentGear == 0){
            cout << "Cannot accelerate. Please shift to a higher gear." << endl;
            return;
        }
        currentSpeed += 10; // Increase speed by 10 units
        cout<<"Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
    }

    void brake(){
        if(!isEngineOn){
            cout << "Cannot brake. Engine is off." << endl;
            return;
        }
        currentSpeed -= 10; // Decrease speed by 10 units
        if(currentSpeed < 0) currentSpeed = 0; // Prevent negative speed
        cout << "Braking. Current speed: " << currentSpeed << " km/h"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0; // Reset speed when engine is stopped
        currentGear = 0; // Reset gear when engine is stopped
        cout << "Engine stopped for " << brand << " " << model << endl;
    }


    // Destructor to clean up resources
    ~sportsCar() {
        cout << "Destroying sportsCar object for " << brand << " " << model << endl;
    }
};

int main(){
    //create object of class super car
    sportsCar * mySuperCar = new sportsCar("Lamborgini","Aventador");
    mySuperCar->startEngine();
    mySuperCar->shiftGear(1);
    mySuperCar->accelerate();
    mySuperCar->brake();
    mySuperCar->stopEngine();
    mySuperCar->setTyreCompany("CEAT");

    cout<< "current spedd is: "<<mySuperCar->getSpeed()<<endl;

    cout<< "Tyre company is: "<<mySuperCar->getTyreCompany()<<endl;

    delete mySuperCar; // Clean up memory

    cout << "Program finished." << endl;

    return 0;
}