#ifndef REPORT_H_
#define REPORT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "maintenance.h"
using namespace std;

class Report {
	int date; // date of the report
	int type; // 0-monthly report, 1- trimestral report, 2- annual report
	vector<string> negativeCond; // all the negative condominiums
	vector<float> profitlosses; // all the profitloss from all condominiums

public:
	/* constructors */
	Report();
	Report(int, int, vector<string>, vector<float>);

	/* set */
	void setDate(int);
	void setNegConds(vector<string>);
	void setProfitLosses(vector<float>);

	/* get functions */
	int getMonth();
	int getYear();
	int getDate();
	int getType();
	vector<string> getNegConds();
	vector<float> getProfitLoss();

	/* save report */
	void saveReport();

};

#endif /* REPORT_H_ */
