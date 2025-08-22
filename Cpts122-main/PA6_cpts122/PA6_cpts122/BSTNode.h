#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

    template <class A, class B>

class BSTNode
{
  private: 
    A text;
    B morse_code;
    BSTNode<A,B>* pLeft;    // Child pointer to BSTNode class
    BSTNode<A,B>* pRight;    // Child pointer to BSTNode class
          
  public:
      template <class A, class B>
     friend class BST;       

       // Constructor
         BSTNode( A& newText, B& newMorse_code);

         //Destructor
         ~BSTNode();

         // Setters
         void setLeft(BSTNode<A, B>*  newpLeft);
         void setRight(BSTNode<A, B>* newpRight);
         void setText(A& newText);
         void setMorse_code(B& newMorse_code);

         // Getters
         BSTNode<A, B>* getpLeft();
         BSTNode<A, B>* getpRight();
         A getText();
         B getMorse_code();
};


   template < class A, class B >
  BSTNode<A, B> :: BSTNode( A& newText, B& newMorse_code )
{
   this->pLeft = nullptr;
   this->pRight = nullptr;
   this->text = newText;      // Assignment operator of type A
   this->morse_code = newMorse_code;    // Assignment operator of type B
}

template < class A, class B >
void BSTNode <A, B> ::setLeft(BSTNode <A, B>*  newpLeft)
{
    this->pLeft = newpLeft;
}

template <class A, class B>
void BSTNode <A, B> ::setRight(BSTNode<A, B>* const newpRight)
{
    this->pRight = newpRight;
}

template <class A, class B>
void BSTNode<A, B> :: setText( A& newText)
{
    this->text = newText;
}

template <class A, class B>
void BSTNode <A, B> :: setMorse_code( B& newMorse_code)
{
    this->morse_code = newMorse_code;
}

template <class A, class B>
BSTNode<A, B>* BSTNode <A, B> :: getpLeft() 
{
    return this->pLeft;
}

template <class A, class B>
BSTNode<A, B>* BSTNode <A, B> ::getpRight() 
{
    return this->pRight;
}

template <class A, class B>
A BSTNode <A, B> :: getText() 
{
    return this->text;
}

template <class A, class B>
B BSTNode <A, B> :: getMorse_code() 
{
    return this-> morse_code;
}

template <class A, class B>
BSTNode <A, B> :: ~BSTNode()
{
      //  It does nothing
}