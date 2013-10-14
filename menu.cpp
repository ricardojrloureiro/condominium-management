/*
 * menu.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: rui
 */

#include "menu.h"

Menu::Menu(string title) {
	this->title = title;
}

void Menu::addMenuItem(string item) {
	items.push_back(item);
}

int Menu::showMenu() {
	int option;
	cout << "1 - Access Admin control panel" << endl;
	cout << "2 - Access as User." << endl << endl;
	do {
		//option = promptInt("Choose an option: ");
		if(option < 1 || option > 2) {
			cout << endl << "This input is not valid. Please try and follow the indicated instructions." << endl << endl;
		}
	} while (option < 1 || option > items.size());
	return 0;
}
