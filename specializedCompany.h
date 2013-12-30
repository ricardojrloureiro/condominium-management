#ifndef SPECIALIZEDCOMPANY_H_
#define SPECIALIZEDCOMPANY_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "menu.h"
using namespace std;

class SpecializedCompany	 {
	struct MaintenanceReport {
		string name;
		int condominiumid;
		float cost;
	};
	struct PropertiesReport {
		string address;
		int condominiumid;
		int ownerid;
		float amountPaid;
	};

	float hourlyRate;
	vector<MaintenanceReport> maintenance;
	vector<PropertiesReport> properties;

	float totalProfitLoss;

public:

	/**
	 * Do:
	 *  default constructor
	 */
	SpecializedCompany();

	SpecializedCompany(int, int, vector< vector <string> >, vector< vector <string> >);



};

#endif /* SPECIALIZEDCOMPANY_H_ */
