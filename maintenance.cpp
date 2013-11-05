#include "maintenance.h"

// Constructors
Maintenance::Maintenance() {
	name = "";
	monthsLeft = 0;
}

Maintenance::Maintenance(int type, string name, Worker* worker) {
	this->type = type;
	this->name = name;
	this->worker = worker;
	switch(type) {
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

Maintenance::Maintenance(int monthsLeft, int type, string name, Worker* worker) {
	this->monthsLeft = monthsLeft;
	this->type = type;
	this->name = name;
	this->worker = worker;
}


//set & get functions
void Maintenance::setMonth(int months) {
	monthsLeft = months;
}

int Maintenance::getMonth() {
	return monthsLeft;
}

void Maintenance::setName(string name) {
	this->name=name;
}

string Maintenance::getName() {
	return name;
}

int Maintenance::getType()  {
	return type;
}

void Maintenance::setType(int type) {
	this->type=type;
}

bool Maintenance::payMonth() {
	if(monthsLeft == 0){
		return true;
	}
	return false;
}

void Maintenance::decMonths() {
	monthsLeft--;
}

int Maintenance::getWorkerId() {
	return worker->getId();
}
