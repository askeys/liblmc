/*
 *  SimulationIsingModel.h
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _SimulationIsingModel_H
#define _SimulationIsingModel_H

#include "Simulation.h"

#include <vector>

namespace lmc
{

    class SimulationIsingModel : public Simulation
    {
        public:
            SimulationIsingModel(Lattice&, RandomNumberGenerator&);
            ~SimulationIsingModel();
        
            void setCouplingMatrix(std::vector< std::vector<double> >&);
            void setBeta(double);
            void setField(double);
            
            void run(int);

            double computeEnergy(int);
            double computeEnergy();

            
        protected:
            int _n;
            double _B;
            double _beta;
            std::vector< std::vector<double> > _J;

            int attemptFlip(int);
            double computePairEnergy(int);
            double computeFieldEnergy(int);
            
    };
}

#endif
