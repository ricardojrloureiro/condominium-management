#include "owner.h"

long Owner::ownerId = 0;

// constructor


Owner::Owner(string nome, int contract, int monthsLeft){
	ownerId++;
	this->id = ownerId;
	this->name = nome;
	this->contract = contract;
	this->monthsLeft = monthsLeft;
}

Owner::Owner(int id,string nome, int contract, int monthsLeft){
	ownerId++;
	this->id = id;
	this->name = nome;
	this->contract = contract;
	this->monthsLeft = monthsLeft;
}

Owner::Owner(string name, int contractType) {
	ownerId++;
	this->id = ownerId;
	this->name = name;
	this->contract = contractType;
	switch (contractType) {
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

int Owner::getMonthsLeft() {
	return monthsLeft;
}

int Owner::getId() {
	return id;
}

void Owner::setId(int id){
	this->id = id;
}
string Owner::getName() {
	return name;
}

int Owner::getContractType() {
	return contract;
}

string Owner::printType() {
	switch (contract) {
		case 0:
			return "monthly";
			break;
		case 1:
			return "trimestral";
			break;
		case 2:
			return "annually";
			break;
	}
	return "";
}

void Owner::setName(string name) {
	this->name = name;
}

void Owner::setType(int type) {
	this->contract = type;
	switch (type) {
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
