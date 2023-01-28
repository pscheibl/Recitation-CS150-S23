/// CS 150 Recitation Exercise 2
/// Peter Scheible
/// January 23, 2023

///-----------------------------------------------------///

/// Instructions:
/// design an algorithm and write a C++ program to do the following:
/// Prompt the user to input the following car information: Car brand,
/// Car name, Car year, Car cost (USD), Loan down payment (USD),
/// Loan yearly interest rate (%), Loan term (number of months),
/// Car MPG, and Car yearly mileage use (miles).

/// Calculates the users monthly loan payment on a car given the
/// interest rate, original cost (Car cost), down payment,
/// and length of the loan in months

/// Calculates the annual cost of gas given the miles per gallon (Car MPG)
/// and anticipated mileage usage per year, the cost per gallon is assumed
/// to be $2.75.

/// Calculates the total annual cost by considering the yearly fuel cost,
/// yearly loan payment, yearly oil change cost, yearly basic upkeep
/// and annual pass cost.

/// Calculates the total monthly cost using the total annual cost

/// Outputs information to the screen and to an output file

///-----------------------------------------------------///

/// Include IOstream header for std::cin and std::cout
#include <iostream>
/// Include IOmanip header for input/output manipulation such as
/// std::setw and std::setprecision
#include <iomanip>
/// Include fstream header for file stream operations to read and write to a file
#include <fstream>
/// include cmath for more advanced math operations, such as sqrt and pow
#include <cmath>

/// Using this namespace enables us to just type 'cin', 'cout', and 'endl'
/// rather than 'std::cin', 'std::cout', and 'std::endl'
/// All the standard library identifiers provided by the standard header files like
/// <iostream>, <string>, <vector>, etc. are declared in the std namespace.
using namespace std;

