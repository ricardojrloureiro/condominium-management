#include "property.h"

// constructors

Property::Property(string address, float area, int floor,Owner *owner) {
	totalDue=0;
	this->address = address;
	this->area = area;
	this->floor = floor;
	this->owner = owner;
}

Apartment::Apartment(string address, float area, int floor, Owner *owner) : Property(address, area, floor,owner) {
}

Office::Office(string address, float area, int floor,Owner *owner) : Property(address, area, floor,owner) {
}

Store::Store(string address, float area, int floor,Owner *owner) : Property(address, area, floor,owner) {
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
	totalDue = 0;
	floor = 0;
	area=0;
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

int Property::getOwnerId() {
	return owner->getId();
}

void Property::setOwnerId(int id){
	owner->setId(id);
}

void Property::setOwner(Owner* O){
	owner=O;
}

string Property::getOwnerName() {
	return owner->getName();
}
