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
	int hours;
	string name;
	int type; //0 = monthly, 1 = trimestal, 2 = annually
	Worker* worker;
public:
	/* constructors */
	Maintenance();
	Maintenance(int,float,int,string,Worker*);
	Maintenance(int,float,string,Worker*);

	/* set functions */
	void setMonth(int);
	void setName(string);
	string getName();
	void setType(int);
	void setHours(float);
	void decMonths();

	/* get functions */
	int getMonth();
	int getType();
	int getWorkerId();
	float getHours();

	/* other */
	bool payMonth();
	string printType();
};
#endif /* MAINTENANCE_H_ */