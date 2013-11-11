#include "report.h"

/* constructs */
Report::Report() {
	date=0;
	totalProfitLoss=0;
}

Report::Report(int date, int totalProfitLoss, vector< vector<string > > maintenanceReportVec, vector< vector<string> > propertiesReportVec){
	this->date = date;
	this->maintenance = maintenance;
	this->totalProfitLoss = totalProfitLoss;
	for(unsigned int w=0; w<maintenanceReportVec.size(); w++) {
		MaintenanceReport temp;
		temp.name = maintenanceReportVec[w][0];
		temp.condominiumid = atoi(maintenanceReportVec[w][1].c_str());
		temp.workerid = atoi(maintenanceReportVec[w][2].c_str());
		temp.cost = atof(maintenanceReportVec[w][3].c_str());
		maintenance.push_back(temp);
	}
	for(unsigned int w=0; w<propertiesReportVec.size(); w++) {
		PropertiesReport temp;
		temp.address = propertiesReportVec[w][0];
		temp.condominiumid = atoi(propertiesReportVec[w][1].c_str());
		temp.ownerid = atoi(propertiesReportVec[w][2].c_str());
		temp.amountPaid = atof(propertiesReportVec[w][3].c_str());
		properties.push_back(temp);
	}
}

/* get functions */

int Report::getDate(){
	return this->date;
}

int Report::getYear() {
	return date/100;
}

int Report::getMonth() {
	return date%100;
}

float Report::getProfitLoss() {
	return totalProfitLoss;
}

/* set functions */
void Report::setDate(int date) {
	this->date = date;
}

void Report::showInfo() {
	cout << "Report for " << getMonth() << "/" << getYear() << endl << endl;
	cout << "Total profit/loss: " << getProfitLoss() << " euros" << endl;
	cout << "# of maintenances paid: " << maintenance.size() << endl;
	cout << "# of properties payments received: " << properties.size() << endl;
	cout << endl;
}

void Report::showMaintenance() {
	cout << "Maintenance performed on the " << getMonth() << "/" << getYear() << endl << endl;
	for(unsigned int i=0; i<maintenance.size(); i++) {
		cout << maintenance[i].name << endl;
		cout << "Total cost: " << maintenance[i].cost << " euros" << endl << endl;
	}
	Menu menu("Continue");
	menu.addMenuItem("Continue");
	menu.showMenu();
}

void Report::showProperties() {
	cout << "Properties paid on the " << getMonth() << "/" << getYear() << endl << endl;
	for(unsigned int i=0; i<properties.size(); i++) {
		cout << properties[i].address << endl;
		cout << "Total paid: " << properties[i].amountPaid << " euros" << endl << endl;
	}
	Menu menu("Continue");
	menu.addMenuItem("Continue");
	menu.showMenu();
}

void Report::saveMaintenanceReport() {
	stringstream ssfilename;
	ssfilename << date << "maintenance" << ".csv";
	string filename = ssfilename.str();
	ofstream file(filename.c_str(),ios::app);
	file << "name" << "," << "condominiumid" << "," << "workerid" << "," << "cost" << endl;
	for(unsigned int i = 0; i < maintenance.size(); i++)
	{
		file << maintenance[i].name << "," << maintenance[i].condominiumid << "," << maintenance[i].workerid << "," << maintenance[i].cost;
		if(i < (maintenance.size() -1))
			file << endl;
	}
	file.close();
}

void Report::savePropertiesReport() {
	stringstream ssfilename;
	ssfilename << date << "properties" << ".csv";
	string filename = ssfilename.str();
	ofstream file(filename.c_str(),ios::app);
	file << "address" << "," << "condominiumid" << "," << "ownerid" << "," << "amountPaid" << endl;
	for(unsigned int i = 0; i < properties.size(); i++)
	{
		file << properties[i].address << "," << properties[i].condominiumid << "," << properties[i].ownerid << "," << properties[i].amountPaid;
		if(i < (properties.size() -1))
			file << endl;
	}
	file.close();
}
