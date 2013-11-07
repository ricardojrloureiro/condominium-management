/*
 * Corporation.h
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#ifndef CORPORATION_H_
#define CORPORATION_H_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "condominium.h"
#include "worker.h"
#include "property.h"
#include "owner.h"

using namespace std;

class Corporation {
	vector <Condominium> condominiums;
	vector <Worker> workers;
	vector <Owner> owners;
	float totalProfitLoss;
	int date; // mmaaaa
public:
	/* constructors */
	Corporation();
	Corporation(int);

	/*manage functions */
	void manageCondominium();
	void manageWorkers(int);

	/* load functions */
	void loadCondominiums(string);
	void loadProperties(int);
	void loadMaintenance(int);
	void loadWorkers(string);
	void loadReports(string);
	void loadOwner(string);

	/* save functions */
	void saveCondominiums(string);
	void saveWorkers();
	void saveOwners();

	/* remove functions */
	void removeCondominium(Condominium);
	void removeWorker(Worker);

	/* add functions */
	void addWorker();
	void addWorker(Worker);
	void addCondominium(Condominium);
	void createCondominium();

	/* get functions */
	int getMonth();
	int getYear();
	vector<Worker*> getWorkersList();
	Worker* getWorker(int);
	vector<Owner*> getOwnersList();
	Owner* getOwner(int);


	/* set functions */
	void incDate();


	/* show functions */
	void showCondominium(int);
	void showAllCondominiums();
	void manageWorkers();
	void showWorker();

	/* search & others */
	int searchCondominiumId(int);
	void financeReports();
	void fastForward();
	bool isEmpty();
};

#endif /* CORPORATION_H_ */
