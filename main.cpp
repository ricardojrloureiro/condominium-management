#include "condominium.h"
#include "property.h"
#include "corporation.h"
#include "owner.h"
#include "worker.h"
#include "menu.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

Corporation corporation;

int main() {
	Menu mainMenu("Main Menu");
	mainMenu.addMenuItem("Condominiums");
	mainMenu.addMenuItem("Quit");

	Menu condominiumsMenu("Condominiums");
	condominiumsMenu.addMenuItem("List all condominiums");
	condominiumsMenu.addMenuItem("Add new condominium");
	condominiumsMenu.addMenuItem("Manage existing condominium");
	condominiumsMenu.addMenuItem("Return to Main Menu");

	while(mainMenu.isActive()) {
		switch(mainMenu.showMenu()) {
		case 1:
			condominiumsMenu.activateMenu();
			while(condominiumsMenu.isActive()) {
				switch(condominiumsMenu.showMenu()) {
				case 1:
					corporation.showAllCondominiums();
					break;
				case 2:
					corporation.createCondominium();
					break;
				case 3:
					corporation.manageCondominium();
					break;
				case 4:
					condominiumsMenu.toggleMenu();
					break;
				}
			}
			break;
		case 2:
			mainMenu.toggleMenu();
			break;
		}
	}
}
