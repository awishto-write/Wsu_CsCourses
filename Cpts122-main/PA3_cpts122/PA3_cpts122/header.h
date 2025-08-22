/********************************************************************************
 * Programmer: Naomi Dion-Gokan                                                 *
 * Class: CptS 122; Lab Section 11                                              *
 * Programming Assignment: PA 2 and PA 3                                        *
 * Date Created: January 29, 2022                                               *
 * Date Last Modified: February 17, 2022                                        *
 * Description: This program will write a basic digital music manager(DMM).     *
 *              It would manipulate the music collection based on attributes    *
                such as artist, album title, song title, genre, song length,    *
                number of times played, and rating.                             *
 *******************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#define TEMP 100

#include <stdio.h>  /* Needed for fscanf ( ), fprintf ( ), fopen ( ), etc. */
#include <stdlib.h> /* Needed for exit ( ) */
#include <string.h>
#include <stdbool.h>             
#include <Windows.h>     
#include <time.h>
#include <math.h>    

typedef struct duration
{
    int minutes;
    int seconds;

} Duration;

typedef struct record
{
    char artist[50];      //string
    char album_title[50];
    char song_title[50];
    char genre[50];
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


          // This program has been derived with the codes given in class, by yself and with the help of other people/resources//


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
    * Input parameters: The struct Record newData               *
    * Returns: A pointer to the struct Node.                    *
    * Preconditions: The input files must already be            *
                      open.                                     *
 ****************************************************************/
Node* makeNode(Record newData);

/****************************************************************
    * Function: insertFront ()                                  *
    * Date Created: January 30, 2022                            *
    * Date Last Modified: February 04, 2022                     *
    * Description: The function adds a new Node with new        *
                   data from a new record in the object         *
                   "sub_record" to the front of the             *
                   linkedList "pList".                          *
    * Input parameters: The doubly linked list to the struct    *
                        Node and a call to the struct           *
                        Record.                                 *
    * Returns: True or False.                                   *
    * Preconditions: The function makeNode() should             *
                     already exits.                             *
    * Postconditions: Returns 1 for successfully allocating     *
                      space for a node; 0 otherwise.            *
    *************************************************************/
bool insertFront(Node** pList, Record newData);

/****************************************************************
    * Function: Load ()                                         *
    * Date Created: January 31, 2022                            *
    * Date Last Modified: February 14, 2022                     *
    * Description: The function read all records from a file    *
                   called musicPlayList.csv into a dynamic      *
                   doubly linked list. Each record must be      *
                   inserted at the front of the list.           *
    * Input parameters: An input file pointer, infile.          *
    * Returns: A pointer to the struct Node.                    *
    * Preconditions: The infile musicPlayList.csv should        *
                     be open for reading.                       *
    * Postconditions: All records must be able to be read and   *
                      each record inserted at the front         *
                      of the list.                              *
    *************************************************************/
Node* Load(FILE* infile);

/****************************************************************
    * Function: Store ()                                        *
    * Date Created: January 31, 2022                            *
    * Date Last Modified: February 06, 2022                     *
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

/****************************************************************
    * Function: Display ()                                      *
    * Date Created: February 02, 2022                           *
    * Date Last Modified: February 05, 2022                     *
    * Description: The function prints records to the screen    *
    *              in two ways: print all records or            *
    *              print all recors that match an artist.       *
    * Input parameters: The single linked list of the           *
                        struct Node.                            *
    * Returns: Nothing.                                         *
    * Preconditions: Access to the file musicPlayList.csv       *
                     should be given.                           *
    * Postconditions: All the records or selected records       *
                      from the user should be displayed         *
                      on the screen.                            *
   *************************************************************/
void Display(Node* pList);

/****************************************************************
    * Function: Edit ()                                         *
    * Date Created: February 03, 2022                           *
    * Date Last Modified: February 13, 2022                     *
    * Description: The function allows the user to find a       *
                   record in the list by artist. If there are   *
                   multiple records with the same artist,       *
                   it prompts the user which one to edit.       *
    * Input parameters: The single linked list of the           *
                        struct Node.                            *
    * Returns: Nothing.                                         *
    * Preconditions: Access to the file musicPlayList.csv       *
                     should be given.                           *
    * Postconditions: All the modifications should be           *
    *                 stored in the file.                       *
   *************************************************************/
void Edit(Node* pList);

/****************************************************************
    * Function: Rate ()                                         *
    * Date Created: February 03, 2022                           *
    * Date Last Modified: February 10, 2022                     *
    * Description: The function allows the user to assign       *
                   a value of 1 – 5 to a song; 1 is the         *
                   lowest rating and 5 is the highest rating.   *
    * Input parameters: The single linked list of the           *
                        struct Node.                            *
    * Returns: Nothing.                                         *
    * Preconditions: Access to the file musicPlayList.csv       *
                     should be given.                           *
    * Postconditions: All the new ratings should replace        *
                      the previous rating                       *
   *************************************************************/
void Rate(Node* pList);

/****************************************************************
    * Function: Play ()                                         *
    * Date Created: February 03, 2022                           *
    * Date Last Modified: February 12, 2022                     *
    * Description: The function allows the user to select a     *
                   song, and must start “playing” each song in  *
                   order from the current song. By playing, it  *
                   means displaying the contents of the record  *
                   that represents the song for a short period  *
                   of time.                                     *
    * Input parameters: The single linked list of the           *
                        struct Node.                            *
    * Returns: Nothing.                                         *
    * Preconditions: Access to the file musicPlayList.csv       *
                     should be given.                           *
   *************************************************************/
void Play(Node* pList);

/****************************************************************
    * Function: Shuffle ()                                      *
    * Date Created: February 04, 2022                           *
    * Date Last Modified: February 13, 2022                     *
    * Description: The function provides a random order in      *
                   which the songs are played. It does not      *
                   modify the links in the list. It specifies   *
                   the order in which songs are played, based   *
                   on the position of the song in the list.     *
    * Input parameters: The single linked list of the           *
                        struct Node.                            *
    * Returns: Nothing.                                         *
    * Preconditions: Access to the file musicPlayList.csv       *
                     should be given.                           *
    * Postconditions: The record should be played on the        *
                      screen on a random order.                 *
   *************************************************************/
void Shuffle(Node* pList);

/****************************************************************
    * Function: Sort ()                                         *
    * Date Created: February 05, 2022                           *
    * Date Last Modified: February 15, 2022                     *
    * Description: The function prompts the user for 4          *
                  different methods to sort the records         *
                  in the list and allows the user to            *
                  pick one and executes the function.           *
    * Input parameters: The double linked list of the           *
                        struct Node.                            *
    * Returns: Nothing.                                         *
    * Preconditions: Access to the file musicPlayList.csv       *
                     should be given.                           *
   *************************************************************/
void Sort(Node** pList);

/****************************************************************
    * Function: Insert ()                                       *
    * Date Created: February 05, 2022                           *
    * Date Last Modified: February 16, 2022                     *
    * Description: The function prompts the user for the        *
                  details of a new record, the prompt must      *
                  request elements from the Record struct and   *
                  inserted the new record at the front of       *
                  the list.                                     *
    * Input parameters: The double linked list of the           *
                        struct Node and a call to the struct    *
                        Record.                                 *
    * Returns: An integer.                                      *
    * Preconditions: Access to the file musicPlayList.csv       *
                     should be given.                           *
    * Postconditions: The new record should be correctly        *
                      inserting the record at the front of      *
                      the list.                                 *
   *************************************************************/     
int Insert_newRecord(Node** pList, Record newData);

/****************************************************************
    * Function: Delete ()                                       *
    * Date Created: February 05, 2022                           *
    * Date Last Modified: February 14, 2022                     *
    * Description: The function provides a random order in      *
                   which the songs are played. It does not      *
                   modify the links in the list. It specifies   *
                   the order in which songs are played, based   *
                   on the position of the song in the list.     *
    * Input parameters: The double linked list of the           *
                        struct Node.                            *
    * Returns: Nothing.                                         *
    * Preconditions: Access to the file musicPlayList.csv       *
                     should be given.                           *
   *************************************************************/
void Delete(Node** pList);

/****************************************************************
    * Function: Exit()                                          *
    * Date Created: February 06, 2022                           *
    * Date Last Modified: February 14, 2022                     *
    * Description: The function command saves the most recent   *
                   list to the musicPlayList.csv file. It       *
                   completely overwrites the previous           *
                   contents in the file.                        *
    * Input parameters: The file pointer, outfile and the       *
                        single linked list of the struct Node.  *
    * Returns: Nothing.                                         *
    * Preconditions: The outfile musicPlayList.csv should       *
                     be open for writing.                       *
    * Postconditions: The modified (or loaded) record           *
                      should be written to outfile and exit     *
                      the program.                              *
   *************************************************************/
void Exit(FILE* outfile, Node* pList);

#endif 

