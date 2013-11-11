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

	/**
	 * Do:
	 * Creates a condominium with a sequence id.
	 * @param string Name of the condominium.
	 * @param float AreaMultiplier, cost per area in this condominium.
	 * @param float floorMultiplier, cost per floor in this condominium can go from 0-inf.
	 * @param float baseApartmentCost, cost minimum per apartement.
	 * @param float baseOfficeCost, cost minimum per office.
	 * @param float baseStoreCost, cost minimum per store.
	 */
	Condominium(string,float,float,float,float,float);

	/**
	 * Do:
	 * Creates a condominium with a fixed id.
	 * @param long Id of the condominium.
	 * @param string Name of the condominium.
	 * @param float AreaMultiplier, cost per area in this condominium.
	 * @param float floorMultiplier, cost per floor in this condominium can go from 0-inf.
	 * @param float baseApartmentCost, cost minimum per apartement.
	 * @param float baseOfficeCost, cost minimum per office.
	 * @param float baseStoreCost, cost minimum per store.
	 */
	Condominium(long, string,float,float,float,float,float);

	/**
	 * Do:
	 *  Pushes back the property to the properties vector.
	 * @param Property* Property to add;
	 */
	void addProperty(Property*);

	/**
	 * Do:
	 * Shows a menu to the user that i'll help to add a property to the condominium.
	 * Allows to add between a Office, Apartment or a Store and associate it with a owner.
	 * @param vector<Owner*> vector of owners.
	 */
	void addProptoCond(vector <Owner*>);

	/**
	 * Do:
	 * Pushes back the property to the properties vector.
	 * @param Maintenance* maintenance to add.
	 */
	void addMaintenance(Maintenance*);

	/**
	 * Do:
	 * Shows a menu to the user that i'll help to add a Maintenance to the condominium.
	 * Allows to add maintenance and associate it with a worker.
	 * @param vector<Worker*> vector of corporation's workers.
	 */
	void addMaintenanceToCondominium(vector<Worker*>);

	/**
	 * Do:
	 * returns areaMultiplier.
	 */
	float getAreaMultiplier();

	/**
	 * Do:
	 * returns floorMultiplier.
	 */
	float getFloorMultiplier();

	/**
	 * Do:
	 * returns apartmentCost.
	 */
	float getBaseApartmentCost();

	/**
	 * Do:
	 * returns officeCost.
	 */
	float getBaseOfficeCost();

	/**
	 * Do:
	 * returns storeCost.
	 */
	float getBaseStoreCost();

	/**
	 * Do:
	 * -Allows the user to choose a Corporation's Workers
	 * @param vector<Worker*> corporation workers.
	 * Return:
	 * -Chosen worker-
	 */
	Worker* getWorkerFromList(vector<Worker*>);

	/**
	 * Do:
	 * Allows the user to choose a Corporation's Owner
	 * @param vector<Owner*> corporation Owners.
	 * Return:
	 * -Chosen Owner.
	 */
	Owner* getOwnerFromList(vector<Owner*>);

	/**
	 * Do:
	 * returns the Id of this condominium.
	 */
	int getId();

	/**
	 * Do:
	 * returns the Name of this condominium.
	 */
	string getName();

	/**
	 * @todo:
	 * saber ao certo o que faz a funcao.
	 * returns Maintenances Report
	 */
	vector < vector <string> > getMaintenanceReport();

	/**
	 * @todo:
	 * saber ao certo o que faz a funcao.
	 * returns Properties Report
	 */
	vector < vector <string> > getPropertiesReport();

	/**
	 * Do:
	 * set Area Mutiplier of this condominium.
	 * @param float Area Mutiplier.
	 */
	void setAreaMultiplier(float);

	/**
	 * Do:
	 * set Floor Mutiplier of this condominium.
	 * @param float Floor Mutiplier .
	 */
	void setFloorMultiplier(float);

	/**
	 * Do:
	 * set Base Apartment Cost of this condominium.
	 * @param float Apartment Cost .
	 */
	void setBaseApartmentCost(float);

	/**
	 * Do:
	 * set Base Office Cost of this condominium.
	 * @param float Office Cost.
	 */
	void setBaseOfficeCost(float);

	/**
	 * Do:
	 * set Base Office Cost of this condominium.
	 * @param float Store Cost.
	 */
	void setBaseStoreCost(float);

	/**
	 * Do:
	 * Allows the user to manage all the Condominium information.
	 * @param vector<Worker*> corporation's workers.
	 * @param vector<Owner*> owners.
	 */
	void manageCond(vector<Worker*>,vector<Owner*>);

	/**
	 * Do:
	 * Allows the user to manage the condominium Based values.
	 */
	void manageCondFixedValues();

	/**
	 * Do:
	 * Allows the user to change all the properties information.
	 * @param vector<Owner*> list of owners.
	 */
	void managePropertyFromCond(vector<Owner*>);

	/**
	 * Do:
	 * -Allows the user to change all the maintenances information.
	 * @param vector<Worker*> list of corporation's workers.
	 */
	void manageTaskFromCond(vector<Worker*>);

	/**
	 * Do:
	 * Checks all the maintenances and the base costs and returns a value of the profit/loss.
	 */
	float getProfitLoss();

	/**
	 * Do:
	 * returns a value of how much the property cost.
	 * @param int property Id.
	 */
	float getPropertyCost(int);

	/**
	 * Do:
	 * Runs throughout all the properties and decreases a month to the "Months left to Pay".
	 */
	void advanceOneMonth();

	/**
	 * Do:
	 * Saves to a csv file the current properties from a condominium.
	 */
	void saveProperties();

	/**
	 * Do:
	 * Saves to a csv file the current maintenance from a condominium.
	 */
	void saveMaintenances();

	/**
	 * Do:
	 * Removes a certain property from the condominium list.
	 * @param Property* property to remove.
	 */
	bool removeProperty(Property*);

	/**
	 * Do:
	 * Allows the user to check all properties and choose each one he wants to be removed.
	 */
	void removePropertyFromCond();

	/**
	 * Do:
	 * Allows the user to check all properties and choose each one he wants to be removed.
	 */
	void removeMaintenanceFromCond();

	/**
	 * Do:
	 * Show the list of condominiuns and allows the user to choose one.
	 */
	void showCondominium();

	/**
	 * Do:
	 * Show the list of Properties and allows the user to choose one.
	 */
	void showProperties();

	/**
	 * Do:
	 * Checks if there is any property of the current condominium.
	 * if it has returns false other ways returns true.
	 * */
	bool isEmpty();
};
#endif /* CONDOMINIUM_H_ */
