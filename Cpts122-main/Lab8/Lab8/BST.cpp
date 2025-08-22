#include "BST.h"


BST::BST(Node* newProot)
{
	this->root = newProot; // pointer assignment
}


//void BST::insertNode(const Node& data)
//{
//	insert(this->root, data);
//}

void BST::insert(const Node& data)
{
	insertNode(this->root, data);
}

void BST::insertNode(Node* pTree, const Node &newData)
{

	if (pTree == nullptr) // base case - empty tree
	{
		this->root = new Node(newData); 
	}

	else                    //ptree has a pointer(*)  so I used (->) below
		                    //newData does have a pointer, so I use (.)
	{
		if (newData.getData() > pTree->getData())         // Superior values   // Right side
		{
			if (pTree->getRightPtr() == nullptr)
			{
				pTree->setRightPtr(new Node (newData));         
			}
			   
			else  {                     // call the recursive function
				      insertNode(pTree->getRightPtr(), newData);
			       }

		}


		if (newData.getData() < pTree->getData())              // Inferior values   // Left Values
		{
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new Node(newData));
			}

			else {                      // call the recursive function
				     insertNode(pTree->getLeftPtr(), newData);
			      }
		}

	}
}

void BST :: inOrderTraversal()
{
	inOrderTraversal(this->root);
}

void BST :: inOrderTraversal(Node* pTree)
{
	// Left, data, right

	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeftPtr());     //Left
		pTree->getData();      // Data
		inOrderTraversal(pTree->getRightPtr());      // Right
	}
}

void BST :: PreOrderTraversal()
{
	PreOrderTraversal(this->root);
}

void BST :: PreOrderTraversal(Node* pTree)
{
	  // Data, left, right

	if (pTree != nullptr)
	{
		pTree->getData();             // Data                                               
		PreOrderTraversal(pTree->getLeftPtr());    //Left
		PreOrderTraversal(pTree->getRightPtr());          // Right
	}
}

void BST :: PostOrderTraversal()
{
	return PostOrderTraversal(this->root);
}

void BST :: PostOrderTraversal(Node* pTree)
{
	// Left, right, data

	if (pTree != nullptr)
	{
		PostOrderTraversal(pTree->getLeftPtr());     // Left
		PostOrderTraversal(pTree->getRightPtr());              //  Right
		pTree->getData();       // Data
	}
}


