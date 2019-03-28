#include "pch.h"

using namespace std;

enum class Error
{
	FailedToOpen,
	wrong—ountOfEdge,
	wrong—ountOfPoint,
	EmptyFile,
	Ok,
};

using Matrix = vector<vector<int>>;

void InitMatrix(Matrix& adjacencyMatrix, int countOfPoint);
Error LoadMatrix(const char* fileName, Matrix& adjacencyMatrix, Matrix& edgeList);
vector<int> ReadVector(string& line);
void PrintBridge(Matrix const& matrix);
void PrintMatrix(Matrix const& matrix);
void DFS(Matrix& matrix, Matrix& bridge, vector<int>& cutPoint, int v, int p);
void FindBridges(Matrix& matrix, Matrix& bridge, vector<int>& cutPoint);
void PrintCutPoint(const vector<int>& cutPoint);
void SortCutPoint(vector<int>& cutPoint);