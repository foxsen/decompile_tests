#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>
#include <complex>


typedef long long ll;
const double Eps = 1e-6;

using namespace std;

pair<int, int> p[10000];
struct Sorter
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.first > b.first || a.first == b.first && a.second < b.second;
	}
};
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; ++i)
		{
			int no;
			scanf("%d", &no);

			int total = 0;
			int W = 0;
			int a, b;
			for (int f = 1; f <= 10; ++f)
			{
				scanf("%d", &a);
				total += a;
				if (W)
				{
					total += a * (W % 10);
					W /= 10;
				}
				if (a == 10 && f != 10)
				{
					W += 11;
					continue;
				}

				scanf("%d", &b);
				total += b;
				if (W)
				{
					total += b;
					W /= 10;
				}
				if (a + b == 10)
					++W;
			}
			if (a == 10 || a + b == 10)
			{
				int c;
				scanf("%d", &c);
				total += c;
			}
			p[i] = make_pair(total, no);
		}
		sort(p, p+n, Sorter());
		for (int i = 0; i < n; ++i)
			printf("%d %d\n", p[i].second, p[i].first);
	}

	return 0;
}