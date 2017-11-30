/******************************************************************************
 * The following is the header file for the nearest neighbor algorithm
 * used by main.cpp. Nearest neighbor is an approximation algorithm that 
 * calculates an approximate solution to the travelling salesman problem
 * when all cities lies in a Euclidean plane. 
******************************************************************************/

#ifndef NEAREST_NEIGHBOR_HPP
#define NEAREST_NEIGHBOR_HPP

#include <vector>
#include <cmath>

/******************************************************************************
 * Function: nearestNeigbor
 * Parameters: a constant reference to the vector holding city data, a 
 * reference to an empty vector to hold the solution tour calculated
 * by the nearest neighbor algorithm, the starting city.
 * Returns: none
 * Description: nearest neighbor is a greedy approximation algorithm. The 
 * greedy choice is the city that is closest to the current city. This 
 * function must be called before TwoOpt because TwoOpt requires the solution
 * tour T calculated by nearest neighbor.
******************************************************************************/
void nearestNeighbor(std::vector<std::vector<int>*> C, std::vector<long>& T, int startPoint);

#endif
