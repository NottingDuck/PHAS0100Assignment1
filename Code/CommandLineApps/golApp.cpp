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
int main(int argc, char** argv)
{

    // instantiate
    gol::Grid2d Grid();

    // Grid2d Grid(filepath)

    //Grid.showStatus();

    // gol::Grid2d grid_random(8, 7, 3);

    // std::cout<<grid_random.getRow();
    // std::cout<<"\n";
    // std::cout<<grid_random.getColumn();
    // std::cout<<"\n";

    // grid_random.showStatus();

    //----------

    //std::string path = "../testing/data/glider.txt";

    gol::Grid2d grid_2 = gol::Grid2d("../../testing/data/glider.txt");
    std::cout<<grid_2.getRow();
    std::cout<<grid_2.getColumn();
    std::cout<<"\n";
    grid_2.showStatus();
    std::cout<<"\n";

    //std::cout<<grid_2.neighbour_ALIVE(1,0);
    // std::cout<<grid_2.neighbour_ALIVE(2,1);

    // std::cout<<grid_2.neighbour_ALIVE(2,2);
    // std::cout<<grid_2.neighbour_ALIVE(2,3);
    // std::cout<<grid_2.neighbour_ALIVE(9,9);

    // std::cout<<grid_2.neighbour_ALIVE(0,0);
    // std::cout<<grid_2.neighbour_ALIVE(1,0);
    // std::cout<<grid_2.neighbour_ALIVE(2,0);

    gol::GameofLife grid_test = gol::GameofLife(grid_2);

    grid_test.TakeStep();
    grid_test.PrintGrid();

    std::cout<<"\n";

}
