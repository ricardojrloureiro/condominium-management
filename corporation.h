#ifndef CORPORATION_H_
#define CORPORATION_H_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "condominium.h"
#include "worker.h"
#include "property.h"
#include "owner.h"
#include "report.h"

using namespace std;

class Corporation {
	vector <Condominium> condominiums;
	vector <Worker> workers;
	vector <Owner> owners;
	vector <Report> reports;
	int date; // mmaaaa
public:
	/* constructors */
	Corporation();

	/*manage functions */
	void manageCondominium();
	void manageWorkers(int);
	void manageOwners(int);

	/* load functions */
	void loadCondominiums(string);
	void loadProperties(int);
	void loadMaintenance(int);
	void loadWorkers(string);
	void loadReports(string);
	void loadOwners(string);
	vector < vector < string > > loadMaintenanceReport(int);
	vector < vector < string > > loadPropertiesReport(int);

	/* save functions */
	void saveCondominiums(string);
	void saveWorkers();
	void saveOwners();
	void saveReports(string);

	/* remove functions */
	void removeCondominium(Condominium);
	void removeWorker(Worker);

	/* add functions */
	void addReport(Report);
	void addWorker();
	void addWorker(Worker);
	void addOwner();
	void addOwner(Owner);
	void addCondominium(Condominium);
	void createCondominium();

	/* get functions */
	int getMonth();
	int getYear();
	int getLastDate();
	vector<Worker*> getWorkersList();
	Worker* getWorker(int);
	vector<Owner*> getOwnersList();
	Owner* getOwner(int);

	/* set functions */
	void incDate();

	/* show functions */
	void showCondominium(int);
	void showAllCondominiums();
	void manageWorkers();
	void showWorker();
	void showOwner();
	void browseReports();

	/* search & others */
	int searchCondominiumId(int);
	void financeReports();
	void fastForward();
	bool isEmpty();
};

#endif /* CORPORATION_H_ */
