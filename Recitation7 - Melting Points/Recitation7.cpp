#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void selection_sort(double melting_points[], string metal_names[], int length);


int main()
{
    /// Arrays are fixed size, so the size has to be known before it's initialized
    const int numberOfMetals = 14;

    /// Declare the Arrays
    string metals[numberOfMetals];
    /// Using '= {0}' initialized each element of the array to 0
    double temperature[numberOfMetals] = {0};

    /// Open input.txt with the melting point of each metal and it's name
    ifstream inData;
    inData.open("input.txt");

    /// Print table header
    cout<< left;
    cout << setw (20) << "Melting Temperature" << setw(11) <<" Metal"<< endl;
    cout << setw (20) << "-------------------" << setw(11) <<" -----"<< endl;


    for (int i = 0; i < numberOfMetals; i++) ///Loop through number of elements
    {
        inData >> temperature[i]; ///Read in Melting temperature
        getline(inData, metals[i]); ///Read in metal name
        cout<< left;
        ///Print melting temperature and name
        cout << setw (20) <<temperature[i] << setw (7) <<metals[i]<< endl;
    }

    /// call the function sort() to sort the array
    selection_sort(temperature, metals, numberOfMetals);


    /// print the output
    cout << endl << endl;

    cout << "The sorted array" << endl;
    cout << "----------------" << endl<< endl;

    cout<< left;
    cout << setw (20) << "Melting Temperature" << setw(11) <<" Metal"<< endl;
    cout << setw (20) << "-------------------" << setw(11) <<" -----"<< endl;

    /// use a loop to print the output
    for (int i = 0; i < numberOfMetals; i++)
    {
        cout<< left;
        cout << setw (20) <<temperature[i] << setw (7) << metals[i] << endl;
    }

    cout << endl;
    cout << "The metal with the highest melting temperature is:"<< metals[0]<< endl;

    return 0;
}
/**
Selection sort is a simple and efficient sorting algorithm that works by repeatedly
selecting the smallest (or largest) element from the unsorted portion of the array
and moving it to the sorted portion of the array.
*/
void selection_sort(double melting_points[], string metal_names[], int length)
{
    int index_unsorted_begin;
    int index_max;
    int index_current;
    int temp;
    string temp_metal;

    for (index_unsorted_begin = 0; index_unsorted_begin < length; index_unsorted_begin++)
    {
        index_max = index_unsorted_begin;
        ///Find the index of the largest element in the smaller array and store it in smallestIndex

        for (index_current = index_unsorted_begin + 1; index_current < length; index_current++)
            if (melting_points[index_current] > melting_points[index_max])
                index_max = index_current;

        ///Use the index_max variable to swap the largest variable with the first position of the subarray

        temp = melting_points[index_max];
        melting_points[index_max] = melting_points[index_unsorted_begin];
        melting_points[index_unsorted_begin] = temp;

        ///Swap the metals in metals array the same way you swap the melting temperature

        temp_metal = metal_names[index_max];
        metal_names[index_max] = metal_names[index_unsorted_begin];
        metal_names[index_unsorted_begin] = temp_metal;
    }
}


