#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <boost/timer.hpp>
#include <utility>

using namespace std;

void Print(const vector<int>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid count of arguments";

		return 1;
	}
	const size_t n = atoi(argv[1]);
	vector<int> a(n);
	fill(a.begin(), a.end(), 1);

	boost::timer time;
	time.restart();

	size_t k = n;
	unsigned int i = 0;
	int sum;

	Print(a);
	while (a.size() > 1)
	{
		sum = a.back();
		a.erase(std::prev(a.end()));
		i = a.size() - 1;
		while (i > 0 && a[i - 1] == a[i])
		{
			sum += a.back();
			a.erase(std::prev(a.end()));
			--i;
		}
		a[i] += 1;
		sum -= 1;
		vector<int> b(sum);
		fill(b.begin(), b.end(), 1);
		a.insert(a.end(), b.begin(), b.end());
		
		Print(a);
	}

	printf("Time: %.4f \n", time.elapsed());

	return 0;
}
