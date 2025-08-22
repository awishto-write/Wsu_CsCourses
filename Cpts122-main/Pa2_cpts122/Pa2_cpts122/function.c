#include "header.h"

                    // Display the main menu and allow the user to choose an option

int print_menu(void) 
{  
	int choice = 0;

	//loops for valid input
	do { 

		printf("    Welcome to the digital music management! \n");
		printf("MUSIC PLAYLIST- MAIN MENU:\n");
		printf("(1)  Load\n");
		printf("(2)  Store\n");
		printf("(3)  Display\n");
		printf("(4)  Insert\n");
		printf("(5)  Delete\n");
		printf("(6)  Edit\n");
		printf("(7)  Sort\n");
		printf("(8)  Rate\n");
		printf("(9)  Play\n");
		printf("(10) Shuffle\n");
		printf("(11) Exit\n\n");
		printf(" Pick a number from 1 to 11: ");

		scanf("%d", &choice);

	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 &&
		choice != 7 && choice != 8 && choice != 9 && choice != 10  && choice != 11);

	//system("cls");

	return choice; //returns choice to main 
}

      // Allocate space for a Node on the heapand initializes the Node with the information found in the inputs

//Node* makeNode(char* sub_artist, char* sub_album, char* sub_title, char* sub_genre, int sub_min, 
//	int sub_sec, int sub_time_played, int sub_rate)
//{
//	Node* pMem = malloc(sizeof(Node));    //58 Bytes allocated
//
//	if (pMem != NULL)
//	{
//		// Allocated space for Node successfully
//		//Let's initialize it
//
//		strcpy(pMem->data.album_title, sub_album);
//		strcpy(pMem->data.artist, sub_artist);
//		strcpy(pMem->data.song_title, sub_title);
//		strcpy(pMem->data.genre, sub_genre);
//
//		pMem->data.song_length.minutes = sub_min;
//		pMem->data.song_length.seconds = sub_sec;
//		pMem->data.num_times_played = sub_time_played;
//		pMem->data.rating = sub_rate;
//
//		pMem->pNext = NULL;
//		pMem->pPrev = NULL;
//
//	}
//
//	return pMem;
//}

Node* makeNode(Record newData)
{
	//Node* pMem = NULL;
	Node* pMem = malloc(sizeof(Node));    

	if (pMem != NULL)
	{
		// Allocated space for Node successfully
		pMem->data = newData;             // struct assignment, shallow copy

		pMem->pNext = NULL;
		pMem->pPrev = NULL;

	}

	return pMem;
}


      // Adds a new Node with new data from a new record in the object "sub_record" to the front of the linkedList "pList".

//// inserts the new movie at the front of the movie collection.
//// returns 1 if successfully inserts at the front; 0 if malloc ()
//// fails to get the memory necessary for the Node
//int insertFront(Node** pList, char* sub_artist, char* sub_album, char* sub_title, char* sub_genre, int sub_min,
//	int sub_sec, int sub_time_played, int sub_rate)
//{
//	Node* pMem = makeNode(sub_artist, sub_album, sub_title, sub_genre, sub_min, sub_sec, sub_time_played, sub_rate);
//	int success = 0;
//
//	// think state of linked list
//	// 2 states - empty, not empty
//
//	if (pMem != NULL)
//	{
//		// succeeded at allocating space on heap for Node
//		//if (*pList == NULL)
//		//{
//		//	// it is an empty list
//		//	*pList = pMem; // note: if pList wasn't a **, then we couldn't retain a change to the original pHead
//		//}
//		//else
//		//{
//		//	// it is not empty
//		//	pMem->pNext = *pList;
//		//	*pList = pMem; // note: if pList wasn't a **, then we couldn't retain a change to the original pHead
//		//}
//
//		pMem->pNext = *pList;
//		*pList = pMem; // note: if pList wasn't a **, then we couldn't retain a change to the original pHead
//
//		success = 1;
//	}
//
//	return success;
//}

// inserts the new movie at the front of the movie collection.
// returns 1 if successfully inserts at the front; 0 if malloc ()
// fails to get the memory necessary for the Node
int insertFront(Node** pList, Record newData)
{
	//Node* pMem = NULL;
	int success = 0;

	// allocate space for a Node and set it to data
	Node* pMem = makeNode(newData);

	// think state of linked list
	// 2 states - empty, not empty

	if (pMem != NULL)
	{
		 //succeeded at allocating space on heap for Node
		if (*pList == NULL)
		{
			// it is an empty list
			*pList = pMem; // note: if pList wasn't a **, then we couldn't retain a change to the original pHead
		}
		else
		{
			// it is not empty
			pMem->pNext = *pList;
			*pList = pMem; // note: if pList wasn't a **, then we couldn't retain a change to the original pHead
		}

		pMem->pNext = *pList;
		*pList = pMem; // note: if pList wasn't a **, then we couldn't retain a change to the original pHead

		success = 1;
	}

	return success;
}


          // Read all records from a file called musicPlayList.csv into a dynamic doubly linked list
