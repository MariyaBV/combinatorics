#include "pch.h"
#include <boost/timer.hpp>

using namespace std;

void Print(const vector<size_t>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<size_t>(cout));
	cout << endl;
}

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid count of arguments";
		return 1;
	}

	const int leftAndRightConstraints = 2;
	const size_t arraySize = atoi(argv[1]);
	vector<size_t> pi(arraySize + leftAndRightConstraints);
	iota(pi.begin(), pi.end(), 0);

	vector<size_t> p(arraySize + leftAndRightConstraints);
	p = pi;

	vector<int> d(arraySize + leftAndRightConstraints);
	fill(d.begin() + 1, d.end() - 1, -1);

	const int borderNumber = arraySize + 1;
	d[1] = 0;
	pi[0] = borderNumber;
	pi[arraySize + 1] = borderNumber;
	int m = borderNumber;
	int n = arraySize;

	boost::timer time;
	time.restart();
	while (m != 1)
	{
		m = n;
		while ((pi[p[m] + d[m]]) > m)
		{
			d[m] = -d[m];
			m--;
		}
		swap(pi[p[m]], pi[p[m] + d[m]]);
		swap(p[pi[p[m]]], p[m]);
	}

	double duration = time.elapsed();
	cout << fixed;
	cout.precision(2);
	cout << duration << endl;

	return 0;
}

//N = 10, time = 32.36 sec;
//N = 11, time = 381.27 sec;
//N = 15, time = 15 ! / 11 !*381, 27 = 12490405.2 ~1.25 * 10 ^ 7 sec;
//N = 20, time = 20 ! / 11 !*381.27 ~6.095 * 10 ^ 10 sec;
//N = 50, time = 50 ! / 11 !*381.27 ~7.62 * 10 ^ 56 sec;
//N = 100, time = 100 ! / 11 !*381.27 ~2.34 * 10 ^ 150 sec;
