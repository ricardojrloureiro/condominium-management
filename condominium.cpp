/*
 * condominio.c
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "condominium.h"

Condominium::Condominium(string name) {
	this->name = name;
}

void Condominium::addProperty(Property property) {
	properties.push_back(property);
}
