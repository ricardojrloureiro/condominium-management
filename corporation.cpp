#include "corporation.h"

// constructor

Corporation::Corporation(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	stringstream datess;
	datess << 1900 + ltm->tm_year;
	datess << 1 + ltm->tm_mon;
	date = atoi(datess.str().c_str());
	totalProfitLoss = 0;
	loadWorkers("workers.csv");
	loadOwners("owners.csv");
	loadCondominiums("condominiums.csv");	
}

Corporation::Corporation(int date) {
	this->date = date;
	loadReports("reports.csv");
	loadWorkers("workers.csv");
	loadCondominiums("condominiums.csv");
}

void Corporation::incDate() {
	if(date%100 == 12){
		date = ((date / 100) + 1) * 100 + 1;
	} else {
		date++;
	}
}

/* get functions*/

int Corporation::getYear() {
	return date/100;
}

int Corporation::getMonth() {
	return date%100;
}

Worker* Corporation::getWorker(int id) {
	for(unsigned int i=0; i<workers.size(); i++) {
		if(workers[i].getId() == id) {
			return &workers[i];
			break;
		}
	}
	return 0;
}

Owner* Corporation::getOwner(int id) {
	for(unsigned int i=0; i<owners.size(); i++) {
		if(owners[i].getId() == id) {
			return &owners[i];
			break;
		}
	}
	return 0;
}

vector <Worker*> Corporation::getWorkersList() {
	vector <Worker*> tempvector;

	for(unsigned int i=0; i<workers.size(); i++) {
		tempvector.push_back(&workers[i]);
	}

	return tempvector;
}

vector <Owner*> Corporation::getOwnersList() {
	vector <Owner*> tempvector;

	for(unsigned int i=0; i<owners.size(); i++) {
		tempvector.push_back(&owners[i]);
	}

	return tempvector;
}


// remove/add functions

void Corporation::removeCondominium(Condominium cond){
	int id = cond.getId();
	for(unsigned int i=0;i<condominiums.size();i++){
		if(condominiums[i].getId() == id){
			condominiums.erase(condominiums.begin()+i);
		}
	}
}

void Corporation::addCondominium(Condominium cond){
	condominiums.push_back(cond);
}

void Corporation::addWorker() {
	string name = "";
	float wage=0;
	Menu showMenu("Workers");
	showMenu.addMenuItem("Add a new worker");
	showMenu.addMenuItem("Go back to the MAIN menu");

	while(showMenu.isActive()){
		switch(showMenu.showMenu()){
		case 1:{
			name = Menu::promptString("Insert Worker's name: ");
			wage = Menu::promptFloat("Insert Worker's wage: ");
			Worker worker(name,wage);
			addWorker(worker);
			saveWorkers();
			break;}
		case 2:{
			showMenu.toggleMenu();
			break;}
		}
	}

}

void Corporation::addOwner() {
	string name = "";
	int contractType=0;
	Menu showMenu("Owners");
	showMenu.addMenuItem("Add a new owner");
	showMenu.addMenuItem("Go back to the MAIN menu");

	while(showMenu.isActive()){
		switch(showMenu.showMenu()){
		case 1:{
			name = Menu::promptString("Insert Owner's name: ");
			Menu subMenu("Which type of contract will this owner have?");
			subMenu.addMenuItem("monthly");
			subMenu.addMenuItem("trimestal");
			subMenu.addMenuItem("annually");
			contractType = subMenu.showMenu();
			Owner owner(name,(contractType- 1));
			addOwner(owner);
			saveOwners();
			break;
		}
		case 2:{
			showMenu.toggleMenu();
			break;}
		}
	}

}

void Corporation::addWorker(Worker w1) {
	workers.push_back(w1);
}

void Corporation::addOwner(Owner w1) {
	owners.push_back(w1);
}

