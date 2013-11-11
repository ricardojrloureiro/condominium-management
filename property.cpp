#include "property.h"

// constructors

Property::Property(string address, float area, int floor,Owner *owner) {
	totalDue=0.0;
	this->address = address;
	this->area = area;
	this->floor = floor;
	this->owner = owner;
	switch (owner->getContractType()) {
	case 0:
		monthsLeft=1;
		break;
	case 1:
		monthsLeft=3;
		break;
	case 2:
		monthsLeft=12;
		break;
	}
}

Property::Property(string address, float area, int floor,Owner *owner,float totalDue,int monthsLeft) {
	this->address = address;
	this->area = area;
	this->floor = floor;
	this->owner = owner;
	this->totalDue = totalDue;
	this->monthsLeft = monthsLeft;
}

Apartment::Apartment(string address, float area, int floor, Owner *owner) : Property(address, area, floor,owner) {
}

Office::Office(string address, float area, int floor,Owner *owner) : Property(address, area, floor,owner) {
}

Store::Store(string address, float area, int floor,Owner *owner) : Property(address, area, floor,owner) {
}

Apartment::Apartment(string address, float area, int floor, Owner *owner,float totalDue,int monthsLeft) : Property(address, area, floor,owner,totalDue,monthsLeft) {
}

Office::Office(string address, float area, int floor,Owner *owner,float totalDue,int monthsLeft) : Property(address, area, floor,owner,totalDue,monthsLeft) {
}

Store::Store(string address, float area, int floor,Owner *owner,float totalDue,int monthsLeft) : Property(address, area, floor,owner,totalDue,monthsLeft) {
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
	totalDue = 0.0;
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

bool Property::payMonth() {
	if(monthsLeft == 1){
		return true;
	}
	return false;
}

void Property::decMonth() {
	monthsLeft--;
	if(monthsLeft == 0) {
		switch(owner->getContractType()) {
		case 0:
			monthsLeft = 1;
			break;
		case 1:
			monthsLeft = 3;
			break;
		case 2: 
			monthsLeft = 12;
			break;
		default:
			monthsLeft = 0;
			break;
		}
	}
}

void Property::addDue(float amount) {
	totalDue += amount;
}

float Property::getDue() {
	return totalDue;
}

int Property::getMonthsLeft() {
	return monthsLeft;
}

void Property::resetDue() {
	this->totalDue = 0;
}
