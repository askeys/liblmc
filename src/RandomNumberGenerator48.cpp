/*
 *  RandomNumberGenerator48.cpp
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "RandomNumberGenerator48.h"
#include <cstdlib>

namespace lmc
{

    RandomNumberGenerator48::RandomNumberGenerator48(unsigned short s0, unsigned short s1, unsigned short s2)
    {
        _seed[0] = s0;
        _seed[1] = s1;
        _seed[2] = s2;	
    }

    RandomNumberGenerator48::RandomNumberGenerator48(unsigned short seed[3])
    {
        setSeed(seed);
    }

    RandomNumberGenerator48::~RandomNumberGenerator48()
    {
    }

    void RandomNumberGenerator48::setSeed(unsigned short seed[3])
    {
        _seed[0] = seed[0];
        _seed[1] = seed[1];
        _seed[2] = seed[2];
    }

    double RandomNumberGenerator48::randDouble()
    {
        return erand48(_seed);
    }

    int RandomNumberGenerator48::randInt()
    {
        return nrand48(_seed);
    }
}