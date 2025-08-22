/********************************************************************************
 * Programmer: Naomi Dion-Gokan                                                 *
 * Class: CptS 122; Lab Section 11                                              *
 * Programming Assignment: PA 1                                                 *
 * Date Created: January 15, 2022                                               *
 * Date Last Modified: January 29 ,2022                                         *
 * Description: This program will evaluate 24 hours of data from Fitbit's       *
 *              patients. It will filter any data that is not related to        *
 *              the given target patient. It will also dedupe any entries       *
 *              hat appear multiple times and perform data cleansing any        *
 *              entries that have missing fields.                               *
 *******************************************************************************/


#include "header.h"

 // Read the data

void read_data_dedupe(FILE* infile, FitbitData data[SIZE])
{
	
	int lineCount = 0;

	char line[256] = " ";    // empty string line[0] = '\0'    
	char* temp;    //  temp information holder
	char target[256] = " ";			   // getting the target id for dynamic use

	fgets(line, 256, infile);     // Skip the first header line

	temp = strtok(line, ",");
	temp = strtok(NULL, ",");

	strcpy(target, temp);      // target 

	 char dump[256] = " ";
	fgets(dump, 256, infile);

	//can't read anymore lines of data; fgets () returns
	// NULL pointer
	while (!feof(infile))    
	{
		fgets(line, 256, infile);
		temp = strtok(line, ",");

		// patient
		strcpy(data[lineCount].patient, temp);
		strcpy(dump, strtok(NULL, ","));

		// Check for data entry that has the same ID has the target patient and have a duplicate time
		if( (strcmp(target, data[lineCount].patient) == 0) && (lineCount == 0 || strcmp(dump, data[lineCount - 1].minute) != 0))
		{
			                                // Reading of the struct
			// minute
			strcpy(data[lineCount].minute, dump);

			// calories
			temp = strtok(NULL, ",");
			data[lineCount].calories = atof(temp);

			// distance
		    temp = strtok(NULL, ",");
			data[lineCount].distance = atof(temp);

			// floors
			temp = strtok(NULL, ",");
			data[lineCount].floors = atoi(temp);

			// heartrate                            
			temp = strtok(NULL, ",");
			data[lineCount].heartRate = atoi(temp);

			// steps
			temp = strtok(NULL, ",");
			data[lineCount].steps = atoi(temp);

			//sleep level
			//temp = strtok(NULL, " ");        
			data[lineCount].sleepLevel = atoi(temp);

			lineCount++;
		}

	}
}



                     // Clean the data

void clean_data(FILE* infile, FitbitData data[SIZE])  
{

	char line[150] = " ", line_edited[150] = " ";
	char temp4 = '\0', temp5 = '\0';        
	char* temp;
	temp = strtok(NULL, ",");

	fgets(line, 150, infile);      // get the first header line      
	
	while (!feof(infile))
	{
		fgets(line, 150, infile);   // skips the second line
		strcpy(line_edited, line); // preserve the original line

		int size = strlen(line_edited);

		if (line_edited[size - 2] == ',')   
		{
			line_edited[size - 1] = '0';      
			line_edited[size] = '\0';
		}

		temp4 = '\0';
		temp5 = '\0';


		for (int x = 0; line_edited[x + 1] != '\0'; x++)     
		{
			
		    if (line_edited[x] == ',' && line_edited[x + 1] == ',')
			{
				temp4 = line_edited[x + 1];

				for (int i = x + 1; i < size; i++)
				{
					temp5 = line_edited[i + 1];
					line_edited[i + 1] = temp4;
					temp4 = temp5;
				}

				line_edited[x + 1] = '0';
			}
		}  
	}
}

// Calculates the total calories burned.

double sum_calories_burned(FitbitData data[SIZE])
{
	double cal = 0;

	for (int i = 0; i < SIZE; i++)
	{
		cal += data[i].calories;
	}

	return cal;
}

// Calculate the sum of the distance walked

double sum_distance_walked(FitbitData data[SIZE])
{
	double dis = 0;

	for (int i = 0; i < SIZE; i++)
	{
		dis += data[i].distance;
	}

	return dis;
}

