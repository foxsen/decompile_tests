// 2018/12/26 Tazoe

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A, B, C, D, E, F;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	cin >> E;
	cin >> F;

	cout << A+B+C+D+E+F-min(A, min(B, min(C, D)))-min(E, F) << endl;

	return 0;
}

