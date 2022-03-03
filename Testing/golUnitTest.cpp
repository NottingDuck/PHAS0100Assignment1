#include "catch.hpp"
#include"golGrid2d.h"
#include"golGameofLife.h"
#include <iostream>
#include <vector>

TEST_CASE("Invalid Number", "[Invalid Number]"){
    // Unit Test for invalid number
    REQUIRE_THROWS(gol::validate_size(1,0));
    REQUIRE_THROWS(gol::validate_size(0,1));
    REQUIRE_THROWS(gol::validate_size(-1,-1));

    REQUIRE_THROWS(gol::validate_num_ALIVE(5,5,30));
}

TEST_CASE("Invalid index", "[Invalid index]"){

    // Unit Test of indice of single cell
    gol::Grid2d grid_test1("../../testing/data/glider.txt");
    REQUIRE_THROWS(grid_test1.neighbour_ALIVE(20,20));

    gol::Grid2d grid_test2(5,5,5);
    REQUIRE_THROWS(grid_test2.neighbour_ALIVE(20,20));
}

TEST_CASE("FileReader","[FileReader]"){
    REQUIRE_NOTHROW(gol::FileReader("../../Testing/Data/glider.txt"));
    
    REQUIRE_THROWS(gol::FileReader("../../Testing/Data/input.txt"));
    REQUIRE_THROWS(gol::FileReader("InvalidPath.txt"));
}

std::string Patterns_Compare(std::vector<std::vector<int>>vect_test1,std::vector<std::vector<int>>vect_test2){
    // Compare two patterns
    if (vect_test1==vect_test2){
        return "Two patterns are same.";
    }
    else{
        return "Two patterns are not same.";
    }
}

TEST_CASE("Different instances are different patterns","[Different patterns]"){
    // Unit tests to check if the different instances are different patterns
    gol::Grid2d grid_test1(4,4,4);
    std::vector<std::vector<int>> grid_Status_1 = grid_test1.get_grid2d();
     
    gol::Grid2d grid_test2(4,4,4);
    std::vector<std::vector<int>> grid_Status_2 = grid_test2.get_grid2d();
    REQUIRE(Patterns_Compare(grid_Status_1,grid_Status_2)=="Two patterns are not same.");
}

TEST_CASE("Number ALIVE Neighbours","[ALIVE neighbours]"){
  // Unit tests to check if the number of ALIVE neighbours is correct
  gol::Grid2d grid("../../Testing/Data/glider.txt");
  REQUIRE(grid.neighbour_ALIVE(0,0)==0);
  REQUIRE(grid.neighbour_ALIVE(1,1)==3);
  REQUIRE(grid.neighbour_ALIVE(2,2)==3);
  REQUIRE(grid.neighbour_ALIVE(3,3)==2);
}

TEST_CASE("Take Step","[Take Step]"){
    // Unit tests to check if the function TakeStep is expected
    gol::Grid2d grid("../../Testing/Data/step_test.txt");
    gol::GameofLife grid_status(grid);

    grid_status.TakeStep();
    REQUIRE(grid_status.getCell(0,0) == 0);
    REQUIRE(grid_status.getCell(1,1) == 1);
    REQUIRE(grid_status.getCell(1,0) == 0);
}
