/********************************************************************************
 * Programmer: Naomi Dion-Gokan                                                 *
 * Class: CptS 122; Lab Section 11                                              *
 * Programming Assignment: PA 2                                                 *
 * Date Created: January 29, 2022                                               *
 * Date Last Modified: Febraury  02, 2022                                       *
 * Description: This program will write a basic digital music manager(DMM).     *
 *              It would manipulate the music collection based on attributes    *
				such as artist, album title, song title, genre, song length,    *
				number times played, and rating.                                *
 *******************************************************************************/

#include "header.h"

int main(void)
{
	char artist[30] = { '\0' }, song[30] = { '\0' }, song2[30] = { '\0' };       //
	Record data = { "", "", "", "", 0, 0, 0 };

	int choice = 0, selection = 0, rate = 0;
	FILE* infile = NULL, * outfile = NULL;

	Node* pList = NULL;
	Node* pHead = NULL; // empty list - initList that would set head to NULL

	infile = fopen("musicPlayList.csv", "r");

	//outfile = fopen("musicPlayList.csv", "w");


    while (choice != 11)
    {
			choice = print_menu();
			//system("cls");

			switch (choice)
			{
			case 1:// load                     // PA2   
				Load(infile, &pList);
				break;
			case 2:  // store                  // PA2   
				Store(outfile, pList);
				break;

			case 3:  // display                          //For PA2    
				printf("Please select an option:\n");
				printf("(1) Display all the records.\n");
				printf("(2) Display record based on an artist.\n");
				printf("Selection: ");
				scanf("%d", &selection);

				if (selection == 1)
				{
					printList(pHead); //prints every record in the file
				}
				if (selection == 2)
				{
					int exit2 = 0;

					while (exit2 != 1) // prompts the user to select an artist, based on the name
					{
						printf("Artist: ");
						gets(artist);
						gets(artist);
						system("cls");
						exit2 = display_selected_record(&pHead, artist, data);
					}
				
				}

				break;

			case 4:  // insert
		
				break;
			case 5:  // delete
				
				break;
			case 6:  // edit                    //For PA2
				                                //should be able to use the same search function as used in the “display” command
				break;
			case 7:  // sort
				
				break;
			case 8:  // rate Song           //For PA2
				 rate = 0;
				printf("Please rate a song. \n");
				printf("Song Title: ");
				gets(song);
				gets(song);
				system("cls");
				rate = Rate(&pHead, song, data);
	
				break;
			case 9:  // play                    //For PA2  
				
				break;
			case 10: // shuffle
				
				break;
			case 11: // exit                    //For PA2
				Store(outfile, pList);
				printf("Goodbye!\n");
				
				break;
			}
	}
	

	return 0;
}