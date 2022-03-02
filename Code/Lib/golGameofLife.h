#ifndef golGameofLife_h
#define golGameofLife_h

/**
* \file golGameofLife.h
* \brief Various Utilities.
* \ingroup utilities
*/
#include "golGrid2d.h"

#include <iostream>
#include <vector>
#include <string>

namespace gol
{

/**
* \brief GameofLife class.
*/

class GameofLife
{
private:
	Grid2d grid2d_current;
	Grid2d grid2d_next;

public:
	GameofLife(){};
    GameofLife(Grid2d);
	~GameofLife();

	// Function:
	void TakeStep();
	void PrintGrid();

};

} // end namespace

#endif
