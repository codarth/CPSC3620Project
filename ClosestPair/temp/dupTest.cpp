#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>

class Point {
public:
	Point() {};
	Point(int X, int Y) {
		x = X;	y = Y;
	}
	int x, y;
};
// Needed for sorting for X
inline bool compareX(const Point& a, const Point& b) {
	return (a.x < b.x);
}
// Needed for sorting for Y
inline bool compareY(const Point& a, const Point& b) {
	return (a.y < b.y);
}


int main() {

	// Input File to the points
	std::ifstream inFile;
	inFile.open("../ClosestPair/output4000.txt");
	if (!inFile.is_open()) {	// error checking
		std::cout << "failed to open file for input\n";
	}
	std::vector<Point> points(4000);	// List of points
	for (size_t i = 0; i < points.size(); i++) {	// populate list from file
		inFile >> points[i].x >> points[i].y;
	}
	std::ofstream outFile;
	outFile.open("TESTDup.txt");
	if (!outFile.is_open()) {	// error checking
		std::cout << "failed to open file for output\n";
	}
	//for (int i = 0; i < points.size(); i++) {
	//	std::cout<<i<<": " << points[i].x << " " << points[i].y << "\n";
	//}

	for (auto i = 0; i < points.size() - 1; i++) {
		for (auto j = i + 1; j < points.size(); j++) {
			if (points[i].x == points[j].x || points[i].y == points[j].y) {
				outFile << points[i].x << " " << points[i].y << " : " << points[j].x << " " << points[j].y << "\n";
			}
		}
	}

	return 0;
}