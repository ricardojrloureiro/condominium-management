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

void Condominium::removeProperty(Property property){
	for (unsigned int i = 0; i < properties.size(); i++)
	{
	}
}

int Condominium::getId() {
	return id;
}

string Condominium::getName() {
	return name;
}

void Condominium::addProperty(Property p1){
	properties.push_back(p1);
}

void Condominium::addStore(Store s1){
	properties.push_back(s1);
}

void Condominium::addOffice(Office s1){
	properties.push_back(s1);
}

void Condominium::addApartment(Apartment s1){
	properties.push_back(s1);
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
	for(unsigned int i = 0; i < properties.size(); i++)	{
		cout << "Type of property: " << properties[i].returnType() << endl;
		cout << "Address: " << properties[i].getAddress() << endl;
		cout << "Cost: " << properties[i].getCost() << endl;
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
		file << properties[i].returnType() << "," << properties[i].getAddress() << "," << properties[i].getCost();
		if(i < (properties.size() -1))
			file << endl;
	}
	file.close();
}

void Condominium::manageCond() {
	stringstream topic;
	topic << "Managing cond nº: " << getId() << ", " << getName();
	string topic2 = topic.str();
	Menu showMenu(topic2.c_str());
	showMenu.addMenuItem("Add a new property");
	showMenu.addMenuItem("Remove property");
	showMenu.addMenuItem("Manage the existing properties");
	showMenu.addMenuItem("Go BACK to the previous Menu");

	while(showMenu.isActive()) {
		switch(showMenu.showMenu()) {
		case 1:
			addProptoCond();
			saveProperties();
			break;
		case 2:
			break;
		case 3:
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
	Menu.addMenuItem("Store");
	Menu.addMenuItem("Office");
	Menu.addMenuItem("Apartment");
	Menu.addMenuItem("Go BACK to the PREVIOUS menu");
	Store store;
	Office office;
	Apartment apartment;
	while(Menu.isActive()) {
		switch(Menu.showMenu()) {
		case 1:
			cout << "Which is the address you want to build in\n";
			getline(cin,address);
			store.setAddress(address);
			this->addStore(store);
			break;
		case 2:
			cout << "Which is the address you want to build in\n";
			getline(cin,address);
			office.setAddress(address);
			this->addOffice(office);
			Menu.toggleMenu();
			break;
		case 3:
			cout << "Which is the address you want to build in\n";
			getline(cin,address);
			apartment.setAddress(address);
			this->addApartment(apartment);
			break;
		default:
			Menu.toggleMenu();
			break;
		}
		Menu.toggleMenu();
	}
}
