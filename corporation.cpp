/*
 * corporation.cpp
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#include "corporation.h"

// constructor

Corporation::Corporation(){
	date = 201310;
	loadCondominiums("condominiums.csv");
	loadWorker("workers.csv");
}

Corporation::Corporation(int date) {
	this->date = date;
	loadCondominiums("condominiums.csv");
	loadWorker("workers.csv");
}

void Corporation::incDate() {
	if(date%100 == 12){
		date = ((date / 100) + 1) * 100;
	} else {
		date++;
	}
}

/* get functions*/

int Corporation::getAno() {
	return date/100;
}

int Corporation::getMes() {
	return date%100;
}

Worker* Corporation::getWorker(int id) {
	for(unsigned int i=0; i<workers.size(); i++) {
		if(workers[i].getId() == id) {
			return &workers[i];
			break;
		}
	}
	return 0;
}

vector <Worker*> Corporation::getWorkersList() {
	vector <Worker*> tempvector;

	for(unsigned int i=0; i<workers.size(); i++) {
		tempvector.push_back(&workers[i]);
	}

	return tempvector;
}

// remove/add functions

void Corporation::removeCondominium(Condominium cond){
	int id = cond.getId();
	for(unsigned int i=0;i<condominiums.size();i++){
		if(condominiums[i].getId() == id){
			condominiums.erase(condominiums.begin()+i);
		}
	}
}

void Corporation::addCondominium(Condominium cond){
	condominiums.push_back(cond);
}

void Corporation::addWorker() {
	string name = "";
	int wage=0;
	Menu showMenu("Workers");
	showMenu.addMenuItem("Add a new worker");
	showMenu.addMenuItem("Go back to the MAIN menu");

	while(showMenu.isActive()){
		switch(showMenu.showMenu()){
		case 1:{
			name = Menu::promptString("Insert Worker's name: ");
			wage = Menu::promptInt("Insert Worker's wage: ");
			Worker worker(name,wage);
			addWorker(worker);
			break;}
		case 2:{
			showMenu.toggleMenu();
			break;}
		}
	}
	saveWorkers();
}

void Corporation::addWorker(Worker w1) {
	workers.push_back(w1);
}

void Corporation::createCondominium() {
	string name;
	name = Menu::promptString("Name: ");
	float areaMultiplier = Menu::promptFloat("Cost per Square Meter: ");
	float floorMultiplier = Menu::promptFloat("Floor Multiplier: ");
	float baseApartmentCost = Menu::promptFloat("Base Apartment Cost: ");
	float baseOfficeCost = Menu::promptFloat("Base Office Cost: ");
	float baseStoreCost = Menu::promptFloat("Base Store Cost: ");
	Condominium condominium(name, areaMultiplier, floorMultiplier, baseApartmentCost, baseOfficeCost, baseStoreCost);
	addCondominium(condominium);
	saveCondominiums("condominiums.csv");
}


/* load functions */

void Corporation::loadWorker(string filename){
	ifstream file;
	string line;
	int id, wage;
	string name;
	vector <string> workersInfo;
	file.open(filename.c_str());
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
				workersInfo.push_back(sub);
			} while (iss);

			id = atol(workersInfo[0].c_str());
			name = workersInfo[1];
			wage = atol(workersInfo[2].c_str());
			Worker wtemp(id,wage,name);
			workers.push_back(wtemp);

			workersInfo.clear();
		}
		lineNumber++;
	}
	file.close();
}

void Corporation::loadCondominiums(string filename) {
	ifstream file;
	string line;
	int id;
	vector <string> condominiumInfo;
	file.open(filename.c_str());
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
				Condominium condominium(id, condominiumInfo[1], atof(condominiumInfo[2].c_str()), atof(condominiumInfo[3].c_str()), atof(condominiumInfo[4].c_str()), atof(condominiumInfo[5].c_str()), atof(condominiumInfo[6].c_str()));
				condominiums.push_back(condominium);
				loadProperties(id);
				loadMaintenance(id);
			}
			condominiumInfo.clear();
		}
		lineNumber++;
	}
	file.close();
}

void Corporation::loadProperties(int condominiumid) {
	stringstream ssfilename;
	ssfilename << "properties" << condominiumid << ".csv";
	string filename = ssfilename.str(), address;
	ifstream file(filename.c_str());
	string line;
	int type;
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

			if(propertyInfo.size() == 4){
				type = atol(propertyInfo[0].c_str());
				address = propertyInfo[1];
				if (type==1) {
					condominiums[searchCondominiumId(condominiumid)].addProperty(new Apartment(address));
				} else if (type==2) {
					condominiums[searchCondominiumId(condominiumid)].addProperty(new Office(address));
				} else if (type==3) {
					condominiums[searchCondominiumId(condominiumid)].addProperty(new Store(address));
				}
				propertyInfo.clear();
			}
		}
		lineNumber++;
	}
}

