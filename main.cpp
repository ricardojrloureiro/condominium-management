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

int quit() {
	cout << "QUIT";
	return 0;
}

int main() {
	Menu mainMenu("Main Menu");
	mainMenu.addMenuItem("Condominiums", *quit);
	mainMenu.addMenuItem("Quit", *quit);
	mainMenu.showMenu();
}
