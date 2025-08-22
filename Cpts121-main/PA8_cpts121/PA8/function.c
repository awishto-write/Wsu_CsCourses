#include "header.h"

           // 1. Copy n characters from source to destination

char* my_str_n_cat(char* ptr_dest, char* ptr_src, int n)
{
	int counter = 0;
	int count_n = 0;

	while (*ptr_dest != '\0')
	{
		counter++;
		*ptr_dest++;
		
	}

	const int size = counter + n; //Gets the overall size of both strings together

	for (int i = 0; i < n; i++) 
	{
		if (*ptr_src == '\0') 
		{
			break;
		}
		else 
		{
			*ptr_dest = *ptr_src;
			ptr_dest++;
			ptr_src++;
			count_n++;
		}
	}


	ptr_dest = ptr_dest - (count_n + counter);

	return ptr_dest;

}
          // 2. Do a binary search

int binary_search(int sorted_int[], int target, int size)
{
	
	int n = size;
	int left = 0, right = n, target_index = -1, mid = 0, found = 0;

	while (found == 0 && left <= right)

	{ //loops through and cuts seach area in half each time
		mid = ((right + left) / 2);
		if (target == sorted_int[mid]) 
		{
			target_index = mid;
			found = 1;
		}
		if (target < sorted_int[mid]) 
		{
			right = mid - 1;
		}
		if (target > sorted_int[mid])
		{
			left = mid + 1;
		}
	}

	return target_index;
}

                 // 3. Do a bubble sort

void bubble_sort(char* pointer_array[], int num_strings)
{
	int U = num_strings;

	while ( U > 0)
	{ //for the amount of the data that isn't sorted, 
		int C = 1; //set the counter in the unsorted range to 1
		while (C < U)
		{  //and run while there is still unsorted data
			if (strcmp(pointer_array[C], pointer_array[C - 1]) < 0)
			{ //if the data to the right is less than the left, move the data upward
				char* temp = pointer_array[C];
				pointer_array[C] = pointer_array[C - 1];
				pointer_array[C - 1] = temp;
			}
			C++;
		}
		U--;
	}
}
          // 4. Determine if a string is palindrome recursively

int is_palindrome(char* ptr_string, int lenght) 
{
	return help_is_palindrome(ptr_string, lenght, 0); //call the recursive helper to complete the function
}

int help_is_palindrome(char* ptr_string, int lenght, int shift)
{
	if ( ((int)lenght / 2) == shift)
		return 1;

	char lowchar = ptr_string[ lenght- shift - 1]; 
	char uppchar = ptr_string[shift]; 

	//if one of the two characters is a space, skip the character
	if (lowchar == ' ')
		lowchar = ptr_string[lenght - shift - 2];
	else if (uppchar == ' ')
		uppchar = ptr_string[shift + 1];

	if (lowchar == uppchar) //check if the two characters are equal
		help_is_palindrome(ptr_string, lenght, shift + 1);
	else
		return 0; //if they don't match, it is not a palindrome.
}

                 // 5. Find sum of primes using recurssion    

int sum_primes(unsigned int n)
{
	return help_sum_primes(n, 0, 2) - 4; //values: sum starts at 0 and index starts at 2. Subtract 4 because result is always 4 over 
}

int help_sum_primes(unsigned int n, int sum, int index) 
{
	int prime_or_not = 0; 

	for (int i = 2; i < (index / 2); i++) //loop for all numbers under index
		if ((index % i) == 0) 
		{ //if it ever finds a value in which it can be evenly divided
			prime_or_not = 1; //set it to not prime
			break;
		}

	if (prime_or_not == 0) //it's prime
		sum += index; //add the index to the sum

	if (n == index) 
		return sum; 
	else
		help_sum_primes(n, sum, index + 1); //otherwise, add one to the sum and recurse
}

           // 6. Determine the frequency of each character found in the array.


void maximum_occurences(char* ptr_string, Occurrences* ptr_struct, int* ptr_n, char* ptr_char)
{
	int length = strlen(ptr_string); //gets length
	char letter = "\0";
	int max_char_index = -1;
	int max_count = 0;

	for (int i = 0; i < length; i++)
	{ //loops through string and sets all letters to l
		letter = tolower(ptr_string[i]);
		if (letter != ' ') 
		{ //tests for spaces
			letter -= 'a'; //subtracts ascii vales of a to get index values from 0-25
			ptr_struct[(int)letter].num_occurrences++; 
		}
	}
	for (int i = 0; i < 26; i++) 
	{
		ptr_struct[i].frequency = (ptr_struct[i].num_occurrences / length); //calculates frequency of each letter
		if (ptr_struct[i].num_occurrences > max_count) 
		{
			max_count = ptr_struct[i].num_occurrences; //find the max count of number
			max_char_index = i;
		}
	}

	*ptr_n = max_count; //returns max count and max letter thoguh pointers
	*ptr_char = (char)max_char_index + (int)'a';

	return;
}

               // 7. Bonus Question

void max_consecutive_integers(int arr[][5], int** start_max_consec_point, int* num_same_consec_point, int num_rows, int num_cols, int *count)
{
	int* start_pt2 = &arr[0][0];
	int* start_pt = 0, num_same_higher_consec_pt = 0;
	int temp = arr[0][0], counter = 1;
	
	for (int i = 0; i < num_rows; i++)
	{
		for (int j = 0; j < num_cols; j++)
		{

			if(temp == arr[i][j])
			{
				if (counter == 1 )
				{
					start_max_consec_point = &arr[i][j];
				}
				
				counter++;
				*num_same_consec_point = counter;
			
			}

			else
			{
				if (counter > num_same_higher_consec_pt)
				{
					num_same_higher_consec_pt = counter;
					start_pt = start_pt2;                      
					*count = counter;
				}
			

				counter = 1;
				temp = arr[i][j];
				start_pt2 = &arr[i][j];
				
			}

		}

		
	}

	*start_max_consec_point = &start_pt;

	printf("7. The integer that gets consecutively repeats the most is %d and the address where that integer occurs first is %d\n",
		*start_pt, start_pt);
	
}

