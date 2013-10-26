/*
 * condominio.cpp
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "condominium.h"

long Condominium::condominiumId = 0;

// constructor

Condominium::Condominium(string name) {
	condominiumId++;
	id = condominiumId;
	this->name = name;
}

Condominium::Condominium(long id, string name) {
	condominiumId = id;
	this->id = id;
	this->name = name;
}

// add/remove functions

void Condominium::addProperty(Property property) {
	properties.push_back(property);
}

void Condominium::removeProperty(Property property){
	for (unsigned int i = 0; i < properties.size(); i++)
	{
			// proceder à remoção
	}
}

int Condominium::getId() {
	return id;
}

string Condominium::getName() {
	return name;
}

int Condominium::getProfit() {
	int income;
	for(unsigned int i=0; i<properties.size(); i++) {
		income += properties[i].getCost();
	}
	return income;
}

void Condominium::showCondominium() {
	cout << "Condominium ID: " << id << endl;
	cout << "Condominium Name: " << name << endl;
	cout << "Properties #: " << properties.size() << endl << endl;
}

void Condominium::showProperties() {
	for(unsigned int i = 0; i < properties.size(); i++)
	{
		cout << "Address: " << properties[i].getAddress() << endl;
		cout << "Cost: " << properties[i].getCost() << endl;
	}
}

void Condominium::saveProperties(){
	stringstream ssfilename;
	ssfilename << "condominium" << id << ".csv";
	string filename = ssfilename.str();
	ofstream file(filename.c_str());
	for(unsigned int i = 0; i < properties.size(); i++)
	{
		file << properties[i].returnType() << "," << properties[i].getAddress() << "," << properties[i].getCost();
		if(i < (properties.size() -1))
			file << endl;
	}
	file.close();
}
