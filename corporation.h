#ifndef CORPORATION_H_
#define CORPORATION_H_

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <tr1/unordered_set>
#include <queue>

#include "condominium.h"
#include "worker.h"
#include "property.h"
#include "owner.h"
#include "report.h"
#include "meeting.h"
#include "BST.h"
#include "specializedCompany.h"

using namespace std;
struct ownerHash
{
	int operator() (const Owner & o1) const {
		return o1.getId();
	}
	bool operator() (const Owner & o1, const Owner & o2) const{
		return o1.getId() == o2.getId();
	}
};
typedef tr1::unordered_set<Owner, ownerHash, ownerHash> HashOwners;


class Corporation {
	vector <Condominium> condominiums;
	vector <Worker> workers;
	vector <Owner> owners;
	vector <Report> reports;
	HashOwners possibleOwners;
	BST<SpecializedCompany> specializedCompanies;
	int date; // mmaaaa
public:
	void showPossibleOwners();
	void addToPossibleOwners(Owner);

	int getDate() {return date;}

	/**
	 * Do:
	 * Constructor, creates a corporation
	 * Sets the date the current date or the last reported date incremented.
	 * */
	Corporation();

	/**
	 * Do:
	 * Allows the user to see and choose which condominium will be chosen to manage.
	 */
	void manageCondominium();

	/**
	 * Do:
	 * Allows the user to manage a specific worker.
	 * @param int worker's Id.
	 */
	void manageWorkers(int);

	/**
	 * Do:
	 * Allows the user to manage a specific owners.
	 * @param int owner's Id.
	 */
	void manageOwners(int);

	/**
	 * Do:
	 * Load condominium from file.
	 * @param string filename.
	 */
	void loadCondominiums(string);

	/**
	 * Do:
	 * load properties from a specific condominium.
	 * @param int condominium Id.
	 */
	void loadProperties(int);

	/**
	 * Do:
	 * load maintenance from a specific condominium.
	 * @param int condominium Id.
	 */
	void loadMaintenance(int);

	/**
	 * Do:
	 * load workers from the Corporation.
	 * @param string filename.
	 */
	void loadWorkers(string);

	/**
	 * Do:
	 * Load corporation reports.
	 * @param string filename.
	 */
	void loadReports(string);

	/**
	 * Do:
	 * Load corporation Owners.
	 * @param string filename.
	 */
	void loadOwners(string);

	void loadMeetings(int);

	/**
	 * Do:
	 * Load Maintenance from a specific date.
	 * @param int specific date.
	 */
	vector < vector < string > > loadMaintenanceReport(int);

	/**
	 * Do:
	 * Load Report from a specific date.
	 * @param int specific date.
	 */
	vector < vector < string > > loadPropertiesReport(int);

	/**
	 * Do:
	 * Saves condominiuns to a csv file.
	 * @param string filename.
	 */
	void saveCondominiums(string);

	/**
	 * Do:
	 * Saves workers to a csv file.
	 */
	void saveWorkers();

	/**
	 * Do:
	 * Saves owners to a csv file.
	 */
	void saveOwners();

	/**
	 * Do:
	 * Saves reports to a csv file.
	 * @param string filename.
	 */
	void saveReports(string);

	/**
	 * Do:
	 * Removes a certain condominium from the condominium list.
	 * @param Condominium condominium to remove.
	 */
	void removeCondominium(Condominium);

	/**
	 * Do:
	 * Removes a certain worker from the Corporation list.
	 * @param Worker worker to remove.
	 */
	void removeWorker(Worker);

	/**
	 * Do:
	 * Add a report to the report list.
	 * @param Report report to add.
	 */
	void addReport(Report);

	/**
	 * Do:
	 * Allows the user to add a worker.
	 */
	void addWorker();

	/**
	 * Do:
	 * Allows the user to add a worker.
	 * @param Worker specific worker to add.
	 */
	void addWorker(Worker);

	/**
	 * Do:
	 * Allows the user to add a owner.
	 */
	void addOwner();

	/**
	 * Do:
	 * Allows the user to add a owner.
	 * @param Owner specific owner to add.
	 */
	void addOwner(Owner);

	/**
	 * Do:
	 * Allows the user to add a condominium to the Condominium's list.
	 * @param Condominium Condominium to add.
	 */
	void addCondominium(Condominium);

	/**
	 * Do:
	 * Shows a menu to the user that allows him to put the Based costs of the created condominium.
	 */
	void createCondominium();

	/**
	 * Do:
	 * divides the date for 100 and returns the rest that is the month.
	 */
	int getMonth();

	/**
	 * Do:
	 * divides the date for 100 and returns the value that is the year.
	 */
	int getYear();

	/**
	 * Do:
	 * gets the full date YYYY-MM.
	 */
	int getLastDate();

	/**
	 * Do:
	 * Shows a list of workers and allows the user to choose one of them.
	 * returns the chosen worker.
	 */
	vector<Worker*> getWorkersList();

	/**
	 * Do:
	 * If there is a worker with that Id returns it other ways returns Null.
	 * @param Int worker Id.
	 */
	Worker* getWorker(int);

	/**
	 * Do:
	 * Shows a list of owner and allows the user to choose one of them.
	 * returns the chosen owner.
	 */
	vector<Owner*> getOwnersList();

	/**
	 * Do:
	 * If there is a owner with that Id returns it other ways returns Null.
	 * @param Int owner Id.
	 */
	Owner* getOwner(int);

	/**
	 * Do:
	 * Increments the month and if the month is 12 increases the year and sets the month to 1.
	 */
	void incDate();

	/**
	 * Do:
	 * Shows a specific condominium
	 * @param int Condominium Id.
	 */
	void showCondominium(int);

	/**
	 * Do:
	 * Allows the user to go throughout all the condominiums 1 by 1.
	 */
	void showAllCondominiums();

	/**
	 * Do:
	 * Allows the user to manage all the workers information.
	 */
	void manageWorkers();

	/**
	 * Do:
	 * Allows the user to see all the workers information 1 by 1.
	 */
	void showWorker();

	/**
	 * Do:
	 * Allows the user to see all the owners information 1 by 1.
	 */
	void showOwner();

	/**
	 * Do:
	 * Allows the user to check all the report information.
	 */
	void browseReports();

	/**
	 * Do:
	 * Sends the condominium id and returns the position in the vector.
	 * @param int condominium Id.
	 */
	int searchCondominiumId(int);

	/**
	 * Do:
	 * Allows to check the reports.
	 */
	void financeReports();

	/**
	 * Do:
	 * The function that allows the user to pass throughout the months and realizes all the processes.
	 */
	void fastForward();

	/**
	 * Do:
	 * Allows each condominium to manage their own event and realise it.
	 */
	void condEvents(int);

	/**
	 * Do:
	 * Check if there is any condominium returns true if there isnt or if there is returns false.
	 */
	bool isEmpty();

	void fillPossibleOwners();

};

#endif /* CORPORATION_H_ */
