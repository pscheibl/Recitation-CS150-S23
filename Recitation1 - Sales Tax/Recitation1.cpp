/// CS 150 Recitation Exercise 1
/// Peter Scheible
/// January 9, 2023

///-----------------------------------------------------///

/// Instructions:
/// Design an algorithm that calculates the sales tax and
/// the price of an item sold in a particular state
/// The sales tax calculated is as follows:
/// State: 4%, City: 1.5%, If luxury item: 10%

///-----------------------------------------------------///

/// Include IOstream header for std::cin and std::cout
#include <iostream>

/// Using this namespace enables us to just type 'cin', 'cout', and 'endl'
/// rather than 'std::cin', 'std::cout', and 'std::endl'
/// All the standard library identifiers provided by the standard header files like
/// <iostream>, <string>, <vector>, etc. are declared in the std namespace.
using namespace std;

/// Here we define our own namespace where we can store our constants
namespace tax_rate
{
    const double state = 0.04;
    const double city = 0.015;
    const double luxury = 0.10;
}
/// The main function is the entry point of the program.
/// This function is called automatically at the start
/// of the program and cannot be called from within the program.
int main()
{
    /// Declare variables
    double sale_price; // The selling price of the item in dollars
    double state_tax; // The dollar value of taxes collected by the state
    double city_tax; // The dollar value of taxes collected by the city

    // luxury tax is given an initial value of zero, this way we can safely add it
    // to the final sale price even if it isn't set as a luxury item.
    double luxury_tax = 0.f; // The dollar value of taxes collected for luxury items.
    bool is_luxury = false; // whether or not the item is considered luxury
    char luxury_char = ' '; // a character read from the console to determine if the item is luxury

    /// Prompt the user for the selling price of the item.
    cout << "What is the price of the item?" << endl;
    /// Read the sale price from user input
    cin >> sale_price;
    /// Print the sale price to confirm it was read correctly
    cout << "The sale price is: " << sale_price << endl;
    /// Ask the user if it is a luxury item.
    cout << "is it a luxury item (y or n)" << endl;
    /// read in user response
    cin >> luxury_char;
    /// If the first character of the users response is 'y'
    // Everything withing the {} brackets after the if statement
    // will run if and only if the condition within () is true
    if (luxury_char == 'y')
    {
        /// Then confirm it is a luxury item and calculate the luxury tax
        // as a reminder that this code is part of an if block, it should be indented.
        // this is also true of code within functions, loops, etc.
        cout << "It is a luxury item" << endl;
        luxury_tax = sale_price*tax_rate::luxury;
    }
    /// Calculate state tax
    state_tax = sale_price * tax_rate::state;
    /// Calculate City tax
    city_tax = sale_price * tax_rate::city;
    /// Calculate sale price
    sale_price = sale_price + state_tax + city_tax + luxury_tax;
    /// Output the results to the console
    cout << "The total price is $" << sale_price << endl;

    /// a return value of 0 indicates that the program executed successfully.
    /// If the program encounters an error and needs to terminate early,
    /// it can return a non-zero value to indicate an error has occurred.
    return 0;
}
