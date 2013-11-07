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
	this->id = id;
	this->name = nome;
	this->contract = contract;
	this->monthsLeft = monthsLeft;
}

int Owner::getId() {
	return id;
}

string Owner::getName() {
	return name;
}
