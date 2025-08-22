#include "header.h"

// Display the main menu and allow the user to choose an option

int print_menu(void)
{
	int choice = 0;

	printf(" \n              Welcome to the digital music management!        \n");
	printf("--------MUSIC PLAYLIST- MAIN MENU:\n");
	printf(" 1. Load - (Please do this only once)\n");
	printf(" 2.  Store\n");
	printf(" 3. Display\n");
	printf(" 4. Insert\n");
	printf(" 5.  Delete\n");
	printf(" 6.  Edit\n");
	printf(" 7.  Sort\n");
	printf(" 8.  Rate\n");
	printf(" 9.  Play\n");
	printf(" 10. Shuffle\n");
	printf(" 11. Exit\n\n");
	printf("          Please do not forget to load(1) before any other functions.\n");
	printf("-----------------Pick a number from 1 to 11---------------------: ");

	scanf("%d", &choice);

	system("cls");

	return choice;
}

// Allocate space for a Node on the heapand initializes the Node with the information found in the inputs

Node* makeNode(Record newData)
{
	Node* pMem = NULL;
	pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		// Allocated space for Node successfully
		pMem->data = newData;             // struct assignment, copy

		pMem->pNext = NULL;
		pMem->pPrev = NULL;
	}

	return pMem;
}

// Adds a new Node with new data from a new record in the object "sub_record" to the front of the linkedList "pList".

bool insertFront(Node** pList, Record newData)
{
	bool success = false;
	//int success = 0;
	Node* pMem = NULL, * pCur = *pList, * pPrev = NULL;
	pMem = makeNode(newData); // calls makeNode() to make new node of newData

	if (pMem != NULL)
	{
		success = true; // shows success if allocation was sucessful
		//success = 1;

		if (*pList == NULL) //empty list
			*pList = pMem;

		else
		{
			while (pCur != NULL)  //loops to end of linked list
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}

			if (pPrev != NULL)       // at the end of the list
			{
				pPrev->pNext = pMem;
				pMem->pNext = pCur;
				pMem->pPrev = pPrev;
			}
			else
			{
				pMem->pNext = pCur; // places at the start of the list
				*pList = pMem;
			}
		}

	}
	//return success;
}

// Read all records from a file called musicPlayList.csv into a dynamic doubly linked list

Node* Load(FILE* infile)
{
	Record data = { 0 };
	Node* pList = NULL;

	char line[200] = " ";
	char* info = " ";
	//char delim[2] = ",";
	char delim[10] = ",";
	int min = 0, sec = 0, repeats = 0, rating = 0;

	char firstName[15] = " ";
	char lastName[15] = " ";


	while (!feof(infile))
	{
		fgets(line, 200, infile);

		//Artist 
		if (line[0] == '\"')           // For artist with last and first name
		{
			strcpy(data.artist, strtok(line, "\""));
		}
		else                           // For artist with single name
		{
			strcpy(data.artist, strtok(line, ","));

		}

		//Album
		info = strtok(NULL, delim);
		if (info != '\0')
		{
			strcpy(data.album_title, info);
		}

		//Song
		info = strtok(NULL, delim);
		if (info != '\0')
		{
			strcpy(data.song_title, info);
		}

		//Genre
		info = strtok(NULL, delim);
		if (info != '\0')
		{
			strcpy(data.genre, info);
		}

		//Minutes and seconds
		info = strtok(NULL, ":");
		if (info != '\0')
		{
			min = atoi(info);
			data.song_length.minutes = min;
			info = strtok(NULL, delim);

			sec = atoi(info);
			data.song_length.seconds = sec;
		}

		//Number of times played
		info = strtok(NULL, delim);
		if (info != '\0')
		{
			data.num_times_played = atoi(info);
		}

		//Rating
		info = strtok(NULL, delim);
		if (info != '\0')
		{
			data.rating = atoi(info);
		}

		//Start building the LinkedList
		insertFront(&pList, data);       
	}

	printf("\n The record has been already loaded, please once is sufficient!\n");

	return pList;
}

// Write the records in the outfile

