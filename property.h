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

using namespace std;

class Property {
protected:
	string address;
	int cost;
public:
	Property();
	void setAddress(string);
	Property(string,int);
	void setCost(int);
	int getCost();
	string getAddress();
	virtual void showInfo() const;
	virtual int returnType()const;
};

class Apartment : public Property {
	int type;
public:
	Apartment();
	Apartment(string,int);
	void showInfo() const;
	int returnType() const;

};

class Office : public Property {
	int type;
public:
	Office();
	Office(string,int);
	void showInfo() const;
	int returnType() const;
};

class Store : public Property {
	const int type;
public:
	Store();
	Store(string,int);
	void showInfo() const;
	int returnType() const;
};

#endif /* PROPERTY_H_ */
