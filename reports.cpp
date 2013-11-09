#include "report.h"

/* constructs */
Report::Report() {
	date=0;
	type=0;
}

Report::Report(int date, int type, vector<string> neg, vector<float> profitloss){
	this->type=type;
	this->date = date;
	this->negativeCond = neg;
	this->profitlosses = profitloss;

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



/* set functions */

void Report::setNegConds(vector<string> negconds) {
	this->negativeCond = negconds;
}

void Report::setProfitLosses(vector<float> lossprofit) {
	this->profitlosses = lossprofit;
}


void Report::setDate(int date) {
	this->date = date;
}

int Report::getYear() {
	return date/100;
}

int Report::getMonth() {
	return date%100;
}

int Report::getType() {
	return type;
}

void Report::saveReport() {
	ofstream file;
	file.open ("reports.csv", std::ofstream::out | std::ofstream::app);
	file << "Month,Year,Type";
	for(unsigned int i=0;i<profitlosses.size();i++){
		file << ",ProfitLoss_cond" << i+1;
	}
	for(unsigned int i=0;i<negativeCond.size();i++){
		file << ", NegativeCond";
	}
	file << endl;
	file << getMonth() << "," << getYear() << "," << getType();
	for(unsigned int i=0;i<profitlosses.size();i++){
		file << ", " << profitlosses[i];
	}
	for(unsigned int i=0;i<negativeCond.size();i++){
		file << ", " << negativeCond[i];
	}
	file << endl;
	file.close();
}
