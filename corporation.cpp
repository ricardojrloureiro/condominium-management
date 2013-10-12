/*
 * corporation.cpp
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#include "corporation.h"

// constructor

Corporation::Corporation(string name){
this->name = name;
}

// remove/add functions

void Corporation::remCond(Condominium cond){
	// procurar o metodo que procura no vetor e associa à possição seguinte passado a dele
}

void Corporation::addCond(Condominium cond){
	condominiuns.push_back(cond);
}

// set & gets

string Corporation::getName(){
	return name;
}

void Corporation::setName(string name){
	this->name = name;
}
