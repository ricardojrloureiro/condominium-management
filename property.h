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

	bool operator <(const Property& p1) const{
		cout << "area: " << area << " OUTRO: " << p1.getArea() << endl;
		return area > p1.getArea();
	}
	/**
	 * Do:
	 *  constructor
	 */
	Property();

	/**
	 * Do:
	 *  overload constructor
	 * @param string address ;
	 * @param float area;
	 * @param int floor;
	 * @param Owner* owner ;
	 */
	Property(string,float,int,Owner*);

	/**
	 * Do:
	 *  overload constructor
	 * @param string address ;
	 * @param float area;
	 * @param int floor;
	 * @param Owner* owner ;
	 * @param float due to pay ;
	 * @param int monthsleft ;
	 */
	Property(string,float,int,Owner*,float,int);

	/**
	 * Do:
	 *  set the current property address as the specified in the parameter.
	 * @param string property address;
	 */
	void setAddress(string);

	/**
	 * Do:
	 * returns the property area.
	 */
	float getArea() const;

	/**
	 * Do:
	 *  returns the property floor.
	 */
	int getFloor();

	/**
	 * Do:
	 *  returns the property address.
	 */
	string getAddress();

	/**
	 * Do:
	 *  Depending of the type of property it can return an int.
	 *  1->"apartment";
	 *  2->"office";
	 *  3->"store".
	 */
	virtual int returnType() const = 0;

	/**
	 * Do:
	 *  Depending of the type of property it can return an string.
	 *  1->"apartment";
	 *  2->"office";
	 *  3->"store".
	 */
	virtual string printType() const = 0;

	/**
	 * Do:
	 * returns owner Id.
	 */
	int getOwnerId();

	/**
	 * Do:
	 *  sets the current owner Id as the specified in the parameter.
	 * @param int owner id;
	 */
	void setOwnerId(int);

	/**
	 * Do:
	 *  sets the current owner to the specified in the parameter.
	 * @param Owner* owner;
	 */
	void setOwner(Owner*);

	/**
	 * Do:
	 * returns the owners Name.
	 */
	string getOwnerName();

	/**
	 * Do:
	 *  returns true if is the month to pay or not.
	 */
	bool payMonth();

	/**
	 * Do:
	 *  adds the current due to the one in the parameter
	 * @param float due;
	 */
	void addDue(float);

	/**
	 * Do:
	 *  return due of the current property.
	 */
	float getDue();

	/**
	 * Do:
	 *  returns the months left to pay.
	 */
	int getMonthsLeft();

	/**
	 * Do:
	 *  decreases the months left to pay and if it is 1 goes back to the previous type.
	 */
	void decMonth();

	/**
	 * Do:
	 *  sets due to 0.
	 */
	void resetDue();

};

class Apartment : public Property {
public:
	/**
	 * Do:
	 *  constructor.
	 */
	Apartment();
	/**
	 * Do:
	 *  overload constructor.
	 * @param string address;
	 * @param float area;
	 * @param int floor;
	 * @param Owner* owner;
	 */
	Apartment(string,float,int,Owner *);

	/**
	 * Do:
	 *  overload constructor.
	 * @param string address;
	 * @param float area;
	 * @param int floor;
	 * @param Owner* owner;
	 * @param int monthsLeft.
	 */
	Apartment(string,float,int,Owner *,float,int);

	/**
	 * Do:
	 * returns 1, apartment type.
	 */
	int returnType() const;

	/**
	 * Do:
	 *  return "Apartment".
	 */
	string printType() const;
};

class Office : public Property {
public:
	/**
	 * Do:
	 *  constructor.
	 */
	Office();

	/**
	 * Do:
	 *  overload constructor.
	 * @param string address;
	 * @param float area;
	 * @param int floor;
	 * @param Owner* owner;
	 */
	Office(string,float,int,Owner *);

	/**
	 * Do:
	 *  overload constructor.
	 * @param string address;
	 * @param float area;
	 * @param int floor;
	 * @param Owner* owner;
	 * @param int monthsLeft.
	 */
	Office(string,float,int,Owner *,float,int);

	/**
	 * Do:
	 * returns 2, Office type.
	 */
	int returnType() const;

	/**
	 * Do:
	 *  return "Office".
	 */
	string printType() const;
};

class Store : public Property {
public:
	/**
	 * Do:
	 *  constructor.
	 */
	Store();

	/**
	 * Do:
	 *  overload constructor.
	 * @param string address;
	 * @param float area;
	 * @param int floor;
	 * @param Owner* owner;
	 */
	Store(string,float,int,Owner *);

	/**
	 * Do:
	 *  overload constructor.
	 * @param string address;
	 * @param float area;
	 * @param int floor;
	 * @param Owner* owner;
	 * @param int monthsLeft.
	 */
	Store(string,float,int,Owner *,float,int);

	/**
	 * Do:
	 * returns 3, Store type.
	 */
	int returnType() const;

	/**
	 * Do:
	 *  return "Store".
	 */
	string printType() const;

};

class Equity {
	int floor;
	float area;
	string address;
	vector<float>baseCost;
	int ownerId;
public:
	Equity(int floor,float area, string address,vector<float>base,int Id): floor(floor),area(area),address(address),baseCost(base), ownerId(Id){}
	float getArea()const {return area;}
	int getFloor()const {return floor;}
	string getAddress()const {return address;}
	vector<float> getBases() const {return baseCost;}
	int getId()const {return ownerId;}
	bool operator <(const Equity &e1) const{
		vector<float> atual = e1.getBases();
		float cost1,cost2;
		cost1 = area*baseCost[1] + floor*baseCost[2] + baseCost[3];
		cost2 = e1.getArea()*atual[1] + e1.getFloor()*atual[2] + atual[3];
		return cost1<cost2;
	}
	int getCost() const{
		return area*baseCost[1] + floor*baseCost[2] + baseCost[3];
	}
};

#endif /* PROPERTY_H_ */
