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

void Menu::clearScreen() {
	cout << string( 100, '\n' );
}

int Menu::promptInt(string message) {
	string tempinput;
	int outputvalue;
	bool validInput;
	do
	{
		cout << message;
		getline(cin,tempinput);
		validInput = true;
		if (cin.fail())
		{
			validInput = false;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		if(!tempinput.empty()) {
			for (unsigned int i = 0; i < tempinput.length(); i++)
			{
				if (!isdigit(tempinput[i])) {
					validInput=false;
					break;
				}
			}
		} else {
			validInput = false;
		}
		if (validInput==true) {
			outputvalue=atoi(tempinput.c_str());
		}
		if(!validInput) {
			cout << endl << "This input is not valid. Please try and follow the indicated instructions." << endl << endl;
		}
	} while (!validInput);
	return outputvalue;
}

int Menu::showMenu() {
	clearScreen();
	unsigned int option;
	cout << title << endl;
	for(unsigned int i = 0; i<items.size(); i++) {
		cout << i + 1 << " - " << items[i] << endl;
	}
	option = promptInt("Choose an option: ");
	return option;
}
