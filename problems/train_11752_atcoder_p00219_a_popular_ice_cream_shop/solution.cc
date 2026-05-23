#include <iostream>
using namespace std;
int main()
{
	int n, t, s[10], i, j;
	while (cin >> n && n)
	{
		for (i = 0; i < 10; i++)
			s[i] = 0;
		for (i = 0; i < n; i++)
		{
			cin >> t;
			s[t]++;
		}
		for (i = 0; i < 10; i++)
		{
			if (s[i] == 0)
				cout << "-" << endl;
			else
			{
				for (j = 0; j < s[i]; j++)
					cout << "*";
				cout << endl;
			}
		}
	}
}