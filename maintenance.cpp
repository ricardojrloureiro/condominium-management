#include "maintenance.h"

// Constructors
Maintenance::Maintenance() {
	name = "";
	type = 0;
	monthsLeft = 0;
}

Maintenance::Maintenance(int months,int type, string name) {
	this->name = name;
	this->type = type;
	monthsLeft = months;
}


//set & get functions
void Maintenance::setMonth(int months) {
	monthsLeft = months;
}

int Maintenance::getMonth() {
	return monthsLeft;
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
	if(monthsLeft == 0){
		return true;
	}
	return false;
}

void Maintenance::decMonths() {
	monthsLeft--;
}
