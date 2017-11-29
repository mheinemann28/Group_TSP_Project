#ifndef TWO_OPT_HPP
#define TWO_OPT_HPP

#include <vector>
#include <cmath>

void TwoOpt(const std::vector< std::vector<int>* >& C, std::vector<double>& T);
void TwoOptSwap(const std::vector<double> tour, std::vector<double>& newRoute, int i, int k);

#endif