// Calculate the sum of the distance walked.

int sum_floors_walked(FitbitData data[SIZE])
{
	int flo = 0;

	for (int i = 0; i < SIZE; i++)
	{
		flo += data[i].floors;
	}

	return flo;
}

// Calculate the sum of the steps taken

int sum_steps_taken(FitbitData data[SIZE])
{
	int ste = 0;

	for (int i = 0; i < SIZE; i++)
	{
		ste += data[i].steps;
	}

	return ste;
}

// Calculate the average of heartrate

double average_heartrate(FitbitData data[SIZE])
{

	double total = 0.0;
	int i = 0, num = 0;


	while (i <= SIZE)
	{
		if (data[i].heartRate != 0)
		{
			total += data[i].heartRate;
			num++;
		}
		i++;
	}

	double average = total / num;

	return average;
}

// Calculate the maximum steps taken

int max_steps_taken(FitbitData data[SIZE])
{
	int maxsteps = 0, i = 0;

	while (i <= SIZE)
	{
		if (maxsteps <= data[i].steps)
		{
			maxsteps = data[i].steps;
		}
		i++;
	}
	return maxsteps;
}

// Calculate the longest consecutive range of poor sleep.

PoorSleep worst_sleep(FitbitData data[SIZE])
{
	PoorSleep current = { 0 };
	PoorSleep worst = { 0 };   

	for (int i = 0; i < SIZE; i++)   
	{
		
		if (data[i].sleepLevel > 1)    
		{ // to find the start point of the time to wake up
			
			//current.time_total = 0;
			strcpy(current.start_minute, data[i].minute);

			while (data[i].sleepLevel > 1)         
			{ 

				current.time_total += data[i].sleepLevel;  

			     i++;
			}
			
		     strcpy(current.end_minute, data[i - 1].minute);
		}

		if (current.time_total > worst.time_total)
		{ //compares current to the worst time

			worst.time_total = current.time_total;
			strcpy(worst.start_minute, current.start_minute);
			strcpy(worst.end_minute, current.end_minute);
			
		}
		
	}

	return worst;

}


				   // Printing the results and clean data to the screen and outfile

void print_results(FILE* outfile, FitbitData data[SIZE])
{

	PoorSleep sleep = worst_sleep(data);

	// Printing the output on the screen

	printf("Total Calories, Total Distance, Total Floors, Total Steps, Average heartrate, Max Steps, Sleep\n");
	printf("%lf, %lf, %d, %d, %.lf, %d, %s:%s\n", sum_calories_burned(data), sum_distance_walked(data), sum_floors_walked(data),
		sum_steps_taken(data), average_heartrate(data), max_steps_taken(data), sleep.start_minute, sleep.end_minute);


	// Printing the output in the outfile

	fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Average heartrate, Max Steps, Sleep\n");
	fprintf(outfile, "%lf, %lf, %d, %d, %lf, %d, %s:%s\n", sum_calories_burned(data), sum_distance_walked(data), sum_floors_walked(data),
		sum_steps_taken(data), average_heartrate(data), max_steps_taken(data), sleep.start_minute, sleep.end_minute);

	// Printing the new clean data to the screen and outfile

	fprintf(outfile, "Target: ,12cx7,,,,,,\n");
	fprintf(outfile, "Patient,minute,calories,distance,floors,heart,steps,sleep_level\n");
	printf("Target: ,12cx7,,,,,,\n");
	printf("Patient,minute,calories,distance,floors,heart,steps,sleep_level\n");

	for (int i = 0; i < 1440; i++)
	{
		fprintf(outfile, "%s,%s,%.9lf,%lf,%d,%d,%d,%d\n", data[i].patient, data[i].minute, data[i].calories, data[i].distance,
			data[i].floors, data[i].heartRate, data[i].steps, data[i].sleepLevel);
		printf("%s,%s,%.9lf,%lf,%d,%d,%d,%d\n", data[i].patient, data[i].minute, data[i].calories, data[i].distance,
			data[i].floors, data[i].heartRate, data[i].steps, data[i].sleepLevel);
	}



}

