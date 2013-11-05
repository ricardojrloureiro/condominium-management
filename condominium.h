/*
 * condominio.h
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#ifndef CONDOMINIUM_H_
#define CONDOMINIUM_H_

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "worker.h"
#include "property.h"
#include "menu.h"
#include <stdlib.h>

using namespace std;

class Condominium {
	long id;
	float areaMultiplier;
	float floorMultiplier;
	float baseApartmentCost;
	float baseOfficeCost;
	float baseStoreCost;
	string name;
	vector <Maintenance*> maintenance;
	vector <Property*> properties;
	vector <int> fixedCosts; //monthly costs for water, electricity, ...
	static long condominiumId;

public:
	Condominium(string,float,float,float,float,float);
	Condominium(long, string,float,float,float,float,float);
	void addProperty(Property*);
	bool removeProperty(Property*);
	void removePropertyFromCond();
	void addMaintenanceToCondominium();
	void addProptoCond();
	void addMaintenance(Maintenance*);
	void showCondominium();
	void showProperties();
	int getId();
	string getName();
	void saveProperties();
	int getProfit();
	void manageCond(vector<Worker*>);
	void managePropertyFromCond();
	void addMaintenanceToCondominium(vector<Worker*>);
	bool isEmpty();
	void setAreaMultiplier(float);
	float getAreaMultiplier();
	void setFloorMultiplier(float);
	float getFloorMultiplier();
	void setBaseApartmentCost(float);
	float getBaseApartmentCost();
	void setBaseOfficeCost(float);
	float getBaseOfficeCost();
	void setBaseStoreCost(float);
	float getBaseStoreCost();
	Worker* getWorkerFromList(vector<Worker*>);
	void saveMaintenances();
};


#endif /* CONDOMINIUM_H_ */
