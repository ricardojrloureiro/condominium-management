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

// sets & gets

long Worker::getId() {
	return id;
}

string Worker::getName(){
	return name;
}

int Worker::getWage() {
	return wage;
}

void Worker::setWage(int wage) {
	this->wage=wage;
}

Worker::Worker(string name, int wage) {
	workerId++;
	id = workerId;
	this->name = name;
	this->wage = wage;
}