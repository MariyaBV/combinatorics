#include "pch.h"
#include "VectorProcess.h"

using namespace std;

void GenerationAllSubsetsOfSet(int k, vector<int>& set)
{
	int i;

	while (set[k] != 1)
	{
		PrintSet(set);
		i = 0;

		while (set[i] == 1)
		{
			set[i] = 0;
			i++;
		}
			set[i] = 1;
	}
}

void PrintSet(vector<int> const& set)
{
	for (int i = (set.size() - 1); i >= 0; i--)
	{
		if (set[i] != 0)
		{
			cout << i << ' ';
		}
	}
	cout << endl;
}