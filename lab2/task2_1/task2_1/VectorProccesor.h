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
void PrintMatrix(Matrix const& matrix);