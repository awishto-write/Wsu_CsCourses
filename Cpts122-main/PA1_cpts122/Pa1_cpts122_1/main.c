/********************************************************************************
 * Programmer: Naomi Dion-Gokan                                                 *
 * Class: CptS 122; Lab Section 11                                              *
 * Programming Assignment: PA 1                                                 *
 * Date Created: January 15, 2022                                               *
 * Date Last Modified: January 30 ,2022                                         *
 * Description: This program will evaluate 24 hours of data from Fitbit's       *
 *              patients. It will filter any data that is not related to        *
 *              the given target patient. It will also dedupe any entries       *
 *              hat appear multiple times and perform data cleansing any        *
 *              entries that have missing fields.                               *
 *******************************************************************************/

#include "header.h"

int main(void)
{
	// Innitialization of the FitbitData Array
	FitbitData data[1442] = { 0 };
	//FitbitData data[1442] = { " "," ", 0.0,0.0,0,0,0,NONE};
	

	FILE* infile = NULL, * outfile = NULL;

	// Opening of the files
	infile = fopen("FitbitData.csv", "r");
	outfile = fopen("Results.csv", "w");

	
	// Read data, get of line that do not contain the target, dedupe any entries that appear multiple times.
	read_data_dedupe(infile, data);

	// Cleaning the data
	clean_data(infile, data); 
   

	//Calculations 
	double totalCalories = sum_calories_burned(data);
	double totalDistance = sum_distance_walked(data);
	int totalSteps = sum_steps_taken(data);
	int totalFloors = sum_floors_walked(data);
	double avgHeart = average_heartrate(data);
	int maxstep = max_steps_taken(data);
	PoorSleep worstsleep = worst_sleep(data);

	
	// Close the infile
	fclose(infile);

	// To print the output and clean data on the screen and in the outfile
	print_results(outfile, data);

	// Closing the outfile
	fclose(outfile);

	return 0;
}