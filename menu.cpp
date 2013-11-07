/*
 * menu.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: rui
 */

#include "menu.h"

Menu::Menu(string title) {
	this->title = title;
	active = true;
}

void Menu::addMenuItem(string item) {
	items.push_back(item);
}

void Menu::toggleMenu() {
	active = !active;
}

bool Menu::isActive() {
	return active;
}

void Menu::activateMenu() {
	active = true;
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

float Menu::promptFloat(string message) {
	string tempinput;
	float outputvalue;
	bool validInput;
	bool dotUsed;
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
		dotUsed = false;
		if(!tempinput.empty()) {
			for (unsigned int i = 0; i < tempinput.length(); i++)
			{
				if (!isdigit(tempinput[i]) && dotUsed) {
					validInput=false;
					break;
				}
				if(tempinput[i] == '.') {
					dotUsed = true;
				}
			}
		} else {
			validInput = false;
		}
		if (validInput==true) {
			outputvalue=atof(tempinput.c_str());
		}
		if(!validInput) {
			cout << endl << "This input is not valid. Please try and follow the indicated instructions." << endl << endl;
		}
	} while (!validInput);
	return outputvalue;
}

int Menu::showMenu() {
	unsigned int option;
	bool valid = false;
	cout << title << endl;

	for(unsigned int i = 0; i<items.size(); i++) {
		cout << i + 1 << " - " << items[i] << endl;
	}

	while(!valid) {
		option = promptInt("Choose an option: ");
		valid = false;
		for (unsigned int i = 0; i<items.size(); i++) {
			if(i+1 == option) {
				valid = true;
			}
		}

		if(!valid) {
			cout << endl << "This input is not valid. Please try and follow the indicated instructions." << endl << endl;
		}
	}
	cout << endl;
	return option;
}

string Menu::promptString(string message) {
	string tempinput;
	string outputvalue;
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
		if (tempinput.empty()) {
			validInput = false;
		}
		if(!validInput) {
			cout << endl << "This input is not valid. Please try and follow the indicated instructions." << endl << endl;
		}
	} while (!validInput);
	outputvalue = tempinput;
	return outputvalue;
}
