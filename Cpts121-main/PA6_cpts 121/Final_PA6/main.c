// Naomi Dion-Gokan
// 11/16/21
// CPT-S 121
// Programming Assignment 6
// This program will evaluate and implement an interactive two-players game called Battleship.

#include "header.h"


int main(void)
{
									  srand((unsigned int)time(NULL));
								

	char p1_board[MAX_ROWS][MAX_COLS] = { '\0' }, p2_board[MAX_ROWS][MAX_COLS] = { '\0' };  //Players' boards

	           bool plays = false;

	//Setting the ship class to their name, symbol, and length.
	Ship ship[5] = { {"Carrier",'c',5},{"Battleship",'b',4},{"Cruiser",'r',3}, {"Submarine",'s',3}, {"Destroyer",'d',2} };

	Stats p1_stats = { 0,0,0,0.0 }; Stats p2_stats = { 0,0,0,0.0 };

	int c_shots[MAX_ROWS][MAX_COLS] = { 0 };   int p1_sunkships[5] = { 5,4,3,3,2 }, p2_sunkships[5] = { 5,4,3,3,2 };

	//initializes player 1's board and player 2 (computer) board
	init_board(p1_board, MAX_COLS, MAX_COLS); init_board(p2_board, MAX_COLS, MAX_COLS);

	print_board(p1_board, MAX_COLS, MAX_COLS, false);


	               int choice = welcome_screen_rules_menu(); // welcome screen with the rules and menu

	                                if (choice == 2)   //exit the game
                                 	{ 
		                                printf("Thank you for playing Battleship!\n\n");
		                                 return 0;
	                                }

	                               if (choice = 1) // Player decides to play the game 
	                	           plays = true;

    while (plays = true)
	{
		FILE* outfile = NULL;  outfile = fopen("Battleship.log", "w");  int option = ship_placement_option();
			
		       if (option == 1) // Random placement
			   randomly_place_ships(p1_board, MAX_ROWS, MAX_COLS, ship);

		      if (option == 2) // Manual placement
			  manually_place_ships(p1_board, MAX_ROWS, MAX_COLS, ship);

			  //Random placement for the computer board
			  randomly_place_ships(p2_board, MAX_ROWS, MAX_COLS, ship);

		int start_player = who_starts_first();


		        if (start_player == 2)    // Player 2 (computer) starts the game
		        {    
			        system("cls");
					printf(" Player 2 (computer) has been randomly selected to go first\n\n");
			        computer_shot(p1_board, MAX_ROWS, MAX_ROWS, outfile, p2_stats, c_shots, p1_sunkships);
		        }

		        else if (start_player == 1)   // Player 1 starts the game
		        {
			      system("cls");
				  printf(" Player 1 has been randomly selected to go first\n\n");
			      
		        }

		do    // Playing the game
		{ 
			player_shot(p2_board, MAX_ROWS, MAX_COLS, outfile, p1_stats, p2_sunkships); // player shoots
			computer_shot(p1_board, MAX_ROWS, MAX_ROWS, outfile, p2_stats, c_shots, p1_sunkships); //computer shoots

		} while (!is_ships_sunk(p1_sunkships) || !is_ships_sunk(p2_sunkships));

		system("cls");  

		if (is_ships_sunk(p1_sunkships))   // if player 2 wins
		{ 
			printf(" \nPlayer 2 (computer) wins!\n");
			fprintf(outfile, "\nPlayer 2 (computer) wins, player 1 loses!\n");
		}

		if (is_ships_sunk(p2_sunkships))    // if player 1 wins
		{ 
			printf(" \nPlayer 1 wins!\n");
			fprintf(outfile, "\nPlayer 1 wins, player 2 (computer) loses!\n");
		}

		          system("pause");

		// printing the statistics to outfile and screen
		output_stats(p1_stats, p2_stats, outfile); 

		fclose(outfile); 

		plays = false; //exit the game
	}

	return 0;
}