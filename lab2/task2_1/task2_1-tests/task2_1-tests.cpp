#include "pch.h"
#include "../task2_1/VectorProccesor.h"

TEST_CASE("InitMatrix")
{
	CHECK("" == "");
	Matrix adjacencyMatrix;
	int countOfPoint = 5;

	InitMatrix(adjacencyMatrix, countOfPoint);
	CHECK(adjacencyMatrix.size() == countOfPoint);
	CHECK(adjacencyMatrix[countOfPoint - 1][countOfPoint - 1] == 0);
	CHECK(adjacencyMatrix[0][0] == 0);
}

TEST_CASE("LoadMatrix")
{
	Matrix adjacencyMatrix, edgeList;
	Error errOk = Error::Ok, err;
	Error failed = Error::FailedToOpen;
	const char* fileName = "in.txt";

	err = LoadMatrix(fileName, adjacencyMatrix, edgeList);
	CHECK(err == errOk);
	PrintMatrix(adjacencyMatrix);
	cout << "!!!" << endl;
	PrintMatrix(edgeList);
}