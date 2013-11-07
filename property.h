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
	float area;
	int floor;
	float totalDue;
	Owner* owner;
	string address;
public:
	Property();
	void setAddress(string);
	Property(string,float,int,Owner*);
	float getArea();
	int getFloor();
	string getAddress();
	virtual int returnType() const = 0;
	virtual string printType() const = 0;
	int getOwnerId();

};

class Apartment : public Property {
public:
	Apartment();
	Apartment(string,float,int,Owner *);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

class Office : public Property {
public:
	Office();
	Office(string,float,int,Owner *);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

class Store : public Property {
public:
	Store();
	Store(string,float,int,Owner *);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

#endif /* PROPERTY_H_ */
