#include "AVLTree.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    // The first tree will have an ascending order
   AVLTree<int>* tree1 = new AVLTree<int> ();
//
//    // The second tree will have a descending order
   AVLTree<int>* tree2 = new AVLTree<int> ();
//
//    // The third tree will have a random order
 AVLTree<int>* tree3 = new AVLTree<int> ();

                              // For All trees     // Insertion and printing heights


    for(int i = 1; i < 100; i += 2)   // i = i + 2
    {
        tree1->insert(i);   // Inserting: 1,3,5,7,9,11, etc..
    }

    vector<int> array2, array3;

    for(int i = 1; i < 100; i +=2 )
    {
        array2.push_back(i);
        array3.push_back(i);
    }


   sort(array2.rbegin(),array2.rend() );


    for (int j = 0; j < array3.size(); j++)
    {
        int r = j + rand() % (array3.size()- j);

              swap(array3[j], array3[r]);

    }



    for(auto i: array2)
    {
        tree2->insert(i);
    }


    for(int i: array3)
    {
        tree3->insert(i);
    }

   cout << endl;

        // Printing the height of each tree
 cout << "The height of the first tree (tree1) is " << tree1->height_tree_p()<< endl;
 cout << "The height of the second tree (tree2) is " << tree2->height_tree_p() << endl;
 cout << "The height of the third tree (tree3) is " << tree3->height_tree_p() << endl;

        // For Validate Functions
cout << endl;
cout << "For Validate() of the AVL trees, when 1 is returned, it means that the tree is balanced" << endl;
cout << "         For Validate() for the AVL Tree 1: " << tree1->validate() << endl;
cout << "         For Validate() for the AVL Tree 2: " << tree2->validate() << endl;
cout << "         For Validate() for the AVL Tree 3: " << tree3->validate() << endl << endl;

              // For Contains Functions

  // Tree1
 for(int i = 1; i <= 100; i ++ )
 {
     bool result = tree1->contains(i);

     if( (result && i % 2 == 0) || (!result && i % 2 == 1) ) {
         cout << "At " << i << " : My AVL tree 1 implementation is wrong! " << endl;
     }
   else
     {
       cout << "At " << i << " : My AVL tree 1 implementation is " << (result? "Correct\n" : "Wrong\n");
     }

 }
 cout << endl;

    // Tree2
    for(int i = 1; i <= 100; i ++ )
    {
        bool result = tree2->contains(i);

        if( (result && i % 2 == 0) || (!result && i % 2 == 1) ) {
            cout << "At " << i << " : My AVL tree 2 implementation is wrong! " << endl;
        }
        else {
            cout << "At " << i << " : My AVL tree 2 implementation is " << (result ? "Correct\n" : "Wrong\n");
        }
    }

    cout << endl;

    // Tree3
    for(int i = 1; i <= 100; i ++ )
    {
        bool result = tree3->contains(i);

          if( (result && i % 2 == 0) || (!result && i % 2 == 1) ) {
              cout << "At " << i << " : My AVL tree 3 implementation is wrong! " << endl;
          }

        else
        {
              cout << "At " << i << " : My AVL tree 3 implementation is " << (result ? "Correct\n" : "Wrong\n");
          }
    }

    return 0;
}
