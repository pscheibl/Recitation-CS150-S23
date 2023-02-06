/// CS 150 Recitation Exercise 3
/// Peter Scheible
/// February 6, 2023

///-----------------------------------------------------///

/// Instructions:
/// Write an algorithm and a C++ program that keeps a running total
/// of the number of insects collected over seven days.
/// The loop should ask for the number of insects collected
/// for each day, and when the loop is finished,
/// the program should display the total number of
/// insects collected.

///-----------------------------------------------------///

/// Include IOstream header for std::cin and std::cout
#include <iostream>
/// Include string header for std::string
#include <string>


using namespace std;

int main()
{
    //1. Declare variables for the day, the insects collected on a specific day and the running total.
    //2. initialize the running total to 0 and the day to 1
    int day = 1;
    int insects_total = 0;
    int insects_daily = 0;
    //3. Start a while loop that checks that the day is less than or equal to 7
    while(day <= 7)
    {
        //3.1 prompt the user for the number of insects
        cout << "It's day " << day << ", How many insects did you collect? ";
        //3.2 Read in insect count
        cin >> insects_daily;
        //3.3 if insect count >= 0,
        if(insects_daily >= 0)
        {
            //3.3.1 add count to running total
            insects_total += insects_daily;
            //3.3.2 add 1 to the day counter
            day++;
        }
        else
        {
            cout << "The number of insects must be nonnegative. :(" << endl;
        }
    }
    //4. Display total number of insects
    cout << "You collected a total of " << insects_total << " insects this week." << endl;
return 0;
}
