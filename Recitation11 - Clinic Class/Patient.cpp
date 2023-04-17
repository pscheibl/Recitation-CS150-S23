#include "Patient.h"

Patient::Patient()
{
    m_name = "John";
    m_birth_state = "Confusion";
    m_birth_year = 0;
    m_gender = Other;
}

std::string Patient::get_gender_string()
{
    switch(m_gender)
    {
    case Male:
        return "Male";
    case Female:
        return "Female";
    case Other:
        return "Other";
    }
    return "Other";
}

