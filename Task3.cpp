#include <iostream>
using namespace std;

class Figure {
public:

    virtual void area()=0; 
    void printArea();

};
class Parallelogram : public Figure {
private:
    int a = 4;
    int h = 2;

public:
    void area() {
       int s = a * h;
    }
};
class Circle : public Figure {

    void area();

};
class Rectangle : public Parallelogram {

    void area();
};
class Square : public Parallelogram {

    void area();
};
class Rhombus : public Parallelogram {

    void area();
};


int main()
{

    return 0;
}

