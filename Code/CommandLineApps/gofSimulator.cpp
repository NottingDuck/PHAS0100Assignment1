/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <golGrid2d.h>
#include <golGameofLife.h>
#include <golExceptionMacro.h>
#include <iostream>

// Example, header-only library, included in project for simplicity's sake.


/**
 * \brief Demo file to check that includes and library linkage is correct.
 */

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name
    << "Options:\n"
    << "\tOption1 (File Path Input):\tUsers should specify .1) .txt FilePath .2) number of Generations.\n"
    << "\tOption2 (Random Cell Contents):\tUsers should input .1) Grid Row .2) Grid Column .3) the number of random Alive cells .4) number of Generations.\n"
    << "Options:\n"
    << "\t-h,--help\t\t\tShow this help message.\n"
    << std::endl;
}

int main(int argc, char** argv)
{   
    // -h and --help:
    if (argc == 2){
        if((argv[1] == "-h") or (argv[1] == "--help")){
            show_usage(argv[0]);
            return 0;
        }
        else{
            show_usage(argv[0]);
            return 0;
        }
    }
    
    // Option 1: Input File Path:
    if(argc == 3){
        std::string FilePath;
        FilePath = argv[1];
        int iteration = std::stoi(argv[2]);
        
        gol::Grid2d grid2d = gol::Grid2d(FilePath);
        gol::GameofLife gol = gol::GameofLife(grid2d);

        for (int iter = 0; iter < iteration; iter++){
            gol.TakeStep();
        }

        gol.PrintGrid();
        
        return 1;
    }
    
    // Option 2: Random Alive:
    if (argc == 5){
        int row = std::stoi(argv[1]);
        int column = std::stoi(argv[2]);
        int numAlive = std::stoi(argv[3]);
        int iteration = std::stoi(argv[4]);

        gol::Grid2d grid2d = gol::Grid2d(row,column,numAlive);
        gol::GameofLife gol = gol::GameofLife(grid2d);

        for (int iter=0;iter<iteration;iter++){
            gol.TakeStep();
        }
        gol.PrintGrid();
        return 1;      
    }

    // Default Option:
    else{
        show_usage(argv[0]);
        return 0;
    }
}
