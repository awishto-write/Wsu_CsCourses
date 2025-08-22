// Naomi Dion-Gokan
// 12/02/21
// CPT-S 121
// Programming Assignment 7
// This program will evaluate and implement the game called 5-Card-Draw Poker between an user and the computer.

#include "header.h"

int main(void)
{
	srand((unsigned int)time(NULL));

	int option = 0, current_card = 0, running = 1, index = 0;
	int player_score = 0, dealer_score = 0, dealer_cards_to_draw = 0;
	int card_choice = 0, change_num = 0, num = 0, num_change = 0;
	char response = '\0';

	// initialize suit array 
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	// initialize face array 
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


	do 
	{
		game_menu();

		option = get_option();

		if (option == 2)       // Play the game
		{
			while (1)                
			{
				Hand dealer = { { {0,0} } };  // Dealer's hand
				Hand player = { { {0,0} } };   //Player's hand
				int deck[4][13] = { 0 };   // initialize deck array 

				shuffle(deck);

				deal(deck, &player, 5, &current_card);
				deal(deck, &dealer, 5, &current_card);

				printf("\n    Player's hand:\n");
				print_hand(player, face, suit);


				//Initial evaluation
				player_score = evaluate_hand(player);
				dealer_score = evaluate_hand(dealer);

				// Display first scores
				printf("Player's points: %d\n\n", player_score);
				
				
				      // Option for the player to redraw new cards

				printf("Would you like to switch out any cards (y/n): \n");
				scanf(" %c", &response);

				if (response == 'y' || response == 'Y')      // If the player wants to get new cards
				{

					do        // Amount of cards to change
					{
						printf("How many cards would you like to change? (1-3): ");
						scanf("%d", &num);

					} while (num > 3);


					do          // Specific cards to change
					{
						change_num++;;                           // Is it the right place?
						printf("\nWhich card would you like to switch out (1-5): ");    
						scanf("%d", &card_choice);

						dealOneCard(deck, &player, card_choice - 1, &current_card); // new hand for the player 

					} while (change_num < num);          

					printf("\n    New Player's hand:\n");         //Display final user hand for the player
					print_hand(player, face, suit);

					player_score = evaluate_hand(player);
					printf("Final player's points: %d\n\n", player_score);

				}    // End of if-statement for the option when the player wants to redraw cards


				                    // Dealer redraws      

				dealer_cards_to_draw = dealer_draw(dealer, player_score, dealer_score);
				printf("\nThe dealer decided to draw %d cards.\n", dealer_cards_to_draw);   //num of cards to draw

				// when the dealer draws 1 card
				if (dealer_cards_to_draw == 1)
				{
					num_change = rand() % 5 + 1;
					printf("\n The dealer chooses to switch out card number %d \n", num_change);   // Specific change of card   
					dealOneCard(deck, &dealer, num_change - 1, &current_card);
				}

				// when the dealer draws 2 cards 
				else if (dealer_cards_to_draw == 2)
				{
					for (int i = 0; i < 2; i++)
					{
						num_change = rand() % 5 + 1;
						printf("\n The dealer chooses to switch out card number %d \n", num_change); // Specific change of card   
						dealOneCard(deck, &dealer, num_change - 1, &current_card);
					}
				}

				// when the dealer draws 3 cards 
				else if (dealer_cards_to_draw == 3)
				{
					for (int i = 0; i < 3; i++)
					{
						num_change = rand() % 5 + 1;
						printf("\n The dealer chooses to switch out card number %d. \n", num_change); // Specific change of card   
						dealOneCard(deck, &dealer, num_change - 1, &current_card);
					}
				
				}      
				                       

				dealer_score = evaluate_hand(dealer);
				printf(" \nFinal dealer's points: %d\n", dealer_score);        

				       // Determine the winner; if it is a win/loss/tie

				if (player_score > dealer_score)       // players wins
				{
					printf("\nYou won the game with a score of %d! The dealer lost with as score of %d!\n", player_score, dealer_score);

					printf("\n    DEALER'S HAND:\n");
					print_hand(dealer, face, suit);
					
				}

				else if (dealer_score > player_score)       // dealer wins
				{
					printf("\nYou lost the game with a score of %d! The dealer won with as score of %d!\n", player_score, dealer_score);

					printf("\n      DEALER'S HAND:\n");
					print_hand(dealer, face, suit);
					
				}
				                                            
				else if (dealer_score == player_score)    // tie
				{
					printf("\nIt's a tie! The player got %d points and the dealer got %d points!\n", player_score, dealer_score);

					printf("\n     DEALER'S HAND:\n");
					print_hand(dealer, face, suit);
				}
				
				         // Option to keep playing or stop

				char ok = '\0';
				printf("\nDo you want to play again?(y/n)\n");
				scanf(" %c", &ok);

				if (ok == 'n' || ok == 'N')
				{
					break;
				}

				system("cls");
			}

		}   // End of option 2


		else if (option == 1)   // Rules of the game
		{
			system("cls");
			print_rules();
			system("pause");
			system("cls");
		}

		else if (option == 3)     // Quit the game
		{
			printf("\n\n Thank you for playing Pocker: 5-Card-Draw. Goodbye! \n\n");
			running = 0;
		}

	}	while (running);

	return 0;
}