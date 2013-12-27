#ifndef OWNER_H_
#define OWNER_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Owner {
	string name;
	int contract; //0 = monthly, 1 = trimestal, 2 = annually
	static long ownerId;
	long id;
public:

	/**
	 * Do:
	 *  constructor
	 * @param string owner name;
	 * @param int owner contract;
	 */
	Owner(string,int);

	/**
	 * Do:
	 *  constructor
	 * @param string owner name;
	 * @param int owner contract;
	 * @param int owners id;
	 */
	Owner(int,string,int);

	/**
	 * Do:
	 * returns the Owners Id.
	 */
	int getId()const;

	/**
	 * Do:
	 *  returns the Owners Name.
	 */
	string getName() const;

	/**
	 * Do:
	 * return the Owners Contract Type as an int.
	 * if it is 0 -> monthly;
	 * if it is 1 -> trimestral;
	 * if it is 2 -> annually.
	 */
	int getContractType();


	/**
	 * Do:
	 * return the Owners Contract Type as a string.
	 * if it is 0 -> "monthly";
	 * if it is 1 -> "trimestral";
	 * if it is 2 -> "annually".
	 */
	string printType() const;

	/**
	 * Do:
	 *  Set the current owner's name to the one in the parameter.
	 * @param string Owners Name;
	 */
	void setName(string);

	/**
	 * Do:
	 *  Set the current owner's contract type to the one in the parameter.
	 * @param int Owners Type;
	 */
	void setType(int);

	/**
	 * Do:
	 *  Set the current owner Id.
	 * @param int Owners Id;
	 */
	void setId(int);
};

#endif /* OWNER_H_ */
