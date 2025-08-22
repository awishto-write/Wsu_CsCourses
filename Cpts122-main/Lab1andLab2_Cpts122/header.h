/*******************************************************************************************
* Programmer: Naomi Dion-Gokan                                                             *
* Class: CptS 122, Spring 2022; Lab Section 11                                             *
* Programming Assignment: Lab 1 & 2                                                        *
* Date: January 27, 2022                                                                   *
* Description:  Task 1: This program prints out a simple "hello world" message.            *  
                Task 2: Design, implement, compile, and test Csolutions                    *
                to the following problems.                                                 *
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  /* Needed for fscanf ( ), fprintf ( ), fopen ( ), etc. */
#include <math.h>	/* Needed for sqrt ( ) */
#include <stdlib.h> /* Needed for exit ( ) */
#include <string.h>
#include <stdbool.h>

      // Question a 
//void reverse_string(char p_str, int index, int size);    // did not call it in main yet

//char* myStrTok(char* str, const char* delim);

//char* new (char* arr1, char* arr2);
char* mergeAndSort(char* arr1, char* arr2);
int cmpstr(void const* a, void const* b);
void sort(char* str, int count);

char* mergeAndSort2(char* arr1, char* arr2);
