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

using namespace std;

class Corporation {
	vector <Condominium> condominiums;
	vector <Worker> workers;
	float totalProfitLoss;
	int date; // mmaaaa
public:
	/* constructors */
	Corporation();
	Corporation(int);

	/*manage functions */
	void manageCondominium();

	/* load functions */
	void loadCondominiums(string);
	void loadProperties(int);
	void loadMaintenance(int);
	void loadWorkers(string);

	/* save functions */
	void saveCondominiums(string);
	void saveWorkers();

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
	Worker* getWorker(int id);

	/* set functions */
	void incDate();


	/* show functions */
	void showCondominium(int);
	void showAllCondominiums();
	void manageWorkers();

	/* search & others */
	int searchCondominiumId(int);
	void financeReports();
	void fastForward();
	bool isEmpty();
};

#endif /* CORPORATION_H_ */
