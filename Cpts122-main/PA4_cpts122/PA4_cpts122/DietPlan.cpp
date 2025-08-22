///////////////////////////////////////////////////////////////////////////////
/// \file         DietPlan.cpp
///////////////////////////////////////////////////////////////////////////////

#include "DietPlan.h"

          // Constructor

DietPlan::DietPlan(string newPlanName, int newGoalCalories, string newDate)
{
    _planName = newPlanName;

    if (newGoalCalories <= 0)
    {
        _goalCalories = 0;
    }
    else
    {
        _goalCalories = newGoalCalories;
    }

   // _goalCalories = newGoalCalories;
    _date = newDate;
}

         // Constructor Copy

DietPlan :: DietPlan (const DietPlan& copyDiet)
{
    _planName = copyDiet.getPlanName();
    _goalCalories = copyDiet.getGoalCalories();
    _date = copyDiet.getDate();
}

         //Destructor

DietPlan :: ~DietPlan()
{
	// This method does nothing.
	//cout << "This is the destructor of the dietPlan!" << endl;
}

           // Getters for the class DietPlan

int DietPlan :: getGoalCalories() const
{
	return _goalCalories;
}

string DietPlan :: getPlanName() const
{
	return _planName;
}

string DietPlan :: getDate() const
{
	return _date;
}

        // Setters for the class DietPlan

void DietPlan :: setGoalCalories(int newGoalCalories)
{
    _goalCalories = newGoalCalories;
}
void DietPlan :: setPlanName(string newPlanName)
{
    _planName = newPlanName;
}
void DietPlan :: setDate(string newDate)
{
    _date = newDate;
}

          // Edit Goal Function        

void DietPlan :: editGoal_Diet()
{
    cout << "The present goal is: " << getGoalCalories() << endl;
    int edit_goal = 0;

    cout << "Let's insert a new value for the goal of calories: ";
    cin >> edit_goal;

    //Setting the edit goal to the present goal
    setGoalCalories(edit_goal);     // equivalent of _goalCalories = edit_goal ? 
}

        // Edit Name of the Plan Function

void DietPlan :: editName_Diet()
{
    cout << "The present name of the plan is: " << getPlanName() << endl;
    string edit_name;
    char input[100];

    cout << "Let's insert a new name for the plan: ";
    cin.ignore();
    cin.getline(input, 99);
    edit_name = (string)input;

    // Setting the edit name to the present name
    setPlanName(edit_name);        // equivalent to _name = edit_name ?

}

         // Edit of the date Function

void DietPlan ::editDate_Diet()
{
    cout << "The present date is: " << getDate() << endl;
    string edit_date;
    char input[100];

    cout << "Let's insert a new date for the plan: ";
    cin.ignore();
    cin.getline(input, 99);
    edit_date = (string)input;

       // Setting the edit date to the present date
    setDate(edit_date);     // equivalent to _name = edit_name ?
}


               // Non-Members Functions
                                                        // Insertion Function  //  We write
                                                        // Access of the information we have, we do not get new information, so get.
                                                        
ostream& operator << (ostream& ins, const DietPlan& diet_plan)    
{ 
       ins << diet_plan.getPlanName() << endl;
       ins << diet_plan.getGoalCalories() << endl;
       ins << diet_plan.getDate() << endl;

       return ins;
}
                                                        // Extraction Function   // We read
                                                         // We use set because it is the beginning, we need to set to what we have to read.
istream& operator >> (istream& ext, DietPlan& diet_plan)      
{
     string multi = " ";

     //Set Plan Name
        getline(ext, multi);              //getline to be able to read the whole line, string without stopping at a white space
        diet_plan.setPlanName(multi);

     //Set Goal Steps
        getline(ext, multi);
        diet_plan.setGoalCalories(stoi(multi));    //stoi to be able to convert the string into an integer

      //Set Goal Date 
        getline(ext, multi);
        diet_plan.setDate(multi);

        //Blank Space
        getline(ext, multi);

    return ext;
}