#include "pch.h"
#include "VectorProcess.h"
#include <boost/timer.hpp>

using namespace std;

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: task4.exe <int k>\n";

		return 1;
	}
	const size_t k = atoi(argv[1]);

	vector<int> set(k + 1);
	fill(set.begin(), set.end(), 0);

	boost::timer time;
	time.restart();

	GenerationAllSubsetsOfSet(k, set);

	double duration = time.elapsed();
	cout << duration << endl;

	return 0;
}