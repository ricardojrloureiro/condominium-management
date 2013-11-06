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

#include "condominium.h"
#include "worker.h"
#include "property.h"

using namespace std;

class Corporation {
	vector <Condominium> condominiums;
	vector <Worker> workers;
	int date; // mm-aaaa
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
	void loadWorker(string);

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
	int getMes();
	int getAno();
	vector<Worker*> getWorkersList();
	Worker* getWorker(int id);

	/* set functions */
	void incDate();


	/* show functions */
	void showCondominium(int);
	void showAllCondominiums();
	int showAllCondominiums2();

	/* search & others */
	int searchCondominiumId(int);
	void gettingReal();
	void timeGoing();
	bool isEmpty();
};

#endif /* CORPORATION_H_ */
