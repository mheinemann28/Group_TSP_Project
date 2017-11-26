import sys
import math
import pdb

def nearestNeighbour(C, T, startPoint):
	# create temp copy of City data
	temp = C[:]

	totalDistance = 0

	currentCityIndex = 0

	# append starting distance and city to path
	T.append(0)
	T.append(startPoint)

	j = 0

	# loop untill temp array is empty
	while len(temp) > 0:
			
		#get coordinates of current city
		x_coord1 = temp[currentCityIndex][1]
		y_coord1 = temp[currentCityIndex][2]

		# delete current city from temp list
		del temp[currentCityIndex]
		
		distance1 = 1000000
		distance2 = 0
		
		k = 0

		# if temp array is empty connect back to start city
		if len(temp) == 0:
			# get coordinates of start city
			x_coord2 = C[startPoint][1]
			y_coord2 = C[startPoint][2]

			# calculate distance back to start city
			distance1 =  round(math.sqrt(math.pow(x_coord1 - x_coord2, 2) + math.pow(y_coord1 - y_coord2, 2)))

			currentCityIndex = startPoint			

			# add to total distance
			totalDistance += distance1
			T[0] = totalDistance

			break
		else:
			
			# loop through unvisited cities
			for i in temp:
				# get coordinates of unvisited cities
				x_coord2 = i[1]
				y_coord2 = i[2]
				test = x_coord1 - x_coord2

				# calculate distance to unvisited city
				distance2 =  round(math.sqrt(math.pow(x_coord1 - x_coord2, 2) + math.pow(y_coord1 - y_coord2, 2)))
				
				# keep track of shortest route
				if distance1 > distance2:
					distance1 = distance2
					currentCityIndex = k
				k += 1
	
		
		# add to total distance
		totalDistance += distance1
		
		T[0] = totalDistance

		# append city to route
		T.append(temp[currentCityIndex][0])

	return T




			


def main():
	# List to hold city data
	Cities = []

	fileName = sys.argv[1]

	# open file specified through command line
	file = open(fileName, "r")

	# read data from file
	fileData = file.readlines()

	# close file
	file.close()

	j = 0
	for i in fileData:
		tmpArray = []

		# split string element into 3 separate elements
		tmpArray = i.split()

		# loop to convert elements from str to int
		k = 0
		for i in tmpArray:
			tmpArray[k] = int(i)
			k += 1

		# append to Cities list
		Cities.append(tmpArray)

		j += 1

	Tour = []

	nearestNeighbour(Cities, Tour, Cities[0][0])

	print(Tour)

	outFileName = fileName + ".tour"

	outputFile = open(outFileName, "w")

	for i in Tour:
		outputFile.write(str(i))
		outputFile.write('\n')


if __name__ == '__main__':
	main()