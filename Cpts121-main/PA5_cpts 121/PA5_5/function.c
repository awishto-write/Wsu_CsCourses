
#include "function.h"

// A. Game's menu

int print_menu(int menu_choice)
{
  //  int menu_choice = 0;    // why can't I put it here?

	// display of the game's rules 

	printf(" *************************************************************************************************\n");
	printf(" *                                WELCOME TO THE GAME OF YAHTZEE                                 *\n");
	printf(" *                                                                                               *\n");
	printf(" *                      Select your option below                                                 *\n");
	printf(" *                                                                                               *\n");
	printf(" *                         1: Rules of the game                                                  *\n");
	printf(" *                         2: Start game                                                         *\n");
	printf(" *                         3: Exit game                                                          *\n");
	printf(" *                                                                                               *\n");
	printf(" *                         What is your choice?                                                  *\n");
	printf(" *************************************************************************************************\n");

	scanf("%d", &menu_choice);   //get user input
	system("cls");

   // Let's get an menu option from the user

    switch (menu_choice)   
    {
    case 1: print_rules();         // game's rules
        break;
    case 2: play_game();         // play the game
        break;
	 system("pause");   // check this one

    case 3:          // exit
        printf("Thank you for playing! Goodbye!\n\n");
        break;
    default:
        printf("Error: Invalid Option!\n\n");
        print_menu(menu_choice);
    } // end of first switch-statement

	return menu_choice;
}

// B. Display of game's rules

void print_rules(void)
{

	printf("The scorecard used for Yahtzee is composed of an upper and a lower section\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n\n");

	printf("Once a box to score is chosen, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63,\n");
	printf("then 35 more points are added to the players overall score as a bonus.\n\n");

	printf("The lower section contains a number of poker like combinations. See the table provided below: \n");
	printf("\n\tName\t\t\tCombination\t\t\tScore");
	printf("\nThree-of-a-kind  || Three dice with the same face  ||  Sum of all face valuse on 5 dice");
	printf("\nFour-of-a-kind   || Four dice with the same face   ||  Sum of all face values on 5 dice");
	printf("\nFull House       || One pair and three-of-a-kind   ||  25 points");
	printf("\nSmall Straight   || A sequence of four dice        ||  30 points");
	printf("\nLarge Straight   || A sequence of five dice        ||  40 points");
	printf("\nYahtzee          || Five dice with the same face   ||  50 points");
	printf("\nChance           || May be used for any sequence   ||  Sum of all face values on 5 dice\n\n");
}

// C. Play the game

void play_game(void)
{
	int array_check1[14] = { 0 };
	int array_check2[14] = { 0 };
	
	int player1_result = 0, player2_result = 0;

	for (int i = 0; i < 14; i++) 
	{
		printf("\nIt is your turn, Player 1!\n\n");         // Player 1's turn
		player1_result += alternations(array_check1);

		printf("\nIt is your turn, Player 2!\n\n");         //Player 2's turn
		player2_result += alternations(array_check2);
	}

	if (player1_result >= 63)
		player1_result += 35;
	else if (player2_result >= 63)
		player2_result += 35;

	if (player1_result > player2_result)                // Player 1 wins
		printf("\nPlayer 1 won with a score of %d to player 2's score of %d\n\n", player1_result, player2_result);

	else if (player2_result > player1_result)           // Player 2 wins
		printf("\nPlayer 2 won with a score of %d to player 1's score of %d\n\n", player2_result, player1_result);

	else                                               // Both players are tied
		printf("\nPlayer 1 and 2 have tied with a score of %d.\n\n", player1_result);
}

// D. Roll a die   

int roll_die(void)
{
	int roll_die = 0;
	roll_die = rand() % 6 + 1;
	return roll_die;
}

// E. Rolling all the dice

int alternations(int array_check[])
{
	printf("Press (enter/return) to roll the dice\n");                 
	getchar(); getchar();   // Why can't I use printf(\n) to make it work?


	int dice_value[5], number_roll= 0; char response = 'n';

	for (int i = 0; i < 5; i++)
	{
		dice_value[i] = roll_die();            // Roll 5 dice
	}

	do    //beggining of do-while statement
	{
		if (number_roll < 3)   // ask if user wants to use this roll for game's comb
			                   // First main If- statement in that Section E
		{
			for (int i = 0; i < 5; i++)
			printf("Dice #%d. %d\n", (i + 1), dice_value[i]); 

			printf("Do you want to use this roll for one of the game combinations? [y/n]\n");
			scanf(" %c", &response);

			if (response == 'y') //when answer is Yes to use roll for comb    
			{  
				//system("cls");
			    break;
			}
		      else    // when answer is NO "not use roll for combi"             // if, else, else if structure.
			  {
				  for (int i = 0; i < 5; i++)
				  {
					printf("Would you like to re-roll dice #%d?\n", (i + 1));
					scanf(" %c", &response);

					if (response == 'y')      // Yes to re-roll the dice.
						dice_value[i] = roll_die();

					printf(" New_Dice #%d: %d\n\n", (i + 1), dice_value[i]);
					
				  }
				number_roll++;
			  }
		}
		else if (number_roll == 3)    
		{
			
			break;
		}
	} while (number_roll <= 3 && response != 'y');   //end of do- while statement

	      
     int points = final_score(dice_value, array_check);          
	printf("Points from this round: %d\n\n", points);              // Printing the points for round

	return points;
}

