/*
 * condominio.c
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "condominium.h"

long Condominium::numMusic = 0;

// constructor

Condominium::Condominium(string name) {
	numMusic++;
	id = numMusic;
	this->name = name;
}

Condominium::Condominium(long id, string name) {
	this->id = id;
	this->name = name;
}

// add/remove functions

void Condominium::addProperty(Property *property) {
	properties.push_back(property);
}

void Condominium::removeProperty(Property *property){
	for (unsigned int i = 0; i < properties.size(); i++)
	{
			// proceder à remoção
	}
}

int Condominium::getId() {
	return id;
}
