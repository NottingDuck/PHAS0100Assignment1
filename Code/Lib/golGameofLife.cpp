#include "golGameofLife.h"
#include <iostream>
#include <algorithm>

namespace gol {

//-----------------------------------------------------------------------------
GameofLife::GameofLife(gol::Grid2d grid) : grid2d_current(grid),grid2d_next(grid) {};
GameofLife::~GameofLife(){};

// Function:
void GameofLife::TakeStep(){

    for (int idx_row=0; idx_row<grid2d_current.getRow();idx_row++){
        for (int idx_col = 0; idx_col < grid2d_current.getColumn(); idx_col++){
            
            int num_ALIVE = grid2d_current.neighbour_ALIVE(idx_row,idx_col);
            int status_Cell = grid2d_current.getCellStatus(idx_row,idx_col);

            // Case 1: DEAD, ALIVE:
            if(status_Cell == 0){
                if (num_ALIVE == 3){
                    grid2d_next.setCellStatus(idx_row,idx_col,1);
                }
            }
            else if(status_Cell == 1){
            // Case 2: ALIVE, ALIVE:
                if(num_ALIVE == 2 or num_ALIVE == 3){
                    grid2d_next.setCellStatus(idx_row,idx_col,1);
                }
            // Case 3: ALIVE, DEAD:
                else{
                    grid2d_next.setCellStatus(idx_row,idx_col,0);
                }
            }   
        }
    }

    // find still lifes:
    if(grid2d_next.get_grid2d() == grid2d_current.get_grid2d()){
        return;
    }

    // Update:
    grid2d_current = grid2d_next;
};

void GameofLife::PrintGrid(){
    grid2d_current.showStatus();
    std::cout<<"------------------------------------";
    std::cout<<"\n";
};

void validate_iteration(int iteration){
    if (iteration<0){
        throw std::invalid_argument("The iteration should be a positive integer.");
    }
}

int GameofLife::getCell(int row, int column) { return grid2d_current.getCellStatus(row, column); }


} // end namespace
