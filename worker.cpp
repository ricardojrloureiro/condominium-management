/*
 * workers.cpp
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#include "worker.h"

// constructors

Worker::Worker(string name){
	this->name = name;
}

Painter::Painter(int wage, string name): Worker(name){
	this->wage = wage;
}

Electricist::Electricist(int wage, string name): Worker(name){
	this->wage = wage;
}


// sets & gets

string Worker::getName(){
	return name;
}

void Painter::setWage(int wage){
	this->wage = wage;
}

int Painter::getWage(){
	return wage;
}

void Electricist::setWage(int wage){
	this->wage = wage;
}

int Electricist::getWage(){
	return this->wage;
}
