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

int Property::getCost() {
	return cost;
}

Apartment::Apartment(int area,string address) : Property(address) {
	this->area = area;
}

Office::Office(int area,string address) : Property(address) {
	this->area = area;
}

Store::Store(int area,string address) : Property(address) {
	this->area = area;
}

// get & sets

int Property::returnType() const {
	return 0;
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

int Store::getArea(){
	return area;
}

int Office::getArea(){
	return area;
}

int Apartment::getArea(){
	return area;
}

void Store::setArea(int area){
	this->area = area;
}

void Office::setArea(int area){
	this->area = area;
}

void Apartment::setArea(int area){
	this->area = area;
}

// other functions

void Apartment::showInfo() const{
	Property::showInfo(); cout <<" cost: " << cost << " area: " << area << endl;
}

void Office::showInfo() const{
	Property::showInfo(); cout <<" cost: " << cost << " area: " << area << endl;
}

void Store::showInfo()const {
	Property::showInfo(); cout <<" cost: " << cost << " area: " << area << endl;
}

void Property::showInfo()const{
	cout << "address: " << address;
}
