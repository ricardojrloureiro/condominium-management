/*
 * workers.h
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#ifndef WORKER_H_
#define WORKER_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Worker{
	long id;
	string name;
	int wage;
	static long workerId;
public:
	string getName();
	void setName(string);
	int getWage();
	void setWage(int);

	Worker(string);
	Worker(long,string);
	Worker(string,int);

	long getId();
};
#endif /* WORKER_H_ */
