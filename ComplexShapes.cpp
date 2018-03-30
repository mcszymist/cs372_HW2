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

string Scaled::getPostscript(){
    stringstream ss;
    ss << shape->getPostscript() << " " << getFX() << " "<< getFY() << " scaled";
    return ss.str();
}