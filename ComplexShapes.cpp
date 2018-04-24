#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include "headers/ComplexShapes.h"

string Rotated::getPostscript(){
    stringstream ss;
    ss << angle << " rotate " << shape->getPostscript();
    return ss.str();
}

string Scaled::getPostscript(){
    stringstream ss;
    ss << getFX() << " " << getFY() << " scale " <<shape->getPostscript();
    return ss.str();
}

string ComplexShapes::getPostscript() {
    stringstream ss;
    for (auto shape : shapes )
        ss << shape->finalize() << " ";
    string ps = ss.str();
    ps.pop_back(); // Delete the last space!
    return ps;
}
void ComplexShapes::fillVector(initializer_list<shared_ptr<Shape>> list){
    for (auto shape : list)
        shapes.push_back(shape);
        calculateCompoundSize(shape);
        calculateBiggestSize(shape);
    return;
}

void Layered::calculateBiggestSize(shared_ptr<Shape> shape){
    if (getHeight() < shape->getHeight()) {
        setHeight(shape->getHeight());
    }
    if (getWidth() < shape->getWidth()){
        setWidth(shape->getWidth());
    }
};
void Layered::calculateCompoundSize(shared_ptr<Shape> shape){
    
};
