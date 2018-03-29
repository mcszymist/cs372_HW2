#include <string>
using std::string;
#include "Shape.h"

class Circle : public Shape{
private:
    int radius;
public:
    Circle(int h) : radius(h/2){
        setHeight(h);
    }
    string getPostscript() override;
};
class Triangle : public Shape{
public:
    Triangle(int h){
        setHeight(h);
        setWidth(h);
    }
    string getPostscript() override;
};
class Polygon : public Shape{
private:
    int sides;
public:
    Polygon(int s,int h) : sides(s){
        setHeight(h);
        setWidth(h);
    }
    string getPostscript() override;
};
class Square : public Shape{
public:
    Square(int h){
        setHeight(h);
        setWidth(h);
    }
    string getPostscript() override;
};
class Rectangle : public Shape{
public:
    Rectangle(int w,int h){
        setHeight(h);
        setWidth(w);
    }
    string getPostscript() override;
};
class Spacer : public Shape{
public:
    Spacer(int w,int h){
        setHeight(h);
        setWidth(w);
    }
    string getPostscript() override;
};
