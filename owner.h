/*
 * proprietario.h
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#ifndef OWNER_H_
#define OWNER_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Owner {
	string name;
	int contract; //0 = monthly, 1 = trimestal, 2 = annually
	int monthsLeft;
	static long ownerId;
	long id;
public:
	Owner(string, int, int);
	Owner(int,string,int,int);

	//get functions
	int getId();
	string getName();
};

#endif /* OWNER_H_ */
