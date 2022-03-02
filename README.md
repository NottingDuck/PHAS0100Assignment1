PHAS0100ASSIGNMENT1
------------------

[![Build Status](https://travis-ci.com/[USERNAME]/PHAS0100Assignment1.svg?branch=master)](https://travis-ci.com/[USERNAME]/PHAS0100Assignment1)
[![Build Status](https://ci.appveyor.com/api/projects/status/[APPVEYOR_ID]/branch/master)](https://ci.appveyor.com/project/[USERNAME]/PHAS0100Assignment1)


Purpose
-------

This project serves as a starting point for the PHAS0100 2021/22 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects,
that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

Further information on the specific project is left as an exercise for the student.


Credits
-------

This project is maintained by [Dr. Jim Dobson](https://www.ucl.ac.uk/physics-astronomy/people/dr-jim-dobson). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](http://rits.github-pages.ucl.ac.uk/research-computing-with-cpp/)
course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james)
and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).


Build Instructions
------------------
****
Open the terminal and create a new directory called "build" and enter into it.

```Bash
mkdir build
cd build
cmake ..
make
```

Run Instructions
----------------
****
The command should under the "build" directory.

----------------

### ***Command-Line application 1: gofSimulator***

The guidance of gofSimulator apps

```Bash
./bin/gofSimulator -h
```
or
```Bash
./bin/gofSimulator --help
```

***Two Options for users to start the game of life programme.***

- **Option 1:** Read the txt file
```Bash
./bin/gofSimulator <filepath> 
```

- **Option 2:** Create a new random life grid

```Bash
./bin/gofSimulator <grid row> <grid column> <number of alive cell> <number of alive >
```

### ***Command-Line application 2: golStillLifes***

The guidance of gofSimulator apps

```Bash
./bin/gofSimulator -h
```
or
```Bash
./bin/gofSimulator --help
```

To create a new random life grid:
    
    Enter:
    1. number of alive cell
    2. grid row 
    3. grid column
    4. iteration

The Code:
```Bash
./bin/golStillLifes <number of alive > <grid row> <grid column> <iteration> 
```

### ***Unit Test***
```Bash
ctest -V
```

### ***- THE Still Life's Pattern***

### **Example 1:**
![4x4fig1](/Screengrabs/StillPattern/Pattern1.png)
### **Example 2:**
![4x4fig1](/Screengrabs/StillPattern/Pattern2.png)
### **Example 3:**
![4x4fig1](/Screengrabs/StillPattern/Pattern3.png)
### **Example 4:**
![4x4fig1](/Screengrabs/StillPattern/Pattern4.png)
### **Example 5:**
![4x4fig1](/Screengrabs/StillPattern/Pattern5.png)