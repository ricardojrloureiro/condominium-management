/*
 * propriedade.h
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#ifndef PROPERTY_H_
#define PROPERTY_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "menu.h"
#include "maintenance.h"
#include "owner.h"

using namespace std;

class Property {
protected:
	int area;
	int floor;
	Owner* owner;
	string address;
public:
	Property();
	void setAddress(string);
	Property(string);
	void setCost(int);
	int getCost();
	string getAddress();
	virtual int returnType() const = 0;
	virtual string printType() const = 0;

};

class Apartment : public Property {
public:
	Apartment();
	Apartment(string);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

class Office : public Property {
public:
	Office();
	Office(string);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

class Store : public Property {
public:
	Store();
	Store(string);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

#endif /* PROPERTY_H_ */
