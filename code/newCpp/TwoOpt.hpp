
/******************************************************************************
 * The following are function declarations for the 2-opt procedure used by
 * main.cpp. Together, these functions implement a version of the 
 * 2-optimization algorithm first described by Croes in 1958:
 * (G. A. CROES (1958). A method for solving traveling salesman problems. 
 * Operations Res. 6 (1958) , pp., 791-812). The code for these functions
 * was adapted from pseudocode from the following source:
 * “2-Opt.” Wikipedia, Wikimedia Foundation, 9 Nov. 2017, 
 * en.wikipedia.org/wiki/2-opt. 
******************************************************************************/

#ifndef TWO_OPT_HPP
#define TWO_OPT_HPP

#include <vector>
#include <cmath>

/******************************************************************************
 * Function: TwoOpt
 * Parameters: a constant reference to the vector holding city data, and a 
 * reference to the vector holding the current solution tour calculated
 * by the nearest neighbor algorithm.
 * Returns: none (T is an out parameter)
 * Description: Performs a slightly modified version of the 2-optimization 
 * algorithm on the current tour solution. The original 2-opt algorithm 
 * would not complete within the time alloted, so the goto statement found in
 * the original pseudocode was ommitted. The algorithm nevertheless
 * improves upon the solution found by nearest neighbor in a significant way.
******************************************************************************/
void TwoOpt(const std::vector< std::vector<int>* >& C, std::vector<long>& T);

/******************************************************************************
 * Function: TwoOptSwap
 * Parameters: a constant copy of the current solution tour, and a 
 * reference to a vector that will hold a new solution tour.
 * Returns: none (newRoute is an out parameter)
 * Description: TwoOptSwap is a function used by TwoOpt to produce a new
 * solution tour. It works by reversing the indices of a segments of the tour, 
 * effectively creating a new ordering of the tour. TwoOpt then checks if this
 * ordering produces a shorter route and updates the solution tour if it does.
******************************************************************************/
void TwoOptSwap(const std::vector<long> tour, std::vector<long>& newRoute, int i, int k);

#endif
