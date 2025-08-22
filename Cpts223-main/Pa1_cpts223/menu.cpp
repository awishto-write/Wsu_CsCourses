//
// Created by sherryl Dion-Gokan on 9/8/22.
//

#include "menu.h"

Menu :: Menu()
{
    // Nothing
}

Menu :: ~Menu()
{
    // It does nothing
}

void Menu::display_menu()
{
    cout << endl;
    cout << "          WELCOME !       " << endl;
    cout << " Please, choose an option below !" << endl << endl;
    cout << " 1. Game Rules" << endl;
    cout << " 2. Play Game" << endl;
    cout << " 3. Load Previous Game" << endl;
    cout << " 4. Add Command" << endl;
    cout << " 5. Remove Command" << endl;
    cout << " 6.  Exit" << endl << endl;
}

void Menu::RunApp()
{
    int option = 0;
    do
    {
        do // input validation loop
        {
            display_menu();
            cin >> option;

        } while (option < 1 || option > 6);   // validate the input; option must be [1 - 7]

        //system("cls"); // clear the screen
        system("clear");

        // have obtained the option from the user; need to determine next operation
        performUserSelection(option);

    } while (option != 6); // 6 = exit the program

    master_file.~List();   // Deallocating the memory
}

void Menu::display_gameRules()
{
    cout << "The objective of the game is to match Linux commands to appropriate \n"
            "descriptions of those commands. If a command is matched, then the player \n"
            "earns 1 point. The if the command is not matched, then the player loses \n"
            "a point. The player selects the number of match questions at the beginning \n"
            "of the game. The game continue until the number is reached.  " << endl;
}


void Menu::performUserSelection(const int& option)
{
    bool success = false;

    switch (option)
    {
        case 1: display_gameRules();
            break;

        case 2: playGame(master_file, player_info, info_file);
            break;

        case 3: loadPrevious_game(master_file, player_info, info_file);
            break;

        case 4:
           add_command(master_file, info_file);
            break;

        case 5:
            remove_command(master_file);
            break;

        case 6:
                  // Storing Data
            writeToProfiles(player_info);
            write_InCommand_file(master_file);

            cout << "Goodbye" << endl;
            break;
    }

}

void Menu :: playGame(List<Data,Data> &file, Player &playerInfo, vector<Data> &info)
{
    int size_game_list = file.getList_size();
    string name;
       // Asking the player name
    player_info.set_player_name(name);

        // Set the player points to 0
    player_info.reset_points();

            // Ask the user for the number of commands he/she wants to generate
    int num_command = 0, random = 0;
    cout << "Now, how many commands/questions do you want to generate for matching?" << endl;
    cin >> num_command;

               //
    vector<int> gLength;
    gLength.resize(num_command);

          // Create a vector/ list of commands for the game
    for (int i = 0; i < num_command; i++) {
        random = rand() % size_game_list;
        gLength[i] = random;
    }

}

void Menu :: loadPrevious_game(List<Data,Data> &file, Player &playerInfo, vector<Data> &info)
{
    playGame(file, playerInfo, info);
}

void Menu :: add_command(List<Data,Data> &file, vector<Data> &info)
{
    string choice;
    Data *temp = nullptr;
    temp = new Data;

    cout << "Do not press 'enter' until you finish adding every entry.\n";
    cout << "Please enter the command (name) you would like to add: ";
    std::cin >> choice;
    temp->set_command(choice);

    std::cout << "Please enter a description for the command: ";
    std::cin >> choice;
    temp->set_description(choice);

    Node<Data,Data> *newInfo = nullptr;
    newInfo = new Node<Data,Data>;

    //newInfo->Ptr = temp;
   // file.InsertAtFront(newInfo, newInfo);
    //info.push_back(*temp);
}



void Menu::remove_command(List<Data,Data>& file)
{
    string to_delete;
    Data *temp = nullptr;
    temp = new Data;

    std::cout << "Please choose the command(name) you want to remove: ";
    std::cin >> to_delete;
    temp->set_command(to_delete);

    Node<Data,Data> *command_to_delete= nullptr;

    command_to_delete = new Node<Data,Data>;

    //command_to_delete->Ptr = temp;
   //file.help_destroy(command_to_delete);
}

void Menu:: write_InCommand_file(List<Data,Data>& file)
{
    fstream CommandFile;
    CommandFile.open("commands.csv", std::ios::out);

    Node<Data, Data> *nodePtr;
    // Get the head of the list
    nodePtr = file.get_pHead();

    string name, description;

    while (nodePtr != nullptr) {
        // Declare a dummy data
        Data *newdata;
        name = newdata->getCommand();
        description = newdata->getDescription();

        CommandFile << name << ", \"" << description << "\"" << std::endl;
        nodePtr = nodePtr->nextPtr;
    }

    CommandFile.close();

}