/// Here we define our own namespace where we can store our constants
namespace upkeep_price
{
    const double gas = 2.75;
    const double oil_change = 50.;
    const double maintainance = 400.;
    const double parking = 306.;
}
int main()
{
//    2. Declare Variables
    string make;
    string model;
    string year;

    double price;
    double downpayment;
    double principle;
    double interest_rate_annual;
    double interest_rate_monthly;
    double interest_payment;
    int loan_term_months;
    double MPG;
    double mileage_annual;
    double gas_cost_annual;
    double total_cost_annual;
    double total_cost_monthly;

//    3. Declare and open an output file
    ofstream out_file;
    out_file.open("output.txt");
///---------- 4. Take user input. ------------
//    4.1 Prompt and get Car Make
    cout << "Enter car Make: ";
    cin >> make;
//    4.2 Prompt and get Car Model
    cout << "Enter car Model: ";
    cin >> model;
    cout << "Enter car Year: ";
    cin >> year;
//    4.3 Prompt and get Car Cost
    cout << "Enter car Sticker Price: ";
    cin >> price;
//    4.4 Prompt and get down payment
    cout << "Enter loan down payment: ";
    cin >> downpayment;
//    4.5 Prompt and get annual interest
    cout << "Enter Annual Interest Rate: ";
    cin >> interest_rate_annual;
//    4.6 Prompt and get Loan Term
    cout << "Enter loan term: ";
    cin >> loan_term_months;
//    4.7 Prompt and get MPG
    cout << "Enter Fuel Efficiency (MPG):";
    cin >> MPG;
//    4.8 Prompt and get annual mileage
    cout << "Enter Annual Mileage:";
    cin >> mileage_annual;

/// ------------Calculations----------------
//    5. Calculate total cost of gas per year
    gas_cost_annual = (mileage_annual/MPG) * upkeep_price::gas;
//    6. Calculate Monthly interest rate
    interest_rate_monthly = (interest_rate_annual/100)/12;
//    7. Calculate the monthly loan payment
    principle = price - downpayment;
    interest_payment = (principle) * (interest_rate_monthly*pow(1+interest_rate_monthly, loan_term_months))
                       /((pow(1+interest_rate_monthly,loan_term_months))-1);
//    8. Calculate Annual upkeep cost.
    total_cost_annual = gas_cost_annual + upkeep_price::parking + upkeep_price::oil_change * 4
                      + upkeep_price::maintainance + interest_payment * 12;
//    9. Calculate Monthly upkeep cost.
    total_cost_monthly = total_cost_annual/ 12;
//    10. Set output parameters to display 2 decimal points
    out_file << fixed << showpoint << setprecision(2);
    cout << fixed << showpoint << setprecision(2);
//    11. Output Results to console
    cout << endl << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << "Cost Analysis" << endl;
    cout << setfill('.') << left << setw(35) << " Car Name: "
         << right << " " << year << " " << make << " " << model <<endl;

    cout << left << setw(35) << " Principle: " << setfill(' ') << right
         << "$" <<setw(8) << principle <<endl;

    cout << setfill('.') << left << setw(35)
         << " Interest Rate: "
         << setfill(' ') << right
         << setw(8) << interest_rate_annual << " %" << endl;

    cout << setfill('.') << left << setw(35)
         << " Loan Term: "
         << setfill(' ') << right
         << setw(8) << loan_term_months << endl << endl;
    cout << setfill('.') << left << setw(35) << " Monthly Loan Payment: "
         << setfill(' ') << right << " $"
         << setw(8) << interest_payment<< endl;
    cout << setfill('.') << left << setw(35) << " Yearly Fuel Cost: "
         << setfill(' ') << right << " $"
         << setw(8) << gas_cost_annual << endl;

    cout << setfill('.') << left << setw(35) << " Annual Maintenance Cost: "
         << setfill(' ') << right << " $"
         << setw(8) << upkeep_price::maintainance << endl;

    cout << setfill('.') << left << setw(35) << " Annual Oil Change Cost: "
         << setfill(' ') << right << " $"
         << setw(8) << upkeep_price::oil_change * 4 << endl;

    cout << setfill('.') << left << setw(35) << " Annual Parking Pass: "
         << setfill(' ') << right << " $"
         << setw(8) << upkeep_price::parking << endl;

    cout << setfill('.') << left << setw(35) << " Total Annual Cost: "
         << setfill(' ') << right << " $"
         << setw(8) << total_cost_annual<< endl;
    cout << setfill('.') << left << setw(35) << " Total Monthly Cost: "
         << setfill(' ') << right << " $"
         << setw(8) << total_cost_monthly << endl;
//    12. Output Results to file
    out_file << "Cost Analysis" << endl;
    out_file << setfill('.') << left << setw(35) << " Car Name: "
             << right << " " << year << " " << make << " " << model <<endl;

    out_file << left << setw(35) << "Principle: " << setfill(' ') << right
             << "$" <<setw(8) << principle <<endl;

    out_file << setfill('.') << left << setw(35)
             << " Interest Rate: "
             << setfill(' ') << right
             << setw(8) << interest_rate_annual << " %" << endl;

    out_file << setfill('.') << left << setw(35)
             << " Loan Term: "
             << setfill(' ') << right
             << setw(8) << loan_term_months << endl << endl;
    out_file << setfill('.') << left << setw(35) << " Monthly Loan Payment: "
             << setfill(' ') << right << " $"
             << setw(8) << interest_payment<< endl;
    out_file << setfill('.') << left << setw(35) << " Yearly Fuel Cost: "
             << setfill(' ') << right << " $"
             << setw(8) << gas_cost_annual << endl;

    out_file << setfill('.') << left << setw(35) << " Annual Maintenance Cost: "
             << setfill(' ') << right << " $"
             << setw(8) << upkeep_price::maintainance << endl;

    out_file << setfill('.') << left << setw(35) << " Annual Oil Change Cost: "
             << setfill(' ') << right << " $"
             << setw(8) << upkeep_price::oil_change * 4 << endl;

    out_file << setfill('.') << left << setw(35) << " Annual Parking Pass: "
             << setfill(' ') << right << " $"
             << setw(8) << upkeep_price::parking << endl;

    out_file << setfill('.') << left << setw(35) << " Total Annual Cost: "
             << setfill(' ') << right << " $"
             << setw(8) << total_cost_annual<< endl;
    out_file << setfill('.') << left << setw(35) << " Total Monthly Cost: "
             << setfill(' ') << right << " $"
             << setw(8) << total_cost_monthly << endl;
//    13. Close the outfile.
    out_file.close();

    return 0;
}
