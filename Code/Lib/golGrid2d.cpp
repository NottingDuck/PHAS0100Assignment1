#include "golGrid2d.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <cassert>

#define ALIVE 1
#define DEAD 0

namespace gol {

//-----------------------------------------------------------------------------

// Constructor 1:
Grid2d::Grid2d(int row, int column) : grid_row(row), grid_col(column), grid2d(row, std::vector<int>(column, 0)) {};
// Constructor 2:
Grid2d::Grid2d(int row, int column, int numAlive) : grid_row(row), grid_col(column), grid2d(row, std::vector<int>(column, 0)) {
	
    // create a 1d vector:
    std::vector<int> vect1d;

    // fill with 1:
    for (int i=0;i<numAlive;i++){
        vect1d.push_back(1);
    }

    // fill with 0:
    for (int i=numAlive;i<row*column;i++){
        vect1d.push_back(0);
    }

    // shuffle elements:
    std::shuffle(vect1d.begin(), vect1d.end(), std::random_device());

    // convert 1d vector to 2d vector:
    for (int idx_row=0; idx_row<row;idx_row++){
        for (int idx_col = 0; idx_col < column; idx_col++){
            grid2d[idx_row][idx_col] = vect1d[idx_row*column+idx_col];
        }
    }
};

// Constructor 3:
Grid2d::Grid2d(std::string filePath){
    
    std::ifstream myFile(filePath);
    std::string str;
    
    // check the filepath:
    if (!myFile){
        throw std::logic_error("Invalid File Path!");
    }
    else{
        // read data line by line:
        while(getline(myFile, str)){
            
            std::vector<int> grid_row = {};

            for (auto value : str){
                // check ALIVE or DEAD:
                if (value == '-'){
                    grid_row.push_back(0);
                    }
                else if(value == 'o'){
                    grid_row.push_back(1);
                    }
            }

            grid2d.push_back(grid_row);
        }
    myFile.close();
    }
}

Grid2d::~Grid2d(){}


// Grid Function:
int Grid2d::getRow(){return grid2d.size();};
int Grid2d::getColumn(){return grid2d[0].size();};

// Single Cell Function:
int Grid2d::getCellStatus(int id_row, int id_col) {
    return grid2d[id_row][id_col];
};

void Grid2d::setCellStatus(int id_row, int id_col, int status) {
    grid2d[id_row][id_col] = status;
};

void Grid2d::showStatus() {
    
    for (int id_row = 0;  id_row < getRow(); ++id_row) {
        for (int id_col = 0; id_col < getColumn(); ++id_col) {
            
            // check status:
            if (getCellStatus(id_row, id_col) == 0){
                std::cout<<"-"<<" "; //DEAD
            }
            else{
                std::cout<<"o"<<" "; //ALIVE
            }
        };
    std::cout<<"\n";

    };
};


int Grid2d::neighbour_ALIVE(int idx_row, int idx_col){
    
    if(idx_row > grid_row or idx_col > grid_col){

        throw std::out_of_range("The cell is out of the grid!");
    }

    int count = 0;
        for (int i = idx_row - 1; i <= idx_row + 1; ++i){
            for (int j = idx_col - 1; j <= idx_col + 1; ++j){
                if (i != idx_row || j != idx_col){
                    // boundary condition:
                    if ((i >= 0) && (i < grid2d.size()) && (j >= 0) && (j < grid2d[0].size())){
                        if (grid2d[i][j] == 1){ // if 1, ALIVE
                            ++count;
                        }
                    }
                }
            }
        }
	return count;

};

} // end namespace