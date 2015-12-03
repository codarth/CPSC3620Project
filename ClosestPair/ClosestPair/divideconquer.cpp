#include <algorithm>
#include "closestPair.h"

std::pair<double, t_points> closestPairDivCon(std::vector<Point> points) {
	std::vector< std::vector<Point> > partPoints;
	std::vector<Point> pointsL, pointsR, pointsXL, pointsXR, pointsYL, pointsYR, strip;
	int mid;

	if (points.size() <= 3) {
		return closestPairBrute(points);
	} else {
		// Get mid line
		mid = points[points.size() / 2].x;

		// Partition all points
		partPoints = partition(points, mid);
		pointsL = partPoints[0];
		pointsR = partPoints[1];

		// Setup distances
		double dist;
		auto dist1 = closestPairDivCon(pointsL);
		auto dist2 = closestPairDivCon(pointsR);
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
		for (size_t i = 0; i < strip.size(); i++) {
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


//std::pair<double, t_points> closestPairDivCon(std::vector<Point> points, std::vector<Point> pointsX, std::vector<Point> pointsY) {
//	std::vector< std::vector<Point> > partPoints;
//	std::vector<Point> pointsL, pointsR, pointsXL, pointsXR, pointsYL, pointsYR, strip;
//	int mid;
//
//	if (points.size() <= 3) {
//		return closestPairBrute(points);
//	} else {
//		// Get mid line
//		mid = pointsX[pointsX.size() / 2].x;
//
//		// Partition all points
//		partPoints = partition(points, mid);
//		pointsL = partPoints[0];
//		pointsR = partPoints[1];
//
//		// Partition X sorted Points
//		partPoints = partition(pointsX, mid);
//		pointsXL = partPoints[0];
//		pointsXR = partPoints[1];
//
//		// Partition Y sorted Points
//		partPoints = partition(pointsY, mid);
//		pointsYL = partPoints[0];
//		pointsYR = partPoints[1];
//
//		// Setup distances
//		double dist;
//		auto dist1 = closestPairDivCon(pointsL, pointsXL, pointsYL);
//		auto dist2 = closestPairDivCon(pointsR, pointsXR, pointsYR);
//		Point pnt1, pnt2;
//
//		// get smaller distance
//		if (dist1.first < dist2.first) {
//			dist = dist1.first;
//			pnt1 = dist1.second.first;
//			pnt2 = dist1.second.second;
//		} else {
//			dist = dist2.first;
//			pnt1 = dist2.second.first;
//			pnt2 = dist2.second.second;
//		}
//
//		// Populate the strip vector
//		for (size_t i = 0; i < pointsY.size(); i++) {
//			if (pointsY[i].x >= mid - dist && pointsY[i].x <= mid + dist) {
//				strip.push_back(pointsY[i]);
//			}
//		}
//
//		// compare all the strip
//		for (size_t i = 0; i < strip.size(); i++) {
//			for (size_t j = i + 1; j < strip.size(); j++) {
//				dist1 = distBetween(strip[i], strip[j]);
//				if (dist1.first < dist) {
//					dist = dist1.first;
//					pnt1 = dist1.second.first;
//					pnt2 = dist1.second.second;
//				}
//			}
//		}
//
//		return{ dist,{ {pnt1},{pnt2} } };
//	}
//
//}

//std::pair<int, t_points> closestPairDivCon(std::vector<Point> points, int n) {
//	if (n <= 3) {
//		return closestPairBrute(points);
//	} else {
//
//		// Find the middle Point
//		int mid = n / 2;
//		Point midPoint = points[mid];
//
//		std::pair<int, t_points> distL = closestPairDivCon(points, mid);
//		std::pair<int, t_points> distR = closestPairDivCon(points[mid], n - mid);
//
//		int dist = std::min(distL.second.first.x, distR.second.first.x);
//
//		std::cout << "dist: " << dist << "\n" << "mid: " << mid << "\nmidPoint :" << midPoint.x << "," << midPoint.y << "\n";
//
//		std::vector<Point> strip;
//		int size = 0;
//		for (int i = 0; i < n; i++) {
//			if (abs(points[i].x - midPoint.x) < dist) {
//				//std::cout << "point: " << points[i].x << "," << points[i].y << "\n";
//				strip.push_back(points[i]);
//				size++;
//			}
//		}
//		std::sort(points.begin(), points.end(), compareY);
//
//		////check array input
//		//for (int i = 0; i < strip.size(); i++) {
//		//	std::cout << "(" << strip[i].x << "," << strip[i].y << "), ";
//		//}
//
//		t_points result = { {99999999,99999999}, {99999999,99999999} };
//		for (int i = 0; i < size; i++) {
//			for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < dist; j++) {
//				int distchk = distBetween(strip[i], strip[j]);
//				if (distchk < dist) {
//					dist = distchk;
//					result.first = strip[i];
//					result.second = strip[j];
//				}
//			}
//		}
//		return{ dist, result };
//	}
//}

