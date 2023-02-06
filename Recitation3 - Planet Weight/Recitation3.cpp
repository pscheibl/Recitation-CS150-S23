/// CS 150 Recitation Exercise 3
/// Peter Scheible
/// January 30, 2023

///-----------------------------------------------------///

/// Instructions:
/// Ask the user to input a weight and a planet
/// convert and output what that weight would be
/// On the chosen planet
/// if the user’s weight is 150 pounds, then the user’s weight on Mars is 150*0.3507 = 52.605

///-----------------------------------------------------///

/// Include IOstream header for std::cin and std::cout
#include <iostream>
/// Include string header for std::string
#include <string>

/// Using this namespace enables us to just type 'cin', 'cout', and 'endl'
/// rather than 'std::cin', 'std::cout', and 'std::endl'
/// All the standard library identifiers provided by the standard header files like
/// <iostream>, <string>, <vector>, etc. are declared in the std namespace.
using namespace std;


/// Here we define our own namespace where we can store our constants
namespace planet_factor
{
    const double mercury = 0.4155;
    const double venus = 0.8975;
    const double earth = 1.0;
    const double mars = 0.3507;
    const double jupiter = 2.5374;
    const double saturn = 1.0677;
    const double uranus = 0.8947;
    const double neptune = 1.1794;
    const double pluto = 0.0899;
}

int main()
{
    /// Declare variables
    double weight_earth;
    double weight_planet;
    string planet_name;
    /// Prompt user for a weight on earth
    cout << "What is the weight of the object on earth: ";
    /// Read input weight
    cin >> weight_earth;
    /// Prompt user for name of planet
    cout << "What is the name of the planet you are converting to: ";
    /// Read planet name
    cin >> planet_name;

    /// Convert planet name to Title case i.e "PLUTO" becomes "Pluto"
    for(int i = 1; i < planet_name.length(); i++) //loop from 2nd character (index 1) to the end)
    {
        planet_name[i] = tolower(planet_name[i]); //convert each character to lowercase
    }
    planet_name[0] = toupper(planet_name[0]); // convert the first character (index 0) to uppercase

    /// Check if the planet name is equal to a known planet.
    /// If so, use a conversion factor for that planet to get the new weight
    /// Otherwise, Print an error message and terminate the program.
    if(planet_name == "Mercury") /// If blocks run only when the condition given is true
    {
        weight_planet = weight_earth * planet_factor::mercury;
    }
    else if(planet_name == "Venus") /// Else if blocks run only if the condition is true and connected previous conditions aren't
    {
        weight_planet = weight_earth * planet_factor::venus;
    }
    else if(planet_name == "Earth")
    {
        weight_planet = weight_earth * planet_factor::earth;
    }
    else if(planet_name == "Mars")
    {
        weight_planet = weight_earth * planet_factor::mars;
    }
    else if(planet_name == "Jupiter")
    {
        weight_planet = weight_earth * planet_factor::jupiter;
    }
    else if(planet_name == "Saturn")
    {
        weight_planet = weight_earth * planet_factor::saturn;
    }
    else if(planet_name == "Uranus")
    {
        weight_planet = weight_earth * planet_factor::uranus;
    }
    else if(planet_name == "Neptune")
    {
        weight_planet = weight_earth * planet_factor::neptune;
    }
    else if(planet_name == "Pluto")
    {
        cout << "Pluto's not a real planet, but okay..." << endl;
        weight_planet = weight_earth * planet_factor::pluto;
    }
    else /// else blocks run when none of the above connected conditions are true
    {
        cout << planet_name << " was not recognized as a planet. check your spelling." << endl;
        return 1; /// Terminates the program early so it doesn't try to print an invalid result
    }
    /// Print the newly converted weight to the console.
    cout << "The weight on " << planet_name <<" is " << weight_planet << endl;
    return 0;
}
