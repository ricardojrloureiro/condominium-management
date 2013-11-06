/*
 * propriedade.cpp
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "property.h"

// constructors

Property::Property(string address) {
	this->address = address;
}

Apartment::Apartment(string address) : Property(address) {
}

Office::Office(string address) : Property(address) {
}

Store::Store(string address) : Property(address) {
}

// get & sets

int Property::getCost() {
	return 0;
}

string Property::getAddress() {
	return address;
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

