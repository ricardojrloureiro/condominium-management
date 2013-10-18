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
	condominiumsMenu.addMenuItem("Manage existing condomium");

	while(1) {
		switch(mainMenu.showMenu()) {
		case 1:
			while(1) {
				switch(condominiumsMenu.showMenu()) {
				case 1:
					corporation.showAllCondominiums();
					break;
				case 2:
					break;
				}
			}
			break;
		case 2:
			return 0;
			break;
		}
	}
}