void Store(FILE* outfile, Node* pList)
{
	outfile = fopen("musicPlayList.csv", "w");

	while (pList != NULL)   // go through the list
	{
		fprintf(outfile, "%s,%s,%s,%s,%d:%d,%d,%d\n", pList->data.artist,
			pList->data.album_title, pList->data.song_title, pList->data.genre, pList->data.song_length.minutes,
			pList->data.song_length.seconds, pList->data.num_times_played, pList->data.rating);

		pList = pList->pNext;
	}
	// "\"%s\"
	fclose(outfile);
	printf("\n The data had been stored /written to the file!\n");
}

// Allow the user to find a record in the list by artist.

void Edit(Node* pList)
{
	char artist_target[TEMP];
	char song_target[TEMP];

	printf("      The list of the songs is displayed below:\n");
	printf("Shake it Off :by Taylor Swift\n");
	printf("Own it :by Drake\n");
	printf("The Motto :by Drake\n");
	printf("Trust :by Christina Perri\n");
	printf("No Sense :by Justin Bieber\n");
	printf("Vegas :by Eminem\n");
	printf("Remedy :by Adele\n");
	printf("Stay Stay Stay :by Taylor Swift\n");
	printf("The Old Stuff :by Garth Brooks\n\n");

	printf("\n     The names of the artists are displayed below: (please follow the instructions below)\n");
	printf("Drake/Adele/Eminem\n");
	printf("Swift, Taylor/Brooks, Garth/Perri, Christina/Bieber, Justin\n");
	printf("\nDon't forget to input the comma and space between names with two words\n");

	printf("Which artist would you like to edit?\n");
	gets(artist_target);
	gets(artist_target);

	printf("Which song would you like to edit?\n");
	gets(song_target);

	while (pList != NULL)
	{
		if (strcmp(pList->data.artist, artist_target) == 0)     //compare the target artist to the artists in the list
		{
			if (strcmp(pList->data.song_title, song_target) == 0)     //compare the target song to the songs in the list
			{
				//Ask for what the user wants to change
				int decision = 0;
				printf("What do you want to edit? \nArtist(1) \nAlbum(2) \nSong(3) \nGenre(4) \nDuration(5) \nTimes played(6) \nRating (7)\n\n");
				scanf("%d", &decision);

				switch (decision)
				{
				case 1:
					printf("\nYou chose to edit the artist. What would you like to change it to?\n");
					scanf("%s", pList->data.artist);
					//store the string in the artist info
					break;

				case 2:
					printf("\nYou chose to edit the album. What would you like to change it to? \n");
					scanf("%s", pList->data.album_title);
					//store it into the album info
					break;

				case 3:
					printf("\nYou chose to edit the song. What would you like to change it to?\n");
					scanf("%s", pList->data.song_title);
					//store it into the song info
					break;

				case 4:
					printf("\nYou chose to edit the genre. What would you like to change it to?\n");
					scanf("%s", pList->data.genre);
					//store into the genre info
					break;

				case 5:                // For minutes and seconds
					printf("\nYou chose to edit the duration field. What would you like to change it to?\n");
					scanf("%d:%d", &pList->data.song_length.minutes, &pList->data.song_length.seconds);
					//store into the duration info
					break;

				case 6:
					do {
						printf("\nYou chose to edit the number of times played field. What would you like to change it to?\n");
						scanf("%d", &pList->data.num_times_played);
					} while (pList->data.num_times_played < 0);
					    //store it into the number of times played info
					break;

				case 7:
					do {
						printf("\nYou chose to edit the rating. What would you like to change it to?\n");
						scanf("%d", &pList->data.rating);

					} while (pList->data.rating != 1 && pList->data.rating != 2 && pList->data.rating != 3
						&& pList->data.rating != 4 && pList->data.rating != 5);
					//store it into the rating info
					break;

				}      //end of swicth-statement

						    //Print the new change to the screen
				printf("The new record has will be dispalyed below.\n\n");
				printf("\n%s,%s,%s,%s,%d:%d,%d,%d\n", pList->data.artist, pList->data.album_title, pList->data.song_title,
					pList->data.genre, pList->data.song_length.minutes, pList->data.song_length.seconds,
					pList->data.num_times_played, pList->data.rating);

			}   //End of last inner if-statement


			else {
				pList = pList->pNext;
			}

		}
		else {
			pList = pList->pNext;
		}
	}


}

