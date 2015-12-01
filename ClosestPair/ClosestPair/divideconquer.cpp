#include <iterator>
#include <algorithm>
#include <iostream>
#include "closestPair.h"

std::pair<int, t_points> closestPairOptimized(const std::vector<Point>& xPoints, const std::vector<Point>& yPoints) {
	int N = xPoints.size();
	if (N <= 3) {
		return closestPairBrute(xPoints);
	}

	// Set middle line
	int xM = xPoints.at(N / 2).x;

	// Setup seperation of points
	std::vector<Point> xL = std::vector<Point>();
	std::vector<Point> yL = std::vector<Point>();
	std::vector<Point> xR = std::vector<Point>();
	std::vector<Point> yR = std::vector<Point>();
	std::copy(std::begin(xPoints), std::begin(xPoints) + (N / 2), std::back_inserter(xL));
	std::copy(std::begin(xPoints) + (N / 2), std::end(xPoints), std::back_inserter(xR));
	std::copy_if(std::begin(yPoints), std::end(yPoints), std::back_inserter(yL), [&xM](const Point& p) {
		return p.x <= xM;
	});
	std::copy_if(std::begin(yPoints), std::end(yPoints), std::back_inserter(yR), [&xM](const Point& p) {
		return p.x > xM;
	});

	// Get closest pair from both sides of the middle line (xM)
	std::pair<int, t_points> p1 = closestPairOptimized(xL, yL);
	std::pair<int, t_points> p2 = closestPairOptimized(xR, xR);

	// Check smaller of the two
	std::pair<int, t_points> min = (p1.first <= p2.first) ? p1 : p2;

	// 
	std::vector<Point> ySmall = std::vector<Point>();
	std::copy_if(std::begin(yPoints), std::end(yPoints), std::back_inserter(ySmall), [&min, &xM](const Point& p) {
		return std::abs(xM - p.x) < min.first;
	});

	for (Point& i:ySmall) {
		std::cout << "\n" << i.x << ',' << i.y;
	}
	return min;
}

std::pair<int, t_points> closestPairDivCon(const std::vector<Point> points, int n) {
	if (n <= 3) {
		return closestPairBrute(points);
	}

	// Find the middle Point
	int mid = n / 2;
	Point midPoint = points[mid];

	std::pair<int, t_points> distL = closestPairDivCon(points, mid);
	std::pair<int, t_points> distR = closestPairDivCon(points, n - mid);

	int dist = std::min(distL.second.first.x, distR.second.first.x);

	std::vector<Point> strip;
	int size = 0;
	for (int i = 0; i < n; i++) {
		if (abs(points[i].x - midPoint.x) < dist) {
			strip.push_back(points[i]);
			size++;
		}
	}
	std::sort(points.begin(), points.end(), compareY);

	t_points result;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < dist; j++) {
			int distchk = distBetween(strip[i], strip[j]);
			if (distchk < dist) {
				dist = distchk;
				result.first = strip[i];
				result.second = strip[j];
			}
		}
	}
	return { dist, result };
}