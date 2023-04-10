#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int num_members = 20;

struct Insuree
{
    string name_first;
    string name_last;
    char indicator;
    int age;

    /// Member function that returns the annual premium of the member while adding to the associated counters
    double premium_annual(int &dis_count, double& M_revenue, double& F_revenue, double& T_revenue,
                               double& S_revenue, double& A_revenue);
};

void read_member_info(Insuree members[]);
void print_member_info(Insuree members[]);

int main()
{
    Insuree* members;
    members = new Insuree[num_members];
    read_member_info(members);
    print_member_info(members);
    delete[] members;
    return 0;
}

void read_member_info(Insuree members[])
{
    ifstream in_file;
    in_file.open("input.txt");
    for(int i = 0; i < num_members; i++)
    {
        in_file >> members[i].name_first >>
                   members[i].name_last  >>
                   members[i].age >>
                   members[i].indicator;
    }
    in_file.close();
}
void print_member_info(Insuree members[])
{
    int dis_count = 0;
    double M_revenue = 0, F_revenue = 0, T_revenue = 0, S_revenue = 0, A_revenue = 0;
    cout << left << fixed << showpoint << setprecision(2);
    cout << setw(15) << "First Name " << setw(15) << "Last Name " << setw(10) << "Indicator " << setw(5) << "Age " << setw(10) << "Cost " << endl;
    for(int i = 0; i < num_members; i++)
    {
        cout << setw(15) << members[i].name_first
             << setw(15) << members[i].name_last
             << setw(10) << members[i].indicator
             << setw(5) << members[i].age << setw(10)
             << members[i].premium_annual(dis_count, M_revenue, F_revenue, T_revenue, S_revenue, A_revenue) << endl;
    }
    cout << "\nTotal number of customers eligible for the discount: " << dis_count << endl << endl;
    cout << "Total revenue from each indicator" << endl;
    cout << "F: $" << F_revenue << endl;
    cout << "M: $" << M_revenue << endl;
    cout << "T: $" << T_revenue << endl;
    cout << "S: $" << S_revenue << endl;
    cout << "A: $" << A_revenue << endl;
}
double Insuree::premium_annual(int &dis_count, double& M_revenue, double& F_revenue, double& T_revenue,
                               double& S_revenue, double& A_revenue)
{
    double premium_annual;
    double discount_multiplier = 1;
    if(age < 35)
    {
        dis_count++;
        discount_multiplier = 0.8;
    }
    switch(indicator)
    {
    case 'M':
        premium_annual = 12*61.5*discount_multiplier;
        M_revenue += premium_annual;
        break;
    case 'F':
        premium_annual = 12*55*discount_multiplier;
        F_revenue += premium_annual;
        break;
    case 'T':
        premium_annual = 12*89*discount_multiplier;
        T_revenue += premium_annual;
        break;
    case 'S':
        premium_annual = 12*72.5*discount_multiplier;
        S_revenue += premium_annual;
        break;
    case 'A':
        premium_annual = 12*9*discount_multiplier;
        A_revenue += premium_annual;
        break;
    }
    return premium_annual;
}
