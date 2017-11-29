#include "nearestNeighbor.hpp"
#include "TwoOpt.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	if (argv[1])
	{
		// List to hold city data
		std::vector< std::vector<int> * > Cities;

		// Open file specified through command line
		std::ifstream file(argv[1]);

		// Check if file exists, exit if it does not
		if (!file) {
			std::cerr << "File could not be read for opening. Exiting program." << std::endl;
			std::exit(EXIT_FAILURE);
		}

		// Read data from file into separate vectors, ppending each one to Cities vector
		int city, x, y;
		while (file >> city)
		{
			file >> x >> y;
			std::vector<int>* tempArray = new std::vector<int>;
			tempArray->push_back(city);
			tempArray->push_back(x);
			tempArray->push_back(y);

			Cities.push_back(tempArray);
		}

		std::vector<long> Tour;

		// Run nearest neighbor approximation algorithm
		nearestNeighbor(Cities, Tour, Cities.at(0)->at(0));
	
		// Run two-opt if optimizaton option chosen
		if (argv[2] && *argv[2] == 'o')
		{
			TwoOpt(Cities, Tour);
		}


		// Write results to file
		std::string outfileName = std::string(argv[1]);
		outfileName.append(".tour");
		std::ofstream outfile(outfileName);

		for (int i = 0; i < Tour.size(); i++)
		{
			outfile << Tour.at(i) << '\n';
		}

		// Free dynamically allocated memory.
		for (int i = 0; i < Cities.size(); i++)
		{
			delete Cities.at(i);
		}
	}
	else
	{
		std::cerr << "Missing command line arguments. Please re-run with the correct number/type of arguments.";
		std::exit(EXIT_FAILURE);
	}
	return 0;
}