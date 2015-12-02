#include <fstream>
#include <random>
#include <ctime>

int main() {

	std::ofstream outFile;
	outFile.open("../ClosestPair/output10.txt");		//file to output to

	int n = 10;		// Number of points

						// Random generator
	std::mt19937 randomEngine;
	randomEngine.seed(time(nullptr));
	//std::uniform_int_distribution<int> randX(-1000000, 1000000);	// Get random value for x
	//std::uniform_int_distribution<int> randY(-1000000, 1000000);	// and Y
	std::uniform_int_distribution<int> randX(-100, 100);	// Get random value for x
	std::uniform_int_distribution<int> randY(-100, 100);	// and Y

	for (int i = 0; i < n; i++) {
		outFile << randX(randomEngine) << ' ' << randY(randomEngine) << std::endl; //output to file
	}

	return 0;
}