//
//void Load(FILE* infile, Node** pList) 
//{
//	infile = fopen("musicPlayList.csv", "r");   //opening of the input file
//
//	while (!feof(infile))
//	{
//
//		char line[256];
//		fgets(line, 100, infile);
//
//		char time_temp[100];
//		//char time_temp[TEMP];
//		Record newData;
//
//		char* hope;   //
//
//		if (line[0] == '\"')
//		{
//			strcpy(newData.artist, strtok(line, "\""));
//		}
//		else
//		{
//			strcpy(newData.artist, strtok(line, ","));
//
//		}
//
//		////system("pause");
//
//		//strcpy(newData.album_title, strtok(NULL, ","));
//		//strcpy(newData.song_title, strtok(NULL, ","));
//		//strcpy(newData.genre, strtok(NULL, ","));
//
//		////store the duration into the struct Record
//		////newData.song_length.minutes = atoi(strtok(time_temp, ":"));
//		//newData.song_length.minutes = atoi(strtok(NULL, ":"));    // mine
//		//newData.song_length.seconds = atoi(strtok(NULL, ":"));
//
//		//////system("pause");
//		//////strcpy(time_temp, strtok(NULL, ","));
//		////newData.num_times_played = atoi(strtok(NULL, ","));
//		////newData.rating = atoi(strtok(NULL, "\n"));
//
//
//		         //   new stuff
//		hope = strtok(NULL, ",");
//		strcpy(newData.album_title, hope);
//
//		hope = strtok(NULL, ",");
//		strcpy(newData.song_title, hope);
//
//		hope = strtok(NULL, ",");
//		strcpy(newData.genre, hope);
//
//		//store the duration into the struct Record
//		strcpy(time_temp, strtok(NULL, ","));
//		//time_temp = strtok(line, ":");
//		newData.song_length.minutes = atoi(strtok(time_temp, ":"));
//
//		hope = strtok(NULL, ",");
//		newData.song_length.seconds = atoi(hope);
//
//
//		//hope = strtok(NULL, ",");
//		//newData.num_times_played = atoi(hope);
//		newData.num_times_played = atoi(strtok(NULL, ","));
//
//		//hope = strtok(NULL, "\n");
//		newData.rating = atoi(hope);
//
//
//		    //attatch the struct to the list, insert will create a node for the record
//		insertFront(pList, newData);
//	}
//}

void Load(FILE* infile, Node** pList)
{
	int minutes = 0, seconds = 0, played = 0, rating = 0;
	char line[256] = "", artist[50] = "", albulm[50] = "", title[50] = "", genre[50] = "", time[50] = "";
	Node* pMem = NULL, * pCur = NULL, * pPrev = NULL;
	Record newData = { 0 };

	infile = fopen("musicPlayList.csv", "r");

	if (infile != NULL)
	{
		fgets(line, 256, infile);

		while (!feof(infile))
		{

			strcpy(artist, strtok(line, "\""));

			if (strlen(artist) > 25) 
			{
				strcpy(artist, strtok(line, ","));
			}
			strcpy(albulm, strtok(NULL, ","));
			strcpy(title, strtok(NULL, ","));
			strcpy(genre, strtok(NULL, ","));
			strcpy(time, strtok(NULL, ","));
			played = atoi(strtok(NULL, ","));
			rating = atoi(strtok(NULL, ","));
			minutes = atoi(strtok(time, ":"));
			seconds = atoi(strtok(NULL, ","));

			// create space for the new node
			//pMem = makeNode(newData);
			insertFront(pList, newData);
			
		}
			fgets(line, 256, infile);
	}
	fclose(infile);
}
	



                // Write the records in the outfile

void Store(FILE* outfile, Node* pList)
{
	outfile = fopen("musicPlayList.csv", "w");

	while (pList != NULL)
	{
			// go through the list

			fprintf(outfile,"%s,%s,%s,%s,%d:%d,%d,%d\n", pList->data.artist, pList->data.album_title, pList->data.song_title,
				pList->data.genre, pList->data.song_length.minutes, pList->data.song_length.seconds, pList->data.num_times_played,
				pList->data.rating);
			pList = pList->pNext;
	}

	//system("pause");
	fclose(outfile);
}

               // Print the list the screen

