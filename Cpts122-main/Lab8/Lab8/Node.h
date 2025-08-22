
#include <iostream>
#include <fstream>
#include <string>

//#include "Node.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ostream;

using std::string;

class Node
{
private: 

	std::string data;
	Node* pLeft;
	Node* pRight;

public:

	    // Destructor
	~Node();

     	// Copy Constructor?   //Constructor?
	Node(const string& newData);

	Node* getRightPtr() const;
	Node* getLeftPtr() const;
	string getData() const;

	void setRightPtr(Node* const newRightPtr);
	void setLeftPtr(Node* const newLeftPtr);

	void setData(const string& newData);  // Passing by reference 

	friend ostream& operator << (ostream& os, const Node&node);
};

ostream& operator << (ostream& os, const Node& node)
{
	cout << node.data << endl;
	return os;
}
