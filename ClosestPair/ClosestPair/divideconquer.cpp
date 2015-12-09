#include <algorithm>
#include <iterator>
#include "closestPair.h"

std::pair<double, t_points> closestPairDivCon(std::vector<Point> points) {
	std::vector< std::vector<Point> > partPoints;
	std::vector<Point> pointsL, pointsR, pointsXL, pointsXR, pointsYL, pointsYR, strip;
	int mid;
	if (points.size() > 1) {
		if (points.size() <= 3) {
			return closestPairBrute(points);
		} else {
			// Get mid line
			mid = points[points.size() / 2].x;
			int n = points.size();
			
			// Partition all points
			std::copy(points.begin(), points.begin()+(n/2), std::back_inserter(pointsL));
			std::copy(points.begin()+(n/2), points.end(), std::back_inserter(pointsR));


			// Setup distances
			double dist;
			std::pair<double, t_points> dist1 = closestPairDivCon(pointsL);
			std::pair<double, t_points> dist2 = closestPairDivCon(pointsR);
			Point pnt1, pnt2;

			std::sort(points.begin(), points.end(), compareY);

			// get smaller distance
			if (dist1.first < dist2.first) {
				dist = dist1.first;
				pnt1 = dist1.second.first;
				pnt2 = dist1.second.second;
			} else {
				dist = dist2.first;
				pnt1 = dist2.second.first;
				pnt2 = dist2.second.second;
			}

			// Populate the strip vector
			for (size_t i = 0; i < points.size(); i++) {
				if (points[i].x >= mid - dist && points[i].x <= mid + dist) {
					strip.push_back(points[i]);
				}
			}

			// compare all the strip
			for (size_t i = 0; i < strip.size() - 1; i++) {
				for (size_t j = i + 1; j < strip.size(); j++) {
					dist1 = distBetween(strip[i], strip[j]);
					if (dist1.first < dist) {
						dist = dist1.first;
						pnt1 = dist1.second.first;
						pnt2 = dist1.second.second;
					}
				}
			}

			return{ dist,{ { pnt1 },{ pnt2 } } };
		}
	}
	return{ 999999,{ { {0},{0} },{ {0},{0} } } };
}

