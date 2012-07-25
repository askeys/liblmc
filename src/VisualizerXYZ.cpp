/*
 *  VisualizerXYZ.cpp
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "VisualizerXYZ.h"

namespace lmc
{
    VisualizerXYZ::VisualizerXYZ(const char* filename)
        : _os(filename)
    {
    }

    VisualizerXYZ::~VisualizerXYZ()
    {
    }
        
    void VisualizerXYZ::visualize(Simulation& sim)
    {
        Lattice& lattice = sim.getLattice();
        std::vector<double> spin = sim.getSpins();
        int n = lattice.getN();
        
        _os << 2*n << "\n\n";
                
        for (int i=0; i<n; i++) {
            std::vector<double> x = lattice.getPositionOfCell(i);
            x.resize(3, 0.0);
            if (spin[i] > 0) {
                _os << "O" << "\t" << x[0] << "\t" << x[1] << "\t" << x[2] << "\n";
            }
            else {
                _os << "O\t0\t0\t-1\n";
            }

        }
        for (int i=0; i<n; i++) {
            std::vector<double> x = lattice.getPositionOfCell(i);
            x.resize(3, 0.0);
            if (spin[i] < 0) {
                _os << "N" << "\t" << x[0] << "\t" << x[1] << "\t" << x[2] << "\n";
            }
            else {
                _os << "N\t0\t0\t-1\n";
            }
        }
        
        
    }
}