// Sort the records in the list in different methods and allows the user to pick one and excutes the function 

void Sort(Node** pList)
{
	int element = -1, type = -1;

	printf("\nHow would you like to sort?\n");
	printf(" 1. By Artist (A-Z)\n");
	printf(" 2. By Album title (A-Z)\n");
	printf(" 3. By Rating (1-5)\n");
	printf(" 4. By times played (most-least)\n");
	scanf("%d", &type);

	element = type - 1;
	bool success = false;

	while (success == false)
	{
		Node* pCur = *pList;
		Node** pCurPtr = pList;
		Node* pNextTemp = pCur->pNext;
		success = true;

		char* pNextTemp1 = NULL;
		char* pCur1 = NULL;

		int pNextTemp2;
		int pCur2;

		while (pNextTemp != NULL)
		{
			switch (element)
			{
			case 0:           //sort by artist

				pNextTemp1 = (char)malloc(sizeof(char)) * strlen(pNextTemp->data.artist);
				pNextTemp1 = pNextTemp->data.artist;

				pCur1 = (char)malloc(sizeof(char) * strlen(pCur->data.artist));
				pCur1 = pCur->data.artist;
				break;

			case 1:       //sort by album
				pNextTemp1 = (char)malloc(sizeof(char)) * strlen(pNextTemp->data.album_title);
				pNextTemp1 = pNextTemp->data.album_title;

				pCur1 = (char)malloc(sizeof(char) * strlen(pCur->data.album_title));
				pCur1 = pCur->data.album_title;

				break;

			case 2:         //sort by rating
				pNextTemp2 = pNextTemp->data.rating;
				pCur2 = pCur->data.rating;
				break;

			case 3:         //sort by number of times played
				pNextTemp2 = pNextTemp->data.num_times_played;
				pCur2 = pCur->data.num_times_played;
				break;
			}

			if ((element <= 1) && (strcmp(pNextTemp1, pCur1) == -1))
			{
				pCur->pNext = pNextTemp->pNext;
				pNextTemp->pNext = pCur;
				*pCurPtr = pNextTemp;

				success = false;
			}
			else if ((element >= 2) && (pNextTemp2 > pCur2))
			{
				pCur->pNext = pNextTemp->pNext;
				pNextTemp->pNext = pCur;
				*pCurPtr = pNextTemp;

				success = false;
			}

			pCurPtr = &pCur->pNext;
			pCur = pNextTemp;
			pNextTemp = pNextTemp->pNext;

		}
	}

	printf("\nThe sorting has been effectuated!\n");
}

// Display the records

void Display(Node* pList)
{
	Node* pCur = NULL;
	pCur = pList;
	int count = 0;
	char Artist[75] = { '\0' };

	printf("\n     The names of the artists are displayed below:\n");
	printf("Drake/Adele/Eminem\n");
	printf("Swift, Taylor/Brooks, Garth/Perri, Christina/Bieber, Justin\n");
	printf("\nDon't forget to input the comma and space between names with two words\n");

	printf("\nDo you want to display the whole list '1' or display a specific artist (case sensitive) '2'? \n");
	scanf("%d", &count);

	switch (count)
	{ 
	case 1:              //Display the whole list

		while (pCur != NULL)
		{
			printf("Artist: %s\n", pCur->data.artist);
			printf("Album: %s\n", pCur->data.album_title);
			printf("Song: %s\n", pCur->data.song_title);
			printf("Genre: %s\n", pCur->data.genre);
			printf("Duration: %d:%d\n", pCur->data.song_length.minutes, pCur->data.song_length.seconds);
			printf("Played: %d\n", pCur->data.num_times_played);
			printf("Rating: %d\n", pCur->data.rating);
			printf("\n");

			pCur = pCur->pNext;
		}
		break;

	case 2:        // Display the record(s) off a specific artist

		printf("What artist do you want to display?\n");
		getchar();
		gets(Artist);

		while (pCur != NULL)
		{
			if (strcmp(pCur->data.artist, Artist) == 0)
			{
				printf("\nArtist: %s\n", pCur->data.artist);
				printf("Album: %s\n", pCur->data.album_title);
				printf("Song: %s\n", pCur->data.song_title);
				printf("Genre: %s\n", pCur->data.genre);
				printf("Duration: %d:%d\n", pCur->data.song_length.minutes, pCur->data.song_length.seconds);
				printf("Played: %d\n", pCur->data.num_times_played);
				printf("Rating: %d\n\n", pCur->data.rating);
				pCur = pCur->pNext;
			}

			else
			{
				pCur = pCur->pNext;
			}
		}

		break;
	}

}

 // Ask the user for the details of a new record and the new record inserted at the front of the list.

