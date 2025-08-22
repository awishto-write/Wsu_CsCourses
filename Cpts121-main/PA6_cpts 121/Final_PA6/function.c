#include "header.h"


                   // Welcome Screen including the rules and the menu

int welcome_screen_rules_menu(void)
{
	int choice = '\0', attempt = 0;
	do
	{
		++attempt;
		system("cls");
		if (attempt > 1)

			puts(" Invalid user input, please try again\n");

		printf(" ********************************************************************************************************\n");
		printf("                                                                                                         \n");
		printf("                              WELCOME TO THE GAME OF BATTLESHIP                                          \n");
		printf("                                                                                                         \n");
		printf("                       Rules of the game:                                                                \n");
		printf("                                                                                                         \n");
		printf("     This is a two players game.                                                                          \n");
		printf("   Player1 is you and Player2 is the computer.                                                           \n");
		printf("                                                                                                         \n");
		printf("The object of Battleship is to try and sink all of the other player's before they sink all of your ships.\n");
		printf("                         All of the other player's ships are somewhere on his/her board.                 \n");
		printf("           Each board in the physical game has two grids:                                                \n");
		printf("    - the lower (horizontal) section for the player's ships and                                          \n");
		printf("    - the upper part(vertical during play) for recording the player's guesses.                           \n");
		printf("                                                                                                         \n");
		printf("    Each player places the 5 ships somewhere on their board.                                             \n");
		printf("              The ships can only be placed vertically or horizontally.                                   \n");
		printf("   Diagonal placement is not allowed. No part of a ship may hang off the edge of the board.              \n");
		printf("           Ships may not overlap each other.  No ships may be placed on another ship.                    \n");
		printf("                      Once the guessing begins, the players may not move the ships.                      \n");
		printf("                                                                                                         \n");
		printf(" The 5 ships are : Carrier(5), Battleship(4), Cruiser(3), Submarine(3), and Destroyer(2).                \n");
		printf("               Player's take turns guessing by calling out the coordinates.                              \n");
		printf("        The system responds with 'hit' or 'miss' as appropriate.                                         \n");
		printf("               When all of the squares that one your ships occupies have been hit, the ship will be sunk.\n");
		printf("                                You should announce 'hit and sunk'.                                      \n");
		printf("  As soon as all of one player's ships have been sunk, the game ends.                                    \n");
		printf("                                                                                                         \n");
		printf(" ********************************************************************************************************\n");
		printf("                                                                                                         \n");
		printf("              Please hit (ENTER/RETURN) to start the game or exit                                        \n");
		getchar();
		system("cls");

		printf("---------------------------------------------------------------------\n");
		printf("  Please choose an option(number) from the following menu:           \n");
		printf("            1. Play the game                                         \n");
		printf("            2. Exit                                                  \n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

		scanf("%d", &choice);
		system("cls");


	} while (choice != 1 && choice != 2);


	//system("cls");

	return choice;
}

                    // Initialization of the game boards       

void init_board(char board[][MAX_COLS], int num_rows, int num_cols)  
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '-';
		}
	}
}

                   // Printing the game boards

void print_board(char board[][MAX_COLS], int num_rows, int num_cols, bool hides)
{
	int row_index = 0, col_index = 0;

	printf("  ");

	for (col_index = 0; col_index < num_cols; ++col_index)  // prints the  header 0-9 
	{
		printf("%d ", col_index);
	}

	puts("");

	for (row_index = 0; row_index < num_rows; ++row_index) //prints the board
	{
		printf("%d ", row_index);

		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			if (!hides)
				printf("%c ", board[row_index][col_index]);

			else if (hides)

				switch (board[row_index][col_index])
				{
				case HIT:
					printf("%c ", HIT);
					break;
				case MISS:
					printf("%c ", MISS);
					break;
				default:
					printf("%c ", WATER);
					break;
				}
		}
		printf("\n");
	}
}

                  // Random Selection of the first player to start the game  

int who_starts_first(void)
{
	int first = 0;  
	first = (rand() % 2) + 1;

	printf("  The system will randomly select a player to start first\n\n ");
	
	return first;
}

                  // Choice betweeen placing the ships randomly or manually

