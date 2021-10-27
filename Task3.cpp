#include <iostream>
using namespace std;
#pragma region Task1
class Figure {
public:

    virtual void area()=0; 
   

};
class Circle : public Figure {
private:
    float p = 3.14;
    int r = 3;
    float s;
public:
    void area() {
        s = p * r * r;
    }
    void printCircle() {
        cout << s << endl;
    }
};
class Parallelogram : public Figure {
protected:
    int a = 4;
    int h = 4;
    int s;
public:
    void area() {
      s = a * h;
       
    }
    void printArea() {
        cout << s << endl;
    }
};

class Rectangle : public Parallelogram {
public:  Rectangle() { 
        a = 6;
        h = 9;
    }
};
class Square : public Parallelogram {
public:  Square() {
        a = 9;
        h = a;
    }
};
class Rhombus : public Parallelogram {
public:  Rhombus() {
        a = 10;
        h = 5;
    }
};


#pragma endregion

#pragma region Task2

class Car {
public:
     string company;
     string model;
     Car() {}
     Car(string c, string m) : company(c), model(m) {
       
     }

     ~Car() {}

     };
class PassengerCar : virtual public Car {
public:
    PassengerCar() {}
    PassengerCar(string c, string m):Car(c,m){
    
        cout << company << " " << model << endl;
    }
    ~PassengerCar(){}

};
class Bus : virtual public Car {
public:
    Bus() {}
    Bus (string c, string m) :Car(c, m) {
    
        cout << company << " " << model << endl;
    }
    ~Bus(){}
};
class Minivan : public PassengerCar, public Bus {
public:

    Minivan(string c, string m) : Car(c,m) {

        cout << company << "  " << model << endl;
    }
    ~Minivan(){}
};
#pragma endregion



    int main()
    {
        Parallelogram area;
        area.area();
        area.printArea();
        Rectangle area1;
        area1.area();
        area1.printArea();
        Square area2;
        area2.area();
        area2.printArea();
        Rhombus area3;
        area3.area();
        area3.printArea();
        Circle areaCircle;
        areaCircle.area();
        areaCircle.printCircle();

        cout << endl;

        Car* car = new Car("Company", "Model");
        PassengerCar* passengerCar = new PassengerCar("Lada", "Vesta");
        Bus* bus = new Bus("Ikarus", "2406");
        Minivan* minivan = new Minivan("Mersedes", "Vitto");

        return 0;
    }