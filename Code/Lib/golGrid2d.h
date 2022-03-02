#ifndef golGrid2d_h
#define golGrid2d_h

/**
* \file golGrid2d.h
* \brief Various Utilities.
* \ingroup utilities
*/

#include <iostream>
#include <vector>
#include <string>

namespace gol
{

/**
* \brief Grid2d class.
*/

class Grid2d
{
private:

	int grid_row;
	int grid_col;
	std::vector<std::vector<int>> grid2d;

public:

	// Grid:
	Grid2d() {};
	Grid2d(int grid_row, int grid_col); // first constructor
	Grid2d(int grid_row, int grid_col, int numALIVE); // second constructor
	Grid2d(std::string filePath);

	~Grid2d();

    // Grid:
	int getRow();
	int getColumn();

	// Single Cell:
	int getCellStatus(int idx_row, int idx_col);
	int setCellStatus(int idx_row, int idx_col, int status);

	int neighbour_ALIVE(int idx_row, int idx_col);

	void showStatus();
};

} // end namespace

#endif
