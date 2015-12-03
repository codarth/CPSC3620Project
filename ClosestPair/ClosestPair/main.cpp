#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <time.h>
#include "closestPair.h"

int main() {
	const int SIZE = 1000;
	// Input File to the points
	std::ifstream inFile;
	inFile.open("output1000.txt");
	if (!inFile.is_open()) {	// error checking
		std::cout << "failed to open file\n";
	}
	std::vector<Point> points(SIZE);	// List of points
	for (size_t i = 0; i < points.size(); i++) {	// populate list from file
		inFile >> points[i].x >> points[i].y;
	}

	// For record running time
	clock_t brutStart, brutEnd, dcStart, dcEnd;
	//start brute clock
	brutStart = clock();

	auto brute = closestPairBrute(points);	//use brute force to calculate closest pair
	std::cout << "Minimum Distance Brute: " << brute.first << "\n"	// Output brute force result
		<< "point 1: " << brute.second.first.x << "," << brute.second.first.y << ", "
		<< "point 2: " << brute.second.second.x << "," << brute.second.second.y << "\n";
	
	// End brute clock
	brutEnd = clock();

	// Calculate running time and output to file
	clockWrite(brutStart, brutEnd, brute, "brute", SIZE);

	// Copy points to new vector and sort by X
	std::vector<Point> pointsX;
	std::copy(points.begin(), points.end(), std::back_inserter(pointsX));
	std::sort(pointsX.begin(), pointsX.end(), compareX);
	// Copy points to new vector and sort by Y
	std::vector<Point> pointsY;
	std::copy(points.begin(), points.end(), std::back_inserter(pointsY));
	std::sort(pointsY.begin(), pointsY.end(), compareY);

	// Start divide and conquer clock
	dcStart = clock();

	// Use divide and conquer to calculate closest pair, and output
	//auto divCon = closestPairDivCon(points, pointsX, pointsY);
	auto divCon = closestPairDivCon(pointsX);
	std::cout << "Minimum Distance Div&Con: " << divCon.first << "\n"
		<< "point 1: " << divCon.second.first.x << "," << divCon.second.first.y << ", "
		<< "point 2: " << divCon.second.second.x << "," << divCon.second.second.y << "\n";

	// Stop divide and conquer clock
	dcEnd = clock();
	// Calculate runnning time and output to file
	clockWrite(dcStart, dcEnd, divCon, "Div&Con", SIZE);

	return 0;
}