int Insert_newRecord(Node** pList, Record newData)
{
	Node* pMem = makeNode(newData);
	int success = 1;

	pMem->pNext = *pList;
	*pList = pMem;

	return success;
}

// Delete a record from a list

void Delete(Node** pList)
{
	Node* pMem = *pList;
	char remove[50] = " ";

	printf("      The list of the songs is displayed below:\n");
	printf("Shake it Off :by Taylor Swift\n");
	printf("Own it :by Drake\n");
	printf("The Motto :by Drake\n");
	printf("Trust :by Christina Perri\n");
	printf("No Sense :by Justin Bieber\n");
	printf("Vegas :by Eminem\n");
	printf("Remedy :by Adele\n");
	printf("Stay Stay Stay :by Taylor Swift\n");
	printf("The Old Stuff :by Garth Brooks\n\n");

	printf("\nWhich song would you like to remove? (case sensitive)\n");

	scanf(" %[^\n]s", &remove);


	while (pMem != NULL)
	{
		if (strcmp(pMem->data.song_title, remove) == 0)    //compare the target song with the songs in the list
		{
			printf("\nChoice picked: %s\n", pMem->data.song_title);

			pMem->pPrev->pNext = pMem->pNext;

			pMem->pNext->pPrev = pMem->pPrev;

			free(pMem);     //Erase

			printf("The record has been successfully deleted from the list!\n"); 
			//printf("new:", pMem->data.song_title);

			break;
		}

		pMem = pMem->pNext;
	}

}

// Rate songs and replace them into the original list

void Rate(Node* pList)
{
	char song_title[75];
	int rating = 0;
	Node* pCur = NULL;
	pCur = pList;

	printf("      The list of the songs is displayed below:\n");
	printf("Shake it Off :by Taylor Swift\n");
	printf("Own it :by Drake\n");
	printf("The Motto :by Drake\n");
	printf("Trust :by Christina Perri\n");
	printf("No Sense :by Justin Bieber\n");
	printf("Vegas :by Eminem\n");
	printf("Remedy :by Adele\n");
	printf("Stay Stay Stay :by Taylor Swift\n");
	printf("The Old Stuff :by Garth Brooks\n\n");

	printf("Please select a song to rate(case sensitive): ");
	getchar();
	gets(song_title);


	while (pCur != NULL)
	{
		if (strcmp(song_title, pCur->data.song_title) == 0)     //Compare the target song to the songs in the list
		{
			do
			{
				printf("Please enter a new rating (1-5): ");
				scanf("%d", &rating);          //get a new rating

			} while (rating < 1 || rating > 5);    

			pCur->data.rating = rating;
			printf("New inserted rating: %d\n", pCur->data.rating);     //Printing the new rate given
			pCur = pCur->pNext;

		}

		else
		{
			pCur = pCur->pNext;
		}
	}


}

// Play a song or the whole playlist

