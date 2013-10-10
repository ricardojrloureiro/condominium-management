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
public:
	Apartment(string address);
};

class Office : public Property {

};

class Store : public Property {

};

#endif /* PROPRIEDADE_H_ */
