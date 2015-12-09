#ifndef CLOSESTPAIR_H
#define CLOSESTPAIR_H

#include <vector>
#include <time.h>
#include <fstream>
#include <iostream>
#include <cmath>

class Point {
public:
	Point() {};
	Point(int X, int Y) {
		x = X;	y = Y;
	}
	int x, y;
};

typedef std::pair<Point, Point> t_points;	// so we can use a pair of points

// Forward decleration
std::pair<double, t_points> closestPairBrute(const std::vector<Point>& points);
std::pair<double, t_points> closestPairDivCon(std::vector<Point> points);
std::pair<double, t_points> distBetween(const Point& a, const Point& b);

// Partition for divide and conquer
inline std::vector< std::vector<Point> > partition(std::vector<Point> points, int mid) {
	std::vector< std::vector<Point> > partPoints;
	std::vector<Point> temp1;
	std::vector<Point> temp2;

	for (size_t i = 0; i < points.size(); i++) {
		if (points[i].x <= mid) {
			temp1.push_back(points[i]);
		} else {
			temp2.push_back(points[i]);
		}
	}

	partPoints.push_back(temp1);
	partPoints.push_back(temp2);

	return partPoints;
}

// Needed for sorting for X
inline bool compareX(const Point& a, const Point& b) {
	return (a.x < b.x);
}
// Needed for sorting for Y
inline bool compareY(const Point& a, const Point& b) {
	return (a.y < b.y);
}

// write results to file
inline void clockWrite(clock_t start, 
	clock_t end, 
	std::pair<double, 
	t_points> pair, 
	std::string algo,
	int SIZE) {

	std::ofstream outFile;
	outFile.open("result.txt",std::ios::app);
	if (!outFile.is_open()) {	// error checking
		std::cout << "failed to open file\n";
	}

	outFile << "Point count: " << SIZE << "\n"
		<< "Minimum Distance " << algo.c_str() << ": " << pair.first << "\n"	// Output brute force result
		<< "point 1: " << pair.second.first.x << "," << pair.second.first.y << ", "
		<< "point 2: " << pair.second.second.x << "," << pair.second.second.y << "\n"
		<< "Running time: " << ((double)end - (double)start)/ CLOCKS_PER_SEC<<" seconds" << "\n\n\n";
}

#endif
