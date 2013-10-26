/*
 * corporation.cpp
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#include "corporation.h"

// constructor

Corporation::Corporation(){
	loadCondominiums("condominiums.csv");
}

// remove/add functions

void Corporation::removeCondominium(Condominium cond){
	// procurar o metodo que procura no vetor e associa à possição seguinte passado a dele
}

void Corporation::addCondominium(Condominium cond){
	condominiums.push_back(cond);
}

void Corporation::loadCondominiums(string filename) {
	ifstream file;
	string line;
	int id;
	vector <string> condominiumInfo;
	file.open("condominiums.csv");
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				condominiumInfo.push_back(sub);
			} while (iss);

			id = atol(condominiumInfo[0].c_str());
			if(id>0) {
				Condominium condominium(id, condominiumInfo[1]);
				condominiums.push_back(condominium);
				loadProperties(id);
			}
			condominiumInfo.clear();
		}
		lineNumber++;
	}
	file.close();
}

void Corporation::loadProperties(int condominiumid) {
	stringstream ssfilename;
	ssfilename << "condominium" << condominiumid << ".csv";
	string filename = ssfilename.str(), address;
	ifstream file(filename.c_str());
	string line;
	int type, cost;
	vector <string> propertyInfo;
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				propertyInfo.push_back(sub);
			} while (iss);

			type = atol(propertyInfo[0].c_str());
			address = propertyInfo[1];
			cost = atoi(propertyInfo[2].c_str());

			if (type==1) {
				Apartment property(address, cost);
				condominiums[searchCondominiumId(condominiumid)].addProperty(property);
			} else if (type==2) {
				Office property(address, cost);
				condominiums[searchCondominiumId(condominiumid)].addProperty(property);
			} else if (type==3) {
				Store property(address, cost);
				condominiums[searchCondominiumId(condominiumid)].addProperty(property);
			}

			propertyInfo.clear();
		}
		lineNumber++;
	}
}

int Corporation::searchCondominiumId(int condominiumdid) {
	for(unsigned int i = 0; i<condominiums.size(); i++) {
		if(condominiums[i].getId() == condominiumdid) {
			return i;
		}
	}

	return 0;
}

void Corporation::createCondominium() {
	string name;
	name = Menu::promptString("Name: ");
	Condominium condominium(name);
	addCondominium(condominium);
	saveCondominiums("condominiums.csv");
}

void Corporation::showAllCondominiums() {
	cout << endl << "Condominiums list:";
	int i= 0;

	cout << endl;
	int error=0; // checks the input
	Menu showMenu("Condominiums List");
	showMenu.addMenuItem("List all properties information");
	showMenu.addMenuItem("Go to the NEXT condominium");
	showMenu.addMenuItem("Go to the PREVIOUS condominium");
	showMenu.addMenuItem("Go BACK to the Main Menu");

	while(showMenu.isActive()) {
		cout << "i: " << i << endl;
		condominiums[i].showCondominium();
		switch(showMenu.showMenu()) {
		case 1:
			condominiums[i].showProperties();
			break;
		case 2:
			i = (i+1) % condominiums.size();
			break;
		case 3:
			i = (i-1) % condominiums.size();
			break;
		default:
			showMenu.toggleMenu();
			break;
		}
	}
}

void Corporation::saveCondominiums(string filename){
	ofstream file(filename.c_str());
	file << "id,name" << endl;
	for(unsigned int i = 0; i < condominiums.size(); i++)
	{
		file << condominiums[i].getId() << "," << condominiums[i].getName();
		if (i < (condominiums.size() -1))
			file << endl;
		condominiums[i].saveProperties();
	}
	file.close();
}


