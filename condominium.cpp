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

bool Condominium::removeProperty(Property* property){
	string propertyAdd = property->getAddress();
	for (unsigned int i = 0; i < properties.size(); i++)
	{
		if(propertyAdd == properties[i]->getAddress()){
			properties.erase(properties.begin()+ i);
			return true; // if it has been erased
		}
	}
	return false; // if the property to erase doesn't exist
}

int Condominium::getId() {
	return id;
}

string Condominium::getName() {
	return name;
}

void Condominium::addProperty(Property* p1){
	properties.push_back(p1);
}

int Condominium::getProfit() {
	int income;
	for(unsigned int i=0; i<properties.size(); i++) {
		income += properties[i]->getCost();
	}
	return income;
}

void Condominium::showCondominium() {
	cout << "Condominium ID: " << id << endl;
	cout << "Condominium Name: " << name << endl;
	cout << "Properties #: " << properties.size() << endl << endl;
}

void Condominium::showProperties() {
	for(unsigned int i = 0; i < properties.size(); i++)	{
		cout << "Property #" << i+1 << endl;
		cout << "Type: " << properties[i]->printType() << endl;
		cout << "Address: " << properties[i]->getAddress() << endl;
		cout << "Cost: " << properties[i]->getCost() << endl << endl;
	}
}

void Condominium::saveProperties(){
	stringstream ssfilename;
	ssfilename << "condominium" << id << ".csv";
	string filename = ssfilename.str();
	ofstream file(filename.c_str());
	file << "type" << "," << "address" << "," << "cost" << endl;
	for(unsigned int i = 0; i < properties.size(); i++)
	{
		file << properties[i]->returnType() << "," << properties[i]->getAddress() << "," << properties[i]->getCost();
		if(i < (properties.size() -1))
			file << endl;
	}
	file.close();
}

void Condominium::manageCond() {
	stringstream topic;
	topic << "Managing " << getName() << endl;
	string topic2 = topic.str();
	Menu showMenu(topic2.c_str());
	showMenu.addMenuItem("Add a new property");
	showMenu.addMenuItem("Remove property");
	showMenu.addMenuItem("Manage the existing properties");
	showMenu.addMenuItem("Go BACK to the previous Menu");

	while(showMenu.isActive()) {
		switch(showMenu.showMenu()) {
		case 1:
			//add
			addProptoCond();
			break;
		case 2:
			//remove

			break;
		case 3:
			//manage properties

			break;
		default:
			showMenu.toggleMenu();
			break;
		}
	}
}

void Condominium::addProptoCond() {
	string address;
	Menu Menu("Which type of property would you like to build?\n");
	Menu.addMenuItem("Apartment");
	Menu.addMenuItem("Office");
	Menu.addMenuItem("Store");
	Menu.addMenuItem("Go BACK to the PREVIOUS menu");
	while(Menu.isActive()) {
		switch(Menu.showMenu()) {
		case 1:
			cout << "Apartment Address: ";
			getline(cin,address);
			this->addProperty(new Apartment(address));

			break;
		case 2:
			cout << "Office Address: ";
			getline(cin,address);
			this->addProperty(new Office(address));

			break;
		case 3:
			cout << "Store Address: ";
			getline(cin,address);
			this->addProperty(new Store(address));

			break;
		default:
			Menu.toggleMenu();
			break;
		}
		Menu.toggleMenu();
	}
	//save the properties
	saveProperties();
}
