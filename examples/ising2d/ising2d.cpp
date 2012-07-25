//c++ -O3 ising2d.cpp ../../src/*.cpp

#include "../../src/lmc.h"

using namespace lmc;

int L = 30;

int main(int argc, char** argv)
{
    LatticeSquare lattice(L*L);
    RandomNumberGenerator48 rng;
    
    std::vector<double> s0(L*L, -1.0);
    SimulationIsingModel ising(lattice, rng);
    ising.setSpins(s0);
    //Tc = 2.269;
    //ising.setField(8.1);
    
    VisualizerXYZ xyz("traj.xyz");
    
    for (double T=10.0; T>=2.0; T-=0.01) {
        xyz.visualize(ising);
        ising.setBeta(1.0/T);
        ising.run(1);
    }
}