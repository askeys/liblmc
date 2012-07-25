/*
 *  Visualizer.h
 *  Visualizer
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _Visualizer_H
#define _Visualizer_H

#include "Simulation.h"

namespace lmc
{
    class Visualizer
    {
        public:
            Visualizer();
            ~Visualizer();
        
            virtual void visualize(Simulation&);
            
        protected:
    };
}

#endif
