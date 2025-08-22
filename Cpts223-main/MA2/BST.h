//
// Created by sherryl Dion-Gokan on 10/4/22.
//

#ifndef MA2_BST_H
#define MA2_BST_H

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
    T value;
    Node* left;
    Node* right;

    Node(T val) {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~Node()
    {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
    Node<T>* _root;         // Root of the tree nodes

    /* Add new T val to the tree */
    void addHelper(Node<T>* root, T val);

    /* Print tree out in inorder (A + B) */
    void printInOrderHelper(Node<T>* root);

    /* Return number of nodes in tree */
    int nodesCountHelper(Node<T>* root);

    /* Return height of tree (root == nullptr -> 0) */
    int heightHelper(Node<T>* root);

    /* Delete a given <T> value from tree */
    bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value);

    // Print all the levels of a tree, one by one in order
    void printLevelOrder_Helper(Node<T>* root, int level);

    // Print the longest path in the tree
    void printMaxPath_Helper(Node<T>* root);

    // Helper Function for the destructor, it destroys all nodes recursively
    void destructor_Helper(Node<T>* root);

    // Helper Function for the function contains(), it checks if a value is in the tree
    bool containsH(T value, Node<T>* root);


    /********************************* PUBLIC API *****************************/
public:

    BST() : _root(nullptr) { }               // Basic initialization constructor

    /**
     * Destructor - Needs to free *all* nodes in the tree
     * TODO: Implement Destructor
     */
    ~BST();

    /* Public API */
    void add(T val) {
        if (this->_root) {
            this->addHelper(this->_root, val);
        }
        else {
            this->_root = new Node<T>(val);
        }
    }

    void print() {
        printInOrderHelper(this->_root);
    }


    /**
     * Print the nodes level by level, starting from the root
     * TODO: Implement printLevelOrder
     */
    void printLevelOrder();

    int nodesCount() {
        return nodesCountHelper(this->_root);
    }

    int height() {
        return heightHelper(this->_root);
    }

    /**
     * Print the maximum path in this tree
     * TODO: Implement printMaxPath
     */
    void printMaxPath();

    bool deleteValue(T value) {
        return this->deleteValueHelper(nullptr, this->_root, value);
    }

    /**
     * Find if the BST contains the value
     * TODO: Implement contains
     */
      bool contains(T value);

};   /************ End of the class ************/


   /********************************* Protected Class functions *****************************/

/* Add new T val to the tree */
template <typename T>
void BST<T> :: addHelper(Node<T>* root, T val) {
        if (root->value > val) {
            if (!root->left) {
                root->left = new Node<T>(val);
            }
            else {
                addHelper(root->left, val);
            }
        }
        else {
            if (!root->right) {
                root->right = new Node<T>(val);
            }
            else {
                addHelper(root->right, val);
            }
        }
    }

    /* Print tree out in inorder (A + B) */
    template <typename T>
    void BST<T> :: printInOrderHelper(Node<T>* root) {
        if (!root) return;
        printInOrderHelper(root->left);
        cout << root->value << ' ';
        printInOrderHelper(root->right);
    }

    /* Return number of nodes in tree */
    template <typename T>
    int BST<T> :: nodesCountHelper(Node<T>* root) {
        if (!root) {
            return 0;
        }
        else {
            return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
        }
    }

    /* Return height of tree (root == nullptr -> 0) */
    template <typename T>
    int BST<T> :: heightHelper(Node<T>* root) {
        if (!root) {
            return -1;
        }
        else {
            return 1 + max(heightHelper(root->left), heightHelper(root->right));
        }
    }

    /* Delete a given <T> value from tree */
    template <typename T>
    bool BST<T> :: deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
        if (!current) return false;
        if (current->value == value) {
            if (current->left == nullptr || current->right == nullptr) {
                Node<T>* temp = current->left;
                if (current->right) temp = current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = temp;
                    }
                    else {
                        parent->right = temp;
                    }
                }
                else {
                    this->_root = temp;
                }
            }
            else {
                Node<T>* validSubs = current->right;
                while (validSubs->left) {
                    validSubs = validSubs->left;
                }
                T temp = current->value;
                current->value = validSubs->value;
                validSubs->value = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }

// Helper function for printLevelOrder()
template <typename T>
void BST<T> :: printLevelOrder_Helper(Node<T>* root, int level)
{
    if (!root)
        return;
    if (level == 1)
        cout << " " << root->value;
    else if (level > 1) {
        printLevelOrder_Helper(root->left, level - 1);
        printLevelOrder_Helper(root->right, level - 1);
    }
}

// Helper function for printMaxPath() function
template <typename T>
void BST<T> ::  printMaxPath_Helper(Node<T>* root)
{
    if (!root)
        return;     // When the tree is empty

    cout << root->value << " ";  // Start by printing the value of the root, then the rest

    // Compare the length of each side (left, right) of the tree
    // To figure out the highest, the highest would have be the longest path

    if (heightHelper(root->left) > heightHelper(root->right))
    {
        printMaxPath_Helper(root->left);  // Print the left side tree of the longest path

    } else
    {
        printMaxPath_Helper(root->right);  // Print the right side tree of the longest path
    }

}

// Helper Function for the destructor, destroy all nodes recursively
template <typename T>
void BST <T> :: destructor_Helper(Node<T>* root)
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

    /********************************* PUBLIC API *****************************/

    //  Destructor - Needs to free *all* nodes in the tree
     // TODO: Implement Destructor
template <typename T>
   BST<T> :: ~BST() {
       // cout << "TODO: Implement Destructor" << endl;
        destructor_Helper(this->_root);
    }


    /**
     * Print the nodes level by level, starting from the root
     * TODO: Implement printLevelOrder
     */
    template <typename T>
    void BST<T> :: printLevelOrder() {

        int height_ = heightHelper(_root);
        for (int i = 1; i <= height_ + 1; i++) {
            printLevelOrder_Helper(_root, i);
            cout << " " << endl;
        }
    }


    /**
     * Print the maximum path in this tree
     * TODO: Implement printMaxPath - From the most distant leaf node to the root node
     */
    template <typename T>
    void BST<T> :: printMaxPath()
    {
        //cout << "TODO: Implement printMaxPath" << endl;
        printMaxPath_Helper(_root);
    }


    /**
     * Find if the BST contains the value
     * TODO: Implement contains
     */

template <typename T>
bool BST<T> :: containsH(T value, Node<T>* root)
{
   // cout << "TODO: Implement contains" << endl;
    // return numeric_limits<T>::min();    // What I do with that

    // If the root is null, return false because the value is not the tree because the tree is empty
    if(root == nullptr)
        return false;

                        // while(root != nullptr)

      // When the given value is less than the value of root
       // return the result of the recursive call on the left side tree
      if (value < root->value) {
            return containsH(value,root->left);   // how can I use _value in this case, it only allows
        }

         // When the given value is more than the value of root,
         // return the result of the recursive call on the right side tree
        else if (value > root->value)
        {
            return containsH(value,root->right);
        }

        else  // When the given value is equal to the root (value == root->value), return true
            return true;

       // When the value is not included in the tree, it will return false because it went through
       // all the cases and that value was not found
}

template <typename T>
bool BST<T> :: contains(T value)
{
   return containsH(value, _root);
}

#endif //MA2_BST_H
