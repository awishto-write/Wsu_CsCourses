//
// Created by sherryl Dion-Gokan on 9/13/22.
//

#ifndef PA1_CPTS223_DATA_H
#define PA1_CPTS223_DATA_H

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;


class Data{

public:
    // Constructor
    Data(string new_command = "", string new_description = "");

    // Setters
    void set_command(string& new_command);
    void set_description(string & new_description);

    // Getters

    string getCommand() const;
    string getDescription() const;



protected:
    string command;
    string description;
};

              // Non-Member Functions related to Data

   // This function copies elements from the commands.csv file to
void copyElements_ofOriginalFile(fstream &file, vector<Data> &commands);

     // This function opens input file
     bool openInputFile(fstream &file, string fileName);

      // This function populates the elements from the csv file
      void populateElements(vector<Data> &element);

            // Class Player

class Player {

public:
    Player()
    {
        player_name = "";
        points = 0;
    }

         // Setter
    void set_player_name(string person_name);

        // Getters
    string get_player_name() const;
    int get_player_points() const;

         // Functionalities of the game
    void give_1point();
    void takeAway_1point();
    void reset_points();

protected:
    string player_name;
    int points;
};

              // Non-member functions of Player
bool openOutput_file(fstream &file, string fileName);
void writeToProfiles(Player &player);


#endif //PA1_CPTS223_DATA_H
