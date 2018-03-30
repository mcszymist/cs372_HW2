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
    ss << "/W "<<getWidth()/2.0<<" def /H "<< getHeight()/2.0 <<" def newpath -W -H moveto W -H lineto 0 H lineto closepath stroke";
    return ss.str();
}
string Square::getPostscript(){
    stringstream ss;
    ss << "/W "<< getWidth()/2.0 <<" def /H "<< getHeight()/2.0 <<" def newpath -W -H moveto W -H lineto W H lineto -W H lineto closepath stroke";
    return ss.str();
}
string Rectangle::getPostscript(){
    stringstream ss;
    ss << "/W "<< getWidth()/2.0 <<" def /H "<< getHeight()/2.0 <<" def newpath -W -H moveto W -H lineto W H lineto -W H lineto closepath stroke";
    return ss.str();
}
string Spacer::getPostscript(){
    return "";
}
string Polygon::getPostscript(){
    stringstream ss;
    ss << "0 0 0 360 arc stroke";
    return ss.str();
}
