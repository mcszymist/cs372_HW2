#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include "ComplexShapes.h"

string Rotated::getPostscript(){
    stringstream ss;
    ss << angle << " rotate " << shape->getPostscript();
    return ss.str();
}

string VerticalShape::getPostscript(){
    return "TRIANGLE SQUARE CIRCLE";
}