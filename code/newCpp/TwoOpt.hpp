#ifndef TWO_OPT_HPP
#define TWO_OPT_HPP

#include <vector>
#include <cmath>

void TwoOpt(const std::vector< std::vector<int>* >& C, std::vector<long>& T);
void TwoOptSwap(const std::vector<long> tour, std::vector<long>& newRoute, int i, int k);

#endif
