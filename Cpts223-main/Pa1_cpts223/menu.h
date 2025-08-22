//
// Created by sherryl Dion-Gokan on 9/8/22.
//
#pragma once
#ifndef PA1_CPTS223_MENU_H
#define PA1_CPTS223_MENU_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
//#include <stdlib.h>
#include <vector>
#include <ctime>

#include "list.h"

#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

class Menu{
public:

    // Constructor
    Menu();

    // Destructor
    ~Menu();

    // This function displays the menu to the screen
    void display_menu();

    // This function allows the user to pick its option from the menu
    void performUserSelection(const int &option);

    // This function displays the rules of the game
    void display_gameRules();

    // playGame();
    void playGame(List<Data,Data> &file, Player &playerInfo, vector<Data> &info);

    void loadPrevious_game(List<Data,Data> &file, Player &playerInfo, vector<Data> &info);

    void add_command(List<Data,Data> &file, vector<Data> &info);

    void remove_command(List<Data,Data>& file);

    // This function runs the program and the choices picked by the user
    void RunApp();

    void write_InCommand_file(List<Data,Data>& file);

private:

   List<Data,Data> master_file;
   vector<Data> info_file;
   ifstream extraction;
   ofstream insertion;
   Player player_info;  // & ?
};

#endif //PA1_CPTS223_MENU_H
