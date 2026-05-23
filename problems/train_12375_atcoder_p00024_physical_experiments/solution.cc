#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double v;
	while(cin >> v)
	{
		cout << ceil(v*v/98.0)+1 << endl;
	}

}