void Corporation::createCondominium() {
	string name;
	name = Menu::promptString("Name: ");
	float areaMultiplier = Menu::promptFloat("Cost per Square Meter: ");
	float floorMultiplier = Menu::promptFloat("Floor Multiplier: ");
	float baseApartmentCost = Menu::promptFloat("Base Apartment Cost: ");
	float baseOfficeCost = Menu::promptFloat("Base Office Cost: ");
	float baseStoreCost = Menu::promptFloat("Base Store Cost: ");
	Condominium condominium(name, areaMultiplier, floorMultiplier, baseApartmentCost, baseOfficeCost, baseStoreCost);
	addCondominium(condominium);
	saveCondominiums("condominiums.csv");
}


/* load functions */

void Corporation::loadWorkers(string filename){
	ifstream file;
	string line;
	long id;
	float wage;
	string name;
	vector <string> workersInfo;
	file.open(filename.c_str());
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				workersInfo.push_back(sub);
			} while (iss);

			id = atol(workersInfo[0].c_str());
			name = workersInfo[1];
			wage = atof(workersInfo[2].c_str());
			Worker wtemp(id,wage,name);
			workers.push_back(wtemp);

			workersInfo.clear();
		}
		lineNumber++;
	}
	file.close();
}

void Corporation::loadOwners(string filename){
	ifstream file;
	string line;
	long id;
	int contractType,monthsLeft;
	string name;
	vector <string> ownersInfo;
	file.open(filename.c_str());
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				ownersInfo.push_back(sub);
			} while (iss);

			id = atol(ownersInfo[0].c_str());
			name = ownersInfo[1];
			contractType = atoi(ownersInfo[2].c_str());
			monthsLeft = atoi(ownersInfo[3].c_str());
			Owner otemp(id,name,contractType,monthsLeft);
			owners.push_back(otemp);

			ownersInfo.clear();
		}
		lineNumber++;
	}
	file.close();
}

void Corporation::loadCondominiums(string filename) {
	ifstream file;
	string line;
	int id;
	vector <string> condominiumInfo;
	file.open(filename.c_str());
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				condominiumInfo.push_back(sub);
			} while (iss);

			id = atol(condominiumInfo[0].c_str());
			if(id>0) {
				Condominium condominium(id, condominiumInfo[1], atof(condominiumInfo[2].c_str()), atof(condominiumInfo[3].c_str()), atof(condominiumInfo[4].c_str()), atof(condominiumInfo[5].c_str()), atof(condominiumInfo[6].c_str()));
				condominiums.push_back(condominium);
				loadProperties(id);
				loadMaintenance(id);
			}
			condominiumInfo.clear();
		}
		lineNumber++;
	}
	file.close();
}

void Corporation::loadReports(string filename) {
	ifstream file;
	string line;
	int id;
	vector <string> reportsInfo;
	file.open(filename.c_str());
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				reportsInfo.push_back(sub);
			} while (iss);

			id = atol(reportsInfo[0].c_str());
			if(id>0) {
				//condominiums.push_back(condominium);
			}
			reportsInfo.clear();
		}
		lineNumber++;
	}
	file.close();
}

void Corporation::loadProperties(int condominiumid) {
	stringstream ssfilename;
	ssfilename << "properties" << condominiumid << ".csv";
	string filename = ssfilename.str(), address;
	ifstream file(filename.c_str());
	string line;
	int type, propertyFloor,Id;
	float area;
	vector <string> propertyInfo;
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				propertyInfo.push_back(sub);
			} while (iss);
			if(propertyInfo.size() == 6){
				type = atol(propertyInfo[0].c_str());
				address = propertyInfo[1];
				area = atof(propertyInfo[2].c_str());
				propertyFloor = atof(propertyInfo[3].c_str());
				Id= atoi(propertyInfo[4].c_str());
				if (type==1) {
					condominiums[searchCondominiumId(condominiumid)].addProperty(new Apartment(address,area,propertyFloor,getOwner(Id)));
				} else if (type==2) {
					condominiums[searchCondominiumId(condominiumid)].addProperty(new Office(address,area,propertyFloor,getOwner(Id)));
				} else if (type==3) {
					condominiums[searchCondominiumId(condominiumid)].addProperty(new Store(address,area,propertyFloor,getOwner(Id)));
				}
				propertyInfo.clear();
			}
		}
		lineNumber++;
	}
}

