#include "closestPair.h"

std::pair<double, t_points> closestPairBrute(const std::vector<Point>& points) {
	// Check if there is at least 2 points
	if (points.size() < 2) {
		return { -1, {{0,0},{0,0}} };
	} else {
		std::pair<double, t_points> minDist = distBetween(points[0], points[1]);	// Set initial minimum distance
		for (size_t i = 0; i < points.size() - 1; i++) {
			for (size_t j = i + 1; j < points.size(); j++) {
				std::pair<double, t_points> dist = distBetween(points[i], points[j]); // Compair two new points
				if ( dist.first < minDist.first) {	// Check if closer
					minDist = dist;		// Establish new closest distance
				}
			}
		}
		return minDist;
	}
}

std::pair<double, t_points> distBetween(const Point& a, const Point& b) { // Calculate distance between two points
	return{ abs(sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2))), 
	{ {a}, {b} } };
}