#ifndef REPORT_H_
#define REPORT_H_

#include <string>
#include <vector>
#include <iostream>
#include "maintenance.h"
using namespace std;

class Report {
	int date;
	vector<string> negativeCond;
	vector<float> profitlosses;
	vector<Maintenance> maintenancesdone;

public:
	/* constructors */
	Report();
	Report(int,vector<string>,vector<float>,vector<Maintenance>);

	/* set */
	void setDate(int);
	void setNegConds(vector<string>);
	void setProfitLosses(vector<float>);
	void setDoneMain(vector<Maintenance>);

	/* get functions */
	int getDate();
	vector<string> getNegConds();
	vector<float> getProfitLoss();
	vector<Maintenance> getMaintenances();

};

#endif /* REPORT_H_ */
