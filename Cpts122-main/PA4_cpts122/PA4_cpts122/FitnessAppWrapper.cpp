///////////////////////////////////////////////////////////////////////////////
/// \file         FitnessAppWrapper.cpp
///////////////////////////////////////////////////////////////////////////////

#include "FitnessAppWrapper.h"

            //Constructor       
FitnessAppWrapper::FitnessAppWrapper()
{
		for (int i = 0; i < 7; i++) 
		{
			plan_for_diet[i].setPlanName(" ");
			plan_for_diet[i].setGoalCalories(0);
			plan_for_diet[i].setDate(" ");
		}

		for (int i = 0; i < 7; i++) 
		{
			plan_for_exercise[i].setPlanName(" ");
			plan_for_exercise[i].setGoalSteps(0);
			plan_for_exercise[i].setDate(" ");
		}
}


void FitnessAppWrapper :: displayMenu()
{
	cout << "--------The menu will be displayed below, please choose an option------ " << endl << endl;
		cout << " 1. Load weekly diet plan from file." << endl; 
		cout << " 2. Load weekly exercise plan from file." << endl;
		cout << " 3. Store weekly diet plan to file." << endl;
		cout << " 4. Store weekly exercise plan to file." << endl;
		cout << " 5. Display weekly diet plan to screen." << endl;
		cout << " 6. Display weekly exercise plan to screen." << endl;
		cout << " 7. Edit daily diet plan." << endl;
		cout << " 8. Edit daily exercise plan." << endl;
		cout << " 9. Exit" << endl << endl;    // Note: this must write the most recent weekly plans to the corresponding files.
}


int FitnessAppWrapper :: getMenuOption() const
{
	int option = 0;
	cin >> option;
	system("cls");

	return option;
}

                 // Load Daily

void FitnessAppWrapper :: loadDailyPlan(fstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;     // Extraction
}
																 
void FitnessAppWrapper :: loadDailyPlan(fstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;       // use of Extraction operator
}

              // Load Weekly

void FitnessAppWrapper :: loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[])
{
	DietPlan save;

	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, save);
		weeklyPlan[i] = save;
	}
}
                                                                 // Use of pointer?
void FitnessAppWrapper:: loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[])
{
	ExercisePlan saving;

	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, saving);   
		weeklyPlan[i] = saving;
	}
}


             // Display daily                   // Use of insertion operator

void FitnessAppWrapper :: displayDailyPlan(DietPlan cplan)     
{
	cout << cplan << endl;
}

void FitnessAppWrapper :: displayDailyPlan(ExercisePlan cplan)
{
	cout << cplan << endl;
}

          // Display weekly

void FitnessAppWrapper :: displayWeeklyPlan(DietPlan cplan[])
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(cplan[i]);
	}

}

void FitnessAppWrapper :: displayWeeklyPlan(ExercisePlan cplan[])
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(cplan[i]);
	}
}

         // Store daily

void FitnessAppWrapper :: storeDailyPlan(fstream& fileStream, DietPlan cplan)
{
	fileStream << cplan << endl;     // Use of insertion operator
}

void FitnessAppWrapper :: storeDailyPlan(fstream& fileStream, ExercisePlan cplan)
{
	fileStream << cplan << endl;
}

        // Store weekly

void FitnessAppWrapper :: storeWeeklyPlan(fstream& fileStream, DietPlan cplan[])
{
	//fstream outfile_diet;
	outfile_diet.open("dietPlans.txt");               

	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, cplan[i]);
	}

	outfile_diet.close();
}

void FitnessAppWrapper :: storeWeeklyPlan(fstream& fileStream, ExercisePlan cplan[])
{
	//fstream outfile_exercise;
	outfile_exercise.open("exercisePlans.txt");      

	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, cplan[i]);
	}

	outfile_exercise.close();        // So if I don't call this, I need to insert this in the larger function.
}

               // Edit Daily plan

