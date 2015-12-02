#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
//#include <stdlib.h>
#include "closestPair.h"

int main() {

	// Input File to the points
	std::ifstream inFile;
	inFile.open("output10.txt");
	if (!inFile.is_open()) {	// error checking
		std::cout << "failed to open file\n";
	}
	std::vector<Point> points(10);	// List of points
	for (size_t i = 0; i < points.size(); i++) {	// populate list from file
		inFile >> points[i].x >> points[i].y;
	}

	////check array input
	//for (int i = 0; i < points.size(); i++) {
	//	std::cout << "(" << points[i].x << "," << points[i].y << "), ";
	//}

	auto brute = closestPairBrute(points);
	std::cout << "Minimum Distance Brute: " << brute.first << "\n"	// Output
		<< "point 1: " << brute.second.first.x << "," << brute.second.first.y << ", "
		<< "point 2: " << brute.second.second.x << "," << brute.second.second.y << "\n";

	//int n = sizeof(points);

	std::vector<Point> pointsX;
	std::copy(points.begin(), points.end(), std::back_inserter(pointsX));
	std::sort(pointsX.begin(), pointsX.end(), compareX);
	std::vector<Point> pointsY;
	std::copy(points.begin(), points.end(), std::back_inserter(pointsY));
	std::sort(pointsY.begin(), pointsY.end(), compareY);

	auto check = closestPairDivCon(points, pointsX, pointsY);
		std::cout << "Minimum Distance Div&Con: " << check.first << "\n"	// Output
			<< "point 1: " << check.second.first.x << "," << check.second.first.y << ", "
			<< "point 2: " << check.second.second.x << "," << check.second.second.y << "\n";


	return 0;
}
