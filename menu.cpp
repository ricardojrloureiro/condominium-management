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

void Menu::addMenuItem(string item, FunctionPointer pointer) {
	items.push_back(item);
	functions.push_back(pointer);
}

int Menu::showMenu() {
	unsigned int option;
	cout << title << endl;
	cout << "1 - Access Admin control panel" << endl;
	cout << "2 - Access as User." << endl;
	cout << "Choose an option: " << endl << endl;
	while(!(cin >> option) || option < 1 || option > items.size()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "This input is not valid. Please try again: ";
	}
	functions[option-1]();
	return 0;
}
