#include "Node.h"

class BST
{
private:

	Node* root;
	void insertNode(Node* pTree, const Node &data);

	void inOrderTraversal(Node* pTree);
	void PreOrderTraversal(Node *pTree);
	void PostOrderTraversal(Node* pTree);

public:

	BST(Node* newProot = nullptr);
	void insert(const Node& data);

	void inOrderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();

	//isEmp

};