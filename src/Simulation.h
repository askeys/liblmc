/*
 *  Simulation.h
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _Simulation_H
#define _Simulation_H

#include "RandomNumberGenerator.h"
#include "Lattice.h"

#include <vector>

namespace lmc
{

    class Simulation
    {
        public:
            Simulation(Lattice&, RandomNumberGenerator&);
            ~Simulation();
        
            virtual void run(int);
            std::vector<double>& getSpins();
            void setSpins(std::vector<double>&);
            
            void setNMovesPerCycle(double);
            double getNMovesPerCycle();
            
            Lattice& getLattice();

            virtual double computeEnergy(int);
            virtual double computeEnergy();
            
        protected:
            double _nmovespercycle;
            std::vector<double> _spin;
            Lattice& _lattice;
            RandomNumberGenerator& _rng;
            
    };
}

#endif
