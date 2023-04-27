#pragma once
#include "Service.h"


class UI
{
private:
	Service* service;

	void printAllCoats();

	//menus for the roles
	void runAdminMenu();
	void runUserMenu();
	void displayCoats(ShoppingCart* final_list, int &sum);
	void runCartMenu();

	//admin functions
	void addUI();
	void deleteUI();
	void updateUI();

public:
	//constructor
	UI(Service* new_service) : service{ new_service } {}

	void runMenu();
};
//1h 40 min