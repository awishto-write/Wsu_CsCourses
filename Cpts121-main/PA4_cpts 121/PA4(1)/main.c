// Naomi Dion-Gokan
// 10/12/21
// CPT_S_121
// Programming Assignment 4
 // This program will evaluate a program that implements a craps game in the type of 3 files format
   //  and make use of conditional statements, loops and other resources studied in class.

#include "craps.h"

int main(void)
{
	srand(time(0));

	int option = 0; int validate = 0; double bank_balance = 0.0;
	double initial_bank_balance = 0.0;

	// 0. Welcoming
	welcome();

	do
	{   
		// 1. Display the game's menu

		print_game_menu();

		// 2. Choosing an option

		option = get_option();
		switch (option)
		{
		case 1: // 3. Displaying rules
			print_game_rules();
			break;

		case 2: // 4. Input the bank balance
			bank_balance = get_bank_balance();
			initial_bank_balance = bank_balance;
			break;

		case 3: // Running game

				 // 5. Validate the chosen option

		{	validate = print_and_validate(option);


		// 6. Pick the wager Amount and /7. Check if the wager's amount is within the reach of the bank balance
 
		char want_to_exit = 'y';
		while (want_to_exit == 'y')
		{
			double wager_amount = 0.0;
			do {
				wager_amount = get_wager_amount();
			} while (check_wager_amount(wager_amount, bank_balance) == 0);


			// dice
			int playing = 1, number_rolls = 0, point_value = 0;
			while (playing == 1)
			{
				// 8. Rolling die
				int die1 = 0, die2 = 0;
				die1 = roll_die();
				die2 = roll_die();

				// 9. Displaying the dice rolled
				display_die(die1, die2);

				// 10. Calculation of the dice's sum
				int sum_dice = 0;
				sum_dice = calculate_sum_dice(die1, die2);

				system("pause");
				system("cls");

				// 11. Did you win, lose or did you your sum lead you to points?
						// Is point loss or nbeither?
						// Adjusting bank balance

				int result = 0;
				result = calculate_result(number_rolls, sum_dice, point_value);

				switch (result)  // A switch statement
				{
				case 1:
					playing = 0;
					bank_balance = adjust_bank_balance(bank_balance, wager_amount, 1);
					//adjust_bank_balance(bank_balance, wager_amount, 1);

					check_bank_balance(bank_balance);// add wager's amount into the bank balance
					break;

				case 0:
					playing = 0;
					bank_balance = adjust_bank_balance(bank_balance, wager_amount, 0);
					//adjust_bank_balance(bank_balance, wager_amount, 0); 

					check_bank_balance(bank_balance); // remove wager's amount into the bank balance
					break;

				case -1:
					if (number_rolls == 0)
					{
						point_value = sum_dice;
						playing = 1;
					}
					break;
				} // For the last switch.


				++number_rolls;
				chatter_messages(number_rolls, result, initial_bank_balance, bank_balance);
			

			} // The last while loops.
			         
			     
				printf("Do you want to continue? [y/n]\n");
				scanf(" %c", &want_to_exit);


		} // The following switch before the last one.

		break;
		}// End for the Case 3.

		}// For the first stwich.

	} while (option != 4); // For do-while loop at the beggining.

	return 0;

} // The end of the main.