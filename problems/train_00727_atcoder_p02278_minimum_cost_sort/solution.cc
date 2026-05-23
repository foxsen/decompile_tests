#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

int main(void)
{
	int n, W, MIN = 100001, sum = 0, p = 0, pp, cost = 0, k = 0, min = 100001;
	cin >> n;
	vector<int> box, list;
	vector<bool> mark;
	for (int i = 0; i < n; i++) {
		cin >> W;
		box.push_back(W);
		list.push_back(W);
		mark.push_back(false);
		if (W < MIN)
			MIN = W;
	}
	sort(list.begin(), list.end());
	while (p < n) {
		if (mark[p] == false) {
			sum = 0;
			k = 0;
			min = 100001;
			pp = p;
			while (mark[pp] == false) {
				mark[pp] = true;
				sum += box[pp];
				k++;
				if (box[pp] < min)
					min = box[pp];
				pp = find(list.begin(), list.end(), box[pp]) - list.begin();
			}
			if (sum + (k - 2) * min > sum + min + (k + 1) * MIN)
				cost += sum + min + (k + 1) * MIN;
			else
				cost += sum + (k - 2) * min;
			p++;
		}
		else
			p++;
	}
	cout << cost << endl;
	return 0;
}
