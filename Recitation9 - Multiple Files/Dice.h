#ifndef DICE_H_INCLUDED
#define DICE_H_INCLUDED

class Dice
{
    int side_count;
  public:
    int get_sides() const;
    void set_sides(const int sides);
    int roll(int num_times = 1);
    Dice(int num_sides=6) : side_count(num_sides){}
};



#endif // DICE_H_INCLUDED
