/*
 * condominio.h
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#ifndef CONDOMINIUM_H_
#define CONDOMINIUM_H_

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "property.h"
#include <stdlib.h>

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
	void showProperties();
	int getId();
	string getName();
	void saveProperties();
	int getProfit();
};


#endif /* CONDOMINIUM_H_ */