void FitnessAppWrapper::editDailyPlan(DietPlan& cplan)
{
	int ok = 0;
	cout << "Would you like to edit the plan name (1), the goal (2), the date (3) or (4) to go back to the menu ?" << endl;
	cin >> ok;

		switch (ok)
		{
		case 1:   // Edit Name
			cplan.editName_Diet();
			cout << "A new plan name has been edited." << endl << endl;
			break;

		case 2:   // Edit Goal
			cplan.editGoal_Diet();
			cout << "A new goal has been edited." << endl << endl;
			break;

		case 3:   // Edit Date
			cplan.editDate_Diet();
			cout << "A new plan date has been edited." << endl << endl;
			break;

		case 4: //Going back to the menu
			break;

		default: cout << "ERROR: Invalid choice! Please try again!" << endl;
			break;
		}

}

void FitnessAppWrapper::editDailyPlan(ExercisePlan& cplan)
{
	int ok = 0;
	cout << "Would you like to edit the plan name (1), the goal (2), the date (3) or (4) to go back to the menu?" << endl;
	cin >> ok;

	switch (ok)
	{
	case 1:   // Edit Name
		cplan.editName_Ex();
		cout << "A new plan name has been edited." << endl << endl;
		break;

	case 2:   // Edit Goal
		cplan.editGoal_Ex();
		cout << "A new goal has been edited." << endl << endl;
		break;

	case 3:   // Edit Date
		cplan.editDate_Ex();
		cout << "A new plan date has been edited." << endl << endl;
		break;

	case 4:  //Going back to the menu
		break;

	default: cout << "ERROR: Invalid choice! Please try again!" << endl;
		break;
	}

}

void FitnessAppWrapper::editDailyPlan_Exercise(ExercisePlan cplan[])
{
	int day = 0;
	do
	{
		cout << "Please enter the day of the week you would like to edit ( 1 through 7) : ";
		cin >> day;
		editDailyPlan(cplan[day - 1]);

	} while (day <= 0 || day >= 8);
}

void FitnessAppWrapper::editDailyPlan_Diet(DietPlan cplan[])
{
	int day = 0;
	do
	{
		cout << "Please enter the day of the week you would like to edit ( 1 through 7) : ";
		cin >> day;
		editDailyPlan(cplan[day - 1]);

	} while (day <= 0 || day >= 8);
}

          // Running the Application

void FitnessAppWrapper :: runApp()
{
	int option = 0;    
	bool status = true;
	DietPlan plan_d[7];     
	ExercisePlan plan_e[7];
	
	             // Opening of the files

	//fstream infile_diet;
	infile_diet.open("dietPlans.txt");
	//fstream infile_exercise;
	infile_exercise.open("exercisePlans.txt");

	cout << "*** Welcome to the Fitness Application ***" << endl << endl;

	do
	{
		displayMenu();
		option = getMenuOption();

		switch (option)
		{
		case 1: loadWeeklyPlan(infile_diet, plan_d);
			cout << "The weekly plan for the Diet plan has been loaded!" << endl << endl;
			break;
			

		case 2: loadWeeklyPlan(infile_exercise, plan_e);
			cout << "The weekly plan for the Exercise plan has been loaded!" << endl << endl;
			break;
			

		case 3: storeWeeklyPlan(outfile_diet, plan_d);
			cout << "The weekly plan for the Diet plan has been stored to the file!" << endl << endl;
			break;

		case 4: storeWeeklyPlan(outfile_exercise, plan_e);
			cout << "The weekly plan for the Exercise plan has been stored to the file!" << endl << endl;
			break;

		case 5: cout << "The weekly plan from the Diet plan will be displayed below" << endl << endl;
			displayWeeklyPlan(plan_d);
			break;

		case 6: cout << "The weekly plan from the Exercise plan will be displayed below" << endl << endl;
			displayWeeklyPlan(plan_e);
			break;

		case 7:  
			editDailyPlan_Diet(plan_d);
			break;

		case 8:  
			editDailyPlan_Exercise(plan_e);
			break;
			 
		case 9: status = false;           // Exit               // Need to store, save the files and then exit 

			storeWeeklyPlan(outfile_diet, plan_d);
			cout << "The weekly plan for the Diet plan has been stored to the file!" << endl;

			storeWeeklyPlan(outfile_exercise, plan_e);
			cout << "The weekly plan for the Exercise plan has been stored to the file!" << endl;

			cout << " Goodbye!";
			break;

		default: cout << "ERROR: Invalid choice! Please try again!" << endl;
			break;
		}


	} while (status != false);

	infile_diet.close();
	infile_exercise.close();
}