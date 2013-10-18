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
	Property(string address);
	int getCost();
	virtual void showInfo() const;
	virtual int returnType() const;
};

class Apartment : public Property {
	int area;
public:
	Apartment(int, string);
	void setCost(int);
	int getArea();
	void setArea(int);
	void showInfo() const;
	int returnType() const;

};

class Office : public Property {
	int area;
public:
	Office(int, string);
	void setCost(int);
	int getArea();
	void setArea(int);
	void showInfo() const;
	int returnType() const;
};

class Store : public Property {
	int area;
public:
	Store(int, string);
	void setCost(int);
	int getArea();
	void setArea(int);
	void showInfo() const;
	int returnType() const;
};

#endif /* PROPERTY_H_ */
