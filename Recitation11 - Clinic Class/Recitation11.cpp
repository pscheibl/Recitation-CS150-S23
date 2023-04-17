#include <iostream>
#include <iomanip>
#include <fstream>
#include "Patient.h"

using namespace std;
int get_patient_count();
void read_patient_file(Patient patients[], int num_patients);
void print_patient_table(Patient patients[], int num_patients);
int count_gender(Patient patients[], int num_patients, Gender gender);
Patient get_oldest(Patient patients[], int num_patients);

int main()
{
    int num_patients = get_patient_count();
    Patient* patients = new Patient[num_patients];
    read_patient_file(patients, num_patients);
    print_patient_table(patients, num_patients);
    delete[] patients;
}

int get_patient_count()
{
    ifstream in_file("input.txt");
    if(!in_file)
    {
        cerr << "Error opening input file, aborting" << endl;
        exit(1);
    }
    int num_patients = 0;
    string line;
    while(getline(in_file,line))
            num_patients++;
    return num_patients;
}

void read_patient_file(Patient patients[], int num_patients)
{
    ifstream in_file("input.txt");
    if(!in_file)
    {
        cerr << "Error opening input file, aborting" << endl;
        exit(1);
    }
    string name;
    int year;
    string state;
    char gender;
    for(int i = 0; i < num_patients; i++){
        in_file >> name >> year >> state >> gender;
        patients[i].set_name(name);
        patients[i].set_birth_year(year);
        patients[i].set_birth_state(state);
        if (gender == 'M' || gender == 'm')
            patients[i].set_gender(Male);
        else if (gender == 'F' || gender == 'f')
            patients[i].set_gender(Female);
        else
            patients[i].set_gender(Other);
    }
}

void print_patient_table(Patient patients[], int num_patients)
{
    cout << left << setw(10) << "Name" << setw(6) << "Year" << setw(15) << "State" << "Gender" << endl;
    for(int i = 0; i < num_patients; i++)
    {
        cout << setw(10) << patients[i].get_name() << setw(6) << patients[i].get_birth_year() << setw(15) << patients[i].get_birth_state() << patients[i].get_gender_string() << endl;
    }
    cout << "There are a total of " << num_patients << " patients." << endl
         << "There are " << count_gender(patients, num_patients, Male) << " male patients." << endl
         << "There are " << count_gender(patients, num_patients, Female) << " female patients." << endl;
    Patient oldest = get_oldest(patients, num_patients);
    cout << "The oldest patient is " << oldest.get_name() << " who is " << 2023 - oldest.get_birth_year() << endl;
}
int count_gender(Patient patients[], int num_patients, Gender gender)
{
    int gender_count = 0;
    for(int i = 0; i < num_patients; i++)
        if(patients[i].get_gender() == gender)
            gender_count++;
    return gender_count;
}

Patient get_oldest(Patient patients[], int num_patients)
{
    int min_year = patients[0].get_birth_year();
    int min_index = 0;
    for(int i = 1; i < num_patients; i++)
    {
        if(patients[i].get_birth_year() < min_year)
        {
            min_year = patients[i].get_birth_year();
            min_index = i;
        }
    }
    return patients[min_index];
}
