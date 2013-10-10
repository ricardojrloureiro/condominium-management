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
};

class Morador : public Proprietario {
	string moradation;
};

#endif /* PROPRIETARIO_H_ */
