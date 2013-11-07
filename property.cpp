/*
 * propriedade.cpp
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "property.h"

// constructors

Property::Property(string address, float area, int floor) {
	this->address = address;
	this->area = area;
	this->floor = floor;
}

Apartment::Apartment(string address, float area, int floor) : Property(address, area, floor) {
}

Office::Office(string address, float area, int floor) : Property(address, area, floor) {
}

Store::Store(string address, float area, int floor) : Property(address, area, floor) {
}

// get & sets

string Property::getAddress() {
	return address;
}

float Property::getArea() {
	return area;
}

int Property::getFloor() {
	return floor;
}

int Apartment::returnType() const {
	return 1;
}

int Office::returnType() const {
	return 2;
}

int Store::returnType() const {
	return 3;
}

string Apartment::printType() const {
	return "Apartment";
}

string Office::printType() const {
	return "Office";
}

string Store::printType() const {
	return "Store";
}

Property::Property() {
	address = "";
}

Apartment::Apartment():Property(){
}

Office::Office():Property(){
}

Store::Store():Property(){
}

void Property::setAddress(string name) {
	address = name;
}

