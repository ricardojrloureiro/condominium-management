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
#include <sstream>
#include <fstream>

#include "property.h"

using namespace std;

class Condominium {
	long id;
	string name;
	vector <Property> properties;
	static long condominiumId;

public:
	Condominium(string);
	Condominium(long, string);
	void addProperty(Property);
	void removeProperty(Property);
	void showCondominium();
	string getName();
	int getId();
	void saveProperties();
};


#endif /* CONDOMINIO_H_ */