void Corporation::loadMaintenance(int condominiumid) {
	stringstream ssfilename;
	ssfilename << "maintenance" << condominiumid << ".csv";
	string filename = ssfilename.str(), name;
	ifstream file(filename.c_str());
	string line;
	int monthsLeft, type, workerid;
	float duration;
	vector <string> maintenanceInfo;
	int lineNumber = 0;
	while (file.good())
	{
		getline(file,line);
		if (lineNumber > 0) {
			istringstream iss(line);
			do
			{
				string sub;
				getline(iss, sub , ',');
				maintenanceInfo.push_back(sub);
			} while (iss);

			if(maintenanceInfo.size() == 6){
				monthsLeft = atoi(maintenanceInfo[0].c_str());
				type = atoi(maintenanceInfo[1].c_str());
				name = maintenanceInfo[2];
				workerid = atoi(maintenanceInfo[3].c_str());
				duration = atof(maintenanceInfo[4].c_str());
				condominiums[searchCondominiumId(condominiumid)].addMaintenance(new Maintenance(monthsLeft,duration, type, name, getWorker(workerid)));
				maintenanceInfo.clear();
			}
		}
		lineNumber++;
	}
}

int Corporation::searchCondominiumId(int condominiumdid) {
	for(unsigned int i = 0; i<condominiums.size(); i++) {
		if(condominiums[i].getId() == condominiumdid) {
			return i;
		}
	}
	return 0;
}

void Corporation::showAllCondominiums() {
	int i= 0;

	cout << endl;
	Menu showMenu("Condominiums List");
	showMenu.addMenuItem("List all properties information");
	showMenu.addMenuItem("Go to the NEXT condominium");
	showMenu.addMenuItem("Go to the PREVIOUS condominium");
	showMenu.addMenuItem("Go BACK to the PREVIOUS menu");

	while(showMenu.isActive()) {
		condominiums[i].showCondominium();
		switch(showMenu.showMenu()) {
		case 1:
			condominiums[i].showProperties();
			break;
		case 2:
			i = (i+1) % condominiums.size();
			break;
		case 3:
			i = (i-1) % condominiums.size();
			break;
		default:
			showMenu.toggleMenu();
			break;
		}
	}
}

/* save functions */

void Corporation::saveCondominiums(string filename){
	ofstream file(filename.c_str());
	file << "id,name,areaMultiplier,floorMultiplier,baseApartmentCost,baseOfficeCost,baseStoreCost" << endl;
	for(unsigned int i = 0; i < condominiums.size(); i++)
	{
		file << condominiums[i].getId() << "," << condominiums[i].getName() << "," << condominiums[i].getAreaMultiplier() << "," << condominiums[i].getFloorMultiplier() << "," << condominiums[i].getBaseApartmentCost() << "," << condominiums[i].getBaseOfficeCost() << "," << condominiums[i].getBaseStoreCost();
		if (i < (condominiums.size() -1))
			file << endl;
		condominiums[i].saveProperties();

	}
	file.close();
}

void Corporation::saveWorkers() {
	ofstream file("workers.csv");
	file << "id,name,wage" << endl;
	for(unsigned int i = 0; i < workers.size(); i++)
	{
		file << workers[i].getId() << "," << workers[i].getName() << "," << workers[i].getWage();
		if (i < (workers.size() -1))
			file << endl;
	}
	file.close();
}

void Corporation::saveOwners() {
	ofstream file("owners.csv");
	file << "id,name,contractType,monthsLeft" << endl;
	for(unsigned int i = 0; i < owners.size(); i++)
	{
		file << owners[i].getId() << "," << owners[i].getName() << "," << owners[i].getContractType() << "," << owners[i].getMonthsLeft();
		if (i < (owners.size() -1))
			file << endl;
	}
	file.close();
}

