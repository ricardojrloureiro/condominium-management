#ifndef SPECIALIZEDCOMPANY_H_
#define SPECIALIZEDCOMPANY_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "menu.h"
using namespace std;

class SpecializedCompany {
	struct MaintenanceReport {
		int date;
		string name;
		int condominiumid;
		float cost;
	};

	vector<MaintenanceReport> maintenance;

	string name;
	float price;

public:

	/**
	 * Do:
	 *  default constructor
	 */
	SpecializedCompany();

	SpecializedCompany(string, int, vector< vector <string> >);
	SpecializedCompany(string, int);
	bool operator< (const SpecializedCompany & c) const;

	float getPrice() const;
	string getName() const;

	friend ostream & operator<<(ostream & o, const SpecializedCompany & d);


	void saveMaintenanceReport();
};


#endif /* SPECIALIZEDCOMPANY_H_ */
