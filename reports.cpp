#include "report.h"

Report::Report() {
	this->date=0;
}

Report::Report(int date, vector<string> neg, vector<float> profitloss, vector<Maintenance>maintenance){
	this->date = date;
	this->negativeCond = neg;
	this->profitlosses = profitloss;
	this->maintenancesdone=maintenance;
}

/* get functions */

int Report::getDate(){
	return this->date;
}

vector<float> Report::getProfitLoss() {
	return this->profitlosses;
}

vector<string> Report::getNegConds() {
	return this->negativeCond;
}

vector<Maintenance> Report::getMaintenances() {
	return this->maintenancesdone;
}

/* set functions */

void Report::setNegConds(vector<string> negconds) {
	this->negativeCond = negconds;
}

void Report::setProfitLosses(vector<float> lossprofit) {
	this->profitlosses = lossprofit;
}

void Report::setDoneMain(vector<Maintenance> maintenance) {
	this->maintenancesdone = maintenance;
}

void Report::setDate(int date) {
	this->date = date;
}
