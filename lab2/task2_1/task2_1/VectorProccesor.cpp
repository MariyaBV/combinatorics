#include "pch.h"
#include "VectorProccesor.h"
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void InitMatrix(Matrix & adjacencyMatrix, int countOfPoint)
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
	int countOfPoint, countOfEdge, restrictionOfEdge;

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