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

using namespace std;

class Menu {
	string title;
	vector <string> items;
public:
	Menu(string title);
	void addMenuItem(string option);
	int showMenu();
};

#endif /* MENU_H_ */
