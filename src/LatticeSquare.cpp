/*
 *  LatticeSquare.h
 *  LatticeSquare
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "LatticeSquare.h"
#include <cmath>
#include <iostream>

namespace lmc
{
    LatticeSquare::LatticeSquare(int n)
        : Lattice(n, 2)
    {

        _ncelldim = rint(sqrt(n));
        _nbrs.resize(_ncelldim*_ncelldim);

        for (int j=0; j<_ncelldim; j++) {
            for (int k=0; k<_ncelldim; k++) {
									
				int c = k + j*_ncelldim;
									
				for (int y=-1; y<=1; y++) {
                    for (int z=-1; z<=1; z++) {
                        
                        //don't include the cell itself as a neighbor
                        if (y==0 && z==0) {
                        continue;
                        }
                                                                    
                        //Integer division is for periodic boundary conditions.
                        int neighbor =	(j+y+_ncelldim)%_ncelldim*_ncelldim + 
                                        (k+z+_ncelldim)%_ncelldim;
                        _nbrs[c].push_back(neighbor);
                    }
                }
            }
        }
    }
    
    LatticeSquare::~LatticeSquare()
    {
    }
            
    std::vector<int>& LatticeSquare::getNbrs(int i)
    {
        return _nbrs[i];
    }
    
    std::vector<double> LatticeSquare::getPositionOfCell(int icell)
	{
		std::vector<double> x_cell(_dim, 0.0);		
		x_cell[0] = icell/(_ncelldim)%_ncelldim - _ncelldim/2;
		x_cell[1] = icell%_ncelldim - _ncelldim/2;
		return x_cell;
	}
}
