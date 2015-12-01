#include "closestPair.h"

std::pair<int, t_points> closestPairBrute(const std::vector<Point>& points) {
	// Check if there is at least 2 points
	if (points.size() < 2) {
		return { -1, {{0,0},{0,0}} };
	} else {
		auto minDist = abs(distBetween(points[0], points[1]));	// Set initial minimum distance
		t_points minPoints = { points[0],points[1] };	// Set initial closest points
		for (size_t i = 0; i < points.size() - 1; i++) {
			for (size_t j = i + 1; j < points.size(); j++) {
				auto dist = abs(distBetween(points[i], points[j])); // Compair two new points
				if ( dist < minDist) {	// Check if closer
					minDist = dist;		// Establish new closest distance
					minPoints = { points[i],points[j] };	// and two new points
				}
			}
		}
		return { minDist, minPoints };
	}
}

int distBetween(const Point& a, const Point& b) { // Calculate distance between two points
	return sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
}