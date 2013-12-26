#include "condominium.h"
#include "property.h"
#include "corporation.h"
#include "owner.h"	
#include "worker.h"
#include "menu.h"
#include "maintenance.h"
#include "report.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
Corporation corporation;

int main() {
	Menu mainMenu("Main Menu");
	mainMenu.addMenuItem("Condominiums");
	mainMenu.addMenuItem("Manage Workers");
	mainMenu.addMenuItem("Manage Owners");
	mainMenu.addMenuItem("Finance Reports");
	mainMenu.addMenuItem("Condominium Events");
	mainMenu.addMenuItem("Quit");

	Menu condominiumsMenu("Condominiums");
	condominiumsMenu.addMenuItem("Add new condominium");
	condominiumsMenu.addMenuItem("List all condominiums");
	condominiumsMenu.addMenuItem("Manage existing condominium");
	condominiumsMenu.addMenuItem("Return to Main Menu");

	Menu workersMenu("Manage Workers");
	workersMenu.addMenuItem("Add new worker");
	workersMenu.addMenuItem("Manage existing worker");
	workersMenu.addMenuItem("Return to Main Menu");

	Menu ownersMenu("Manage Owners");
	ownersMenu.addMenuItem("Add new owner");
	ownersMenu.addMenuItem("Manage existing owner");
	ownersMenu.addMenuItem("Return to Main Menu");

	while(mainMenu.isActive()) {
		switch(mainMenu.showMenu()) {
		case 1:
			condominiumsMenu.activateMenu();
			while(condominiumsMenu.isActive()) {
				switch(condominiumsMenu.showMenu()) {
				case 1:
					corporation.createCondominium();
					break;
				case 2:
					if(corporation.isEmpty()) {
						cout << "There are no condominiums yet. Please add one first." << endl;
					} else {
						corporation.showAllCondominiums();
					}
					break;
				case 3:
					if(corporation.isEmpty()) {
						cout << "There are no condominiums yet. Please add one first." << endl;
					} else {
						corporation.manageCondominium();
						corporation.saveCondominiums("condominiums.csv");
					}
					break;
				case 4:
					condominiumsMenu.toggleMenu();
					break;
				}
			}
			break;
		case 2:
			workersMenu.activateMenu();
			while(workersMenu.isActive()) {
				switch(workersMenu.showMenu()) {
				case 1:
					corporation.addWorker();
					break;
				case 2:
					corporation.showWorker();
					break;
				case 3:
					workersMenu.toggleMenu();
					break;
				}
			}
			break;
		case 3:
			ownersMenu.activateMenu();
			while(ownersMenu.isActive()) {
				switch(ownersMenu.showMenu()) {
				case 1:
					corporation.addOwner();
					break;
				case 2:
					corporation.showOwner();
					break;
				case 3:
					ownersMenu.toggleMenu();
					break;
				}
			}
			break;
		case 4:
			corporation.financeReports();
			break;
		case 5:
			corporation.condEvents(corporation.getDate());
			break;
		case 6:
			mainMenu.toggleMenu();
			break;

		}
	}

}

