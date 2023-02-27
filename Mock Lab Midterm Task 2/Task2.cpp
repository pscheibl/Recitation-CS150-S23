/**
Mock Midterm Task 2: Metabolic Equivalent

Design an algorithm and write a C++ program that do the following:
• Prompts the user to input the following:
	o the weight in kilograms
	o the name of the activity
	o the number of minutes spent on that activity
• finds the number of METS for the activity in the input file
• calculates and outputs an estimate for the total number of calories burned.

The number of calories burned per minute is estimated using the following formula:
Calories Per Minute = 0 .0175 × MET × ( Weight in kilograms )

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// Function prototype for finding Metabolic Equivalent in file
double find_met(string activity);
int main()
{
    // Declare variables for activity name, MET, weight, calories, minutes.
    string activity_name;
    double metabolic_equivalent = 0, weight_kg, calories, minutes;
    // Prompt user for weight, name of activity, and time spent on activity.
    // Read in user input.
    cout << "Enter weight in kilograms: ";
    cin >> weight_kg;
    cout << "Enter name of activity: ";
    cin >> activity_name;
    cout << "Enter time spent on activity in minutes: ";
    cin >> minutes;
    metabolic_equivalent = find_met(activity_name);
    // Calculate calories burned: Calories = 0 .0175 × MET × ( Weight in kilograms ) × minutes
    calories = 0.0175 * metabolic_equivalent * weight_kg * minutes;
    // Print the MET and the calories burned.
    cout << "The metabolic equivalent for " << activity_name << " is " << metabolic_equivalent << endl;
    cout << "You burned " << calories << " calories." << endl;

    return 0;
}
/**
Find Met
finds the metabolic equivalent for a given activity
*/
double find_met(string activity)
{
    // Open input file
    ifstream in_file("input.txt");
    // Check if input file correctly opened
    if(!in_file)
    {
        cerr << "Can't open input.txt, is it in the working directory?" << endl;
        exit(1);
    }

    string current_activity;
    double current_met;
    // Loop through each line of the input file
    while(in_file >> current_activity >> current_met)
    {
        // Check if first word of input line is the named activity.
        if(activity == current_activity)
        {
            // return the associated MET value
            return current_met;
        }
    }
    // If it's not found, say the activity is invalid and quit.
    cout << "Invalid activity" << endl;
    exit(1);
}
