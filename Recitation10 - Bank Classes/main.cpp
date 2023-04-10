#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "BankAccount.h"
using namespace std;

/// Function Prototypes
void read_input(BankAccount customerList[]);
void print_accounts(BankAccount customerList[]);


int main()
{
    /// Array of structs
    BankAccount customers [20];

    /// read data form the input file
    read_input(customers);

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
    /// Since we can't directly read into the member functions from outside the class
    /// we need to Declare local variables to pass to setter functions;
    int id;
    std::string name_last;
    std::string name_first;
    int phone;
    int ssn;
    std::string date_birth;
    float balance_checking;
    float balance_saving;
    float interest_saving;
    
    /// Declare input stream variable
    ifstream inData("input.txt");
    /// use a loop to read the data
    for (int i=0; i<20; i++)
    {
      /// Read into the local variables
        inData >> id
               >> name_last
               >> name_first
               >> phone
               >> ssn
               >> date_birth
               >> balance_checking
               >> balance_saving;
       /// Call setter functions to pass copies of the local variables to the customers member variables
        customerList[i].set_id(id);
        customerList[i].set_name_last(name_last);
        customerList[i].set_name_first(name_first);
        customerList[i].set_phone(phone);
        customerList[i].set_ssn(ssn);
        customerList[i].set_date_birth(date_birth);
        customerList[i].set_balance_checking(balance_checking);
        customerList[i].set_balance_saving(balance_saving);
       /// After we've set the other member variables, we can call calculate interest on the customer to set their interest member variable 
        customerList[i].calculate_interest(); 
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
        /// Now uses getter functions rather than directly accessing the member variables
        cout << setw(11) << customerList[i].get_id()
             << setw(10) << customerList[i].get_name_last()
             << setw(11) << customerList[i].get_name_first()
             << setw(13) << customerList[i].get_phone()
             << setw(10) << customerList[i].get_ssn()
             << setw(12) << customerList[i].get_date_birth()
             << setw(10) << customerList[i].get_balance_checking()
             << setw(10) << customerList[i].get_balance_saving()
             << setw(10) << customerList[i].get_interest_saving() << endl;
    }
}
