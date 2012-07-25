/*
 *  Lattice.h
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LATTICE_H
#define _LATTICE_H

#include <vector>

namespace lmc
{
    class Lattice
    {
        public:
            Lattice(int=1000, int=3);
            ~Lattice();
        
            int getN();
            int getDimensions();
            virtual std::vector<int>& getNbrs(int i);
            virtual std::vector<double> getPositionOfCell(int);
            
        protected:
            int _n;
            int _dim;
    };
}

#endif
