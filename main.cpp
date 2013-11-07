#include "condominium.h"
#include "property.h"
#include "corporation.h"
#include "owner.h"	
#include "worker.h"
#include "menu.h"
#include "maintenance.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;
Corporation corporation;

int main() {
	Menu mainMenu("Main Menu");
	mainMenu.addMenuItem("Condominiums");
	mainMenu.addMenuItem("Add workers to the Corporation");
	mainMenu.addMenuItem("Finance Reports");
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
							//manage workers;
							break;
						case 3:
							workersMenu.toggleMenu();
							break;
					}
				}
				corporation.addWorker();
			break;
			case 3:
				corporation.financeReports();
			// add workers
			break;
			case 4:
			mainMenu.toggleMenu();
		}
	}
}
