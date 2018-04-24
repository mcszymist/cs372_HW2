#ifndef COMPLEXSHAPES_H
#define COMPLEXSHAPES_H
#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;
#include <functional>
#include "Shape.h"

class ComplexShapes : public Shape{
public:
    vector<shared_ptr<Shape>> shapes;
    void fillVars(initializer_list<shared_ptr<Shape>> list);
    virtual void calculateCompoundSize(shared_ptr<Shape> shape) = 0;
    virtual void calculateBiggestSize(shared_ptr<Shape> shape) = 0;
	virtual void setPos() = 0;
    string getPostscript() override;
};

class Rotation{
private:
    int angle;
public:
    Rotation(int a){
        if(a == 90 || a == 180 || a == 270){
            angle = a;
        }
        else
        {
            angle = 0;
        }
    }
    int getAngle(){
        return angle;
    };
};

class Rotated : public Shape{
private:
    int angle;
    shared_ptr<Shape> shape;

public:
    Rotated(shared_ptr<Shape> s,Rotation a) : shape(s){
        angle = a.getAngle();
        if(angle == 90 || angle == 270){
            setWidth(s->getHeight());
            setHeight(s->getWidth());
        }
        else{
            setWidth(s->getWidth());
            setHeight(s->getHeight());
        }
        setCursor(s->getLocX(),s->getLocY());
    }
    string getPostscript() override;
};

class Scaled : public Shape{
private:
    double fx;
    double fy;
    shared_ptr<Shape> shape;

public:
    Scaled(shared_ptr<Shape> s, double _fx, double _fy) : fx(_fx), fy(_fy), shape(s){
        setWidth(s->getWidth());
        setHeight(s->getHeight());
        setCursor(s->getLocX(),s->getLocY());
    }
    string getPostscript() override;

    double getFX(){
        return fx;
    }

    double getFY(){
        return fy;
    }
};

class Layered : public ComplexShapes{
public:
    Layered(initializer_list<shared_ptr<Shape>> list) {
        fillVars(list);
    }
    void calculateBiggestSize(shared_ptr<Shape> shape) override;
    void calculateCompoundSize(shared_ptr<Shape> shape) override;
	void setPos() override;
};

class VerticalShape : public ComplexShapes{
public:
    VerticalShape(initializer_list<shared_ptr<Shape>> list) {
        fillVars(list);
    }
    void calculateBiggestSize(shared_ptr<Shape> shape) override;
    void calculateCompoundSize(shared_ptr<Shape> shape) override;
	void setPos() override;
};

class HorizontalShape : public ComplexShapes{
public:
    HorizontalShape(initializer_list<shared_ptr<Shape>> list) {
        fillVars(list);
    }
    void calculateBiggestSize(shared_ptr<Shape> shape) override;
    void calculateCompoundSize(shared_ptr<Shape> shape) override;
	void setPos() override;
};

#endif
