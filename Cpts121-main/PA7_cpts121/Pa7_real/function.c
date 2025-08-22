#include "header.h"

                               // The menu of the game

void game_menu(void)
{
	printf("                                                                                                        \n");
	printf(" *******************************************************************************************************\n");
	printf(" *                                           WELCOME TO POKER!                                         *\n");
	printf(" *                                            - 5 Card Draw -                                          *\n");
	printf(" *        -----------                                                             -----------          *\n");
	printf(" *                                                                                                     *\n");
	printf(" *        |         |                    Select an option below                   |         |          *\n");
	printf(" *                                                                                                     *\n");
	printf(" *        |         |                  1: Rules of the game                       |         |          *\n");
	printf(" *                                     2: Play the game                                                *\n");
	printf(" *                                     3: Exit the game                                                *\n");
	printf(" *        -----------                                                             -----------          *\n");
	printf(" *                                                                                                     *\n");
	printf(" *******************************************************************************************************\n");
}

                         // Printing the rules

void print_rules(void)
{
	printf("**********************************************************************************\n");
	printf("                       RULES OF 5-CARD-DRAW POKER                                 \n");
	printf("                                                                                  \n");
	printf(" - This game facilitates one-on-one play against the dealer (COMPUTER).           \n");
	printf(" - To start, input the player name into the system.                               \n");
	printf(" - Five cards will be dealt to you and the dealer, on at a time.                  \n");
	printf("                                                                                  \n");
	printf(" - You and the dealer will each have the opportunity to select cards,             \n");
	printf("to remove from your hand for reshuffling, to better your hand.                    \n");
	printf(" - Once the selected cards have been removed from the deck and reshuffled,        \n");
	printf("the respective hands will be presented and evaluate.                              \n");
	printf(" - A winner will be selected based upon the quality of the hands.                 \n");
	printf("                                                                                  \n");
	printf("********************************************************************************\n\n");
}

                    // Selection of an option from the menu

int get_option(void)
{
	int option = 0;
	printf("\n Option: ");
	scanf("%d", &option);

	return option;
}

                       // Shuffle cards in deck 

void shuffle(int wDeck[][13])
{
	int row = 0;    // row number 
	int column = 0;   // column number
	int card = 0;     // card counter

	// for each of the 52 cards, choose slot of deck randomly 
	for (card = 1; card <= 52; card++)
	{
		// choose new random location until unoccupied slot found 
		do
		{
			row = rand() % 4;
			column = rand() % 13;

		} while (wDeck[row][column] != 0);

		// place card number in chosen slot of deck
		wDeck[row][column] = card;
	}
}

                      // Deal cards in deck 

void deal(const int wDeck[][13], Hand* poker, int amount, int* current_card)        // cahnge it to integer?
{
	// deal each of the 52 cards 
	for (int card = 0; card < amount; card++)
	{
		// loop through rows of wDeck 
		for (int row = 0; row <= 3; row++)
		{
			// loop through columns of wDeck for current row 
			for (int column = 0; column <= 12; column++)
			{
				// if slot contains current card, display card 
				if (wDeck[row][column] == *current_card)
				{
					poker->hand_array[card].face_value_index = column;
					poker->hand_array[card].suit_index = row;

				}
			}
		}
		(*current_card)++;
	}
}

// Print hand        

void print_hand(Hand poker, const char* wFace[], const char* wSuit[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d %s of %s\n", (i + 1), wFace[poker.hand_array[i].face_value_index], wSuit[poker.hand_array[i].suit_index]);
	}
	printf("\n");
}

              // Deal cards

void dealOneCard(const int wDeck[][13], Hand* poker, int index, int* current_card)
{
	// loop through rows of wDeck 
	for (int row = 0; row <= 3; row++)
	{
		// loop through columns of wDeck for current row 
		for (int column = 0; column <= 12; column++)
		{
			// if slot contains current card, display card 
			if (wDeck[row][column] == *current_card)
			{
				poker->hand_array[index].face_value_index = column;
				poker->hand_array[index].suit_index = row;
			}
		}
	}
	(*current_card)++;
}


//Insert numTimes array with specific count of every face card.
//For example, numTimes at index 0 will contain 4 if there are 4 aces in a hand.

void calcNumTimes(Hand poker, int numTimes[13])
{
	//Reinitializes array
	for (int i = 0; i < FACE_TYPES; i++) 
	{
		numTimes[i] = 0;
	}

	//Populate numTimes array with count of every specific face card
	for (int i = 1; i < HAND_SIZE; i++)
	{
		switch (poker.hand_array[i].face_value_index)     //
		{
		case 0: //Ace
			numTimes[0]++;
			break;
		case 1: //Deuce
			numTimes[1]++;
			break;
		case 3: //Three
			numTimes[2]++;
			break;
		case 4: //Four
			numTimes[3]++;
			break;
		case 5: //Five
			numTimes[4]++;
			break;
		case 6: //Six
			numTimes[5]++;
			break;
		case 7: //Seven
			numTimes[6]++;
			break;
		case 8: //Eight
			numTimes[7]++;
			break;
		case 9: //Nine
			numTimes[8]++;
			break;
		case 10: //Ten
			numTimes[9]++;
			break;
		case 11: //Jack
			numTimes[10]++;
			break;
		case 12: //Queen
			numTimes[11]++;
			break;
		case 13: //King
			numTimes[12]++;
			break;
		}
	}
}

          //Sees if numTimes contains a 2 (has a pair), returns 1 if so and 0 if not.

