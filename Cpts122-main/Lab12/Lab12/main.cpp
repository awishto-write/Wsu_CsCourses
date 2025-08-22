#include "List.h"


int main(void)
{
	List <int> aList;
	
	aList.insertAtFront(5);
	aList.print();
	aList.insertAtFront(7);
	aList.print();
	aList.insertAtFront(9);
	aList.print();

	aList.insertAtBack(2);
	aList.print();

	int removed;

	aList.removeFromFront(removed);
	cout << "Removed: " << removed << endl;
	aList.print();

	aList.removeFromBack(removed);
	cout << "Removed: " << removed << endl;
	aList.print();

	//cout << " Hi " << endl;


	

}