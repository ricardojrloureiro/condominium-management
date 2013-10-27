/*
 * propriedade.cpp
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "property.h"

// constructors

Property::Property(string address, int cost) {
	this->cost = cost;
	this->address = address;
}

Apartment::Apartment(string address, int cost) : Property(address,cost) {
}

Office::Office(string address, int cost) : Property(address,cost) {
}

Store::Store(string address, int cost) : Property(address,cost) {
}

// get & sets

int Property::getCost() {
	return cost;
}

int Property::returnType() const {
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

// other functions

void Apartment::showInfo() const{
	Property::showInfo(); cout <<" cost: " << cost << " area: " << endl;
}

void Office::showInfo() const{
	Property::showInfo(); cout <<" cost: " << cost << " area: " << endl;
}

void Store::showInfo()const {
	Property::showInfo(); cout <<" cost: " << cost << " area: " << endl;
}

void Property::showInfo()const{
	cout << "address: " << address;
}

Property::Property() {
	address = "";
	cost = 0;
}

Apartment::Apartment(){
	address = "";
	cost = 30;
}

Office::Office(){
	address = "";
	cost = 40;
}

Store::Store(){
	address = "";
	cost = 50;
}

void Property::setAddress(string name) {
	address = name;
}
