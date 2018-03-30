#include "UniqueShapes.h"
#include <string>
using std::string;
#include <sstream>
using std::stringstream;


string CircleWithArcs::getPostscript(){
    stringstream ss;
    ss << "/W "<< getWidth()/2.0 <<" def /H "<< getHeight()/2.0 <<" def newpath -W -H moveto W -H lineto W H lineto -W H lineto closepath stroke";
    return ss.str();
}