void Corporation::manageWorkers(int id){
	stringstream topic;
	topic << "Managing " << workers[id].getName() << ", wage: " << workers[id].getWage() << endl;
	string topic2 = topic.str();
	Menu showMenu(topic2.c_str());
	showMenu.addMenuItem("Edit Workers Name");
	showMenu.addMenuItem("Edit Workers Wage");
	showMenu.addMenuItem("Go BACK to the PREVIOUS Menu");

	while(showMenu.isActive()) {
		switch(showMenu.showMenu()) {
		case 1:{
			string name = Menu::promptString("New Name: ");
			workers[id].setName(name);
			saveWorkers();
			showMenu.toggleMenu();
			break;
		}
		case 2:{
			float wage = Menu::promptFloat("Set New Wage: ");
			workers[id].setWage(wage);
			saveWorkers();
			showMenu.toggleMenu();
			break;
		}
		case 3:
			showMenu.toggleMenu();
			break;
		}
	}
}

void Corporation::manageOwners(int id){
	stringstream topic;
	topic << "Managing " << owners[id].getName() << ", wage: " << owners[id].printType() << endl;
	string topic2 = topic.str();
	Menu showMenu(topic2.c_str());
	showMenu.addMenuItem("Edit Workers Name");
	showMenu.addMenuItem("Edit Workers Payment Method");
	showMenu.addMenuItem("Go BACK to the PREVIOUS Menu");

	while(showMenu.isActive()) {
		switch(showMenu.showMenu()) {
		case 1:{
			string name = Menu::promptString("New Name: ");
			owners[id].setName(name);
			saveOwners();
			showMenu.toggleMenu();
			break;
		}
		case 2:{
			Menu subMenu("Which type of contract will this owner have?");
			subMenu.addMenuItem("monthly");
			subMenu.addMenuItem("trimestal");
			subMenu.addMenuItem("annually");
			int type = subMenu.showMenu();
			owners[id].setType(type-1);
			saveOwners();
			showMenu.toggleMenu();
			break;
		}
		case 3:
			showMenu.toggleMenu();
			break;
		}
	}
}


void Corporation::manageCondominium() {
	int i= 0;
	Menu showMenu("Condominium Management");
	showMenu.addMenuItem("Choose this condominium to manage");
	showMenu.addMenuItem("Go to the NEXT condominium");
	showMenu.addMenuItem("Go to the PREVIOUS condominium");
	showMenu.addMenuItem("Go BACK to the PREVIOUS Menu");

	while(showMenu.isActive()) {
		condominiums[i].showCondominium();
		switch(showMenu.showMenu()) {
		case 1:
			condominiums[i].manageCond(getWorkersList(),getOwnersList());
			break;
		case 2:
			i = (i+1) % condominiums.size();
			break;
		case 3:
			i = (i-1) % condominiums.size();
			break;
		default:
			showMenu.toggleMenu();
			break;
		}
	}
}

void Corporation::manageWorkers() {
	int i= 0;
	Menu showMenu("Workers Management");
	showMenu.addMenuItem("Choose this worker to manage");
	showMenu.addMenuItem("Go to the NEXT worker");
	showMenu.addMenuItem("Go to the PREVIOUS worker");
	showMenu.addMenuItem("Go BACK to the PREVIOUS Menu");

	while(showMenu.isActive()) {
		//workers[i].showCondominium();
		switch(showMenu.showMenu()) {
		case 1:
			condominiums[i].manageCond(getWorkersList(),getOwnersList());
			break;
		case 2:
			i = (i+1) % condominiums.size();
			break;
		case 3:
			i = (i-1) % condominiums.size();
			break;
		default:
			showMenu.toggleMenu();
			break;
		}
	}
}

