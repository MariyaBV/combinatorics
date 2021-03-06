#include "pch.h"
#include "VectorProccesor.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: task2_1.exe edge_list.txt" << endl;

		return 1;
	}
	const char* fileName = argv[1];
	Matrix adjacencyMatrix;
	Matrix edgeList;

	LoadMatrix(fileName, adjacencyMatrix, edgeList);
	PrintMatrix(adjacencyMatrix);

	Matrix bridge;
	vector<int> cutPoint;

	FindBridges(adjacencyMatrix, bridge, cutPoint);
	cout << "CutPoint:" << endl;
	SortCutPoint(cutPoint);
	PrintCutPoint(cutPoint);
	cout << "Bridge:" << endl;
	PrintBridge(bridge);

	return 0;
}
