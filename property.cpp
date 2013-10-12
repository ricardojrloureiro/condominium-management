/*
 * propriedade.cpp
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "property.h"

 // constructors

Property::Property(string address) {
	this->address = address;
}

Apartment::Apartment(int cost,string address) : Property(address) {
	this->cost = cost;
}

Office::Office(int cost,string address) : Property(address) {
	this->cost = cost;
}

Store::Store(int cost,string address) : Property(address) {
	this->cost = cost;
}

// get & sets

int Store::getCost(){
	return cost;
}

int Office::getCost(){
	return cost;
}

int Apartment::getCost(){
	return cost;
}

void Store::setCost(int cost){
	this->cost = cost;
}

void Office::setCost(int cost){
	this->cost = cost;
}

void Apartment::setCost(int cost){
	this->cost = cost;
}
