#include "ExercisePlan.h"

        // Constructor

ExercisePlan::ExercisePlan(string newPlanName, int newGoalSteps, string newDate)
{
    _planName = newPlanName;

    if (newGoalSteps <= 0)
    {
        _goalSteps = 0;
    }
    else
    {
        _goalSteps = newGoalSteps;
    }

    //_goalCalories = newGoalCalories;
    _date = newDate;
}

       // Copy Constructor

ExercisePlan ::ExercisePlan(const ExercisePlan& copyExercise)
{
    _planName = copyExercise.getPlanName();
    _goalSteps = copyExercise.getGoalSteps();
    _date = copyExercise.getDate();
}

       // Destructor

ExercisePlan :: ~ExercisePlan()
{
	      // This method does nothing.
    //cout << "This is the destructor of the Exercise plan!" << endl;
}

       // Getters for the class ExercisePlan

int ExercisePlan :: getGoalSteps() const
{
   return _goalSteps;
}

string ExercisePlan::getPlanName() const
{
    return _planName;
}

string ExercisePlan :: getDate() const
{
    return _date;
}

          // Setters for the class ExercisePlan

void ExercisePlan :: setGoalSteps(int newGoalSteps)
{
    _goalSteps = newGoalSteps;
}
void ExercisePlan :: setPlanName(string newPlanName)
{
    _planName = newPlanName;
}
void ExercisePlan :: setDate(string newDate)
{
    _date = newDate;
}

             // Edit Goal Function        // Option for editing many goal?

void ExercisePlan :: editGoal_Ex()
{
    cout << "The present goal is: " << getGoalSteps() << endl;

    int edit_goal = 0;
    cout << "Let's insert a new value for the goal of calories: ";
    cin >> edit_goal;
    cout << endl;
    
         //Setting the edit goal to the present goal
    setGoalSteps(edit_goal);     // equivalent of _goalCalories = edit_goal ? 
}
  
          // Edit Name of the Plan Function

void ExercisePlan :: editName_Ex()
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

void ExercisePlan::editDate_Ex()
{
    cout << "The present date is: " << getDate() << endl;

    string edit_date;
    char input[100];
    cout << "Let's insert a new date for the plan: ";
    
    cin.ignore();
    cin.getline(input, 99);
    edit_date = (string)input;

          // Setting the edit date to the present date
    setDate(edit_date);       // equivalent to _name = edit_name ?
}

         // Non-Member Functions
                                                                     // Insertion
ostream& operator<< (ostream& ins, const ExercisePlan& ex_plan)
{
    ins << ex_plan.getPlanName() << endl;
    ins << ex_plan.getGoalSteps() << endl;
    ins << ex_plan.getDate() << endl;

    return ins;
}
                                                                  // Extraction
istream& operator>> (istream& ext, ExercisePlan& ex_plan)
{
        string multi = " ";

        //Set Plan Name
        getline(ext, multi);              // getline to be able to read the whole line, string without stopping at a white space
        ex_plan.setPlanName(multi);

        //Set Goal Steps
        getline(ext, multi);
        ex_plan.setGoalSteps(stoi(multi));   // number?  // stoi to be able to convert thestring into an integer

              //Set Goal Date 
        getline(ext, multi);
        ex_plan.setDate(multi);

        //Blank Space
        getline(ext, multi);

    return ext;
}