//
// Created by sherryl Dion-Gokan on 10/10/22.
//

#ifndef PA2_CPTS223_AVLNODE_H
#define PA2_CPTS223_AVLNODE_H
/*
 *  Data structure for a single tree node
 */
template <typename T>
struct AVLNode {
public:
    T data;
    AVLNode *left;
    AVLNode *right;
    int node_height;

         // Constructor
    AVLNode(T value);

       // Destructor
    ~AVLNode();

    int height_node(AVLNode<T> *node);

};

template <typename T>
AVLNode<T> :: AVLNode(T value)
{
    this->data = value;
    this->left = nullptr;
    this->right = nullptr;
    this->node_height = 0;
}

template <typename T>
AVLNode<T> :: ~AVLNode()
{
   // It does nothing

    this->data = 0;         // check
    this->left = nullptr;
    this->right = nullptr;
    this->node_height = 0;    // check
}


#endif //PA2_CPTS223_AVLNODE_H
