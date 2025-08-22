// Naomi Dion-Gokan
// 11/01/21
// CPT_S_121
// Programming Assignment 5
// This program will evaluate and implement an interactive two-players game called Yahtzee.

#include "function.h"

int main(void)
{
	srand((unsigned int)time(NULL));

	int menu_choice = 0;
	//while (menu_choice != 3)
	while (menu_choice < 1 || menu_choice > 3)
		menu_choice = print_menu(menu_choice);

	return 0;
}