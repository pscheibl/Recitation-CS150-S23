/**
Mock Midterm Task 1: Florist

The regular price for one dozen of roses is say $20.00 including the tax.
 For special occasions, such as a wedding, the shop offers a
 special discount as follows:
• If the number of dozens of roses is at least 10, the discount is 10%
• If the number of dozens of roses is at least 20, the discount is 20%
• If the number of dozens of roses is at least 30, the discount is 30%

Design an algorithm and write a C++ program that prompts the user to enter the number of dozens of roses to be purchased. The program calculates the total price and applies the discount based on the number of dozens. The program outputs the following:
• The percent of the discount (if there is a discount)
• The amount of discount (if there is a discount)
• The total price 
*/


#include <iostream>
#include <iomanip>

using namespace std;
// constant value for the price of a dozen roses
const double price_per_dozen = 20.f;
// Function prototype for computing the discount rate
double compute_discount(int dozens);
int main()
{
	// Declare Variables for number of roses, discount, and final price
    int dozens;
    double discount_rate, discount_dollars, price;
	// Prompt user for number of roses
    cout << "Enter how many dozens of roses you want to buy: ";
	// Read in number of roses
    cin >> dozens;
    if(dozens <= 0)
    {
        cout << "Can't purchase fewer than 1 dozen roses" << endl;
        return 1;
    }

	// Determine discount
    discount_rate = compute_discount(dozens);
	// Calculate the MSRP as dozens of roses times 20
    price = price_per_dozen * dozens;
	// Calculate the Discount as MSRP * discount_rate
    discount_dollars = price * discount_rate;
	// Calculate final price as MSRP - Discount
    price -= discount_dollars;
	// output results
    cout << fixed << showpoint << setprecision(2);
	// only output discount information if a discount was applied 
    if (discount_dollars > 0)
    {
        cout << "You recieved a " << discount_rate*100 <<"% discount." << endl;
        cout << "You saved $" << discount_dollars << " on this purchase." << endl;
    }
	// print final price
    cout << "Your final price is $" << price << endl;

    return 0;
}

double compute_discount(int dozens)
{
	//	If dozens of roses is >= 30:
    if (dozens >= 30)
		//	Give 30% discount
        return 0.3;
	//	Else If dozens of roses is >= 20:
    else if (dozens >= 20)
	// Give 20% Discount
        return 0.2;
	// Else if dozens of roses >= 10:
    else if (dozens >= 10)
	// Give 10% discount
        return 0.1;
	//	Else charge base price
    else
        return 0;
}
