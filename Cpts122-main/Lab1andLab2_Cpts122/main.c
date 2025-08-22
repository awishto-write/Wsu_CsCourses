/*******************************************************************************************
* Programmer: Naomi Dion-Gokan                                                             *
* Class: CptS 122, Spring 2022; Lab Section 11                                             *
* Programming Assignment: Lab 1&2                                                          *
* Date: January 27, 2022                                                                   *
* Description:  Task 1: This program prints out a simple "hello world" message.            *
                Task 2: Design, implement, compile, and test Csolutions                    *
                to the following problems.                                                 *
*******************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include "header.h"

int main(void)
{
    //(*str, count);
    

                        // Task 2

    //        // solution 1

    char a[] = "absdf";
    char b[] = "fggjh";

    char* arr = mergeAndSort(a,b);
    //printf("%s\n", arr);
    sort(arr, 10);
    printf("%s\n", arr);

          // solution 2


    return 0;
}