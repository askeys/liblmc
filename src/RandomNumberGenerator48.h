/*
 *  RandomNumberGenerator48.h
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RandomNumberGenerator48_H
#define RandomNumberGenerator48_H

#include "RandomNumberGenerator.h"

namespace lmc
{

    /**
    \brief The RandomNumberGenerator48 rng from the unix standard library
    \ingroup rng
    \warning this rng is not available in Visual Studio

    Implements the standard library using RandomNumberGenerator48 generators.  This rng is fairly
    robust and tends to give an unbiased distribution with a long period.  
    */
    class RandomNumberGenerator48 : public RandomNumberGenerator
    {
        public:
            RandomNumberGenerator48(unsigned short=11, unsigned short=7, unsigned short=19);
            RandomNumberGenerator48(unsigned short seed[3]);
            virtual ~RandomNumberGenerator48();
            
            void setSeed(unsigned short seed[3]);
            double randDouble();
            int randInt();
            
        private:
            unsigned short _seed[3];
    };

}
#endif
