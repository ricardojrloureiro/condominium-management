/*
 * condominio.c
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "condominium.h"

// constructor

Condominium::Condominium(string name) {
	this->name = name;
}

// add/remove functions

void Condominium::addProperty(Property property) {
	properties.push_back(property);
}

void Condominium::removeProperty(Property property){
	for (unsigned int i = 0; i < properties.size(); i++)
	{
			// proceder à remoção
	}
}
