/*
 * proprietario.h
 *
 *  Created on: Oct 10, 2013
 *      Author: rui
 */

#ifndef PROPRIETARIO_H_
#define PROPRIETARIO_H_

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

#endif /* PROPRIETARIO_H_ */
