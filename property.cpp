/*
 * propriedade.cpp
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "property.h"

Property::Property(string address) {
	this->address = address;
}

Apartment::Apartment(string address) : Property(address) {
}
