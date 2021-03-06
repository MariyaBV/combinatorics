#include "pch.h"
#include "ProcessVector.h"
#include <boost/timer.hpp>

using namespace std;

int main(const int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: task4.exe <int k> <int n> (k < n)\n";

		return 1;
	}
	const size_t k = atoi(argv[1]);
	const size_t n = atoi(argv[2]);

	if (k > n)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: task4.exe <int k> <int n> (k < n)\n";

		return 1;
	}

	vector<int> combinations(k + 1);
	iota(combinations.begin() + 1, combinations.end(), 1);
	combinations[0] = -1;

	boost::timer time;
	time.restart();

	AlgorithmGeneratingPlacements(k, n, combinations);

	double duration = time.elapsed();
	cout << duration << endl;

	return 0;
}
