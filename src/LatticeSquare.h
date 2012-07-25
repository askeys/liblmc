/*
 *  LatticeSquare.h
 *  LatticeSquare
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LatticeSquare_H
#define _LatticeSquare_H

#include "Lattice.h"

namespace lmc
{
    class LatticeSquare : public Lattice
    {
        public:
            LatticeSquare(int=400);
            ~LatticeSquare();
        
            std::vector<int>& getNbrs(int i);
            std::vector<double> getPositionOfCell(int);

        protected:
            int _ncelldim;
            std::vector<std::vector<int> > _nbrs;
    };
}

#endif
