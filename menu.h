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
	bool active;
	string title;
	vector <string> items;
public:
	Menu(string title);
	void addMenuItem(string);
	static int promptInt(string);
	static string promptString(string);
	void activateMenu();
	void toggleMenu();
	bool isActive();
	int showMenu();

};

#endif /* MENU_H_ */
