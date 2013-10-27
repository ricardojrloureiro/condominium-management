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

class Corporation{
	vector <Condominium> condominiums;
	vector <Worker> workers;

public:
	Corporation();
	void manageCondominium();
	void loadCondominiums(string);
	void loadProperties(int);
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
};


#endif /* CORPORATION_H_ */