int ship_placement_option(void)
{
	int option= 0, attempt = 1;
	do
	{
		system("cls");
		if (attempt > 1)
			printf(" Invalid input, please try again\n\n");
		++attempt;

		printf("-------------------------------------------------------------------\n");
		printf("Please choose an option(number) from the following menu:           \n");
		printf("        1. Allow the program to randomly select positions of ships.\n");
		printf("        2. Enter positions of ships manually.                      \n");
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		printf(" Option: ");

		scanf("%d", &option);

	} while (option != 1 && option != 2);

	return option;
}

                         // Generate direction 

Dir generate_dir(void)
{
	Dir direction = horizontal;

	direction = (Dir)rand() % 2;

	return direction;
}

                          // Manually place the ships on the board

void manually_place_ships(char board[][MAX_COLS], int num_rows, int num_cols, Ship ship[])
{
	      int valid = 0, attempt = 0;   
				    Coordinate start_pt = { -1,-1 };   
				                                         char target = '\0';
	                  Dir direction = horizontal;

	            system("cls");
	printf("Welcome to the manual ship placement.\n\n");
	printf("First pick your starting coordinates and after the direction (right or down) to place the ships\n");

	for (int i = 0; i < 5; i++)
	{
		attempt = 0;
		int attempt1 = 0;

		do
		{
			if (attempt > 0)
			{
				system("cls");
				printf("Invalid placement, please try again\n\n");
			}

			++attempt;

			print_board(board, num_cols, num_cols, false);
			printf("For the %s, (length %d), where would you like the starting point to be?\n", ship[i].name, ship[i].length);
			printf("\n Row: ");
			scanf("%d", &start_pt.row);
			printf("\nColumn: ");
			scanf("%d", &start_pt.col);

			do
			{
				if (attempt1 > 0)
				{
					printf(" Invalid direction, please try again\n");
				}

				attempt1++;

				printf("\n Direction (right 'r', down 'd'): ");
				scanf(" %c", &target);

			} while (target != 'r' && target != 'd');

			if (target == 'r')
				direction = horizontal;
			if (target == 'd')
				direction = vertical;
			valid = is_valid(board, num_rows, num_cols, start_pt, direction, ship[i].length);

		} while (!valid);

		for (int j = 0; j < ship[i].length; j++)
		{
			if (direction == horizontal)
				board[start_pt.row][start_pt.col + j] = ship[i].symbol;
			if (direction == vertical)
				board[start_pt.row + j][start_pt.col] = ship[i].symbol;

			system("cls");
		}
	}
}

                  // Randomly place the ships on the board

void randomly_place_ships(char board[][MAX_COLS], int num_rows, int num_cols, Ship ship[])
{
	Coordinate start_pt = { -1,-1 };
	                         Dir direction = horizontal;
	                                       int num_ships = 0, valid = 0;

	while (num_ships < 5)
	{
		
		do
		{
			direction = generate_dir();
			generate_starting_point(&start_pt, direction, ship[num_ships].length);
			valid = is_valid(board, num_rows, num_cols, start_pt, direction, ship[num_ships].length);

		} while (!valid);

		for (int i = 0; i < ship[num_ships].length; i++)
		{
			if (direction == horizontal)
				board[start_pt.row][start_pt.col + i] = ship[num_ships].symbol;
			if (direction == vertical)
				board[start_pt.row + i][start_pt.col] = ship[num_ships].symbol;
		}
		++num_ships;
	}
}

                         // Generate Starting Point

void generate_starting_point(Coordinate* start_pt_ptr, Dir direction, int length)
{
	if (direction == horizontal)
	{
		start_pt_ptr->row = rand() % MAX_ROWS;
		start_pt_ptr->col = rand() % (MAX_COLS - length + 1);
	}

	else if (direction == vertical)
	{
		start_pt_ptr->row = rand() % (MAX_ROWS - length + 1);
		start_pt_ptr->col = rand() % MAX_COLS;
	}
}

                

int is_valid(char board[][MAX_COLS], int num_rows, int num_cols, Coordinate start_pt, Dir direction, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (direction == horizontal)
			if (board[start_pt.row][start_pt.col + i] != WATER)
				return 0;

		if (direction == vertical)
			if (board[start_pt.row + i][start_pt.col] != WATER)
				return 0;
	}
	return 1;
}

                      

