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
	int monthsLeft;
public:
	Property();
	void setAddress(string);
	Property(string,float,int,Owner*);
	Property(string,float,int,Owner*,float,int);
	float getArea();
	int getFloor();
	string getAddress();
	virtual int returnType() const = 0;
	virtual string printType() const = 0;
	int getOwnerId();
	void setOwnerId(int);
	void setOwner(Owner*);
	string getOwnerName();
	bool payMonth();
	void addDue(float);
	float getDue();
	int getMonthsLeft();
	void decMonth();
	void resetDue();
};

class Apartment : public Property {
public:
	Apartment();
	Apartment(string,float,int,Owner *);
	Apartment(string,float,int,Owner *,float,int);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

class Office : public Property {
public:
	Office();
	Office(string,float,int,Owner *);
	Office(string,float,int,Owner *,float,int);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

class Store : public Property {
public:
	Store();
	Store(string,float,int,Owner *);
	Store(string,float,int,Owner *,float,int);
	void showInfo() const;
	int returnType() const;
	string printType() const;
};

#endif /* PROPERTY_H_ */
