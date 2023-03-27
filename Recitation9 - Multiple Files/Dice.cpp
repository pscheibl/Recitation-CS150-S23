#include <cstdlib>
#include "Dice.h"


int Dice::get_sides() const
{
    return side_count;
}
void Dice::set_sides(const int sides)
{
    side_count = sides;
}
int Dice::roll(int num_times)
{
    int sum = 0;
    for(int i =0; i < num_times; i++)
        sum += rand() % side_count + 1;
    return sum;
}

int roll_D20_3_times()
{
    Dice d20(20);
    return d20.roll(3);
}
