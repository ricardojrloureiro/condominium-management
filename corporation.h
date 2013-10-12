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

#include "condominium.h"
#include "worker.h"

using namespace std;

class Corporation{
	string name;
	vector <Condominium> condominiuns;
	vector <Worker> workers;

public:
	// vamos usar aqui uma template para so definirmos uma vez para remover/add
	Corporation(string);
	void remCond(Condominium);
	void addCond(Condominium);
	string getName();
	void setName(string);
};




#endif /* CORPORATION_H_ */
