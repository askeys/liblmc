/*
 *  Lattice.h
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Lattice.h"
#include <cassert>
#include <iostream>

namespace lmc
{
    Lattice::Lattice(int n, int dim)
        : _n(n), _dim(dim)
    {
        assert(dim > 0);
    }
    
    Lattice::~Lattice()
    {
    }
        
    int Lattice::getN()
    {
        return _n;    
    }

    int Lattice::getDimensions()
    {
        return _dim;    
    }
    
    std::vector<int>& Lattice::getNbrs(int i)
    {
        std::cerr << "Virtual function: Lattice::getNbrs(int) must be defined\n"; 
        assert(0);
    }

    std::vector<double> Lattice::getPositionOfCell(int)
    {
        std::cerr << "Warning: virtual function: populate(std::vector<int>&) does nothing\n"; 
    
        return std::vector<double>();
    }

}