void Corporation::loadMaintenance(int condominiumid) {
	stringstream ssfilename;
	ssfilename << "maintenance" << condominiumid << ".csv";
	string filename = ssfilename.str(), name;
	ifstream file(filename.c_str());
	string line;
	int monthsLeft, type, workerid;
	float hours;
	vector <string> maintenanceInfo;
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
				maintenanceInfo.push_back(sub);
			} while (iss);

			if(maintenanceInfo.size() == 6){
				monthsLeft = atoi(maintenanceInfo[0].c_str());
				type = atoi(maintenanceInfo[1].c_str());
				name = maintenanceInfo[2];
				workerid = atoi(maintenanceInfo[3].c_str());
				hours = atof(maintenanceInfo[4].c_str());
				condominiums[searchCondominiumId(condominiumid)].addMaintenance(new Maintenance(monthsLeft,hours, type, name, getWorker(workerid)));
				maintenanceInfo.clear();
			}
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

void Corporation::showAllCondominiums() {
	int i= 0;

	cout << endl;
	Menu showMenu("Condominiums List");
	showMenu.addMenuItem("List all properties information");
	showMenu.addMenuItem("Go to the NEXT condominium");
	showMenu.addMenuItem("Go to the PREVIOUS condominium");
	showMenu.addMenuItem("Go BACK to the PREVIOUS menu");

	while(showMenu.isActive()) {
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

/* save functions */

void Corporation::saveCondominiums(string filename){
	ofstream file(filename.c_str());
	file << "id,name" << endl;
	for(unsigned int i = 0; i < condominiums.size(); i++)
	{
		file << condominiums[i].getId() << "," << condominiums[i].getName() << "," << condominiums[i].getAreaMultiplier() << "," << condominiums[i].getFloorMultiplier() << "," << condominiums[i].getBaseApartmentCost() << "," << condominiums[i].getBaseOfficeCost() << "," << condominiums[i].getBaseStoreCost();
		if (i < (condominiums.size() -1))
			file << endl;
		condominiums[i].saveProperties();

	}
	file.close();
}

void Corporation::saveWorkers() {
	ofstream file("workers.csv");
	file << "id,name,wage" << endl;
	for(unsigned int i = 0; i < workers.size(); i++)
	{
		file << workers[i].getId() << "," << workers[i].getName() << "," << workers[i].getWage();
		if (i < (workers.size() -1))
			file << endl;
	}
	file.close();
}

void Corporation::manageCondominium() {
	int i= 0;
	Menu showMenu("Condominium management");
	showMenu.addMenuItem("Choose this condominium to manage");
	showMenu.addMenuItem("Go to the NEXT condominium");
	showMenu.addMenuItem("Go to the PREVIOUS condominium");
	showMenu.addMenuItem("Go BACK to the PREVIOUS Menu");

	while(showMenu.isActive()) {
		condominiums[i].showCondominium();
		switch(showMenu.showMenu()) {
		case 1:
			condominiums[i].manageCond(getWorkersList());
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

void Corporation::gettingReal() {
	Menu showMenu("Welcome to the Real life bro");
	showMenu.addMenuItem("Flying throught time");
	showMenu.addMenuItem("Check condominium's reports");
	showMenu.addMenuItem("Go to the MAIN menu");
	while(showMenu.isActive()){
		switch (showMenu.showMenu()) {
		case 1:
			//real stuff
			timeGoing();
			break;
		case 2:
			//checking files
			break;
		default: // going back
			break;
		}
		showMenu.toggleMenu();
	}
}

void Corporation::timeGoing() {
	unsigned int monthsToPass;
	monthsToPass = Menu::promptInt("How many months would you like to pass? : ");

	for(unsigned int i=0;i<monthsToPass;i++){
		for(unsigned int j=0;j<condominiums.size();j++){
			/*
			 chamar funcao que vai propriedade a propriedade dentro de cada condominio:
			 -Escrever relatorio mensal de cada propriedade; //por a escrever no fim do .txt//
			 -Escrever relatorios de 3 em 3 meses;
			 -Escrever relatorios anuais;
			 */
		}
		incDate(); // passa para o mes seguinte
	}
}

bool Corporation::isEmpty() {
	if(condominiums.size() > 0) {
		return false;
	} else {
		return true;
	}
}

