/*
 * Maintenance.h
 *
 *  Created on: Oct 14, 2013
 *      Author: rui
 */

#ifndef MAINTENANCE_H_
#define MAINTENANCE_H_

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Maintenance {
	int monthsLeft;
	int type;
	string name;
public:
	Maintenance();
	Maintenance(int,int,string);
	void setMonth(int);
	int getMonth();
	void setType(int);
	int getType();
	void setName(string);
	string getName();
	void decMonths();
	bool payMonth();
};
#endif /* MAINTENANCE_H_ */
