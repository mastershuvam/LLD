#include<iostream>
#include<string>

using namespace std;

class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;

    //constructor
    public:
        Car(string b, string m) {
            this->brand = b;
            this->model = m;
            this->isEngineOn = false;
            currentSpeed = 0;
        }

    //car comon methods
    void startEngine(){
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0; // Reset speed when engine is stopped
        cout << "Engine stopped for " << brand << " " << model << endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << "Cannot accelerate. Engine is off." << endl;
            return;
        }
        currentSpeed += 20; // Increase speed by 10 units
        cout << "Accelerating. Current speed: " << currentSpeed << " km/h" << endl;
    }

    void brake(){
        currentSpeed -= 10; // Decrease speed by 10 units
        if(currentSpeed < 0) currentSpeed = 0; // Prevent negative speed
        cout << "Braking. Current speed: " << currentSpeed << " km/h"<<endl;
    }

    //destructor
    virtual ~Car(){}
    
};

class petrolCar : public Car{
    private:
        int currentGear;


    //constructor
    public:
        petrolCar(string b, string m): Car(b,m){
            currentGear = 0;
        }
    
    //petrol car specific methods
    void shiftGear(int gear){
        //check engine start or not
       
        if(isEngineOn){
            currentGear = gear;
        }else{
            cout << "Cannot shift gear. Engine is off." << endl;
            return;
        }

        cout << "Gear shifted to: " << currentGear << endl;
    }

};


class electricCar : public Car{
    private:
        int batteryLevel;

    //constructor
    public:
        electricCar(string b,string m): Car(b,m){
            batteryLevel = 100; // Assume full battery at start
        }

    //electric car specific methods
    void chargeBattery(int amount){
        batteryLevel = amount; // Fully charge the battery
        cout << "Battery charged to " << batteryLevel << "%" << endl;
    }
};

int main(){
    petrolCar * myPetrolCar = new petrolCar("Toyota", "Corolla");
    myPetrolCar->startEngine();
    myPetrolCar->shiftGear(1);
    myPetrolCar->accelerate();
    myPetrolCar->brake();
    myPetrolCar->stopEngine();
    delete myPetrolCar; // Clean up memory


    cout << "-------------------------------------" << endl;

    electricCar * myElectricCar = new electricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->chargeBattery(20);
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar; // Clean up memory
    
    return 0;
}


