#include "maintenance.h"

// Constructors
Maintenance::Maintenance() {
	name = "";
	type = 0;
	daysLeft = 0;
}

Maintenance::Maintenance(int days,int type, string name) {
	this->name = name;
	this->type = type;
	daysLeft = days;
}


//set & get functions
void Maintenance::setDays(int days) {
	daysLeft = days;
}

int Maintenance::getDays() {
	return daysLeft;
}

void Maintenance::setType(int type) {
	this->type = type;
}

int Maintenance::getType() {
	return type;
}

void Maintenance::setName(string name) {
	this->name=name;
}

string Maintenance::getName() {
	return name;
}

bool Maintenance::payDay() {
	if(daysLeft == 0){
		return true;
	}
	return false;
}

void Maintenance::decDays() {
	daysLeft--;
}
