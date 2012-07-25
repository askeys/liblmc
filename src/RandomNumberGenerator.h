/*
 *  RandomNumberGenerator.h
 *  lattice
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

/**
\brief The random number generator used by the path sampling algorithm
\ingroup core

Provides an interface for obtaining a random floating point number or integer.  
Also computes some different random distributions.
*/

namespace lmc
{
    class RandomNumberGenerator
    {
        public:
            RandomNumberGenerator();
            virtual ~RandomNumberGenerator();
            
            double randUniform(double min=0.0, double max=1.0);
            double randNormal(double mean=0.0, double stdev=1.0);

            virtual double randDouble();
            virtual int randInt();
            
        protected:
            bool _save;
            double _second;

    };
}
#endif
