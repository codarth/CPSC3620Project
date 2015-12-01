#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
//#include <stdlib.h>
#include "closestPair.h"

int main() {

	// Input File to the points
	std::ifstream inFile;
	inFile.open("output1000.txt");
	if (!inFile.is_open()) {	// error checking
		std::cout << "failed to open file";
	}
	std::vector<Point> points(COUNT);	// List of points
	for (size_t i = 0; i < points.size(); i++) {	// populate list from file
		inFile >> points[i].x >> points[i].y;
	}

	////check array input
	//for (int i = 0; i < points.size(); i++) {
	//	std::cout << "(" << points[i].x << "," << points[i].y << "), ";
	//}

	//auto brute = closestPairBrute(points);
	//std::cout << "Minimum Distance: " << brute.first << "\n"	// Output
	//	<< "point 1: " << brute.second.first.x << "," << brute.second.first.y << ", "
	//	<< "point 2: " << brute.second.second.x << "," << brute.second.second.y << "\n";

	int n = sizeof(points);
	std::sort(points.begin(),points.end(), compareX);

	//std::sort(std::begin(points), std::end(points), [](const Point& a, const Point& b) {
	//	return a.x < b.x;
	//});
	//std::vector<Point> xSorted = points;

	//std::sort(std::begin(points), std::end(points), [](const Point& a, const Point& b) {
	//	return a.y < b.y;
	//});
	//std::vector<Point> ySorted = points;


		//auto check = closestPairOptimized(xSorted, ySorted);	// Variable for result of closest pair
	auto check = closestPairDivCon(points, n);
		std::cout << "Minimum Distance: " << check.first << "\n"	// Output
			<< "point 1: " << check.second.first.x << "," << check.second.first.y << ", "
			<< "point 2: " << check.second.second.x << "," << check.second.second.y << "\n";


	return 0;
}
