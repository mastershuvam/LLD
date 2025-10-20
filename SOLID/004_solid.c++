//I : Interface Segregation Principle 

#include<iostream>
using namespace std;

//2d shape
class TwoDimensionalShape{
    public:
    virtual double area() = 0;
};

//3d shape
class ThreeDimensionalShape{
    public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

// Square implements only the 2D interface
class Square : public TwoDimensionalShape{
    double side;
    public:
    Square(double side){
        this->side = side;
    }

    double area()override{
        return side*side;
    }

};

// Rectangle implements only the 2D interface
class Rectangle : public TwoDimensionalShape{
    double length, width;
    public:
    Rectangle(double length,double width){
        this->length = length;
        this->width = width;
    }

    double area()override{
        return length * width;
    }
};

// Cube implements the 3D interface
class Cube : public ThreeDimensionalShape{
    double side;

    public:
    Cube(double side){
        this->side = side;
    }

    double area()override{
        return 6*side*side;
    }

    double volume() override {
        return side * side * side;
    }
};


int main() {
    int choice;
    cout << "Choose Shape Type:\n";
    cout << "1. Square (2D)\n";
    cout << "2. Rectangle (2D)\n";
    cout << "3. Cube (3D)\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        double side;
        cout << "Enter side length of square: ";
        cin >> side;

        TwoDimensionalShape* square = new Square(side);
        cout << "Area of Square: " << square->area() << endl;
        delete square;
    }
    else if (choice == 2) {
        double length, width;
        cout << "Enter length and width of rectangle: ";
        cin >> length >> width;

        TwoDimensionalShape* rectangle = new Rectangle(length, width);
        cout << "Area of Rectangle: " << rectangle->area() << endl;
        delete rectangle;
    }
    else if (choice == 3) {
        double side;
        cout << "Enter side length of cube: ";
        cin >> side;

        ThreeDimensionalShape* cube = new Cube(side);
        cout << "Surface Area of Cube: " << cube->area() << endl;
        cout << "Volume of Cube: " << cube->volume() << endl;
        delete cube;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}