#include "Randomizer.h"
#include <iostream>

using namespace std;

int Randomizer::in_range(int min, int max)
{
    double rv = std::rand();
    double normalized = rv / RAND_MAX;
    //just a lerp pretty much
    int val = std::round(min + (max - min) * normalized);
    return val;
}

void Randomizer::init(int seed)
{
    //aaaaaa
}
