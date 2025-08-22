#include "header.h"

         //  Question a

//void reverse_string(char p_str[], int index, int size)
//{
//	char temp;
//	temp = p_str[index];
//	p_str[index] = p_str[size - index];
//	p_str[size - index] = temp;
//
//	// base case- the middle letter will be the same thus complete
//	if (index == size / 2)
//	{
//		return;
//	}
//
//	reverse_string(p_str, index + 1, size);
//}

       
// Question c
                            // Solution 1
char* mergeAndSort (char* arr1, char* arr2)
{

    // array 1 has 5 characters: a, a, a, b, b
    // array 2 is has 5 characters: b, b, c, a, c
    // New array (array 3) will be of size 11(+ a null character), in alphabetic order: a, a, a, a, b, b, b, b, c, c
          
    char arr3[11];

    // copy whatever in the first item of arr 1 into arr 3
    //arr3[0] = arr1[0];
    //arr3[1] = arr1[1];
    //arr3[2] = arr1[2];

    // "            " of arr2 into arr3
    //arr3[5] = arr2[0];
    //arr3[6] = arr2[1];
    //arr3[7] = arr2[2];

    for (int i = 0; i < 5; i++)
    {
        arr3[i] = arr1[i];
    }

    for (int i = 0; i < 5; i++)
    {
        arr3[i+5] = arr2[i];
    }

    // arr3[i]
    sort(arr3, 10);

    return arr3;
}

     // compare the string
int cmpstr(void const *a, void const *b)
{
    char* aa = (char const* )a;
    char* bb = (char const* )b;

    return strcmp(aa, bb);

}

    // sort
void sort(char* str, int count) 
{
    qsort(str, count, sizeof(str[0]), cmpstr);
}


                         // solution 2
char* mergeAndSort2(char* arr1, char* arr2)
{
       //char* arr3[11];
   char*arr3 = calloc(11, sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        arr3[i] = arr1[i];
        arr3 = realloc(arr3, 15*sizeof(char));
    }

    for (int i = 0; i < 5; i++)
    {
        arr3[i + 5] = arr2[i];
        arr3 = realloc(arr3, 15 * sizeof(char));
    }

    // arr3[i]
   // sort(arr3, 10);

    return arr3;
}

//void* realloc(void* ptr, size_t new_size)
//{
//
//}



























