//
// Created by sherryl Dion-Gokan on 9/13/22.
//

#include "data.h"

Data :: Data (string new_command, string new_description)
{
       // Setting the elements of the private to those new elements
    command = new_command;
    description = new_description;
}

     // Setters
void Data :: set_command(string& new_command)
{
     // Setting this new element to the element of the private
    new_command = command;
}

void Data :: set_description(string & new_description)
{
       // Setting this new element to the element of the private
    new_description = description;
}

     // Getters
string Data :: getCommand() const
{
    return command;
}
string Data :: getDescription() const
{
     return description;
}


void copyElements_ofOriginalFile(fstream &file, vector<Data> &commands) {
    string input, buffer = "";

    // create temp buffer with size of one Data unit:
    Data *temp = nullptr;
    temp= new Data;

    string buffer1 = ", \"", buffer2 = "\"";

    // As long as the file is open, grab line and copy data until the end of the file
    while (!file.eof())
    {
        // Get the name of the command
        getline(file, input, '\n');
        buffer = input.substr(0, input.find(buffer1));
        temp->set_command(buffer);

        // extract the name from the input string
        buffer += buffer1;
        input.erase(0, buffer.size());
        buffer = "";

        // Get the description:
        buffer = input.substr(0, input.find_last_of(buffer2));
        temp->set_command(buffer);

        commands.push_back(*temp);
    }

    delete temp;
}

bool openInputFile(fstream &file, string fileName) {
    file.open(fileName, std::ios::in);

    if (file.fail())
        return false;
    else
        return true;
}

void populateElements(vector<Data> &element) {
    fstream dataFile;

    if (openInputFile(dataFile, "commands.csv")) {
        cout << "The file is successfully open." << endl;
        copyElements_ofOriginalFile(dataFile, element);
        dataFile.close();
    }

    else
        cout << "Sorry! The file did not open!" << endl;
}

        // Player Information

void Player :: set_player_name(string person_name)
{
    cout << "What is your name? ";

    cin >> person_name;
    player_name = person_name;
}

string Player:: get_player_name() const
{
    return player_name;
}

int Player :: get_player_points() const
{
    return points;
}

void Player :: give_1point()
{
    points += 1;
}
void Player :: takeAway_1point()
{
    points -= 1;
}

void Player :: reset_points()
{
    points = 0;
}

       // Non-Member Functions

bool openOutput_file(fstream &file, string fileName)
{
    file.open(fileName, std::ios::out);

    if (file.fail())
        return false;
    else
        return true;
}


void writeToProfiles(Player &player)
{
    fstream profile_file;
    string name = player.get_player_name();
    int points = player.get_player_points();

    if (openOutput_file(profile_file, "profiles.csv"))
   {
       cout << "File opened successfully! All data have been stored!" << std::endl;
   }
   else
       cout << "Sorry. The file did not open." << std::endl;

    profile_file << " " << name << " " << ", " << points << std::endl;

    profile_file.close();
}