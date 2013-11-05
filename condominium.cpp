/*
 * condominio.cpp
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#include "condominium.h"

long Condominium::condominiumId = 0;

// constructor

Condominium::Condominium(string name, float areaMultiplier, float floorMultiplier, float baseApartmentCost, float baseOfficeCost, float baseStoreCost) {
	condominiumId++;
	id = condominiumId;
	this->name = name;
	this->areaMultiplier = areaMultiplier;
	this->floorMultiplier = floorMultiplier;
	this->baseApartmentCost = baseApartmentCost;
	this->baseOfficeCost = baseOfficeCost;
	this->baseStoreCost = baseStoreCost;
}

Condominium::Condominium(long id, string name, float areaMultiplier, float floorMultiplier, float baseApartmentCost, float baseOfficeCost, float baseStoreCost) {
	condominiumId = id;
	this->id = id;
	this->name = name;
	this->areaMultiplier = areaMultiplier;
	this->floorMultiplier = floorMultiplier;
	this->baseApartmentCost = baseApartmentCost;
	this->baseOfficeCost = baseOfficeCost;
	this->baseStoreCost = baseStoreCost;
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

void Condominium::addMaintenance(Maintenance* m1){
	maintenance.push_back(m1);
}

int Condominium::getProfit() {
	int income = 0;
	for(unsigned int i=0; i<properties.size(); i++) {
		income += properties[i]->getCost();
	}
	return income;
}

void Condominium::setAreaMultiplier(float areaMultiplier) {
	this->areaMultiplier = areaMultiplier;
}

float Condominium::getAreaMultiplier() {
	return areaMultiplier;
}

void Condominium::setFloorMultiplier(float floorMultiplier) {
	this->floorMultiplier = floorMultiplier;
}

float Condominium::getFloorMultiplier() {
	return floorMultiplier;
}

void Condominium::setBaseApartmentCost(float baseApartmentCost) {
	this->baseApartmentCost = baseApartmentCost;
}

float Condominium::getBaseApartmentCost() {
	return baseApartmentCost;
}

void Condominium::setBaseOfficeCost(float baseOfficeCost) {
	this->baseOfficeCost = baseOfficeCost;
}

float Condominium::getBaseOfficeCost() {
	return baseOfficeCost;
}

void Condominium::setBaseStoreCost(float baseStoreCost) {
	this->baseStoreCost = baseStoreCost;
}

float Condominium::getBaseStoreCost() {
	return baseStoreCost;
}

bool Condominium::isEmpty() {
	if(properties.size() > 0) {
		return false;
	} else {
		return true;
	}
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
	ssfilename << "properties" << id << ".csv";
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

void Condominium::manageCond(vector <Worker*> workers) {
	stringstream topic;
	topic << "Managing " << getName() << endl;
	string topic2 = topic.str();
	Menu showMenu(topic2.c_str());
	showMenu.addMenuItem("Add a new property");
	showMenu.addMenuItem("Remove property");
	showMenu.addMenuItem("Manage the existing properties");
	showMenu.addMenuItem("Add maintenance task");
	showMenu.addMenuItem("Remove maintenance task");
	showMenu.addMenuItem("Go BACK to the previous Menu");

	while(showMenu.isActive()) {
		switch(showMenu.showMenu()) {
		case 1:
			//add
			addProptoCond();
			break;
		case 2:
			//remove
			if(this->isEmpty()) {
				cout << "There are no properties yet. Please add one property first." << endl << endl;
			} else {
				removePropertyFromCond();
			}
			break;
		case 3:
			//manage properties
			if(this->isEmpty()) {
				cout << "There are no properties yet. Please add one property first." << endl << endl;
			} else {
				managePropertyFromCond();
			}
			break;
		case 4:
			if(workers.size()==0) {
				cout << "There are no workers yet. Please add one worker from the Main Menu first." << endl << endl;
			} else {
				addMaintenanceToCondominium(workers);
			}
			break;
		case 5:
			if(workers.size()==0) {
				cout << "There are no workers yet. Please add one worker from the Main Menu first." << endl << endl;
			} else {
				addMaintenanceToCondominium(workers);
			}
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
			break;
		}
		Menu.toggleMenu();
	}
	//save the properties
	saveProperties();
}

void Condominium::removePropertyFromCond() {
	stringstream name;
	int id;
	Menu menu("Choose one of the id's");
	for(unsigned int i=0;i<properties.size();i++) {
		name << "Address: " << properties[i]->getAddress();
		menu.addMenuItem(name.str());
		name.clear();
		name.str("");
	}
	menu.addMenuItem("Go back to the PREVIOUS menu");
	id = menu.showMenu();
	if(id<=properties.size()){
		properties.erase(properties.begin() + (id - 1));
		saveProperties();
	}
}

void Condominium::managePropertyFromCond() {
	stringstream name;
	int id;
	string newAddress;
	Menu menu("Choose one of the IDs");
	for(unsigned int i=0;i<properties.size();i++) {
		name << "Address: " << properties[i]->getAddress();
		menu.addMenuItem(name.str());
		name.clear();
		name.str("");
	}
	menu.addMenuItem("Go back to the PREVIOUS menu");
	id = menu.showMenu();
	if(id<=properties.size()) {
		Menu manage("Managing");
		manage.addMenuItem("Edit address");
		manage.addMenuItem("Go to the PREVIOUS menu");
		while(manage.isActive()){
			switch (manage.showMenu()) {
			case 1:
				cout << "New Address: ";
				getline(cin,newAddress);
				properties[id-1]->setAddress(newAddress);
				break;
			case 2:
				break;
			default:
				manage.toggleMenu();
				break;
			}
			//manage.toggleMenu();
		}
		saveProperties();
	}
}

Worker* Condominium::getWorkerFromList(vector <Worker*> workers) {

	Menu workersMenu("Workers List");
	for (unsigned int i=0; i<workers.size(); i++) {
		workersMenu.addMenuItem(workers[i]->getName());
	}
	workersMenu.addMenuItem("Go back to the PREVIOUS menu");
	return workers[workersMenu.showMenu()-1];
}

void Condominium::addMaintenanceToCondominium(vector <Worker*> workers) {
	string name = Menu::promptString("Maintenance Name: ");
	Menu typeMenu("Maintenance Schedule");
	typeMenu.addMenuItem("Monthly");
	typeMenu.addMenuItem("Trimestral");
	typeMenu.addMenuItem("Annually");
	int type = typeMenu.showMenu() - 1;
	Worker* worker = getWorkerFromList(workers);
	this->addMaintenance(new Maintenance(type, name, worker));
	saveMaintenances();
}

void Condominium::saveMaintenances() {
	stringstream ssfilename;
	ssfilename << "maintenance" << id << ".csv";
	string filename = ssfilename.str();
	ofstream file(filename.c_str());
	file << "MonthsLeft" << "," << "Type" << "," << "Name" << "," << "WorkerId" << endl;
	for(unsigned int i = 0; i < maintenance.size(); i++){
		file << maintenance[i]->getMonth() << "," << maintenance[i]->getType() << "," << maintenance[i]->getName() << "," << maintenance[i]->getWorkerId();
		if(i < (maintenance.size() -1))
			file << endl;
	}
	file.close();
}
