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

using namespace std;

class Corporation{
	vector <Condominium> condominiums;
	vector <Worker> workers;

public:
	Corporation();
	void loadCondominiums(string);
	void loadProperties(int);
	int searchCondominiumId(int);
	void removeCondominium(Condominium);
	void addCondominium(Condominium);
	void removeWorker(Worker);
	void addWorker(Worker);
};


#endif /* CORPORATION_H_ */
