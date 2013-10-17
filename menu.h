/*
 * menu.h
 *
 *  Created on: Oct 14, 2013
 *      Author: rui
 */

#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Menu {
	string title;
	vector <string> items;
public:
	Menu(string title);
	void addMenuItem(string);
	void clearScreen();
	int promptInt(string);
	int showMenu();

};

#endif /* MENU_H_ */
