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

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#define TEMP 100
#include <stdio.h>  /* Needed for fscanf ( ), fprintf ( ), fopen ( ), etc. */
#include <math.h>	/* Needed for sqrt ( ) */
#include <stdlib.h> /* Needed for exit ( ) */
#include <string.h>


typedef struct duration
{
    int minutes;
    int seconds;
} Duration;

//typedef struct record
//{
//	char* artist;     //string    //Or do I need size like char[15] artist; ??
//	char* album_title;
//	char* song_title;
//	char* genre;
//	Duration song_length;
//	int num_times_played;
//	int rating;      //(1 – 5)
//
//} Record;

typedef struct record
{
    char artist[TEMP];     //string    //Or do I need size like char[15] artist; ??
    char album_title[TEMP];
    char song_title[TEMP];
    char genre[TEMP];
    Duration song_length;
    int num_times_played;
    int rating;      //(1 – 5)

} Record;

typedef struct node
{
	Record data;
	struct node* pNext;    //Pointer to the next node
	struct node* pPrev;    //Pointer to the previous node

} Node;

/****************************************************************
    * Function: print_menu ()                                   *
    * Date Created: January 29, 2022                            *
    * Date Last Modified: January 29, 2022                      *
    * Description: The function clean the FitbitData.cvs        *
    *              file and check for empty data and extra      *
    *              comma and change it with something else, so  *
    *              that all lines are filled with values after  *
    *              every comma.                                 *
    * Input parameters: Nothing.                                *
    * Returns: An integer.                                      *                                   
    * Postconditions: The user should be able to see the menu   * 
                      and enter an input and gets to the        *
                      chosen option corresponding to            *
                      the integer.                              *
    *************************************************************/
int print_menu(void);

/****************************************************************
    * Function: makeNode ()                                     *
    * Date Created: January 30, 2022                            *
    * Date Last Modified: January 31, 2022                      *       
    * Description: The function allocates space for a           *
                   struct Node on the heap, and                 *
                   initializes the node.                        *            
    * Input parameters: Four characters to a pointer (all       *
                        different pointers) and four integers.  *           
    * Returns: Nothing.                                         *  
    * Preconditions: The input files must already be            *
                      open.                                     *
 ****************************************************************/
//Node* makeNode(char* sub_artist, char* sub_album, char* sub_title, char* sub_genre, int sub_min,
//    int sub_sec, int sub_time_played, int sub_rate);
Node* makeNode(Record newData);


/****************************************************************
    * Function: insertFront ()                                  *
    * Date Created: January 30, 2022                            *
    * Date Last Modified: January 31, 2022                      *            
    * Description: The function adds a new Node with new        *
                   data from a new record in the object         *
                   "sub_record" to the front of the             *
                   linkedList "pList".                          *
    * Input parameters: The doubly linked list to the struct    *
                        Node and a call to the struct           *
                        Record.                                 *
    * Returns: An integer.                                      *
    * Preconditions: The function makeNode() should             *
                     already exits.                             *
    * Postconditions: Returns 1 for successfully allocating     *
                      space for a node; 0 otherwise.            *
    *************************************************************/
//int insertFront(Node** pList, Record sub_record);
//int insertFront(Node** pList, char* sub_artist, char* sub_album, char* sub_title, char* sub_genre, int sub_min,
//    int sub_sec, int sub_time_played, int sub_rate);
int insertFront(Node** pList, Record newData);

/****************************************************************
    * Function: Load ()                                         *
    * Date Created: January 31, 2022                            *           
    * Date Last Modified: February 01, 2022                     *             
    * Description: The function read all records from a file    *
                   called musicPlayList.csv into a dynamic      *
                   doubly linked list. Each record must be      *
                   inserted at the front of the list.           *                                     
    * Input parameters: An input file pointer, infile and       *
                        the doubly linked list to the struct    *
                        Node.                                   *
    * Returns: Nothing.                                         *
    * Preconditions: The infile musicPlayList.csv should        *
                     be open for reading.                       *
    * Postconditions: All records must be able to be read and   *
                      each record inserted at the front         *
                      of the list.                              *
    *************************************************************/
void Load(FILE* infile, Node** pList);

/****************************************************************
    * Function: Store ()                                        *
    * Date Created: January 31, 2022                            *
    * Date Last Modified: February 01, 2022                     *              
    * Description: The function writes the records in the       *
                   dynamic doubly linked list to the            *
                   musicPlayList.csv file.                      *
    * Input parameters: The file pointer, outfile and the       *
                        single linked list of the struct Node.  *                                                           
    * Returns: Nothing.                                         *
    * Preconditions: The outfile musicPlayList.csv should       * 
                     be open for writing.                       *
    * Postconditions: All the records should be written in      *
                      the list to the outfile, maintaining      *
                      the .csv format.                          *
   *************************************************************/
void Store(FILE* outfile, Node* pList);

void printList(Node* pHead);
int display_selected_record(Node** pHead, char* artist, Record newData);

int Rate(Node** pHead, char* song, Record newData);
//void play(Node* pList);



#endif 
