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

Apartment::Apartment(int area,string address) : Property(address) {
	this->area = area;
	this->cost = 30*area;
}

Office::Office(int area,string address) : Property(address) {
	this->area = area;
	this->cost = 50*area;
}

Store::Store(int area,string address) : Property(address) {
	this->area = area;
	this->cost = 40*area;
}

// get & sets

int Store::getCost(){
	return cost;
}

int Store::getArea(){
	return area;
}

int Office::getCost(){
	return cost;
}

int Office::getArea(){
	return area;
}

int Apartment::getCost(){
	return cost;
}

int Apartment::getArea(){
	return area;
}

void Store::setCost(int cost){
	this->cost = cost;
}

void Store::setArea(int area){
	this->area = area;
}

void Office::setCost(int cost){
	this->cost = cost;
}

void Office::setArea(int area){
	this->area = area;
}

void Apartment::setCost(int cost){
	this->cost = cost;
}

void Apartment::setArea(int area){
	this->area = area;
}

// other functions

void Apartment::showInfo() const{
	Property::showInfo(); cout <<" cost: " << cost << " area: " << area << endl;
}

void Office::showInfo() const{
	Property::showInfo(); cout <<" cost: " << cost << " area: " << area << endl;
}

void Store::showInfo()const {
	Property::showInfo(); cout <<" cost: " << cost << " area: " << area << endl;
}

void Property::showInfo()const{
	cout << "address: " << address;
}


