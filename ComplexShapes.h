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
        setWidth(s->getWidth());
        setHeight(s->getHeight());
        setCursor(s->getLocX(),s->getLocY());
    }
    string getPostscript() override;
};

class VerticalShape : public Shape{
private:
    vector<shared_ptr<Shape>> shapes;

public:
    VerticalShape(initializer_list<shared_ptr<Shape>> list) {
        setHeight(0);   // Initialize height

        // Populate vector
        for (auto shape : list)
            shapes.push_back(shape);
        
        // Set height and width
        for (auto shape : shapes ) {
            setHeight(getHeight() + shape->getHeight());
            if (getWidth() <  shape->getWidth())
                setWidth(shape->getWidth());
        };

        // Set coordinates for bounding boxes
        for (std::size_t i = 1; i != shapes.size(); i++) { // Iterators didn't work so we're doing indices
            auto shape = shapes[i];
            auto prevShape = shapes[i-1];
            shape->setCursor( prevShape->getLocX() , (prevShape->getLocY() + ((prevShape->getHeight())/2) + (shape->getHeight()/2) ) );
        };
    }

    string getPostscript() override;
};

#endif