// Naomi Dion-Gokan
// 11/30/21
// CPT-S 121
// Programming Assignment 8
// This program will evaluate and solve different problems

#include "header.h"

int main(void)
{
	                       // Question 1

	char str1 [25] = "Like";    // destination
	char str2 [20]= "PA8";    //source
	printf("1. %s\n", my_str_n_cat(str1, str2, 2) ); // Print LikePA

	char str3 [40] = "Cpts121";     //destination
	char str4 [30] = "fascination";     //source
	printf("1. %s\n\n", my_str_n_cat(str3, str4, 5)); // Print Cpts121fasci


	               // Question 2 

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int list_size = sizeof(arr);
	
	printf("2. %d\n", binary_search(arr,7, 9)); //Returns 6 after performing a binary search for 7

	int arr2[] = { 11, 12, 13, 14, 15};
	int list_size2 = sizeof(arr2) / sizeof (arr2[0]);

	printf("2. %d\n\n", binary_search(arr2, 13, list_size2)); //Returns 2 after performing a binary search for 13
	                                                         // Index of 13


	                      // Question 3

	char* strings[] = {"yatch", "angel", "ballon", "zebu"};
	bubble_sort(strings, 4);
	printf("3.");
	for (int i = 0; i < 4; i++)
	{
		printf(" %s", strings[i]);
	}
	printf("\n");

	char* strings2[] = { "mouse", "phone", "computer", "can" , "pencil", "marker", "table"};
	bubble_sort(strings2, 7);
	printf("3.");
	for (int i = 0; i < 7; i++)
	{
		printf(" %s", strings2[i]);
	}
	printf("\n\n");

	                            // Question 4     

	char* noun = "race car";    //sample string

	if (is_palindrome(noun, 8) == 1) //If it is a palindrome
		printf("4. %s is a palindrome.\n", noun); 
	else 
		printf("4. %s is not a palindrome.\n", noun); //print it is not a palindrome
	   
	     //check this one
	char* noun2 = "white snow";      //sample string
	if (is_palindrome(noun2, 10) == 1) 
		printf("4. %s is a palindrome.\n", noun2);
	else
		printf("4. %s is not a palindrome.\n\n", noun2);


	                      //  Question 5

	unsigned int maximum = 10;
	printf("5. The sum of primes is %d\n", sum_primes(maximum));

	unsigned int maximum2 = 20;
	printf("5. The sum of primes is %d\n\n", sum_primes(maximum2));
	

	                    // Question 6
	                                         
	                                               //example 1, do I need to add a size to the array?
	char string_count[] = "notebook", letter = "\0";      // for a word like eating, how will it work?
	int count = 0;
	Occurrences alphabet[26] = { {0,0} };  


	printf(" 6. String to analyze: %s\n", string_count); 
	maximum_occurences(&string_count, &alphabet, &count, &letter); //analyzes the string and outputs with pointers 
	printf("Most common letter: %c\n", letter); //prints most common letter and count of that letter from a-z
	printf("Num occurrences: %d\n\n", count);
	 
	                                              // example 2

	char string_count2[] = "constitutional institutions", letter2 = "\0";      
	int count2 = 0;
	Occurrences alphabet2[26] = { { 0,0 } };     
	printf(" 6. String to analyze: %s\n", string_count2);
	maximum_occurences(&string_count2, &alphabet2, &count2, &letter2);
	printf("Most common letter: %c\n", letter2); 
	printf("Num occurrences: %d\n\n", count2);


	                     // Question 7

	int array[4][5] = { { -5, 6, 0, 2, 2 }, { 2, 2, 2, 9, 3 }, { 3, 3, 2, 1, -8 }, { 7, -2, 6, 0, 4} };
	int start_max_consec_point = 0, num_same_consec_point = 0, count3 = 0;
	
	max_consecutive_integers(array, &start_max_consec_point, &num_same_consec_point, 4, 5, &count3);


	printf(" 7. That number occurs %d times\n", count3);

	return 0;
}

