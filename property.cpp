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

Apartment::Apartment(){
	address = "";
}

Office::Office(){
	address = "";
}

Store::Store(){
	address = "";
}

void Property::setAddress(string name) {
	address = name;
}

void Property::addMaintenance(Maintenance *p1) {
	maintenances.push_back(p1);
}

void Property::removeMaintenance() {
	stringstream name;
	int id;
	Menu menu("Choose one of the id's");
	for(unsigned int i=0;i<maintenances.size();i++) {
		name << "Name: " << maintenances[i]->getName() << ", tipo: " << maintenances[i]->getType();
		menu.addMenuItem(name.str());
		name.clear();
		name.str("");
	}
	menu.addMenuItem("Go back to the PREVIOUS menu");
	id = menu.showMenu();
	maintenances.erase(maintenances.begin() + (id - 1));
}
