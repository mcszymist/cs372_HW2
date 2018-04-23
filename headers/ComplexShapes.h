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

#include "Shape.h"

class ComplexShapes : public Shape{
public:
    vector<shared_ptr<Shape>> shapes;
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
         // Populate vector
        for (auto shape : list)
            shapes.push_back(shape);

        auto startShape = shapes[0];
        
        for (auto shape: shapes) {
            if (getHeight() < shape->getWidth()) {
                setHeight(shape->getHeight());
            }
            if (getWidth() < shape->getWidth()){
                setWidth(shape->getWidth());
            }

            shape->setCursor(startShape->getLocX(), startShape->getLocY());
            
        }
    }
};

class VerticalShape : public ComplexShapes{
public:
    VerticalShape(initializer_list<shared_ptr<Shape>> list) {
        // Populate vector
        for (auto shape : list)
            shapes.push_back(shape);
        
        // Set height and width
        for (auto shape : shapes ) {
            setHeight(getHeight() + shape->getHeight());
            if (getWidth() < shape->getWidth())
                setWidth(shape->getWidth());
        };

        // Set coordinates for bounding boxes
        for (std::size_t i = 1; i != shapes.size(); i++) { // Iterators didn't work so we're doing indices
            auto shape = shapes[i];
            auto prevShape = shapes[i-1];
            shape->setCursor( prevShape->getLocX() , (prevShape->getLocY() + ((prevShape->getHeight())/2) + (shape->getHeight()/2) ) );
        };
    }
};

class HorizontalShape : public ComplexShapes{
public:
    HorizontalShape(initializer_list<shared_ptr<Shape>> list) {
        // Populate vector
        for (auto shape : list)
            shapes.push_back(shape);

        // Set height and width
        for (auto shape : shapes) {
            if (getHeight() < shape->getHeight())
                setHeight(shape->getHeight());
            setWidth(getWidth() + shape->getWidth());
        }
        // Set coordinates for bounding boxes
        for (std::size_t i = 1; i != shapes.size(); i++) { // Iterators didn't work so we're doing indices
            auto shape = shapes[i];
            auto prevShape = shapes[i-1];
            shape->setCursor( (prevShape->getLocX() + ((prevShape->getWidth())/2) + (shape->getWidth()/2) ), prevShape->getLocY() );
        };
    }
};

#endif
