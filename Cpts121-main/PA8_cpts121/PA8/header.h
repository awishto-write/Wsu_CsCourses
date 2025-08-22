#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct occurrences
{
    int num_occurrences;
    double frequency;

} Occurrences;
 
  
char* my_str_n_cat(char* ptr_dest, char* ptr_src, int n);  // Question 1  

int binary_search(int sorted_int [], int target, int size);   // Question 2

void bubble_sort(char* pointer_array[], int num_strings);  // Question 3 

int is_palindrome(char* ptr_string, int length);    // Question 4  
int help_is_palindrome(char* ptr_string, int lenght, int shift);   // Question 4     

int help_sum_primes(unsigned int n, int sum, int index);    // Question 5     
int sum_primes(unsigned int n); // Question 5   

void maximum_occurences(char* ptr_string, Occurrences* ptr_struct, int* ptr_n, char* ptr_char);   //Question 6

                                                                                               //Question 7
void max_consecutive_integers(int arr[][5], int** start_max_consec_point, int* num_same_consec_point, int num_rows, int num_cols,int *count);


