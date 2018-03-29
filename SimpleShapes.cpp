#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include "SimpleShapes.h"

string Circle::getPostscript(){
    stringstream ss;
    ss << "0 0 " << radius << " 0 360 arc stroke";
    return ss.str();
}

string Triangle::getPostscript(){
    stringstream ss;
    ss << "0 0 0 360 arc stroke";
    return ss.str();
}
string Square::getPostscript(){
    stringstream ss;
    ss << "0 0  0 360 arc stroke";
    return ss.str();
}
string Rectangle::getPostscript(){
    stringstream ss;
    double width = getWidth()/2.0;
    double height = getHeight()/2.0;
    ss << "newpath -"<< width <<" -"<< height << " moveto "<< width <<" -" << height;
    ss << " lineto "<< width <<" " << height <<" lineto -"<< width << " " << height <<" lineto closepath stroke";
    return ss.str();
}
string Spacer::getPostscript(){
    stringstream ss;
    ss << "0 0 0 360 arc stroke";
    return ss.str();
}
string Polygon::getPostscript(){
    stringstream ss;
    ss << "0 0 0 360 arc stroke";
    return ss.str();
}
