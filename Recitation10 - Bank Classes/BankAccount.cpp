    #include <string>
    #include "BankAccount.h"
    int BankAccount::get_id()
    {
        return id;
    }
    std::string BankAccount::get_name_last()
    {
        return name_last;
    }
    std::string BankAccount::get_name_first()
    {
        return name_first;
    }
    int BankAccount::get_phone()
    {
        return phone;
    }
    int BankAccount::get_ssn()
    {
        return ssn;
    }
    std::string BankAccount::get_date_birth()
    {
        return date_birth;
    }
    float BankAccount::get_balance_checking()
    {
        return balance_checking;
    }
    float BankAccount::get_balance_saving()
    {
        return balance_saving;
    }
    float BankAccount::get_interest_saving()
    {
        return interest_saving;
    }
    ///Setter Functions
    void BankAccount::set_id(int in_id)
    {
        id = in_id;
    }
    void BankAccount::set_name_last(std::string in_name_last)
    {
        name_last = in_name_last;
    }
    void BankAccount::set_name_first(std::string in_name_first)
    {
        name_first = in_name_first;
    }
    void BankAccount::set_phone(int in_phone)
    {
        phone = in_phone;
    }
    void BankAccount::set_ssn(int in_ssn)
    {
        ssn = in_ssn;
    }
    void BankAccount::set_date_birth(std::string in_date_birth)
    {
        date_birth = in_date_birth;
    }
    void BankAccount::set_balance_checking(float in_balance_checking)
    {
        balance_checking = in_balance_checking;
    }
    void BankAccount::set_balance_saving(float in_balance_saving)
    {
        balance_saving = in_balance_saving;
    }
    void BankAccount::set_interest_saving(float in_interest_saving)
    {
        interest_saving = in_interest_saving;
    }
    ///Constructor
    BankAccount::BankAccount()
    {
        balance_saving = 0;
        balance_checking = 0;
        interest_saving = 0;
    }
    /**
    Calculate the Interest for the customer
    interest is calculated based on the balance in the saving account:
    From $0 to $1000		interest is 1.00%
    From $1001 to $5000		interest is 1.50%
    From $5001 to $10000	interest is 1.75%
    More than $10000		interest is 2.00%
    */

    void BankAccount::calculate_interest()
    {
        if (balance_saving > 10000)
            interest_saving = balance_saving * 2/100;
        else if (balance_saving > 5001)
            interest_saving = balance_saving * 1.75/100;
        else if (balance_saving > 1001)
            interest_saving = balance_saving * 1.5/100;
        else if (balance_saving > 0)
            interest_saving = balance_saving * 1/100;
        else
            interest_saving = 0;
    }
