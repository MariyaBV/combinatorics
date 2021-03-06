#include "pch.h"

using namespace std;

void Print(const vector<size_t>& vec)
{
	copy(vec.begin(), vec.end(), ostream_iterator<size_t>(cout));
	cout << endl;
}

void getRandomPermutation(vector<size_t>& vec)
{
	const int arraySize = vec.size();

	for (int i = 0; i < arraySize; i++)
	{
		int j = rand() % arraySize;

		swap(vec[i], vec[j]);
	};
}

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid count of arguments";
		return 1;
	}

	const size_t arraySize = atoi(argv[1]);
	vector<size_t> vec(arraySize);
	iota(vec.begin(), vec.end(), 0);

	srand(0);
	Print(vec);
	getRandomPermutation(vec);
	Print(vec);

	return 0;
}
