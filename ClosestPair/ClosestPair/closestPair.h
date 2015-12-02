#pragma once

#include <vector>

class Point {
public:
	Point() {};
	Point(int X, int Y) {
		x = X;
		y = Y;
	}
	int x, y;
};

//const int COUNT = 10;
typedef std::pair<Point, Point> t_points;	// so we can use a pair of points

std::pair<double, t_points> closestPairBrute(const std::vector<Point>& points);
std::pair<double, t_points> distBetween(const Point& a, const Point& b);
//std::pair<int, t_points> closestPairOptimized(const std::vector<Point>& xPoints, const std::vector<Point>& yPoints);

std::pair<double, t_points> closestPairDivCon(std::vector<Point> points, std::vector<Point> pointsX, std::vector<Point> pointsY);

inline std::vector< std::vector<Point> > partition(std::vector<Point> points, int mid) {
	std::vector< std::vector<Point> > partPoints;
	std::vector<Point> temp1;
	std::vector<Point> temp2;

	for (size_t i = 0; i < points.size(); i++) {
		if (points[i].x < mid) {
			temp1.push_back(points[i]);
		} else {
			temp2.push_back(points[i]);
		}
	}

	partPoints.push_back(temp1);
	partPoints.push_back(temp2);

	return partPoints;
}

inline bool compareX(const Point& a, const Point& b) {
	return (a.x < b.x);
}

inline bool compareY(const Point& a, const Point& b) {
	return (a.y < b.y);
}

