#include <iostream>
#include <fstream>

using namespace std;

/** Function Prototypes:  these are a declaration of a function's signature,
* which includes the function name, its parameter list, and return type, without actually defining the function.
* It serves as a blueprint for the compiler, informing it of the existence and interface of a function that will be defined later in the code.
*
* Note: parameters with a & are passed by reference, a way of passing function arguments where a reference to the original value is passed
* to the function rather than a copy of the value. This means that changes made to the value inside the function also affect the
* original value outside the function. by default, values are passed as copies so changes to them in the function do not effect the original.
*/
void add_vowel(char character, unsigned &count_a, unsigned &count_e,
               unsigned &count_i, unsigned &count_o, unsigned &count_u,
               unsigned &count_misc);
void print_counts(unsigned count_a, unsigned count_e, unsigned count_i,
                  unsigned count_o, unsigned count_u, unsigned count_other);
int main()
{
    /// Declare variables for current character, and character counters.
    unsigned int count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0, count_misc = 0;
    char current;
    // Open the paragraph file
    ifstream in_file("paragraph.txt");
    // Ensure the file opened correctly.
    if(!in_file)
    {
        cerr << "Error opening \"paragraph.txt\" Make sure it's in the right place." << endl;
        return 1;
    }
    // Do a EOF controlled while loop reading in one character at a time.
    while(in_file.get(current))
    {
        // Call The add vowel function on the current character.
        add_vowel(current, count_a, count_e, count_i, count_o, count_u, count_misc);
    }
    // Close input file.
    in_file.close();
    // Print the character counts.
    print_counts(count_a,count_e, count_i, count_o, count_u, count_misc);
    return 0;
}

/**-------------------------------------------Funcion Definitions-----------------------------------
* A function definition is a block of code that specifies how a particular function operates.
* It includes the function's signature, its body or implementation,
* and possibly a return statement that specifies the value the function should return to the caller.
*---------------------------------------------------------------------------------------------------

/**
* Adds to the counter corresponding to the current character.
* \param[in] character The character thats being processed.
* \param count_a The number of instances of 'A' or 'a'
* \param count_e The number of instances of 'E' or 'e'
* \param count_i The number of instances of 'I' or 'i'
* \param count_o The number of instances of 'O' or 'o'
* \param count_u The number of instances of 'U' or 'u'
* \param count_misc The number of instances of non-vowel characters.
*/
void add_vowel(char character, unsigned &count_a, unsigned &count_e,
               unsigned &count_i, unsigned &count_o, unsigned &count_u,
               unsigned &count_misc)
{
    // Use a switch structure to determine which vowel counter to add to
    switch(toupper(character))
    {
    // Case A/a, add to A counter.
    case 'A':
        count_a++;
        break;
    // Case E/e, add to E counter.
    case 'E':
        count_e++;
        break;
    // Case I/i, add to I counter.
    case 'I':
        count_i++;
        break;
    // Case O/o, add to O counter.
    case 'O':
        count_o++;
        break;
    // Case U/u, add to U counter.
    case 'U':
        count_u++;
        break;
    // Default add to other counter.
    default:
        count_misc++;
    }
    return;
}


/**
* Prints to the console the count of each character type.
* \param[in] count_a The number of instances of 'A' or 'a'
* \param[in] count_e The number of instances of 'E' or 'e'
* \param[in] count_i The number of instances of 'I' or 'i'
* \param[in] count_o The number of instances of 'O' or 'o'
* \param[in] count_u The number of instances of 'U' or 'u'
* \param[in] count_misc The number of instances of non-vowel characters.
*/
void print_counts(unsigned count_a, unsigned count_e, unsigned count_i,
                  unsigned count_o, unsigned count_u, unsigned count_other)
{
    cout << "Number of each vowel in the file:" << endl
         << "A/a:\t" << count_a << endl
         << "E/e:\t" << count_e << endl
         << "I/i:\t" << count_i << endl
         << "O/o:\t" << count_o << endl
         << "U/u:\t" << count_u << endl
         << "Misc:\t" << count_other << endl;
}
