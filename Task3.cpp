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

#pragma region Task3

class Fraction
{
private:
    double numerator, denominator;
public:
    Fraction(double inputNumerator, double inputDenominator)
        : numerator(inputNumerator), denominator(inputDenominator)
    {
        if (denominator == 0) denominator = 0.00000001;
    }

    friend Fraction operator+(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1);
    friend ostream& operator<<(ostream& out, const Fraction& fraction);

    void setDenominator(double inputDenominator)
    {
        if (inputDenominator == 0) inputDenominator = 0.00000001;
        denominator = inputDenominator;
    }

    void setNumerator(double inputNumerator)
    {
        numerator = inputNumerator;
    }

    double getNumerator()
    {
        return numerator;
    }

    double getDenominator()
    {
        return denominator;
    }
};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
    return Fraction(-d1.numerator, -d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2)
{
    if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
    else return false;
}

bool operator!=(Fraction& d1, Fraction& d2)
{
    if (d1 == d2) return false;
    else return true;
}

bool operator>(Fraction& d1, Fraction& d2)
{
    if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator<=(Fraction& d1, Fraction& d2)
{
    if (!(d1 > d2)) return true;
    else return false;
}

bool operator<(Fraction& d1, Fraction& d2)
{
    if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator>=(Fraction& d1, Fraction& d2)
{
    if (!(d1 < d2)) return true;
    else return false;
}


ostream& operator<<(ostream& out, const Fraction& fraction)
{
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
}

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

        PassengerCar* passengerCar = new PassengerCar("Lada", "Vesta");
        Bus* bus = new Bus("Ikarus", "2406");
        Minivan* minivan = new Minivan("Mersedes", "Vitto");

        cout << endl;

        Fraction d1(6, 4);
        Fraction d2(5, 8);
        cout << "\n\n" << (d1 + d2);
        cout << "\n\n" << (d1 - d2);
        cout << "\n\n" << (d1 * d2);
        cout << "\n\n" << (d1 / d2);
        cout << "\n\n" << (-d1) << "\n";

        if (d1 == d2) cout << "\nFraction 1 == Fraction 2";
        if (d1 != d2) cout << "\nFraction 1 != Fraction 2";
        if (d1 > d2) cout << "\nFraction 1 > Fraction 2";
        if (d1 <= d2) cout << "\nFraction 1 <= Fraction 2";
        if (d1 < d2) cout << "\nFraction 1 < Fraction 2";
        if (d1 >= d2) cout << "\nFraction 1 >= Fraction 2";
    

        return 0;
    }