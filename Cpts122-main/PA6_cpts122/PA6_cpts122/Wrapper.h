#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "BSTNode.h"
#include "BST.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ostream;
using std::fstream;
using std::string;

template <typename A, typename B >  // <class A, class B>

class Wrapper
{

public:

	                // Constructor
	     //This function opens the "MorseTable.txt" and "Convert.txt" files for reading
	Wrapper();

	     // Destructor
	~Wrapper();

	      // This function reads information from "Convert.txt" file and print it to the sc reen
	void print_ConvertInfo_fromFile();

	    // This function runs the program
	void runApp();

	   // This function converts the sentences in English and convert them into Morse Code
	void convertion(BST<A, B>& dTree);
	

private:

	fstream read_morse;
	fstream convert_morse;

};

template <typename A, typename B>  // <class A, class B>
Wrapper <A, B> ::Wrapper()
{
	// Opening of the files For reading

	read_morse.open("MorseTable.txt");
	convert_morse.open("Convert.txt");
}

template <typename A, typename B>  
Wrapper <A, B> :: ~Wrapper()
{
	// It does nothing    

}

template <typename A, typename B>
void Wrapper <A, B> :: print_ConvertInfo_fromFile()
{
	string to_use = " ";

	while (!convert_morse.eof())
	{
		 // Print the sentence in english

			getline(convert_morse, to_use, '\n');
			cout << to_use << endl;
	}

} 

template <typename A, typename B>  
void Wrapper <A, B> :: convertion(BST<A, B>& dTree)
{
	string again = " ";
    char text_to_convert = '\0';
	auto proot = dTree.getpRoot();

	convert_morse.close();
	convert_morse.open("Convert.txt");

	while (!convert_morse.eof())
	{
		        // Proceed

		convert_morse.get(text_to_convert);
		text_to_convert = toupper(text_to_convert);  // conversion into upper case

		if (text_to_convert != '\n' && text_to_convert != ' ')
		{
			again = dTree.searches(proot, text_to_convert);    // Searching
			cout << again << " ";
		}

		else    // When it is a new line, print a new line
		{
			cout << endl;
		}

	}

}

template <typename A, typename B>  // <class A, class B>
void Wrapper <A, B> ::runApp()
{
	BSTNode<A, B>* proot;
	BST <char, string> dTree;     //BST < A, B> dTree;
	proot = dTree.getpRoot();

	                        // Printing the Tree
	cout << "    The tree will be printed below   " << endl << endl;
	if (read_morse.is_open())     
	{
		read_morse >> dTree;           // Read
		dTree.Print_inOrder();          //print the tree    
		cout << endl << endl;
	}

	cout << "  Please, press once the key 'ENTER/ RETURN' to continue! " << endl;
	getchar();
	system("cls");

	                   // Print the sentences from the the file MorseTable.txt file
	cout << "     In English the sentences in the Convert.txt file will be displayed!  " << endl << endl;
	print_ConvertInfo_fromFile();
	cout << endl;

	                      // Convertion of the sentence into Morse Code
	cout << "      The Morse Code of the sentences above will be displayed below: " << endl << endl;
	proot = dTree.getpRoot();
	 convertion(dTree);   
	 cout << endl;

	convert_morse.close();          // Closing the file Convert.txt
	read_morse.close();       // Closing the file MorseTable.txt  

}

           