void Corporation::financeReports() {
	Menu showMenu("Finance Reports");
	showMenu.addMenuItem("Browse through all reports");
	showMenu.addMenuItem("Fast Forward time ");
	showMenu.addMenuItem("Go to the MAIN menu");
	while(showMenu.isActive()){
		switch (showMenu.showMenu()) {
		case 1:
			//browse reports
			break;
		case 2:
			fastForward();
			break;
		case 3:
			showMenu.toggleMenu();
			break;
		default: // going back
			break;
		}

	}
}

void Corporation::fastForward() {
	vector <int> fixedCosts;
	vector <string> negativeCondominiums;
	unsigned int monthsToAdvance;
	stringstream message;
	float profitlosssum = 0, fixed, profitloss;
	monthsToAdvance = Menu::promptInt("How many months would you like to advance? ");
	for(unsigned int i=0;i<monthsToAdvance;i++){
		for(unsigned int j=0;j<condominiums.size();j++){
			cout << endl;
			message << condominiums[j].getName() << " electrity/water/other costs for " << getMonth() << "/" << getYear() << ": ";
			fixed = Menu::promptFloat(message.str());
			fixedCosts.push_back(fixed);
			message.str("");
			message.clear();
			profitloss = (condominiums[j].getProfitLoss() - fixed);
			profitlosssum += profitloss;
			if(profitloss<0) {
				message << condominiums[j].getName() << " - Month " << getMonth() << "/" << getYear();
				negativeCondominiums.push_back(message.str());
				message.str("");
				message.clear();
			}
			cout << endl << condominiums[j].getName() << " generated a total profit/loss of " << profitloss << "€" << endl;
			condominiums[j].advanceOneMonth();
		}
		incDate();
	}
	cout << endl << "Months Fast Forwarded: " << monthsToAdvance << endl;
	cout << "Total Profit/Loss: " << profitlosssum << "€" << endl;
	cout << "Average Profit/Loss " << profitlosssum/monthsToAdvance << "€" << endl;
	cout << "List of negative condominius: " << endl;
	for(unsigned int i=0; i<negativeCondominiums.size(); i++) {
		cout << negativeCondominiums[i] << endl;
	}
	cout << endl;

}

bool Corporation::isEmpty() {
	if(condominiums.size() > 0) {
		return false;
	} else {
		return true;
	}
}

void Corporation::showWorker() {
	if(workers.size()==0){
		cout << "There are no workers in this corporation, please add one first" << endl;
	}else {

		int i= 0;
		Menu showMenu("Workers Management");
		showMenu.addMenuItem("Choose this worker to manage");
		showMenu.addMenuItem("Go to the NEXT worker");
		showMenu.addMenuItem("Go to the PREVIOUS worker");
		showMenu.addMenuItem("Go BACK to the PREVIOUS Menu");

		while(showMenu.isActive()) {
			cout << "Name: " << workers[i].getName() << " ,Wage: " << workers[i].getWage() << endl;
			switch(showMenu.showMenu()) {
			case 1:
				manageWorkers(i);
				break;
			case 2:
				i = (i+1) % workers.size();
				break;
			case 3:
				i = (i-1) % workers.size();
				break;
			default:
				showMenu.toggleMenu();
				break;
			}
		}
	}
}

void Corporation::showOwner() {
	if(owners.size()==0){
		cout << "There are no owners in this corporation, please add one first" << endl;
	}else {

		int i= 0;
		Menu showMenu("Owners Management");
		showMenu.addMenuItem("Choose this owner to manage");
		showMenu.addMenuItem("Go to the NEXT worker");
		showMenu.addMenuItem("Go to the PREVIOUS worker");
		showMenu.addMenuItem("Go BACK to the PREVIOUS Menu");

		while(showMenu.isActive()) {
			cout << "Name: " << owners[i].getName() << " ,contractType: " << owners[i].printType() << endl;
			switch(showMenu.showMenu()) {
			case 1:
				manageOwners(i);
				break;
			case 2:
				i = (i+1) % owners.size();
				break;
			case 3:
				i = (i-1) % owners.size();
				break;
			default:
				showMenu.toggleMenu();
				break;
			}
		}
	}
}
