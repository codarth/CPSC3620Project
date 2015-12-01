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

const int COUNT = 1000;
typedef std::pair<Point, Point> t_points;	// so we can use a pair of points

std::pair<int, t_points> closestPairBrute(const std::vector<Point>& points);
int distBetween(const Point& a, const Point& b);
std::pair<int, t_points> closestPairOptimized(const std::vector<Point>& xPoints, const std::vector<Point>& yPoints);


std::pair<int, t_points> closestPairDivCon(std::vector<Point> Points, int n);

bool compareX(const Point* a, const Point* b) {
	return (a->x < b->x);
}

bool compareY(const Point* a, const Point* b) {
	return (a->y < b->y);

}

