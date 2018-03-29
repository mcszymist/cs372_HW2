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
    return "";
}
string Square::getPostscript(){
    return "";
}
string Rectangle::getPostscript(){
    return "";
}
string Spacer::getPostscript(){
    return "";
}
string Polygon::getPostscript(){
    return "";
}
