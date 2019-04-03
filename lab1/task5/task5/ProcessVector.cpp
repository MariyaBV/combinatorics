#include "pch.h"
#include "ProcessVector.h"

using namespace std;

void AlgorithmGeneratingPlacements(int k, int n, vector<int>& combinations)
{
	int m = 1;

	while (m != 0)
	{
		sort(combinations.begin() + 1, combinations.end());
		do
		{
			//PrintVector(combinations);
		} while (next_permutation(combinations.begin() + 1, combinations.end()));

		m = k;

		while (combinations[m] == n - k + m)
			m--;

		combinations[m]++;

		for (int i = m + 1; i <= k; i++)
		{
			combinations[i] = combinations[i - 1] + 1;
		}
	}
}

void PrintVector(vector<int> const& combinations)
{
	copy(combinations.begin() + 1, combinations.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
