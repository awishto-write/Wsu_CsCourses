#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;


template <class A, class B>
class BST
{
private:

	BSTNode<A, B>* pRoot;
	
         // This function that adds an item to the BST. Recall the properties of a BST. The values in any left subtree are less than 
	//its parent node,and any values in the right subtree are greater than its parent node. Using recursion.
	//void insert_N(const A& newText, const B& newMorse_code, BSTNode <A, B>* pTree);
	void insert_N( A& newText, B& newMorse_code, BSTNode <A, B>* pTree);
	
	     // This function which is called from the destructor to delete each node in the the tree by postorder traversal.
	void destroyTree(BSTNode <A, B>* pTree);
	
	     // This function prints the contents of the BST inorder using recursion.
	void Print_inOrderT(BSTNode<A, B>* pTree);



public:

	    //Constructor
	BST(BSTNode<A, B>* newpRoot = nullptr);

	   //Destructor  // This function calls the function "destroyTree()" from the private
	~BST();

	    // Getter
	BSTNode<A, B>* getpRoot();

	    // Setter
	void setpRoot(BSTNode<A, B>* newpRoot);

	   // This function calls the function "insert_N()" from the private
	//void insert(const A& newText, const B& newMorse_code);
	void insert( A& newText, B& newMorse_code);

	   // This function calls the function "Print_inOrderT()" from the private
	void Print_inOrder();

	  // This function that will return the Morse code string for each English character searched for. Using recursion
	B searches(BSTNode < A, B>* pRoot,  A character_to_search);
};

        //This function uses an extraction operator, it is used to be able
		         // to read the "MorseTable.txt" file and "Convert.txt" file  
//  -----------     Non-Member Function     ------------//     

template <class A, class B>
fstream& operator >> (fstream& res, BST <A, B> & sol)      //ifstream
{
	A text;
	B morse_code;

	while (!res.eof())
	{
		res >> text;
		res >> morse_code;

		sol.insert(text, morse_code);     
	}
		return res;
}

// ----------     End of Non-Member Function    ------------//

template <class A, class B>
BST<A, B> :: BST(BSTNode<A, B>* newpRoot)
{
	this->pRoot = newpRoot;
}

template <class A, class B>
void BST<A, B> :: setpRoot(BSTNode<A, B>* newpRoot)
{
	this->pRoot = newpRoot;
}

template <class A, class B>
BSTNode<A, B>* BST<A, B> :: getpRoot() 
{
	return this->pRoot;
}

template <class A, class B>
void BST<A, B> :: insert (A& newText, B& newMorse_code)
{
	insert_N (newText, newMorse_code, this->pRoot);   
}


template <class A, class B>
void BST <A, B> ::insert_N( A& newText, B& newMorse_code, BSTNode <A, B>* pTree)        // To change everything
{
	      //Base Case
	if (pTree == nullptr)
	{
		this->pRoot = new BSTNode <A, B> (newText, newMorse_code);   // Making a new node  
	}

	else            
	{
		// Comparison of what we have to what we will get or want to be changed

		if (pTree->text < newText)    

		{      // The right side of the tree
			if (pTree->pRight == nullptr)
			{
				// We insert the node now
				pTree->pRight = new BSTNode <A, B>(newText, newMorse_code);
			}

			else       // We continue to progress down the right subtree
			{
				// Recursive step     // Call of the other "insert" function
				insert_N(newText, newMorse_code, pTree->pRight);
			}

		}

		else if (newText < pTree->text)      
		{
			// The left side of the tree
			if (pTree->pLeft == nullptr)
			{
				// We insert the node now
				pTree->pLeft = new BSTNode <A, B>(newText, newMorse_code);
			}

			else
			{
				// Recursive step down the left subtree
				insert_N(newText, newMorse_code, pTree->pLeft);
			}
		}
	}
}

template <class A, class B>
void BST<A, B> ::destroyTree(BSTNode <A, B>* pTree)      
{

	if (pTree != nullptr)
	{
		destroyTree(pTree->getpLeft());  // destroys all the ones on the left an don the right
		destroyTree(pTree->getpRight()); 
		delete pTree;
	}
}

template <class A, class B>
BST <A, B> :: ~BST()                 
{
	destroyTree(this->pRoot);     // calls destroyTree()
}

template <class A, class B>
void BST<A, B>::Print_inOrder()          
{
	Print_inOrderT(this->pRoot);     // calls Print_inOrderT()
}

template <class A, class B>
void BST<A, B>::Print_inOrderT(BSTNode<A, B>* pTree)     // Printing the tree
{
	     // left, process data, right

	if (pTree != nullptr)                 // Getting access of the values
	{
		Print_inOrderT(pTree->getpLeft());
		cout << "The character: " << pTree->getText();
		cout << "  has for morse code: " << pTree->getMorse_code() << endl;
		Print_inOrderT(pTree->getpRight());
	}

}

template <class A, class B>
B BST < A, B> ::searches(BSTNode < A, B>* pRoot, A character_to_search)
{
	B code;

	if (pRoot == nullptr)
	{
		cout << "The search was unsuccessful!" << endl;
		return nullptr;
	}

	if (pRoot != nullptr)
	{

	    if (character_to_search == pRoot->getText())
	    {
		   code = pRoot->getMorse_code();                         // Match the character we are searching for
		  return code;
	    }

		else if (character_to_search < pRoot->getText())
		{
			code = searches(pRoot->getpLeft(), character_to_search);     // Traverse the “left” subtree recursively
			return code;
		}

		else
		{
			code = searches(pRoot->getpRight(), character_to_search);   //  Traverse the “right” subtree by recursively
			return code;
		}

	}

}
