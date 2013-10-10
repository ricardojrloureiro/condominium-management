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

class Proprietario {
	string nome;
	Proprietario(string);
};

class Morador : public Proprietario {
	string address;
	Morador(string);
};

#endif /* PROPRIETARIO_H_ */
