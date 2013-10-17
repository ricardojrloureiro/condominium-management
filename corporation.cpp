/*
 * corporation.cpp
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#include "corporation.h"

// constructor

Corporation::Corporation(){

}

// remove/add functions

void Corporation::removeCondominium(Condominium cond){
	// procurar o metodo que procura no vetor e associa à possição seguinte passado a dele
}

void Corporation::addCondominium(Condominium cond){
	condominiums.push_back(cond);
}

void Corporation::loadCondominiums(string filename) {
	ifstream file(filename.c_str());
	string line;
	vector <string> condominiumInfo;
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				condominiumInfo.push_back(sub);
			} while (iss);

			Condominium condominium(atol(condominiumInfo[0].c_str()), condominiumInfo[1]);

			condominiums.push_back(condominium);
			condominiumInfo.clear();
		}
		lineNumber++;
	}
}

void Corporation::loadProperties(int condominiumid) {
	stringstream ssfilename;
	ssfilename << "condominium" << condominiumid << ".csv";
	string filename = ssfilename.str();
	ifstream file(filename.c_str());
}

int Corporation::searchCondominiumId(int condominiumdid) {
	for(unsigned int i = 0; i<condominiums.size(); i++) {
		if(condominiums[i].getId() == condominiumdid) {
			return i;
		}
	}
	return 0;
}

