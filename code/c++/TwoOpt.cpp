#include "TwoOpt.hpp"
double calculateDistance(const std::vector<std::vector<int>*>& C, std::vector<double> T);

void TwoOpt(const std::vector<std::vector<int>*>& C, std::vector<double>& T)
{
	std::vector<double> newRoute;
	newRoute.resize(T.size());

	bool improve = true;

	while (improve)
	{
		double bestDistance = T.at(0);

		for (int i = 1; i < T.size() - 1; i++)
		{
			for (int k = i + 1; k < T.size(); k++)
			{
				TwoOptSwap(T, newRoute, i, k);
				
				double newDistance = calculateDistance(C, newRoute);
				newRoute.at(0) = newDistance;

				if (newDistance < bestDistance)
				{
					T = newRoute;
					bestDistance = newDistance;
				}
			}
		}
		improve = false;
	}
}

void TwoOptSwap(const std::vector<double> tour, std::vector<double>& newRoute, int i, int k)
{
	for (int s = 0; s < i; s++)
	{
		newRoute.at(s) = tour.at(s);
	}
	int j = 0;
	for (int s = i; s <= k; s++)
	{
		newRoute.at(s) = tour.at(k + j);
		j--;
	}
	for (int s = k + 1; s < tour.size(); s++) 
	{
		newRoute.at(s) = tour.at(s);
	}
}


double calculateDistance(const std::vector<std::vector<int>*>& C, std::vector<double> T)
{
	double x1, x2, y1, y2, sum = 0;
	for (int i = 1; i < T.size() - 1; i++)
	{
		x1 = C.at(T.at(i))->at(1);
		x2 = C.at(T.at(i + 1))->at(1);
		y1 = C.at(T.at(i))->at(2);
		y2 = C.at(T.at(i + 1))->at(2);

		sum += round(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
	}

	x1 = C.at(T.at(T.size() - 1))->at(1);
	x2 = C.at(T.at(1))->at(1);
	y1 = C.at(T.at(T.size() - 1))->at(2);
	y2 = C.at(T.at(1))->at(2);
	sum += round(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
	return sum;
}