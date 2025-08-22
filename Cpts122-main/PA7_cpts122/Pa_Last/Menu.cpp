#include "Menu.h"

Menu::Menu()
{
	// Nothing
}

Menu :: ~Menu()
{
	// It does nothing
}

void Menu::display_menu()
{
	cout << endl;
	cout << "          WELCOME !       " << endl;
	cout << " Please, choose an option below !" << endl << endl;
	cout << " 1.  Import course list" << endl;
	cout << " 2. Load master list" << endl;
	cout << " 3.  Store master list" << endl;
	cout << " 4. Mark absences " << endl;
	cout << " 5. Edit absences " << endl;
	cout << " 6. Generate report" << endl;
	cout << " 7.  Exit" << endl << endl;
}

void Menu::RunApp()
{
	int option = 0;
	do
	{
		do // input validation loop
		{
			display_menu();
			cin >> option;

		} while (option < 1 || option > 7);   // validate the input; option must be [1 - 7]

		system("cls"); // clear the screen

		// have obtained the option from the user; need to determine next operation
		performUserSelection(option);

	} while (option != 7); // 7 = exit the program
}

void Menu::performUserSelection(const int& option)
{
	bool success = false;

	switch (option)
	{
	case 1: import_courseList(master_file);
		break;

	case 2: load_masterList(master_file);
		break;

	case 3: store_masterList(master_file);
		break;

	case 4: mark_absences(master_file);
		break;

	case 5: editAbsences(master_file);
		cout << endl;
		cout <<	" The option is not complete, but most of the work was done! " << endl;
		cout << "     Thank you for testing the feature!  " << endl << endl;
		break;

	case 6: 
		generateReport(master_file);
		break;

	case 7:
		store_masterList(master_file);
		cout << "Goodbye" << endl;
		break;
	}

}


void Menu::import_courseList(List<Data>& File)
{
	Data originalList;
	string to_remove = " ";
	extraction.open("classList.csv");  // Opening of the classList.csv file


	getline(extraction, to_remove); // Remove the header line

	while (!extraction.eof())
	{
		extraction >> originalList;   // Extraction

		File.InsertAtFront(originalList);

	}


	extraction.close();  // Closing the classList.csv file
	cout << "The course list has been imported!" << endl << endl;
}


void Menu::load_masterList(List<Data>& File)
{
	Data newList;
	extraction.open("master.txt");   // Opening of the master.txt files


	List<Data> temp;
	temp.set_pHead(File.get_pHead());

	if (temp.get_pHead() != nullptr)
	{
		while (!temp.get_pHead())
		{
	       temp.destroy_List();  // Delete the old  list to make way for new one

	    }
	}

	temp.set_pHead(nullptr);      


	string buf = " ";
	getline(extraction, buf);   // removing first row

	while (!extraction.eof())
	{

		extraction >> newList;    // Extraction

		temp.InsertAtFront(newList);
	}

	extraction.close();  // Closing the master.txt file
	cout << "The master list has been loaded!" << endl << endl;
}

void Menu::store_masterList(List<Data>& File)
{
	insertion.open("master.txt");
	//insertion << master_file;      
	insertion << File;    // Insertion of the information into that file
	insertion << "Record| ID| Name| Email| Units| Program| Level| Number Absence| Recent Absence Date";

	insertion.close();
	cout << "The master list has been succesfully stored!" << endl << endl;
}


void Menu::mark_absences(List<Data>& File)
{

	List<Data> temp;
	temp.set_pHead(File.get_pHead());

	int isAbsent = 0;

	while (temp.get_pHead() != nullptr)
	{
		cout << "Is " << temp.get_pHead()->getData().getName() << " absent? (Enter 0 for false, 1 for true)" << endl;
		cin >> isAbsent;

		if (isAbsent == 1)
		{
			// retrieved from stackoverflow 
			string date;
			time_t t = time(0);   // get time now
			struct tm* now = localtime(&t);
			date = to_string ((now->tm_year + 1900));

			date = date + "-";
			date = date + to_string((now->tm_mon + 1));
			date = date + "-";
			date = date + to_string(now->tm_mday);

			Stack absence;
			absence.push(date); //push to top of stack

			    //update number of absences
			temp.get_pHead()->getData().setNumAbsences(temp.get_pHead()->getData().getNumAbsences() + 1);

			temp.get_pHead()->getData().setAbsenceDate(absence); //set stack to node

		}

		temp.set_pHead(temp.get_pHead()->getNextPtr());
	
	}


	cout << endl << endl;
	cout << "      The attendence has been taken! " << endl << endl;


}


void Menu::generateReport(List<Data>& File)
{
	insertion.open("master.txt");

	int option = 0;

	while (option > 2 || option < 1)
	{
		cout << "Select an option: " << endl;
		cout << "1. Generate Report for Everyone" << endl;
		cout << "2. Search by Number of Absences" << endl;
		cin >> option;
		system("cls");
	}

	List<Data> temp;
	temp.set_pHead(File.get_pHead());

	if (option == 1)
	{
		while (temp.get_pHead() != nullptr )
		{

			if (temp.get_pHead()->getData().getNumAbsences() != 0)
			{

				cout << temp.get_pHead()->getData().getName() << "  was recently absent on  " <<
					temp.get_pHead()->getData().get_Absence_Dates().peek() << endl;

			}
			else
			{
				cout << temp.get_pHead()->getData().getName() << "  has no absences! " << endl;
			}

			temp.set_pHead(temp.get_pHead()->getNextPtr());
		}
	}

	else //option == 2
	{
		int absences;

		cout << "  You will see absences that match or exceed the 'chosen' number! " << endl << endl;
		cout << "         Enter the record of number of Absences you would like to see: " << endl;
		cin >> absences;

		while (temp.get_pHead() != nullptr)
		{
			if (temp.get_pHead()->getData().getNumAbsences() >= absences)
			{
				cout << temp.get_pHead()->getData().getName() << "  with " << temp.get_pHead()->getData().getNumAbsences()
					<< " absences." << endl;
			}
 
			temp.set_pHead(temp.get_pHead()->getNextPtr());
		}

	}

	insertion.close();
}



void Menu :: editAbsences(List<Data>& File)
{
	int id, size = 0;
	string date, Absence, Dates[100];
	bool found = false;

	//Node* pCur = mList.getFrontPtr(), * pMem;

	List<Data> temp;
	temp.set_pHead(File.get_pHead());
	//List<Data> temp1;

	cout << " Enter the Student's ID Number (4 integers type): ";
	cin >> id;

	while (found != true && temp.get_pHead() != nullptr)
	{
		if (id == temp.get_pHead()->getData().getID_number())
		{
			found = true;
			cout << temp.get_pHead()->getData().getName() << endl;
			
			//temp1 = temp; // saves the node
		}

		temp.set_pHead(temp.get_pHead()->getNextPtr());
	}

	cout << "Enter the date of absence to delete (yyyy-m-dd): ";
	cin >> date;
	
	//Stack absence;
	//absence.pop(); //pop

	//temp.get_pHead()->getData().setAbsenceDate(absence); 

	  // I was looking a way to get the size 
	//int stack_size = temp.get_pHead()->getData().get_Absence_Dates().size();
	

	//while (Absence != date || stack_size > 0)
	//{
	//	Dates[size] = Absence; // store date in seperate array
	//	size++;
	//	stack_size--;

	//	absence.pop();
	//}
	//if (Absence == date)
	//{
	//	File.get_pHead()->getData().setNumAbsences(-1);
	//}
	//while (size >= 0)
	//{
	//	Absence = Dates[size];
	//	absence.push(Absence);
	//	size--;
	//}

}



