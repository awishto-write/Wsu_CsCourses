#include <iostream>
#include <array>

using std::array;

    // typename T
//template <typename Type, size_t Size>
//void mergeSortLast(array <Type, Size>& array)

template <typename Type, size_t Size>
void merge(array <Type, Size>& array, int startIndex, int endIndex, int middleIndex)
{
	//int startIndex, endIndex, middleIndex;
	 middleIndex = startIndex + endIndex / 2;

	int firstHalfLenght = middleIndex - startIndex + 1;
	int SecondHalfLenght = endIndex - middleIndex;

	      // Creation of some sort of temp variables
	int* firstHalf = new int firstHalfLenght;
	int *secondHalf = new int SecondHalfLenght;

	     // Adding data to to the temp variables
	for (int i = 0; i < firstHalfLenght; i++)
		firstHalf <int, i> = array<int, i>;

	for (int i = 0; i < SecondHalfLenght; i++)
		secondHalf <int, i> = array<int, i>;

	     // Continuation of the process
	int a = 0, b= 0, c = startIndex;
	for (; a < firstHalfLenght && b < SecondHalfLenght; c++)
	{
		if (firstHalf < SecondHalf)
		{
			array<int, c> = firstHalf <int, a++>;
		}
		else  // firstHalf >  SecondHalf
		{
			array<int, c> = secondHalf <int, b++>;
		}
	}

	    // Dealing with the rest of the elements
	for (; a < firstHalfLenght; a++, c++)
	{
		array<int, c> = firstHalf <int, a>;
	}
	
	for (; b < SecondHalfLenght; b++, c++)
	{
		array<int, b> = firstHalf <int, a>;
	}

}


template <typename Type, size_t Size>
void mergeSort1(array <Type, Size>& array, int startIndex, int endIndex)
{
	if (startIndex < EndIndex)
	{
		int middleIndex = startIndex + endIndex / 2;
		mergeSort1(array, startIndex, middleIndex );
		mergeSort1(array, middleIndex +1, endIndex);
		
		merge(array, startIndex, endIndex, middleIndex);
	}

}


int main(void)
{

	array <int, 7> arrayToSort( { 23,42,7,10,8,12,21 } );
	//mergeSort(arrayToSort, )


	return 0;
}

