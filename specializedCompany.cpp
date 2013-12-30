#include "specializedCompany.h"

/* constructs */
SpecializedCompany::SpecializedCompany() {
	this->name = "";
	this->price = 0;
}

SpecializedCompany::SpecializedCompany(string name, int price, vector< vector<string > > maintenanceReportVec){
	this->name = name;
	this->price = price;

	for(unsigned int w=0; w<maintenanceReportVec.size(); w++) {
		MaintenanceReport temp;
		temp.name = maintenanceReportVec[w][0];
		temp.condominiumid = atoi(maintenanceReportVec[w][1].c_str());
		temp.cost = atof(maintenanceReportVec[w][3].c_str());
		maintenance.push_back(temp);
	}
}

SpecializedCompany::SpecializedCompany(string name, int price){
	this->name = name;
	this->price = price;
}

float SpecializedCompany::getPrice() const {
	return this->price;
}

string SpecializedCompany::getName() const {
	return this->name;
}

bool SpecializedCompany::operator< (const SpecializedCompany & c) const {
	return (this->price < c.getPrice());

}


void SpecializedCompany::saveMaintenanceReport() {
	stringstream ssfilename;
	ssfilename << this->name << ".csv";
	string filename = ssfilename.str();
	ofstream file(filename.c_str());
	file << "condominiumid" << "," << "cost" << endl;
	for(unsigned int i = 0; i < maintenance.size(); i++)
	{
		file << maintenance[i].condominiumid << "," << maintenance[i].cost;
		if(i < (maintenance.size() -1))
			file << endl;
	}
	file.close();
}

ostream & operator<<(ostream & o, const SpecializedCompany & d)
{
	o << "Name: " << d.getName() << endl << "Price: " << d.getPrice() << endl;
	return o;
}
