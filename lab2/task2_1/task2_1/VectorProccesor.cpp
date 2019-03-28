#include "pch.h"
#include "VectorProccesor.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

int countOfPoint;

void InitMatrix(Matrix& adjacencyMatrix, int countOfPoint)
{
	vector<int> currentRow(countOfPoint, 0);

	for (int row = 0; row < countOfPoint; row++)
	{
		adjacencyMatrix.push_back(currentRow);
	}
}

vector<int> ReadVector(string& line)
{
	vector<int> vec;
	istringstream stringIterator(line);
	copy(istream_iterator<int>(stringIterator), istream_iterator<int>(), back_inserter(vec));

	return vec;
}

Error LoadMatrix(const char* fileName, Matrix& adjacencyMatrix, Matrix& edgeList)
{
	ifstream inputFile(fileName);

	if (!inputFile.is_open())
	{
		return Error::FailedToOpen;
	}

	string line;
	int countOfEdge, restrictionOfEdge;

	if (getline(inputFile, line))
	{
		//istringstream stringIterator(line);
		//stringIterator >> countOfPoint >> countOfEdge;
		vector<int> vec = ReadVector(line);
		countOfPoint = vec[0];
		countOfEdge = vec[1];
		restrictionOfEdge = countOfPoint * (countOfPoint - 1) / 2;
		InitMatrix(adjacencyMatrix, countOfPoint);
	}
	else
	{
		return Error::EmptyFile;
	}

	if ((countOfPoint > 400) || (countOfPoint < 1))
	{
		return Error::wrong—ountOfPoint;
	}

	if ((countOfEdge < 0) || (countOfEdge > restrictionOfEdge))
	{
		return Error::wrong—ountOfEdge;
	}

	while (getline(inputFile, line))
	{
		vector<int> vec = ReadVector(line);
		int point1 = vec[0];
		int point2 = vec[1];

		edgeList.push_back(vec);

		if ((point1 > countOfPoint) || (point2 > countOfPoint))
		{
			return Error::wrong—ountOfPoint;
		}
		else
		{
			adjacencyMatrix[point1 - 1][point2 - 1] = 1;
			adjacencyMatrix[point2 - 1][point1 - 1] = 1;
		}
	}

	if (edgeList.size() != countOfEdge)
	{
		return Error::wrong—ountOfEdge;
	}

	return Error::Ok;
}

void PrintMatrix(Matrix const& matrix)
{
	for (const auto& items : matrix)
	{
		for (const auto& item : items)
			cout << item << " ";
		cout << endl;
	}
}

void PrintBridge(Matrix const& matrix)
{
	for (const auto& items : matrix)
	{
		for (const auto& item : items)
			cout << (item + 1) << " ";
		cout << endl;
	}
}

void PrintCutPoint(const vector<int>& cutPoint)
{
	for (const auto& item : cutPoint)
	{
			cout << (item + 1) << " ";
	}
	cout << endl;
}

void SortCutPoint(vector<int>& cutPoint)
{
	sort(cutPoint.begin(), cutPoint.end());
	cutPoint.erase(unique(cutPoint.begin(), cutPoint.end()), cutPoint.end());
}

int timer;
//int tin[400];
//int fup[400];
//bool used[400];
vector<int> tin, fup;
vector<bool> used;

void DFS(Matrix& matrix, Matrix& bridge, vector<int> & cutPoint, int v, int p = -1)
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;

	for (size_t i = 0; i < matrix[v].size(); ++i)
	{
		if (matrix[v][i] == 1)
		{
			int to = i;
			if (to == p)
				continue;
			if (used[to])
				fup[v] = min(fup[v], tin[to]);
			else
			{
				DFS(matrix, bridge, cutPoint, to, v);
				fup[v] = min(fup[v], fup[to]);
				if (fup[to] > tin[v])
					bridge.push_back({ v, to });
				if ((fup[to] >= tin[v]) && (p != -1))
					cutPoint.push_back(v);
				++children;
			}
		}
	}
	if ((p == -1) && (children > 1))
		cutPoint.push_back(v);
}

void FindBridges(Matrix& matrix, Matrix& bridge, vector<int>& cutPoint)
{
	timer = 0;
	tin.assign(countOfPoint, 0);
	fup.assign(countOfPoint, 0);
	used.assign(countOfPoint, false);
	//for (int i = 0; i < countOfPoint; ++i)
		//used[i] = false;
	for (int i = 0; i < countOfPoint; ++i)
		if (!used[i])
			DFS(matrix, bridge, cutPoint, i);
}