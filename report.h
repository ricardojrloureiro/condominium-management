#ifndef REPORT_H_
#define REPORT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "menu.h"
using namespace std;

class Report {
	struct MaintenanceReport {
		string name;
		int condominiumid;
		int workerid;
		float cost;
	};
	struct PropertiesReport {
		string address;
		int condominiumid;
		int ownerid;
		float amountPaid;
	};

	int date; // date of the report

	vector<MaintenanceReport> maintenance;
	vector<PropertiesReport> properties;

	float totalProfitLoss;

public:
	/* constructors */
	Report();
	Report(int, int, vector< vector <string> >, vector< vector <string> >);

	/* set */
	void setDate(int);

	/* get functions */
	int getMonth();
	int getYear();
	int getDate();
	float getProfitLoss();
	void showInfo();
	void showProperties();
	void showMaintenance();

	/* save report */
	void saveMaintenanceReport();
	void savePropertiesReport();

};

#endif /* REPORT_H_ */