int contains_a_pair(Hand poker, int numTimes[13]) 
{
	
	for (int i = 0; i < FACE_TYPES; i++) 
	{
		if (numTimes[i] == 2) 
		{
			return 1;
		}
	}
	return 0;
}


//Essentially does the same logic as containsPair twice with an additional count variable for tracking, returning 1
//if true, 0 if false.

int contains_two_pairs(Hand poker, int numTimes[13])
{
	int count = 0;
	
	for (int i = 0; i < FACE_TYPES; i++) 
	{
		if (numTimes[i] == 2) 
		{
			count++;
		}
	}
	if (count == 2) 
	{
		return 1;
	}
	return 0;
}

//Checks if numTimes contains a 3 (3 cards with same face value), returns 1 if so, 0 if not.

int contains_three_kind(Hand poker, int numTimes[13])
{
	for (int i = 0; i < FACE_TYPES; i++)
	{
		if (numTimes[i] == 3) 
		{
			return 1;
		}
	}
	return 0;
}

//Checks if numTimes contains a 4 (4 cards with same face value), returns 1 if so, 0 if not.

int contains_four_kind(Hand poker, int numTimes[13])
{
	for (int i = 0; i < FACE_TYPES; i++)
	{
		if (numTimes[i] == 4) 
		{
			return 1;
		}
	}
	return 0;
}

            //Populates suitCount array with count of each suit in the hand.
           //For example, suitCount at index 0 will contain 5 if all 5 cards in the hand are hearts.

void calcCountSuit(Hand poker, int suitCount[4]) 
{
	
	for (int i = 0; i < SUIT_TYPES; i++) 
	{
		suitCount[i] = 0;
	}

	for (int i = 1; i < HAND_SIZE; i++)
	{
		switch (poker.hand_array[i].suit_index)
		{
		case 0:
			suitCount[0]++;
			break;
		case 1:
			suitCount[1]++;
			break;
		case 2:
			suitCount[2]++;
			break;
		case 3:
			suitCount[3]++;
			break;
		}
	}
}


            //Checks if there is a 5 in suitCount array, or if all cards in the hand are of the same suit.
            //1 returned if found, 0 if not.

int contains_flush(Hand poker, int suitCount[4])
{
	
	for (int i = 0; i < SUIT_TYPES; i++) 
	{
		if (suitCount[i] == 5)
		{
			return 1;
		}
	}
	return 0;
}


         //Checks if there are a row of five 1's in numTimes consecutively (hand contains 5 consecutive face values).
       //Returns 1 if found, returns 0 if not.

int contains_straight(Hand poker, int numTimes[13])
{
	int count = 0;
	
	for (int i = 0; i < FACE_TYPES; i++)
	{
		if (numTimes[i] == 1) 
		{
			count++;
		}
		else if (numTimes[i] == 0 && count == 5)
		{
			return 1;
		}
		else
		{
			count = 0;
		}
	}

	if (count == 5) 
	{
		return 1;
	}

	return 0;
}

       
             // It generates and returns a point matrix based on aspects of the hand.

int evaluate_hand(Hand poker)
{
	int points = 0;
	int numTimes[13], suitCount[4];
	calcNumTimes(poker, numTimes);
	calcCountSuit(poker, suitCount);

	//A pair is worth 1, two pairs is worth 2, three of a kind is worth 3, straight is worth 4, flush 5, four of a kind 6
	if (contains_a_pair(poker, numTimes))
		points++;
	if (contains_two_pairs(poker, numTimes) && contains_a_pair(poker, numTimes))      
		points++;
	if (contains_three_kind(poker, numTimes))
		points += 3;
	if (contains_straight(poker, numTimes))
		points += 4;
	if (contains_flush(poker, suitCount))
		points += 5;
	if (contains_four_kind(poker, numTimes))
		points += 6;

	return points;
}


  //Determines how many cards the dealer needs to draw based on current hand score.

int dealer_draw(Hand poker, int player_score, int dealer_score) 
{
	if (dealer_score < player_score)            
	{
		if (dealer_score < 3)
		{
			//draw 1 card
			return 1;
		}
		else if (dealer_score < 2)
		{
			//draw 2 cards
			return 2;
		}
		else if (dealer_score < 1)
		{
			//draw 3 cards
			return 3;
		}
	}
	return 0;
}
