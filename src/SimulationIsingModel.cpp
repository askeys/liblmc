/*
 *  SimulationIsingModel.cpp
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "SimulationIsingModel.h"
#include <cassert>
#include <cmath>
#include <iostream>

namespace lmc 
{

    SimulationIsingModel::SimulationIsingModel(Lattice& lattice, RandomNumberGenerator& rng)
        : Simulation(lattice, rng), _B(0.0), _beta(1.0)
    {
        _n = _lattice.getN();
        _nmovespercycle = _n;
        
        assert(_n > 0);

        _spin.resize(_n, -1);
        _J.resize(_n, std::vector<double>(_n, 1.0));

    }

    SimulationIsingModel::~SimulationIsingModel()
    {
    }

    void SimulationIsingModel::setBeta(double beta)
    {
        _beta = beta;
    }

    void SimulationIsingModel::setField(double B)
    {
        _B = B;
    }


    void SimulationIsingModel::run(int nstep)
    {
        for (int i=0; i<nstep; i++) {
            for (int j=0; j<_nmovespercycle; j++) {
                int p = _rng.randInt()%_n;
                attemptFlip(p);
            }
        }
        
    }

    void SimulationIsingModel::setCouplingMatrix(std::vector< std::vector<double> >& J)
    {
        _J = J;
    }

    double SimulationIsingModel::computeEnergy()
    {
        double e = 0.0;
        for (int i=0; i<_n; i++) {
            e += 0.5*computePairEnergy(i);
            e += computeFieldEnergy(i);
        }
        return e;
    }

    double SimulationIsingModel::computeEnergy(int i)
    {
        return (computePairEnergy(i) + computeFieldEnergy(i));
    }

    double SimulationIsingModel::computePairEnergy(int i)
    {
        double e = 0.0;
        std::vector<int>& nbrs = _lattice.getNbrs(i);    
        for (unsigned int jj=0; jj<nbrs.size(); jj++) {
            int j = nbrs[jj];
            e += -_J[i][j]*_spin[i]*_spin[j];
        }
        return e;
    }
    
    double SimulationIsingModel::computeFieldEnergy(int i)
    {
        return (-_B*_spin[i]);
    }

    int SimulationIsingModel::attemptFlip(int i)
    {
        double old_e = computeEnergy(i);
        _spin[i] *= -1.0;
        double new_e = computeEnergy(i);
        
        //std::cerr << old_e << "\t" << new_e << "\t" << exp(-_beta*(new_e - old_e)) << std::endl;
        
        if (new_e < old_e) {
            //std::cerr << 1 << std::endl;
            return 1;
        }
        else if (_rng.randDouble() < exp(-_beta*(new_e - old_e))) {
            //std::cerr << 1 << std::endl;
            return 1;
        }
        else {
            //std::cerr << 0 << std::endl;
            _spin[i] *= -1.0;
            return 0;
        }
        
    }
}