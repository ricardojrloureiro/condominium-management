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
	virtual void showInfo() const;
};

class Apartment : public Property {
	int cost, area;
public:
	Apartment(int, string);
	void setCost(int);
	int getCost();
	int getArea();
	void setArea(int);
	void showInfo()const ;
};

class Office : public Property {
	int cost, area;
public:
	Office(int, string);
	void setCost(int);
	int getCost();
	int getArea();
	void setArea(int);
	void showInfo()const;
};

class Store : public Property {
	int cost, area;
public:
	Store(int, string);
	void setCost(int);
	int getCost();
	int getArea();
	void setArea(int);
	void showInfo()const;
};

#endif /* PROPRIEDADE_H_ */
