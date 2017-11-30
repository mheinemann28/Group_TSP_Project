/******************************************************************************
 * The following is the implementation of the nearestNeighbor function
 * declared in nearestNeigbor.hpp. Please see the header file as well as the 
 * tspSolver README for details about how to use it.
******************************************************************************/

#include "nearestNeighbor.hpp"

void nearestNeighbor(std::vector< std::vector<int>* > C, std::vector<long>& T, int startPoint)
{
	double startPointX = C.at(startPoint)->at(1), startPointY = C.at(startPoint)->at(2);
	double totalDistance = 0;
	int currentCityIndex = 0;

	// Append starting distance and city to path
	T.push_back(0);
	T.push_back(startPoint);

	// Variable defininitions
	double x_coord1, y_coord1, x_coord2, y_coord2, distance1, distance2;
	int k;

	while (C.size())
	{
		// Get coordinates of current city
		x_coord1 = C.at(currentCityIndex)->at(1);
		y_coord1 = C.at(currentCityIndex)->at(2);
		
		// Delete current city from temp list
		C.erase(C.begin() + currentCityIndex);

		distance1 = 1000000;
		distance2 = 0;

		k = 0;

		// If temp array is empty connect back to start city
		if (!C.size())
		{
			//Get coordinates of start city
			x_coord2 = startPointX;
			y_coord2 = startPointY;

			// Calculate distance back to start city
			distance1 = round(sqrt(pow(x_coord1 - x_coord2, 2) + pow(y_coord1 - y_coord2, 2)));

			currentCityIndex = startPoint;

			// Add to total distance
			totalDistance += distance1;
			T.at(0) = totalDistance;
		}
		else
		{
			// Loop through unvisited cities
			for (int i = 0; i < C.size(); i++)
			{
				x_coord2 = C.at(i)->at(1);
				y_coord2 = C.at(i)->at(2);

				// Calculate distance to unvisted city
				distance2 = round(sqrt(pow(x_coord1 - x_coord2, 2) + pow(y_coord1 - y_coord2, 2)));

				// Keep track of shortest route
				if (distance1 > distance2)
				{
					distance1 = distance2;
					currentCityIndex = k;
				}
				k++;
			}

			// Add to total distance
			totalDistance += distance1;

			T.at(0) = totalDistance;

			// Append city to route
			T.push_back(C.at(currentCityIndex)->at(0));
		}
	}
}