int shot_valid(int row_target, int col_target)
{
	if (row_target <= 9 && row_target >= 0)
	{
		if (col_target <= 9 && col_target >= 0)
			return 1;
	}
	return 0;
}

                      // Determine if ships sunk

bool is_ships_sunk(int sunkships[]) 
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (sunkships[i] != -1)
			return false;

	}

	return true;
}

                     //  Player 2 (computer) shots

void computer_shot(char board[][MAX_COLS], int num_rows, int num_cols, FILE* outfile, Stats stat, int shots[][MAX_COLS], int sunk_ships[])
{
	int row_shot = 0, col_shot = 0;

	do
	{
		do
		{
			row_shot = rand() % num_rows;
			col_shot = rand() % num_cols;

		} while (shots[row_shot][col_shot] != 0);

		shots[row_shot][col_shot]++;

	} while (board[row_shot][col_shot] == HIT || board[row_shot][col_shot] == MISS);


	if (board[row_shot][col_shot] != WATER)
	{
		fprintf(outfile, "\nComputer (player 2): %d, %d is a hit!\n", row_shot, col_shot);
		printf("\n %d, %d is a hit!\n\n", row_shot, col_shot);

		                  stat.total_hits++;

		switch (board[row_shot][col_shot])
		{
		case CARRIER:
			sunk_ships[0]--;
			break;
		case BATTLESHIP:
			sunk_ships[1]--;
			break;
		case CRUISER:
			sunk_ships[2]--;
			break;
		case SUBMARINE:
			sunk_ships[3]--;
			break;
		case DESTROYER: sunk_ships[4]--;
			break;
		}

		if (sunk_ships[0] == 0)
		{
			printf("The computer sunk your Carrier!\n\n");
			fprintf(outfile, " Sunk the Carrier.");
			sunk_ships[0]--;
		}

		if (sunk_ships[1] == 0)
		{
			printf("The computer sunk your Battleship!\n\n");
			fprintf(outfile, " Sunk the Battleship.");
			sunk_ships[1]--;
		}

		if (sunk_ships[2] == 0)
		{
			printf("The computer sunk your Cruiser!\n\n");
			fprintf(outfile, " Sunk the Cruiser.");
			sunk_ships[2]--;
		}

		if (sunk_ships[3] == 0)
		{
			printf("The computer sunk your Submarine!\n\n");
			fprintf(outfile, " Sunk the Submarine.");
			sunk_ships[3]--;
		}

		if (sunk_ships[4] == 0)
		{
			printf("The computer sunk your Destroyer!\n\n");
			fprintf(outfile, " Sunk the Destroyer.");
			sunk_ships[4]--;
		}

		board[row_shot][col_shot] = HIT;
		print_board(board, num_rows, num_cols, false);

		system("pause");
		system("cls");
	}

	else if (board[row_shot][col_shot] == WATER)
	{
		fprintf(outfile, "\nComputer (player 2): %d, %d is a miss.\n", row_shot, col_shot);
		             stat.total_misses++;
		    board[row_shot][col_shot] = MISS;

		print_board(board, num_rows, num_cols, false);
		printf("\n\n %d, %d is a miss.\n\n", row_shot, col_shot);

		system("pause");
		system("cls");
	}
}

                     // Player 1 shots

