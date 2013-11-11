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
	/**
	 * Do:
	 *  Constructor.
	 * @param string Topic of the Menu;
	 */
	Menu(string title);

	/**
	 * Do:
	 *  Adds a line to the current menu that can be used by the user.
	 * @param string string to be apresented to the user as a menu option;
	 */
	void addMenuItem(string);

	/**
	 * Do:
	 *  Checks if every single character in the string is a digit.
	 *  returns the input if it is else gives a error message.
	 * @param string input string;
	 */
	static int promptInt(string);

	/**
	 * Do:
	 *  Checks if every single character in the string is a character.
	 *  returns the input if it is else gives a error message.
	 * @param string input string;
	 */
	static string promptString(string);

	/**
	 * Do:
	 *  Checks if every single character in the string is a digit and if has one and at the max one ".".
	 *  returns the input if it is else gives a error message.
	 * @param string input string;
	 */
	static float promptFloat(string);

	/**
	 * Do:
	 *  activates the Menu.
	 */
	void activateMenu();

	/**
	 * Do:
	 *  if the menu is active it deactivates the menu other ways activates the menu.
	 */
	void toggleMenu();

	/**
	 * Do:
	 *  checks if the menu is either enabled or disabled.
	 * returns true if it is or false if it isn't.
	 */
	bool isActive();

	/**
	 * Do:
	 *  Allows the user to choose either option of the menu he wants
	 * returns the option if it is acceptable otherways shows an error message and asks again.
	 */
	int showMenu();

};

#endif /* MENU_H_ */
