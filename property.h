/*
 * propriedade.h
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#ifndef PROPRIEDADE_H_
#define PROPRIEDADE_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Property {
	string address;
public:
	Property(string address);
};

class Apartment : public Property {
	int cost;
public:
	Apartment(int, string);
	void setCost(int);
	int getCost();
};

class Office : public Property {
	int cost;
public:
	Office(int, string);
	void setCost(int);
	int getCost();
};

class Store : public Property {
	int cost;
public:
	Store(int, string);
	void setCost(int);
	int getCost();
};

#endif /* PROPRIEDADE_H_ */
