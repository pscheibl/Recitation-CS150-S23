#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
/// Class Declaration
class BankAccount
{
    /// Now that BankAccount is a Class, the members are private by default
    int id;
    std::string name_last;
    std::string name_first;
    int phone;
    int ssn;
    std::string date_birth;
    float balance_checking;
    float balance_saving;
    float interest_saving;
    
    public:
    /// Getter Functions return a copy of the value in a member variable
    int get_id();
    std::string get_name_last();
    std::string get_name_first();
    int get_phone();
    int get_ssn();
    std::string get_date_birth();
    float get_balance_checking();
    float get_balance_saving();
    float get_interest_saving();
    
    ///Setter Functions set that value of the member variable to the value of the parameter.
    void set_id(int);
    void set_name_last(std::string);
    void set_name_first(std::string);
    void set_phone(int);
    void set_ssn(int);
    void set_date_birth(std::string);
    void set_balance_checking(float);
    void set_balance_saving(float);
    void set_interest_saving(float);
    ///Constructor is called when a new instance of a class is created.
    BankAccount();
    ///Interest Calculation
    void calculate_interest();
}; /// Note the class ends with a semicolon since it is considered a declaration rather than a definition.

#endif
