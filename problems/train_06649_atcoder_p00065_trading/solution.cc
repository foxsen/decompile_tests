#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <iostream>
#include <climits>
#include <cfloat>


using namespace std;

int main()
{
	map<int, int> first;
	map<int, int> seq;
	char buf[128];
	int a, b;
	while (true)
	{
		cin.getline(buf, sizeof(buf));
		if (strlen(buf) == 0)
			break;
		sscanf(buf, "%d,%d", &a, &b);
		if (first.count(a) > 0)
			++first[a];
		else
			first.insert(make_pair(a, 1));
	}
	while (scanf("%d,%d", &a, &b) != EOF)
	{
		if (first.count(a) > 0)
		{
			if (seq.count(a) > 0)
				++seq[a];
			else
				seq.insert(make_pair(a, first[a]+1));
		}
	}
	for (map<int, int>::iterator it = seq.begin(); it != seq.end(); ++it)
		printf("%d %d\n", it->first, it->second);

	return 0;
}