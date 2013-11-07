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
#include "owner.h"
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
	/*constructor*/
	Condominium(string,float,float,float,float,float);
	Condominium(long, string,float,float,float,float,float);

	/* add/remove functions */
	void addProperty(Property*);
	void addProptoCond(vector <Owner*>);
	void addMaintenance(Maintenance*);
	void addMaintenanceToCondominium(vector<Worker*>);


	/* get functions */
	float getAreaMultiplier();
	float getFloorMultiplier();
	float getBaseApartmentCost();
	float getBaseOfficeCost();
	float getBaseStoreCost();
	Worker* getWorkerFromList(vector<Worker*>);
	Owner* getOwnerFromList(vector<Owner*>);
	int getId();
	string getName();

	/* set functions */
	void setAreaMultiplier(float);
	void setFloorMultiplier(float);
	void setBaseApartmentCost(float);
	void setBaseOfficeCost(float);
	void setBaseStoreCost(float);

	/*Manage functions */
	void manageCond(vector<Worker*>,vector<Owner*>);
	void managePropertyFromCond(vector<Owner*>);
	void manageTaskFromCond();
	float getProfitLoss();
	float getPropertyCost(int);
	void advanceOneMonth();
	
	/* save functions */
	void saveProperties();
	void saveMaintenances();

	/* remove functions */
	bool removeProperty(Property*);
	void removePropertyFromCond();
	void removeMaintenanceFromCond();

	/* show & other */
	void showCondominium();
	void showProperties();
	bool isEmpty();
};
#endif /* CONDOMINIUM_H_ */
