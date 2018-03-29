#define CATCH_CONFIG_FAST_COMPILE
#include <memory>
using std::unique_ptr;
#include "catch.hpp"
#include "Shape.h"
#include "SimpleShapes.h"

TEST_CASE( "Base Class: Cursor", "[base]" ) {
    unique_ptr<Shape> shape(new Shape());
    REQUIRE(shape->getLocX()==0);
    REQUIRE(shape->getLocY()==0);
    shape->setCursor(200,200);
    REQUIRE(shape->getLocX()==200);
    REQUIRE(shape->getLocY()==200);
    shape->setCursor(840,700);
	REQUIRE(shape->getLocX()==840);
	REQUIRE(shape->getLocY()==600);
}
//Not sure how we want to do coords like this or should we just undle in the constructor.
TEST_CASE("Simple Shape Construction: Circle", "[shapes]"){
    unique_ptr<Shape> shape(new Circle(10));
    shape->setCursor(10,10);
    REQUIRE(shape->getSize()==10);
    REQUIRE(shape->getPostscript()=="gsave 10 10 translate 0 0 10 0 360 arc stroke grestore");
}
TEST_CASE("Simple Shape Construction: Polygon", "[shapes]"){
    unique_ptr<Shape> shape(new Polygon(5,10));
    shape->setCursor(100,100);
    REQUIRE(shape->getSize()==10);
    REQUIRE(shape->getPostscript()=="gsave 100 100 translate /S 5 def /H 100 def /A 360 S div def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } repeat closepath stroke grestore");
}

TEST_CASE("Simple Shape Construction: Rectangle", "[shapes]"){
    unique_ptr<Shape> shape(new Rectangle(5,10));
    shape->setCursor(5,5);
    REQUIRE(shape->getSize()==10);
    REQUIRE(shape->getPostscript()=="gsave 5 5 translate newpath -2.5 -5 moveto 2.5 -5 lineto 2.5 5 lineto -2.5 5 lineto closepath stroke grestore");
}
TEST_CASE("Simple Shape Construction: Spacer", "[shapes]"){
    unique_ptr<Shape> shape(new Spacer(5,10));
    shape->setCursor(5,5);
    REQUIRE(shape->getSize()==10);
}
TEST_CASE("Simple Shape Construction: Square", "[shapes]"){
        unique_ptr<Shape> shape(new Square(10));
        shape->setCursor(5,5);
        REQUIRE(shape->getSize()==10);
        REQUIRE(shape->getPostscript()=="gsave 5 5 translate newpath -5 -5 moveto 5 -5 lineto 5 5 lineto -5 5 lineto closepath stroke grestore");
}
TEST_CASE("Simple Shape Construction: Triangle", "[shapes]"){
        unique_ptr<Shape> shape(new Triangle(10));
        shape->setCursor(5,5);
        REQUIRE(shape->getSize()==10);
        REQUIRE(shape->getPostscript()=="gsave 5 5 translate newpath -5 -5 moveto 5 -5 lineto 0 5 lineto closepath stroke grestore");
}

TEST_CASE("Compound Shape Construction: Rotation 90", "[compoundShapes]") {
	unique_ptr<Shape> shape(new Triangle(10));
	shape->setCursor(5, 5);
	Rotation angle(90);
	unique_ptr<Shape> rotated(new Rotated(shape, angle);
	REQUIRE(rotated->getPostScript() == "gsave 5 5 translate 90 rotate newpath -5 -5 moveto 5 -5 lineto 0 5 lineto closepath stroke grestore");
}
TEST_CASE( "Rotation: Triangle 180") {
    unique_ptr<Shape> shape(new Triangle(10));
    shape->setCursor(5,5);
    Rotation angle(180);
    unique_ptr<Shape> rotated(new Rotated(shape, angle);
    REQUIRE(rotated->getPostScript()=="gsave 5 5 translate 180 rotate newpath -5 -5 moveto 5 -5 lineto 0 5 lineto closepath stroke grestore");
}
TEST_CASE( "Rotation: Triangle 270") {
    unique_ptr<Shape> shape(new Triangle(10));
    shape->setCursor(5,5);
    Rotation angle(270);
    unique_ptr<Shape> rotated(new Rotated(shape, angle);
    REQUIRE(rotated->getPostScript()=="gsave 5 5 translate 270 rotate newpath -5 -5 moveto 5 -5 lineto 0 5 lineto closepath stroke grestore");
}

