/*
 *  VisualizerXYZ.h
 *  VisualizerXYZ
 *
 *  Created by Aaron Keys on 7/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _VisualizerXYZ_H
#define _VisualizerXYZ_H

#include "Visualizer.h"
#include <fstream>

namespace lmc
{
    class VisualizerXYZ : public Visualizer
    {
        public:
            VisualizerXYZ(const char *);
            //VisualizerXYZ(std::ostream& os);
            ~VisualizerXYZ();
        
            void visualize(Simulation&);
            
        protected:
            std::ofstream _os;
    };
}

#endif
