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
#include <climits>
#include <cfloat>

using namespace std;

void printTime(int sec)
{
	printf("%02d:%02d:%02d\n", sec/3600, sec/60%60, sec%60);
}
int main()
{
	while (true)
	{
		int h, m, s;
		scanf("%d %d %d\n", &h, &m, &s);
		if (h == -1 && m == -1 && s == -1)
			break;

		const int VideoLen = 2*3600;
		int sec = h*3600+m*60+s;
		printTime(VideoLen - sec);
		printTime(VideoLen*3 - sec*3);
	}

	return 0;
}