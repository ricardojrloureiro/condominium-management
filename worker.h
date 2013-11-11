#ifndef WORKER_H_
#define WORKER_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Worker{
	long id;
	string name;
	float wage;
	static long workerId;
public:

	/**
	 * Do:
	 * returns the workers Name.
	 */
	string getName();

	/**
	 * Do:
	 *  sets the Workers Name the specified in the parameter.
	 * @param string workers name;
	 */
	void setName(string);

	/**
	 * Do:
	 * returns the workers wage.
	 */
	float getWage();

	/**
	 * Do:
	 *  sets the workers wage the specified in the parameter.
	 * @param float workers wage;
	 */
	void setWage(float);

	/**
	 * Do:
	 *  constructor
	 * @param string workers name;
	 */
	Worker(string);

	/**
	 * Do:
	 *  overload constructor, essentially used for load from files.
	 * @param long workers Id;
	 * @param float workers Wage;
	 * @param string workers Name;
	 */
	Worker(long,float,string);

	/**
	 * Do:
	 *  overload constructor.
	 * @param string workers Name;
	 * @param float workers Wage;
	 */
	Worker(string,float);

	/**
	 * Do:
	 *  set the workers Id as the specified in the parameter.
	 * @param int workers Id;
	 */
	void setId(int);

	/**
	 * Do:
	 *  returns the Id from the current worker.
	 */
	long getId();
};
#endif /* WORKER_H_ */
