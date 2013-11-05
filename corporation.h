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
	Corporation();
	Corporation(int);
	void manageCondominium();
	void loadCondominiums(string);
	void loadProperties(int);
	void loadMaintenance(int);
	void saveCondominiums(string);
	int searchCondominiumId(int);
	void removeCondominium(Condominium);
	void addCondominium(Condominium);

	void createCondominium();
	void removeWorker(Worker);
	void addWorker(Worker);
	void loadWorker(string);

	void showCondominium(int);
	void showAllCondominiums();
	int showAllCondominiums2();

	void gettingReal(); // the real badass function
	void incDate();
	int getMes();
	int getAno();
	void timeGoing();

	bool isEmpty();

	Worker* getWorker(int id);
	vector<Worker*> getWorkersList();
};


#endif /* CORPORATION_H_ */
