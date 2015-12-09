#include "closestPair.h"

std::pair<double, t_points> closestPairBrute(const std::vector<Point>& points) {
	// Check if there is at least 2 points
	if (points.size() < 2) {
		return { 999999, {{0,0},{0,0}} };
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

// Get distance Between the two given points
std::pair<double, t_points> distBetween(const Point& a, const Point& b) { // Calculate distance between two points
	return{ std::abs(sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2))), 
	{ {a}, {b} } }; // Returns distance between and the two points
}