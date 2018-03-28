#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <memory>
using std::unique_ptr;
#include "catch.hpp"
#include "CPS.h"

SECTION( "Base Class: Cursor", "[base]" ) {
    unique_ptr<Shape> shape(new Shape());
        
    TEST_CASE("Default Cursor: "){
        REQUIRE(shape->getLocX()==0);
        REQUIRE(shape->getLocY()==0);
    }
    TEST_CASE("Move Cursor: 200,200"){
        shape->setCursor(200,200);
        REQUIRE(shape->getLocX()==200);
        REQUIRE(shape->getLocY()==200);
    }
    TEST_CASE("Max Cursor: 840,700"){
        shape->setCursor(840,700);
        REQUIRE(shape->getLocX()==840);
        REQUIRE(shape->getLocY()==700);
    }  
}
//I have a few ideas on how to pass cords should we just put a pointer to a central base class that it constructs from.
SECTION("Simple Shape Construction: Circle", "[shapes]"){
    TEST_CASE("Circle 10"){
        unique_ptr<Shape> shape(new Circle(10));
        REQUIRE(shape->getSize()==10);
        REQUIRE(shape->getPostscript()=="");
}

SECTION("Simple Shape Construction: Polygon", "[shapes]"){
    TEST_CASE( "Polygon 5,10") {
        unique_ptr<Shape> shape(new Polygon(5,10));
        REQUIRE(shape->getSize()==10);
        REQUIRE(shape->getPostscript()=="");
    }
}

SECTION("Simple Shape Construction: Rectangle", "[shapes]"){
    TEST_CASE( "Rectangle: 5,10") {
        unique_ptr<Shape> shape(new Rectangle(5,10));
        REQUIRE(shape->getSize()==10);
        REQUIRE(shape->getPostscript()=="");
    }
}
SECTION("Simple Shape Construction: Spacer", "[shapes]"){
    TEST_CASE( "Spacer: 5,10") {
        unique_ptr<Shape> shape(new Spacer(5,10));
        REQUIRE(shape->getSize()==10);
        REQUIRE(shape->getPostscript()=="");
    }
}
SECTION("Simple Shape Construction: Square", "[shapes]"){
    TEST_CASE( "Square: 10") {
        unique_ptr<Shape> shape(new Square(10));
        REQUIRE(shape->getSize()==10);
        REQUIRE(shape->getPostscript()=="");
    }
}
SECTION("Simple Shape Construction: Triangle", "[shapes]"){
    TEST_CASE( "Triangle: 10") {
        unique_ptr<Shape> shape(new Triangle(10));
        REQUIRE(shape->getSize()==10);
        REQUIRE(shape->getPostscript()=="");
    }
}
SECTION("Compound Shape Construction: Rotation Square", "[compoundShapes]"){
    TEST_CASE( "Rotation: ") {
        unique_ptr<Shape> shape(new Square(10));
        Rotation angle(180);
        Rotated(shape, angle);
        //check
        
    }
}