#!/usr/bin/env python3
#change file permissions to chmod +x

# CS 325 Project
# 1st December 2017
# edwardse
# garouttc
# heinemam

import os
import sys
import argparse
import math
import pdb

class tspSolver:
    def __init__(self, cities, tour = []):
        self.cities = cities
        self.start = cities[0][0]
        self.tour = tour

    def nearestNeighbour(self):
        # create temp copy of City data
        temp = self.cities[:]

        totalDistance = 0

        currentCityIndex = 0

        # append starting distance and city to path
        self.tour.append(0)
        self.tour.append(self.start)

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
                x_coord2 = self.cities[self.start][1]
                y_coord2 = self.cities[self.start][2]

                # calculate distance back to start city
                distance1 =  round(math.sqrt(math.pow(x_coord1 - x_coord2, 2) + math.pow(y_coord1 - y_coord2, 2)))

                currentCityIndex = self.start           

                # add to total distance
                totalDistance += distance1
                self.tour[0] = totalDistance

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
            
            self.tour[0] = totalDistance

            # append city to route
            self.tour.append(temp[currentCityIndex][0])

        return self.tour

    def twoOpt(self):
        self.tour.append("twoOpt!!!!")
        return self.tour

class fileInterpreter:
    def __init__(self, path='tsp_example_1.txt'):
        if(os.path.exists(path)):
            self.allCities = []
            #get file name without leading path
            # https://stackoverflow.com/questions/678236/how-to-get-the-filename-without-the-extension-from-a-path-in-python
            name = os.path.basename(path)
            print("File name is: " + str(name))
            self.nameOut = name + ".tour"
            self.path = path 
        else:
            print("Path does not exist.  Check input file path.")
            return  #TODO intent is to exit program; should this throw an exception instead?

    def getData(self):
        with open(self.path, "r") as inFile:
            for line in inFile:
                cityStr = line
                cityArr = cityStr.split()    #cityArr[0] is name, cityArr[1] is x coordinate, cityArr[2] is y coordinate
                for value in range(len(cityArr)):    #convert city values to ints
                    cityArr[value] = int(cityArr[value])
                    #print("Converted value to int: " + str(cityArr[value]))
                #TODO This is where we call the object calculating distances
                self.allCities.append(cityArr)  #don't need this line if not storing individual city data
                #DEBUG
                #print("\nNew city is: ")
                #print(cityArr)
        #print("\n\nAll Citites: ")
        #print(allCities)
        #DEBUG
        return self.allCities
        inFile.close() #Unnecessary when using with open(), but put it in for best practice

    def writeData(self, data):
    #def writeData(self, tourLength, tourList):
        #write data out to file
        with open(self.nameOut, "w+") as outFile:
            for item in data:
                outFile.write(str(item) +"\n")
            #outFile.write(str(data)) #test until we get better data to write
            #outFile.write(str(tourLength))
            #outFile.write(str(tourList))
        #outFile.close() #Unnecessary when using with open(), but put it in for best practice



def main():
    parser = argparse.ArgumentParser(description="Use TSPSolver to find an approximately optimized solution to a given TSP instance.")
    parser.add_argument(default="tsp_example_1.txt", nargs="?", dest="datafile", action="store", help="A path to the file containing the input data.  Will default to tsp_example_1.txt if not provided.")
    parser.add_argument("--fast", "-f", action="store_true", help="Get a solution faster, at the cost of optimization.")
    args = parser.parse_args(sys.argv[1:])
    path = args.datafile
    print("Input file is: " + path)

    fileObject = fileInterpreter(path) 
    cities = fileObject.getData()

    # determine distances between cities
    # solve TSP with nearest neighbor or similar
    tour = []
    solveWith = tspSolver(cities, tour)
    nonOptRoute = solveWith.nearestNeighbour()
    # optimize solution from prev step using 2-opt

    if(args.fast):
        fileObject.writeData(nonOptRoute)
    else:
        OptRoute = solveWith.twoOpt()
        fileObject.writeData(OptRoute)



    #get file name without leading path
    # https://stackoverflow.com/questions/678236/how-to-get-the-filename-without-the-extension-from-a-path-in-python
#    name = os.path.basename(path)
#    print("File name is: " + str(name))
#    nameOut = name + ".tour"

#    allCities = []
#    if(os.path.exists(path)):
#        #TODO decide whether or not to put readfile/get input data into its own class/object
#        with open(path, "r") as inFile:
#            for line in inFile:
#                cityStr = line
#                cityArr = cityStr.split()
#                for value in range(len(cityArr)):    #convert city values to ints
#                    cityArr[value] = int(cityArr[value])
#                    #print("Converted value to int: " + str(cityArr[value]))
#                allCities.append(cityArr)
#                #DEBUG
#                #print("\nNew city is: ")
#                #print(cityArr)
#        #print("\n\nAll Citites: ")
#        #print(allCities)
#        #DEBUG
#        #TODO if putting in its own class/object, return array of allCities
#        inFile.close() #Unnecessary when using with open(), but put it in for best practice
#    else:
#        print("Path does not exist.  Check input file path.")
#        return



#    #write data out to file
#    with open(nameOut, "w+") as outFile:
#        outFile.write(str(allCities)) #test until we get better data to write
#        #outFile.write(str(tourLength))
#        #outFile.write(str(tourList))
#    #outFile.close() #Unnecessary when using with open(), but put it in for best practice

if __name__ == '__main__':
    main()