void Play(Node* pList)
{
	//char song_title[75];
	char song_title[75] = { '\0' };
	int found = 0;
	Node* pCur = NULL;
	pCur = pList;

	printf("      The list of the songs is displayed below in order :\n");
	printf("Shake it Off :by Taylor Swift\n");
	printf("Own it :by Drake\n");
	printf("The Motto :by Drake\n");
	printf("Trust :by Christina Perri\n");
	printf("No Sense :by Justin Bieber\n");
	printf("Vegas :by Eminem\n");
	printf("Remedy :by Adele\n");
	printf("Stay Stay Stay :by Taylor Swift\n");
	printf("The Old Stuff :by Garth Brooks\n\n");

	printf("Enter a song name to start playing(case sensitive): ");
	getchar();
	gets(song_title);

	while (!found)
	{
		if (strcmp(song_title, pCur->data.song_title) == 0)
		{
			printf("\nArtist: %s\n", pCur->data.artist);
			printf("Album: %s\n", pCur->data.album_title);
			printf("Song: %s\n", pCur->data.song_title);
			printf("Genre: %s\n", pCur->data.genre);
			printf("Duration: %d:%d\n", pCur->data.song_length.minutes, pCur->data.song_length.seconds);
			printf("Played: %d\n", pCur->data.num_times_played);
			printf("Rating: %d\n\n", pCur->data.rating);

			pCur = pCur->pNext;
			found = 1;
			Sleep(2000);  //2 seconds
		}
		else
		{
			pCur = pCur->pNext;
		}
	}

	while (pCur != NULL)
	{
		printf("---------------Playing next song-------");
		system("pause");
		system("cls");

		         // Playing (printing) the records 

		printf("\nArtist: %s\n", pCur->data.artist);
		printf("Album: %s\n", pCur->data.album_title);
		printf("Song: %s\n", pCur->data.song_title);
		printf("Genre: %s\n", pCur->data.genre);
		printf("Duration:  %d:%d\n", pCur->data.song_length.minutes, pCur->data.song_length.seconds);
		printf("Played: %d\n", pCur->data.num_times_played);
		printf("Rating: %d\n\n", pCur->data.rating);
		pCur = pCur->pNext;

		   //Printing the record for 2 seconds
		Sleep(2000);     
	}

	printf("The list of songs is over!\n");

}


// Provide a random order in which the songs are played.

void Shuffle(Node* pList)
{
	srand(time(NULL));
	Node* pHead = pList, * pMem = pList;
	int length = 0, cur_index = 0, * index_to_play = NULL;

	for (length = 0; pHead != NULL; length++)
		pHead = pHead->pNext;

	index_to_play = malloc(sizeof(int) * length);

	for (int i = 0; i < length; i++)
		index_to_play[i] = i;

	for (int i = 0; i < length; i++)
	{
		int temp = index_to_play[i], j = rand() % (i + 1);    //Randomization
		index_to_play[i] = index_to_play[j];
		index_to_play[j] = temp;
	}

	for (int i = 0; i < length; i++)
	{
		while (cur_index != index_to_play[i])
		{
			if (cur_index < index_to_play[i])
			{
				cur_index++;
				pMem = pMem->pNext;
			}
			else
			{
				cur_index--;
				pMem = pMem->pPrev;
			}
		}
		         // Printing the records in the new order

		printf("\nArtist: %s\n", pMem->data.artist);
		printf("Album: %s\n", pMem->data.album_title);
		printf("Song Title: %s\n", pMem->data.song_title);
		printf("Genre: %s\n", pMem->data.genre);
		printf("Length: %d:%d\n", pMem->data.song_length.minutes, pMem->data.song_length.seconds);
		printf("Times Played: %d\n", pMem->data.num_times_played);
		printf("Rating: %d\n", pMem->data.rating);
		 
		   //Printing the record for 2 seconds
		Sleep(2000);    

		printf("----------------Playing next song-----------\n");

	}

	printf("\n We reached the end of the list, all the songs have been played!\n\n");

}

// Exit the program

void Exit(FILE* outfile, Node* pList)
{
	outfile = fopen("musicPlayList.csv", "w");

	while (pList != NULL)    // go through the list    
	{
		    // Store the last modified/stored record in the file

		fprintf(outfile, "%s,%s,%s,%s,%d:%d,%d,%d\n", pList->data.artist,
			pList->data.album_title, pList->data.song_title, pList->data.genre, pList->data.song_length.minutes,
			pList->data.song_length.seconds, pList->data.num_times_played, pList->data.rating);
		pList = pList->pNext;
	}

	fclose(outfile);
	printf("Goodbye, thank you for passing by! The record has been stored to the file\n");
}