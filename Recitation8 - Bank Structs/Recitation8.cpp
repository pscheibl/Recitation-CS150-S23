#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/// Struct Declaration
struct BankAccount
{
    int id;
    string name_last;
    string name_first;
    int phone;
    int ssn;
    string date_birth;
    float balance_checking;
    float balance_saving;
    float interest_saving;

}; /// Note the struct ends with a semicolon since it is considered a declaration rather than a definition.

/// Function Prototypes
void read_input(BankAccount customerList[]);
void calculate_interest(BankAccount customerList[]);
void print_accounts(BankAccount customerList[]);


int main()
{
    /// Array of structs
    BankAccount customers [20];

    /// read data form the input file
    read_input(customers);

    /// calculate interest
    calculate_interest(customers);

    /// output data
    print_accounts(customers);

    return 0;
}


/**
read user data from input file (input.txt) into an array of structs.
For simplicity, We're assuming a constant 20 users for our bank
*/
void read_input(BankAccount customerList[])
{

    /// Declare input stream variable
    ifstream inData("input.txt");
    /// use a loop to read the data
    for (int i=0; i<20; i++)
    {
        inData >> customerList[i].id
               >> customerList[i].name_last
               >> customerList[i].name_first
               >> customerList[i].phone
               >> customerList[i].ssn
               >> customerList[i].date_birth
               >> customerList[i].balance_checking
               >> customerList[i].balance_saving;
    }
}



/**
Calculate the Interest for the 20 customers in the array
interest is calculated based on the balance in the saving account:
From $0 to $1000		interest is 1.00%
From $1001 to $5000		interest is 1.50%
From $5001 to $10000	interest is 1.75%
More than $10000		interest is 2.00%
*/
void calculate_interest(BankAccount customerList[])
{
    for (int i=0; i<20; i++)
    {
        if (customerList[i].balance_saving > 10000)
            customerList[i].interest_saving = customerList[i].balance_saving * 2/100;
        else if (customerList[i].balance_saving > 5001)
            customerList[i].interest_saving = customerList[i].balance_saving * 1.75/100;
        else if (customerList[i].balance_saving > 1001)
            customerList[i].interest_saving = customerList[i].balance_saving * 1.5/100;
        else if (customerList[i].balance_saving > 0)
            customerList[i].interest_saving = customerList[i].balance_saving * 1/100;
        else
            customerList[i].interest_saving = 0;
    }

}

/**
Print accounts
Prints Header information along with a table of all users account info.
*/
void print_accounts(BankAccount customerList[])
{
   /// programmer information
   cout << "Programmer : Peter Scheible" << endl
        << "UIN        : 01033145" << endl
        << "Date       : 2023-03-20" << endl << endl;

    cout << setw(95)<< setfill('*')<< ""<< endl
         << setw(50)<< setfill(' ')<< "NewCity Bank"<< endl
         << setw(95)<< setfill('*')<< ""<< endl << endl;

    cout << left << setfill(' ');

    /// print the title
    cout << setw(11) << "Account NO"
         << setw(10) << "Last Name"
         << setw(11) << "First Name"
         << setw(13) << "Phone Number"
         << setw(10) << "SSN"
         << setw(12) << "Birth Date"
         << setw(10) << "Checking"
         << setw(10) << "Saving"
         << setw(10) << "interest"<< endl;
    cout << setw(11) << "=========="
         << setw(10) << "========="
         << setw(11) << "=========="
         << setw(13) << "============"
         << setw(10) << "==="
         << setw(12) << "=========="
         << setw(10) << "========"
         << setw(10) << "======"
         << setw(10) << "========"<< endl;


    cout <<fixed << showpoint << setprecision(2);
    /// use a loop to output the data
    for (int i=0; i<20; i++)
    {

        cout << setw(11) << customerList[i].id
             << setw(10) << customerList[i].name_last
             << setw(11) << customerList[i].name_first
             << setw(13) << customerList[i].phone
             << setw(10) << customerList[i].ssn
             << setw(12) << customerList[i].date_birth
             << setw(10) << customerList[i].balance_checking
             << setw(10) << customerList[i].balance_saving
             << setw(10) << customerList[i].interest_saving << endl;
    }
}
