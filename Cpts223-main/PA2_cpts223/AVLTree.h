//
// Created by sherryl Dion-Gokan on 10/10/22.
//

#ifndef PA2_CPTS223_AVLTREE_H
#define PA2_CPTS223_AVLTREE_H

#include "AVLNode.h"

using namespace std;
#include <iostream>

template <typename T>

class AVLTree {

protected:
    AVLNode<T> *_root;         // Root of the tree nodes

    // Helper Function for the destructor, destroy all nodes recursively
    void destructor_Helper(AVLNode<T>* root);

      // Return height of tree (root == nullptr -> 0)
    //int heightHelperTree(AVLNode<T>* root);

    // Helper Function for the function contains(), it checks if a value is in the tree
    //int containsHelper(T value, AVLNode<T>* root);

    int height_tree(AVLNode<T> *tree);

    //void insert(const T &value, AVLNode<T>* &x);

    void insert_T(const T & value, AVLNode<T>* & node);

    void preOrder_display(AVLNode<T>* &tree);

public:
        // Constructor
    AVLTree();

        // Destructor
    ~ AVLTree();

    int height_tree_p() ;

   // it checks if a value is in the tree
    bool contains(const T & value);

    AVLNode<T>* rotateWithRightChild(AVLNode<T>* &k1);

    AVLNode<T>* rotateWithLeftChild(AVLNode<T>* &k2);

   // void insert(const T &value, AVLNode<T>* &x);   // Constant T?

    AVLNode<T>* doubleWithLeftChild(AVLNode<T>* &node);

    AVLNode<T>* doubleWithRightChild(AVLNode<T>* &node);

    void balance(AVLNode<T>* &tree);

    bool is_tree_balanced(AVLNode<T>* &tree);

    bool validate();

    // Insert
    void insert(const T &value);

    void preOrder_display_T();

    //void insert_T(const T &value, AVLNode<T>* &node);

   // AVLTree<T>* getRoot();

};

//template <typename T>
//AVLTree<T>* AVLTree<T> :: getRoot()
//{
//    return _root;
//}

template <typename T>
void AVLTree<T> :: preOrder_display_T()
{
    preOrder_display(this->_root);
}

template <typename T>
void AVLTree<T> :: preOrder_display(AVLNode<T>* &tree)
{
    if(tree != nullptr)
    {
        cout << tree->data << " ";
        preOrder_display(tree->left);
        preOrder_display(tree->right);
    }
}

template <typename T>
void AVLTree<T> :: insert_T(const T &value, AVLNode<T>* &node)
{
    if(node == nullptr)
    {
        node = new AVLNode<T> (value);
        node->node_height = 0;
    }

    else if(value > node->data) {
        insert_T(value, node->right);
    }

    else if (value < node->data)
    {
        insert_T(value, node->left);
    }

    balance(node);
}

template <typename T>
bool AVLTree<T> :: is_tree_balanced(AVLNode<T>* &tree)
{
    if(tree == nullptr)
        return 1;
    if(abs(height_tree(tree->left) - height_tree(tree->right)) <= 1)
    {
        return is_tree_balanced(tree->right) && is_tree_balanced(tree->left);
    }
    is_tree_balanced(tree);

    return 0;
}

template <typename T>
bool AVLTree<T> :: validate()
{
    return is_tree_balanced(this->_root);
}

template <typename T>
void AVLTree<T> :: balance(AVLNode<T>* &tree)
{
    if(tree == nullptr)
        return;
    if(height_tree(tree->left)- height_tree(tree->right) > 1)
    {
        if(height_tree(tree->left->left) >= height_tree(tree->left->right) )
            tree = rotateWithRightChild(tree);
        else
            tree = doubleWithRightChild(tree);
    }

    if(height_tree(tree->right)- height_tree(tree->left) > 1)
    {
        if(height_tree(tree->right) >= height_tree(tree->right->left) )
            tree = rotateWithLeftChild(tree);
        else
            tree = doubleWithLeftChild(tree);
    }

    tree->node_height = max(height_tree(tree->left), height_tree(tree->right)) + 1;
}

// Return the height of the node r - 1 if null
template <typename T>
int AVLTree<T> :: height_tree(AVLNode<T> *tree)
{
    return tree == nullptr ? -1 : tree->node_height;
}

template <typename T>
AVLTree<T> :: AVLTree()
{
    _root = nullptr;
}

template <typename T>
void AVLTree<T> :: insert(const T & value)
{
    //this->_root = insert_T(value,_root);
    insert_T(value,_root);
}

template <typename T>
AVLTree<T>:: ~AVLTree()
{
    destructor_Helper( _root);
}

template <typename T>
int AVLTree<T>::height_tree_p() {
    if(_root == nullptr)
        return -1;
    return height_tree(this->_root);
}


template <typename T>
bool AVLTree<T> :: contains(const T& value)
{
    //return containsH(value, _root);
    bool answer = false;

    AVLNode<T>* temp = _root;
    while(!answer && temp != nullptr)      //
    {
        if(temp->data == value)
            return true;
        if(temp->data > value)
            temp = temp->left;
        else
            temp = temp->right;
    }

    return false;
}

template <typename T>
AVLNode<T>* AVLTree<T> :: rotateWithLeftChild(AVLNode<T>* &k2)
{
    AVLNode<T> *k1 = k2->right;

                       // Perform Rotation
    k2->right = k1->left;
    k1->left = k2;

                       // Update the Heights
    k2->node_height = max( height_tree(k2->right), height_tree(k2->left) ) +1;
    k1->node_height = max( height_tree(k1->right),  k2->node_height ) + 1;

    return k1;
}

template <typename T>
AVLNode<T>* AVLTree<T> :: rotateWithRightChild(AVLNode<T>* &k1)
{
    AVLNode<T> *k2 = k1->left;

                  // Perform Rotation
    k1->left = k2->right;
    k2->left = k1;

                     // Update the Heights
    k1->node_height = max( height_tree(k1->left), height_tree(k1->right)) +1;
    //k2->node_height = max(heightHelperTree(k1->left), k2->node_height) +1;
    k2->node_height = max( height_tree(k2->left), k1->node_height) + 1;

    return k2;
}
template <typename T>
AVLNode<T>* AVLTree<T> :: doubleWithLeftChild(AVLNode<T>* & node)
{
    node->right = rotateWithRightChild(node->right);
    node = rotateWithLeftChild(node);
    return node;
}

template <typename T>
AVLNode<T>* AVLTree<T> :: doubleWithRightChild(AVLNode<T>* &node)
{
    node->left = rotateWithLeftChild(node->left);
    node = rotateWithRightChild(node);
    return node;
}

template <typename T>
void AVLTree <T> :: destructor_Helper(AVLNode<T>* root)
{
    if(root != nullptr)
    {
        // Destroy Recursively
        // Destroys all the ones on the left, the right and the root
        destructor_Helper(root->left);
        destructor_Helper(root->right);
        delete (root);
    }

}


#endif //PA2_CPTS223_AVLTREE_H
