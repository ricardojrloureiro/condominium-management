/*
 * proprietario.h
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#ifndef OWNER_H_
#define OWNER_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Owner {
	string name;
	Owner(string);
};

// Ver bem se estas classes estao bem definidas porque nao sei se faz mt sentido isto
class Dweller : public Owner {
	string address;
	Dweller(string);
};

#endif /* OWNER_H_ */
