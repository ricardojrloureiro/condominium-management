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

	/**
	 * Do:
	 *  default constructor
	 */
	Report();
	/**
	 * Do:
	 *  overload constructor
	 * @param int date;
	 * @param int Total Profit/Loss;
	 * @param vector<vector<string>> maintenance Reports;
	 * @param vector<vector<string>> properties Reports;
	 */
	Report(int, int, vector< vector <string> >, vector< vector <string> >);

	/**
	 * Do:
	 *  Set the current report date to the one in the parameter.
	 * @param int date;
	 */
	void setDate(int);

	/**
	 * Do:
	 *  Divides the date by 100 and returns the rest of the division as an int.
	 */
	int getMonth();

	/**
	 * Do:
	 *  Divides the date by 100 and returns the value as an int.
	 */
	int getYear();

	/**
	 * Do:
	 *  returns the reports Date
	 */
	int getDate();

	/**
	 * Do:
	 *  returns the total profit/loss of the report.
	 */
	float getProfitLoss();

	/**
	 * Do:
	 *  Show to the user the Report information.
	 */
	void showInfo();

	/**
	 * Do:
	 *  Show to the user the Properties of the report and their profit/loss.
	 */
	void showProperties();

	/**
	 * Do:
	 *  Show to the user the realized maintenances in that report.
	 */
	void showMaintenance();

	/**
	 * Do:
	 *  Saves to a csv file the maintenances that have been done in the current report.
	 */
	void saveMaintenanceReport();

	/**
	 * Do:
	 *  save to csv file the current properties and their profitloss.
	 */
	void savePropertiesReport();

};

#endif /* REPORT_H_ */
