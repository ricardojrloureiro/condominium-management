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
#include <limits>

typedef int (*FunctionPointer)();

using namespace std;

class Menu {
	string title;
	vector <string> items;
	vector <FunctionPointer> functions;
public:
	Menu(string title);
	void addMenuItem(string,FunctionPointer);
	int showMenu();
};

#endif /* MENU_H_ */
