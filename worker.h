/*
 * workers.h
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#ifndef WORKERS_H_
#define WORKERS_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Worker{
	string name;
public:
	string getName();
	Worker(string);
};

class Painter: public Worker{
	int wage;
public:
	int getWage();
	void setWage(int);
	Painter(int,string);
};

class Electrician: public Worker{
	int wage;
public:
	int getWage();
	void setWage(int);
	Electrician(int,string);
};


#endif /* WORKERS_H_ */
