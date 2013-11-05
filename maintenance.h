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
#include "worker.h"

using namespace std;

class Maintenance {
	int monthsLeft;
	string name;
	int type; //0 = monthly, 1 = trimestal, 2 = annually
	Worker* worker;
public:
	Maintenance();
	Maintenance(int,int,string,Worker*);
	Maintenance(int,string,Worker*);
	void setMonth(int);
	int getMonth();
	void setName(string);
	string getName();
	void decMonths();
	bool payMonth();
};
#endif /* MAINTENANCE_H_ */
