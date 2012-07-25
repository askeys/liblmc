/*
 *  Simulation.cpp
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Simulation.h"
#include <cassert>
#include <cmath>

namespace lmc 
{

    Simulation::Simulation(Lattice& lattice, RandomNumberGenerator& rng)
        : _lattice(lattice), _rng(rng)
    {
    }

    Simulation::~Simulation()
    {
    }

    void Simulation::run(int nstep)
    {
        assert(0);
    }

    void Simulation::setSpins(std::vector<double>& spins)
    {
        _spin = spins;
    }
    
    std::vector<double>& Simulation::getSpins()
    {
        return _spin;
    }
    
    Lattice& Simulation::getLattice()
    {
        return _lattice;
    }

    double Simulation::computeEnergy()
    {
        return 0.0;
    }
    
    double Simulation::computeEnergy(int i)
    {
        return 0.0;
    }

    double Simulation::getNMovesPerCycle()
    {
        return 0.0;
    }

    void Simulation::setNMovesPerCycle(double nmovespercycle)
    {
        _nmovespercycle = nmovespercycle;
    }

}