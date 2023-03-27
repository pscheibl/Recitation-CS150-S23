/**
 File: Recitation9.cpp
 Name: Peter Scheible
  UIN: 01033145
 Date: 2023-03-27
  CRN: 21793
 Prof: Soad Ibrahim (ibrahim@cs.odu.edu)
   TA: Peter Scheible (psche004@odu.edu)
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Dice.h"
using namespace std;

int main()
{
    srand(time(0));
    Dice d20(20);
    cout << "d20 has " << d20.get_sides() << " sides." << endl;
    cout << "rolling d20 3 times gave us " << roll_D20_3_times() << endl;
    return 0;
}
