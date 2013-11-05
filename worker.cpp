/*
 * workers.cpp
 *
 *  Created on: Oct 12, 2013
 *      Author: ricardo
 */

#include "worker.h"

 long Worker::workerId = 0;

// constructors

Worker::Worker(string name) {
	workerId++;
	id = workerId;
	this->name = name;
}

Worker::Worker(long id, string name) {
	workerId = id;
	this->name = name;
}

Painter::Painter(int wage, string name): Worker(name){
	this->wage = wage;
}

Electrician::Electrician(int wage, string name): Worker(name){
	this->wage = wage;
}

// sets & gets

long Worker::getId() {
	return id;
}

string Worker::getName(){
	return name;
}

void Painter::setWage(int wage){
	this->wage = wage;
}

int Painter::getWage(){
	return wage;
}

void Electrician::setWage(int wage){
	this->wage = wage;
}

int Electrician::getWage(){
	return this->wage;
}