void printList(Node* pHead)
{
	if (pHead != NULL)
	{
		// recursive step
	
		printf("\n Artist: %s, Album: %s, Song: %s, Genre: %s, Lenght: %d:%d, Times Played: %d, Rating: %d", pHead->data.artist,
			pHead->data.album_title, pHead->data.song_title, pHead->data.genre, pHead->data.song_length.minutes, 
			pHead->data.song_length.seconds, pHead->data.num_times_played, pHead->data.rating);
		printList(pHead->pNext);
	}
	else
	{
		// base case
		//printf("-->\n");
	}
}

int display_selected_record(Node** pHead, char* artist, Record newData)
{
	Node* pMem = makeNode(newData), * pPrev = NULL, * pCur = *pHead;

	int exit = 0;

	if (pMem != NULL)
	{
		while (pCur != NULL)
		{

			if ((pCur != NULL) && (strcmp(artist, pCur->data.artist) == 0)) //loooking for the artist
			{
				printf("Artist: %s\n", pCur->data.artist);
				printf("Album: %s\n", pCur->data.album_title);
				printf("Song: %s\n", pCur->data.song_title);
				printf("Genre: %s\n", pCur->data.genre);
				printf("Duration: %d:%d\n", pCur->data.song_length.minutes, pCur->data.song_length.seconds);
				printf("Played: %d\n", pCur->data.num_times_played);
				printf("Rating: %d/5\n", pCur->data.rating);
				exit = 1;
			}

			if (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			else
			{
				printf("Invalid input, please try again.\n");
				system("pause");
				system("cls");
				exit = 2;
				break;
			}
		}
	}
	return exit;
}

void display(Node* pHead) 
{
	int selection = 0;
	printf("Would you like to play all songs (1) or play an artist(2)?");
	scanf("%d", &selection);

	if (selection == 1) 
	{
		//play all till pLink == null
		while (pHead != NULL) 
		{
			printf("\n Artist: %s, Album: %s, Song: %s, Genre: %s, Lenght: %d:%d, Times Played: %d, Rating: %d", pHead->data.artist,
				pHead->data.album_title, pHead->data.song_title, pHead->data.genre, pHead->data.song_length.minutes,
				pHead->data.song_length.seconds, pHead->data.num_times_played, pHead->data.rating);
			pHead = pHead->pNext;
			//printList(pHead->pNext);
		
		}
	}

	else if (selection == 2) 
	{
		printf("Which artist do you want to display?\n");
		char target[TEMP];
		scanf("%s", target);

		//search for the artist
		while (pHead != NULL) 
		{
			if (strcmp(pHead->data.artist, target) == 0)
			{
				printf("\n Artist: %s, Album: %s, Song: %s, Genre: %s, Lenght: %d:%d, Times Played: %d, Rating: %d", pHead->data.artist,
					pHead->data.album_title, pHead->data.song_title, pHead->data.genre, pHead->data.song_length.minutes,
					pHead->data.song_length.seconds, pHead->data.num_times_played, pHead->data.rating);
				pHead = pHead->pNext;
			}
			else 
			{
				pHead = pHead->pNext;
			}
		}
	}
	//putchar('\n');
	//system("Pause");
}

int Rate(Node** pHead, char* song, Record newData)
{
	Node* pMem = makeNode(newData), * pPrev = NULL,* pCur = *pHead;
	int rate = 0, ok= 0;

	if (pMem != NULL)
	{
		while (ok != 1)
		{
			if ((pCur != NULL) && (strcmp(pCur->data.song_title, song) == 0))
			{
				printf(" What rate do you want to give for that song? (1 - 5): ");   // Ask user input
				scanf("%d", &rate);
				pCur->data.rating = rate;
				ok = 1;
			}
			if (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
		}
	}

}

//void play(Node* pList)
//{
//	char song[15] = "";
//	//printf("Song?\n->\t");
//	//scanf(" %[^\n]s", &song);
//
//	printf("Song?\n\t");
//	scanf(" %s", &song);
//
//	while (pList != NULL && strcmp(pList->data.song_title, song) != 0)
//		pList = pList->pNext;
//
//	while (pList != NULL) 
//	{
//		printf("\n\n\\ ________________________________//\n");
//		printf("| |   ___        %.10s           | |\n", pList->data.song_title);
//		printf("| |   \\o \\o    %.10s          | |\n", pList->data.artist);
//		printf(" \\ ______________________________ // |\n");
//
//		system("sleep 2");
//		system("cls");
//
//		pList = pList->pPrev;
//	}
//
//	if (pList == NULL)
//		return;
//}