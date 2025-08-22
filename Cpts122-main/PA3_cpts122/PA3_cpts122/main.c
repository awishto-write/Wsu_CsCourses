//#include "header.h"
#include "test.h"

int main(void)
{
	Record data = { 0 };     // Initialization of our record
	int choice = 0, selection = 0, ins = 0;
	
	FILE* infile = NULL, * outfile = NULL;
	Node* pList = NULL; // empty list 
	infile = fopen("musicPlayList.csv", "r");

	//outfile = fopen("musicPlayList.csv", "w");            

	if (infile != NULL)
	{
		int start_or_test = 0;
		do {
			system("cls");
			printf("-------------------------Welcome!-----------\n");
			printf("You made the right choice to come by, hopefully you leave joyful!\n");
			printf("Please select an option!\n\n");
			printf(" 1. Start the Digital Program Management (The most fun option)\n");   
			printf(" 2. Test the program\n\n");
			scanf("%d", &start_or_test);

		} while (start_or_test != 1 && start_or_test != 2);

		if (start_or_test == 1)
		{

		while (choice != 11)
		{
			choice = print_menu();
			//system("cls");

			switch (choice)
			{
			case 1:// load                     // PA2     

				pList = Load(infile);
				fclose(infile);
				infile = fopen("musicPlayList.csv", "r");        
				break;

			case 2:  // store                  // PA2      
				fclose(infile);
				Store(outfile, pList);
				infile = fopen("musicPlayList.csv", "r");

				break;

			case 3:  // display                          //For PA2     
				Display(pList);
				break;

			case 4:  // insert                             

				printf("-------We will create a new record to add it to the list-----\n"); //prompts user to insert a new record
				printf("*************Please, fill in the information below for your new record!\n\n");

				printf("Artist: ");
				gets(data.artist);
				gets(data.artist);

				printf("Album: ");
				gets(data.album_title);

				printf("Song: ");
				gets(data.song_title);

				printf("Genre: ");
				gets(data.genre);

				printf("Duration in minutes: ");
				scanf("%d", &data.song_length.minutes);

				printf("Duration in seconds: ");
				scanf("%d", &data.song_length.seconds);

				printf("Number of times played: ");
				scanf("%d", &data.num_times_played);

				printf("Rating: ");
				scanf("%d", &data.rating);

				ins = Insert_newRecord(&pList, data);
				break;

			case 5:  // delete
				Delete(&pList);
				break;

			case 6:  // edit                    //For PA2        
				Edit(pList);
				break;

			case 7:  // sort
				Sort(&pList);
				break;

			case 8:  // rate Song           //For PA2
				Rate(pList);
				break;

			case 9:  // play                    //For PA2     
				Play(pList);
				break;

			case 10: // shuffle                
				Shuffle(pList);
				break;

			case 11: // exit                    //For PA2   
				fclose(infile);
				Exit(outfile, pList);
				return 11;
				//break;

			}  //end of switch

		}   //end of while for options of starting program

	 }   //end of starting the program

	  else if (start_or_test == 2)
	  {
		InsertTest();
		printf("The test of the Insert function is over!\n\n");
		DeleteTest();
		printf("The test of the Delete function is over!\n\n");
		ShuffleTest();
		printf("The test of the Shuffle function is over!\n");
	  }

	}   //end of if (infile != NULL)

	return 0;
}