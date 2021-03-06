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

TEST_CASE("LoadMatrix and FindBridges")
{
	Matrix adjacencyMatrix, edgeList;
	Error errOk = Error::Ok, err;
	const char* fileName = "in.txt";

	err = LoadMatrix(fileName, adjacencyMatrix, edgeList);
	CHECK(err == errOk);
	PrintMatrix(adjacencyMatrix);
	cout << "---" << endl;

	Matrix bridge;
	Matrix foundBridge = {
		{ 2, 1 }, //{ 3, 2 },
		{ 3, 4 }, //{ 4, 5 },
		{ 5, 6 }, //{ 6, 7 },
		{ 3, 5 }, //{ 4, 6 },
		{ 2, 3 }, //{ 3, 4 },
		{ 0, 2 } //{ 1, 3 }
	};
	vector<int> cutPoint;

	FindBridges(adjacencyMatrix, bridge, cutPoint);
	PrintBridge(bridge);
	CHECK(bridge == foundBridge);

	vector<int> returnCutPoint = { 2, 3, 5, 3, 2 }; // {3, 4, 6, 4, 3}
	CHECK(cutPoint == returnCutPoint);

	vector<int> sortCutPoint = { 2, 3, 5 }; // {3, 4, 6}
	SortCutPoint(cutPoint);
	CHECK(cutPoint == sortCutPoint);

	cout << "---" << endl;
	PrintCutPoint(cutPoint);
}

TEST_CASE("One Bridge, no cut point")
{
	Matrix adjacencyMatrix, edgeList;
	Error errOk = Error::Ok, err;
	const char* fileName = "oneBridge.txt";

	err = LoadMatrix(fileName, adjacencyMatrix, edgeList);
	CHECK(err == errOk);

	Matrix bridge;
	Matrix foundBridge = {
		{ 0, 1 }, //{ 1, 2 }
	};
	vector<int> cutPoint;

	FindBridges(adjacencyMatrix, bridge, cutPoint);
	CHECK(bridge == foundBridge);

	vector<int> returnCutPoint = { };
	SortCutPoint(cutPoint);
	CHECK(cutPoint == returnCutPoint);
}

TEST_CASE("no Bridge, no cut point")
{
	Matrix adjacencyMatrix, edgeList;
	Error errOk = Error::Ok, err;
	const char* fileName = "noBridge.txt";

	err = LoadMatrix(fileName, adjacencyMatrix, edgeList);
	CHECK(err == errOk);

	Matrix bridge;
	Matrix foundBridge = {};
	vector<int> cutPoint;

	FindBridges(adjacencyMatrix, bridge, cutPoint);
	CHECK(bridge == foundBridge);

	vector<int> returnCutPoint = {};
	SortCutPoint(cutPoint);
	CHECK(cutPoint == returnCutPoint);
}