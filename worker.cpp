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
	wage = 0;
	this->name = name;
}

Worker::Worker(string name, float wage) {
	workerId++;
	id = workerId;
	this->name = name;
	this->wage = wage;
}

Worker::Worker(long id, float wage, string name) {
	workerId = id;
	this->id = id;
	this->wage = wage;
	this->name = name;
}

// sets & gets

long Worker::getId() {
	return id;
}

string Worker::getName(){
	return name;
}

float Worker::getWage() {
	return wage;
}

void Worker::setWage(float wage) {
	this->wage=wage;
}

void Worker::setName(string name) {
        this->name = name;
}

void Worker::setId(int id){
	this->id = id;
}

