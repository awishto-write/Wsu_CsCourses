/********************************************************************************
 * Programmer: Naomi Dion-Gokan                                                 *
 * Class: CptS 122; Lab Section 11                                              *
 * Programming Assignment: PA 1                                                 *
 * Date Created: January 15, 2022                                               *
 * Date Last Modified: January 30 ,2022                                         *
 * Description: This program will evaluate 24 hours of data from Fitbit's       *
 *              patients. It will filter any data that is not related to        *
 *              the given target patient. It will also dedupe any entries       *
 *              that appear multiple times and perform data cleansing any       *
 *              entries that have missing fields.                               *
 *******************************************************************************/

#ifndef HEADER_H
#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  /* Needed for fscanf ( ), fprintf ( ), fopen ( ), etc. */
#include <math.h>	/* Needed for sqrt ( ) */
#include <stdlib.h> /* Needed for exit ( ) */
#include <string.h>
#define SIZE 1440

 // ** Base codes given by the instructor **//

typedef enum sleep
{
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3

} Sleep;

typedef struct fitbit
{
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;

} FitbitData;



// Code Derived with help of other people and personally

typedef struct poorsleep
{
    char start_minute[9];
    char end_minute[9];
    int time_total;

}PoorSleep;

/*************************************************************
 * Function: read_data ()                                    *
 * Date Created: January 23, 2022                            *
 * Date Last Modified: January 26, 2022                      *
 * Description: The function reads the data from             *
 *              the FitbitData file, get of line that do     *
                not contain the target, dedupe any entries   *
 *              that appear multiple times.                  *
 * Input parameters: An input file pointer, infile and       *
                      an array of Fitbitdata.                *
 * Returns: Nothing.                                         *
 * Preconditions: The input file and output file must        *
                    already be open.                         *
 *************************************************************/
 void read_data_dedupe(FILE* infile, FitbitData data[SIZE]);


/****************************************************************
    * Function: clean_data ()                                   *
    * Date Created: January 23, 2022                            *
    * Date Last Modified: January 26, 2022                      *
    * Description: The function clean the FitbitData.cvs        *      
    *              file and check for empty data and extra      *
    *              comma and change it with something else, so  *
    *              that all lines are filled with values after  *
    *              every comma.                                 *
    * Input parameters: An input file pointer, infile and       *
    *                   the file pointer, outfile.              *
    * Returns: Nothing.                                         *
    * Preconditions: The input files must already be            *
                      open.                                     *
    * Postconditions: The FitbitData.csv should be cleaned      *
                      and information of the clean data should  *
                      be stored(not printed) to the outfile.    *
    *************************************************************/      
void clean_data(FILE* infile, FitbitData data[SIZE]);



/******************
* Personal Code: *
******************/

/*************************************************************
  * Function: worst_sleep ()                                 *
  * Date Created: January 23, 2022                            *
  * Date Last Modified: January 25, 2022                      *
  * Description: The function calculates the longest          *
                 consecutive range of poor sleep.             *
  * Input parameters: array of Fitbitdata                     *
  * Returns: Nothing.                                         *
  * Preconditions: The input file must already be             *
                    open.                                     *
  *************************************************************/
PoorSleep worst_sleep(FitbitData data[SIZE]);

/*************************************************************
  * Function: print_results()                                 *
  * Date Created: January 18, 2022                            *
  * Date Last Modified: January 26, 2022                      *
  * Description: This function writes the output and clean    *
                 data in the outfile and prints them on the   *
                 screen.                                      *
  * Input parameters: The file pointer, outfile and array     *
                      of Fitbitdata.                          *
  * Returns: Nothing.                                         *
  * Preconditions: The input file and output file must        *
                     already be open. The data should be      *
                     clean.                                   *
  * Postconditions: The values indicated in the development   *
                    of the function are written to the        *
                    output file and screen. The new clean     *
                    data is also written in the Results.csv   *
                    file and screen.                          *
  *************************************************************/
void print_results(FILE* outfile, FitbitData data[SIZE]);

/*************************************************************
  * Function: sum_calories_burned ()                          *
  * Date Created: January 16, 2022                            *
  * Date Last Modified:  January 21, 2022                     *
  * Description: This function calculates the                 *
  *                   total calories burned.                  *
  * Input parameters: Array of Fitbitdata.                    *
  * Returns: A double precision value.                        *
  * Preconditions: The input file must already be open.       *
  *************************************************************/
double sum_calories_burned(FitbitData data[SIZE]);

/*************************************************************
 * Function: sum_distance_walked ()                          *
 * Date Created: January 16, 2022                            *
 * Date Last Modified:  January 21, 2022                     *
 * Description: This function calculates the total           *
 *                   distance walked in miles.               *
 * Input parameters:  Array of Fitbitdata.                   *
 * Returns: A double precision value.                        *
 * Preconditions: The input file must already be open.       *
 *************************************************************/
double sum_distance_walked(FitbitData data[SIZE]);

/*************************************************************
 * Function: sum_floors_walked ()                            *
 * Date Created: January 16, 2022                            *
 * Date Last Modified:  January 21, 2022                     *
 * Description: This function calculates the                 *
 *                   total of the floor walked.              *
 * Input parameters:  Array of Fitbitdata.                   *
 * Returns: A integer value.                                 *
 * Preconditions: The input file must already be open.       *
 *************************************************************/
int sum_floors_walked(FitbitData data[SIZE]);

/*************************************************************
  * Function:  sum_steps_taken()                              *
  * Date Created: January 16, 2022                            *
  * Date Last Modified:  January 21, 2022                     *
  * Description: This function calculates                     *
  *                  the total steps taken                    *
  * Input parameters:  Array of Fitbitdata.                   *
  * Returns: A integer value.                                 *
  * Preconditions: The input file must already be open.       *
  *************************************************************/
int sum_steps_taken(FitbitData data[SIZE]);

/*************************************************************
  * Function: average_heartrate ()                            *
  * Date Created: January 16, 2022                            *
  * Date Last Modified:  January 21, 2022                     *
  * Description: This function calculates the                 *
  *       average heartrate over the 24 hour period           *
  * Input parameters:  Array of Fitbitdata                    *
  * Returns: A double precision value.                        *
  * Preconditions: The input file must already be open.       *
  *************************************************************/
double average_heartrate(FitbitData data[SIZE]);

/*************************************************************
  * Function: max_steps_taken ()                              *
  * Date Created: January 16, 2022                            *
  * Date Last Modified: January 21, 2022                      *
  * Description: This function calculates the maximum         *
  *    steps taken in one minute over the 24 hour period.     *
  * Input parameters: Array of Fitbitdata                     *
  * Returns: A integer value.                                 *
  * Preconditions: The input file must already be open.       *
  *************************************************************/
int max_steps_taken(FitbitData data[SIZE]);

#endif 