// F. Sum of the dice value 

int sum (int z, int dice_value[])           
{
	int counter = 0;
	for (int i = 0; i < 5; i++) 
	{
		if (dice_value[i] == z)
			counter++;
	}
	return counter * z;    
}

// G. Final score 

int final_score(int* dice_value, int array_check[])
{
	printf("1. Sum of 1's\n 2. Sum of 2's\n 3. Sum of 3's\n 4. Sum of 4's\n 5. Sum of 5's\n");
	printf("6. Sum of 6's\n 7. Three-of-a-kind\n 8. Four-of-a-kind\n 9. Full house\n");
	printf("10. Small straight\n 11. Large straight\n 12.Yahtzee\n 13. Chance\n\n");
	printf("What is your choice?\n");

	
	int choice = 0;
	scanf("%d", &choice); //get user input out of the 13 choices.
                        //This is related to above with yes or no.

	while (array_check[choice] == 1)
	{
		printf("You already picked that option, choose another one\n\n");
		scanf("%d", &choice);
	}

	if (array_check[choice] == 0)
	{
	     array_check[choice] = 1 ;
		//continue
		//update to 1
	}
		 
	int array[5], sum_value= 0, counter = 0, a = 0, b = -1; int verify_comb[6] = { 0 };

	for (int i = 0; i < 5; i++)
		sum_value += dice_value[i];

	                                   
	switch (choice)
	{
	    case 1:    //sum of 1's
			return sum(1, dice_value); 

		case 2:    // sum of 2's
			return sum(2, dice_value);

		case 3:    // sum of 3's
			return sum(3, dice_value);      

		case 4:    // sum of 4's
			return sum(4, dice_value);

		case 5:    // sum of 5's
			return sum(5, dice_value);

		case 6:    // sum of 6's
			return sum(6, dice_value);
			break;

		case 7:    // 3 of a kind   

			                                        
		case 8:     // 4 of a kind                        //3 of a kind and 4 of a kind setting.                 
			for (int i = 0; i < 5; i++) 
				verify_comb[dice_value[i] - 1] += 1;


		int counter = verify_comb[0];
			for (int i = 0; i <= 5; i++)
			{
				if (i == 4 && verify_comb[4] < verify_comb[5])
					counter = verify_comb[5];
				else if (verify_comb[i] < verify_comb[i + 1])
					counter = verify_comb[i + 1];

				if (counter >= 3)
					return sum_value;
			}
			return 0;

		case 9:     //Full house: One pair and a three-of-a-kind
			for (int i = 0; i < 5; i++)
			
				verify_comb[dice_value[i] - 1] += 1;

			for (int i = 0; i <= 5; i++)
			{
				for (int j = 0; j <= 5; j++)
				{
					if (verify_comb[i] == 3 && verify_comb[j] == 2)
						return 25;
				}
			}
			return 0;
		             	

		case 10:     //Small straight: A sequence of four dice
			counter = 0;
			for (int i = 0; i < 5; i++)
				verify_comb [dice_value[i] - 1] += 1;

			for (int i = 0; i <= 5; i++) 
			{
				if (verify_comb[i] >= 3) return 0;
				if (i > 1 && i < 4 && counter == 0) return 0;
				if (i == 4 && verify_comb[5] > 0) counter++;
				if ((i != 4 || i != 5) && verify_comb[i] == verify_comb[i + 1]) counter++;
				if (counter == 4)
					return 30;
			}
			return 0;

		case 11:     // Large straight: A sequence of five dice
			counter = 0;

			for (int i = 0; i < 5; i++)
				verify_comb[dice_value[i] - 1] += 1;

			for (int i = 0; i <= 5; i++) 
			{
				if (verify_comb[i] >= 3) return 0;
				if (i > 1 && i < 4 && counter == 0) return 0;
				if (i == 4 && verify_comb[5] > 0) counter++;
				if ((i != 4 || i != 5) && verify_comb[i] == verify_comb[i + 1]) counter++;
				if (counter == 5) return 40;
			}
			return 0;

		case 12:     // Yahtzee: Five dice with the same face
			      for (int i = 0; i < 5; i++)
			      {
					  for (int j = 0; j < 5; j++)
					  {
						  if (dice_value[i] != dice_value[j])
							  return 0;
					  }
				  }
			return 50;
			           

		case 13:     //Chance: May be used for any sequence of dice     
			        return sum_value;

		default: 
			printf("What is your choice?\n");
			final_score(dice_value, array_check);    
	}

	return choice;  
}