void player_shot(char board[][MAX_COLS], int num_rows, int num_cols, FILE* outfile, Stats stat, int sunk_ships[])
{
	int row_shot = 0, col_shot = 0, attempt = 0;    


	print_board(board, num_rows, num_cols, true);

	do
	{
		do
		{

			if (attempt > 0)
			{
				printf("\nInvalid shot choice. Please try again.\n");
				attempt--;
			}

			attempt++;

			printf("\nWhere would you like to shoot?\n");
			printf("\nRow: ");
			scanf("%d", &row_shot);

			printf("Column: ");
			scanf("%d", &col_shot);
			printf("\n\n");

		} while (! (shot_valid(row_shot, col_shot)) );

		
	} while ( (board[row_shot][col_shot] == MISS ) || (board[row_shot][col_shot] == HIT) );


	if ( (board[row_shot][col_shot] != WATER) && (board[row_shot][col_shot] != MISS) )

	{
		printf("\n %d, %d is a hit!\n\n", row_shot, col_shot);
		fprintf(outfile, "\nPlayer 1: %d, %d is a hit!\n", row_shot, col_shot);


		switch (board[row_shot][col_shot])
		{
		case CARRIER:
			sunk_ships[0]--;
			break;
		case BATTLESHIP:
			sunk_ships[1]--;
			break;
		case CRUISER:
			sunk_ships[2]--;
			break;
		case SUBMARINE:
			sunk_ships[3]--;
			break;
		case DESTROYER:
			sunk_ships[4]--;
			break;
		}

		if (sunk_ships[0] == 0) 
		{
			printf("You sunk the Carrier!\n\n");
			fprintf(outfile, " Sunk the Carrier.");
			sunk_ships[0]--;
		}

		if (sunk_ships[1] == 0)
		{
			printf("You sunk the Battleship!\n\n");
			fprintf(outfile, " Sunk the Battleship.");
			sunk_ships[1]--;
		}

		if (sunk_ships[2] == 0)
		{
			printf("\nYou sunk the Cruiser!\n\n");
			fprintf(outfile, " Sunk the Cruiser.");
			sunk_ships[2]--;
		}

		if (sunk_ships[3] == 0)
		{
			printf("You sunk the Submarine!\n\n");
			fprintf(outfile, " Sunk the Submarine.");
			sunk_ships[3]--;
		}

		if (sunk_ships[4] == 0) 
		{
			printf("You sunk the Destroyer!\n\n");
			fprintf(outfile, " Sunk the Destroyer.");
			sunk_ships[4]--;
		}

		fprintf(outfile, "\nPlayer 1: %d, %d is a hit!\n", row_shot, col_shot);

		stat.total_hits++;
		board[row_shot][col_shot] = HIT;

		system("pause");
		system("cls");
	}

	else if (board[row_shot][col_shot] == WATER && board[row_shot][col_shot] != HIT)
	{

		printf("\n%d, %d is a miss.\n\n", row_shot, col_shot);
		fprintf(outfile, "\nPlayer 1: %d, %d is a miss.", row_shot, col_shot);

		stat.total_misses++;
		board[row_shot][col_shot] = MISS;

		//system("pause");
		//system("cls");
	}
}

                     //     Update the statistics of the game into a file

void output_stats(Stats p1_stats, Stats p2_stats, FILE* outfile)
{
	p1_stats.total_hits = p1_stats.total_hits + p1_stats.total_misses;
	p1_stats.hit_miss_ratio = p1_stats.total_hits / p1_stats.total_misses;

	p2_stats.total_hits = p2_stats.total_hits + p2_stats.total_misses;
	p2_stats.hit_miss_ratio = p1_stats.total_hits / p2_stats.total_misses;

	system("cls");
	printf("***************************************************\n");
	printf("*         Stats                                   *\n");
	printf("*                      Player 1         Player 2  *\n");
	printf("* Total Shots:           %d                %d     *\n", p1_stats.total_shots, p2_stats.total_shots);
	printf("* Total Hits:            %d                %d     *\n", p1_stats.total_hits, p2_stats.total_hits);
	printf("* Total Misses:          %d                %d     *\n", p1_stats.total_misses, p2_stats.total_misses);
	printf("* Hit/Miss Ratio:        %lf               %lf    *\n", p1_stats.hit_miss_ratio, p2_stats.hit_miss_ratio);
	printf("***************************************************\n\n");

	fprintf(outfile, "\n\n");
	fprintf(outfile, "***************************************************\n");
	fprintf(outfile, "*         Stats                                   *\n");
	fprintf(outfile, "*                      Player 1         Player 2  *\n");
	fprintf(outfile, "* Total Shots:           %d                %d     *\n", p1_stats.total_shots, p2_stats.total_shots);
	fprintf(outfile, "* Total Hits:            %d                %d     *\n", p1_stats.total_hits, p2_stats.total_hits);
	fprintf(outfile, "* Total Misses:          %d                %d     *\n", p1_stats.total_misses, p2_stats.total_misses);
	fprintf(outfile, "* Hit/Miss Ratio:        %lf               %lf    *\n", p1_stats.hit_miss_ratio, p2_stats.hit_miss_ratio);
	fprintf(outfile, "***************************************************\n\n");
}
