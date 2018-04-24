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
void ComplexShapes::fillVars(initializer_list<shared_ptr<Shape>> list) {
	for (auto shape : list) {
		shapes.push_back(shape);
		calculateCompoundSize(shape);
		calculateBiggestSize(shape);
	}
	setPos();
}

void Layered::calculateBiggestSize(shared_ptr<Shape> shape){
    if (getHeight() < shape->getHeight()) {
        setHeight(shape->getHeight());
    }
    if (getWidth() < shape->getWidth()){
        setWidth(shape->getWidth());
    }
	return;
};
void Layered::calculateCompoundSize(shared_ptr<Shape> shape){
	return;
};
void Layered::setPos() {
	auto startShape = shapes[0];
	for (auto shape : shapes) {
		shape->setCursor(startShape->getLocX(), startShape->getLocY());
	}
	return;
};

void HorizontalShape::calculateBiggestSize(shared_ptr<Shape> shape) {
	if (getHeight() < shape->getHeight())
		setHeight(shape->getHeight());
	return;
};
void HorizontalShape::calculateCompoundSize(shared_ptr<Shape> shape) {
	setWidth(getWidth() + shape->getWidth());
	return;
};
void HorizontalShape::setPos() {
	for (std::size_t i = 1; i != shapes.size(); i++) { // Iterators didn't work so we're doing indices
		auto shape = shapes[i];
		auto prevShape = shapes[i - 1];
		shape->setCursor((prevShape->getLocX() + ((prevShape->getWidth()) / 2) + (shape->getWidth() / 2)), prevShape->getLocY());
	};
	return;
};
void VerticalShape::calculateBiggestSize(shared_ptr<Shape> shape) {
	if (getWidth() < shape->getWidth())
		setWidth(shape->getWidth());
	return;
};
void VerticalShape::calculateCompoundSize(shared_ptr<Shape> shape) {
	setHeight(getHeight() + shape->getHeight());
	return;
};

void VerticalShape::setPos() {
	for (std::size_t i = 1; i != shapes.size(); i++) { // Iterators didn't work so we're doing indices
		auto shape = shapes[i];
		auto prevShape = shapes[i - 1];
		shape->setCursor(prevShape->getLocX(), (prevShape->getLocY() + ((prevShape->getHeight()) / 2) + (shape->getHeight() / 2)));
	};
	return;
};