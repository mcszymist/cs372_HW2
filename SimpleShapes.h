#include "Shape.h"

class Circle : public Shape{
private:
    int radius;
public:
    Circle(int h) : radius(h/2){
        setHeight(h);
    }
};
class Triangle : public Shape{

};
class Polygon : public Shape{

};
class Square : public Shape{

};
class Rectangle : public Shape{

};
class Spacer : public Shape{

};
