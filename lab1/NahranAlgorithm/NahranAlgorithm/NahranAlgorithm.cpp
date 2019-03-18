#include "pch.h"
#include "tchar.h"
#include <boost/timer.hpp>

using namespace std;

//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	//vector<size_t> v = { 7, 1, 12, 5, 9 };
	//vector<size_t> v = { 7, 1, 12, 5, 9, 20, 15, 2, 11, 4 };
	vector<size_t> v = { 7, 1, 12, 5, 9, 20, 15, 2, 11, 4, 30 };
	boost::timer t;

	t.restart();
	sort(v.begin(), v.end());

	do
	{
		/*copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
		cout << endl;*/
	} while (next_permutation(v.begin(), v.end()));

	double duration = t.elapsed();
	cout << duration << endl;

	return 0;
}

//N = 5, t = 0.36 sec;
//с выводом / 0, 01 sec без вывода N = 10, t = 19.945 sec;
//N = 11, t = 219.998 sec;
//N = 15, t ~219.998 * 12 * 13 * 14 * 15 = 7207134.48 sec ~7 * 10 ^ 6 sec;
//N = 50, t ~50 ! / 11 !*219.998 ~7.61937 * 10 ^ 56 * 219.998 ~1.676 * 10 ^ 59;
//N = 100, t ~100 ! / 11 !*219.998 ~2.338 * 10 ^ 150 * 219.998 ~5.1436 * 10 ^ 152;
