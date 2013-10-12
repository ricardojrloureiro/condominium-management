/*
 * condominio.h
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#ifndef CONDOMINIO_H_
#define CONDOMINIO_H_

#include <vector>
#include <string>

#include "property.h"

using namespace std;

class Condominium {
	string name;
	vector <Property> properties;
public:
	Condominium(string);
	void addProperty(Property);
	void remProperty(Property);
};


#endif /* CONDOMINIO_H_ */
