#ifndef MAINTENANCE_H_
#define MAINTENANCE_H_

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "worker.h"

using namespace std;

class Maintenance {
	int monthsLeft;
	float duration;
	string name;
	int type; //0 = monthly, 1 = trimestal, 2 = annually
	Worker* worker;
public:

	/**
	 * Do:
	 * Maintenance default constructor.
	 */
	Maintenance();

	/**
	 * Do:
	 * overload constructor.
	 * @param int monthsLeft to pay.
	 * @param float duration of the maintenance, hours.
	 * @param int type of maintenance. 0-monthly, 1-trimestral, 2-annually
	 * @param string maintenance name.
	 * @param Worker*
	 */
	Maintenance(int,float,int,string,Worker*);

	/**
	 * Do:
	 * overload constructor.
	 * @param float duration of the maintenance, hours.
	 * @param int type of maintenance. 0-monthly, 1-trimestral, 2-annually
	 * @param string maintenance name.
	 * @param Worker*
	 */
	Maintenance(int,float,string,Worker*);

	/**
	 * Do:
	 * sets a specific month to the maintenance.
	 * @param int Month.
	 */
	void setMonth(int);

	/**
	 * Do:
	 * sets a specific name to the maintenance.
	 * @param string Name.
	 */
	void setName(string);

	/**
	 * Do:
	 * returns maintenance name.
	 */
	string getName();

	/**
	 * Do:
	 * sets a type to the maintenance.
	 * @param int type.
	 */
	void setType(int);

	/**
	 * Do:
	 * sets the duration of the maintenance.
	 * @param float maintenance's duration.
	 */
	void setDuration(float);

	/**
	 * Do:
	 * decrements the months left to pay and if 0 sets to the contracted type.
	 */
	void decMonth();

	/**
	 * Do:
	 * returns the month of the maintenance.
	 */
	int getMonth();

	/**
	 * Do:
	 *returns the type of the maintenance.
	 */
	int getType();

	/**
	 * Do:
	 * returns the Worker Id of the maintenance.
	 */
	int getWorkerId();

	/**
	 * Do:
	 * returns the Worker Id of the maintenance.
	 */
	float getDuration();

	/**
	 * Do:
	 * returns the Worker Wage.
	 */
	float getWorkerWage();

	/**
	 * Do:
	 * sets the worker Id.
	 * @param int workers id.
	 */
	void setWorkerId(int);

	/**
	 * Do:
	 * return the worker's name.
	 */
	string getWorkerName();

	/**
	 * Do:
	 * Sets a specific worker to the maintenance.
	 * @param Worker* specific worker.
	 */
	void setWorker(Worker*);

	/**
	 * Do:
	 * returns true if monthsLeft is zero or false if it isn't.
	 */
	bool payMonth();

	/**
	 * Do:
	 * returns a string depending of the type of maintenance.
	 * if 0 returns "monthly".
	 * if 1 returns "trimestral".
	 * if 2 returns "annually".
	 */
	string printType();
};
#endif /* MAINTENANCE_H_ */
