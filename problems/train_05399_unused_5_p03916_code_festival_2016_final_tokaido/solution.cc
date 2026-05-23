#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 220000;

int fl[MAXN];
int ans[MAXN];
int go[MAXN];
int a[MAXN];
map<int, int> mm;

int get(int x) {
	if (!fl[x])
		return ans[x];
	fl[x] = 0;
	return ans[x] = get(go[x]);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
		scanf("%d", a + i);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		if (!mm.count(x))
			mm[x] = i;
		else
			fl[i] = 1, go[i] = mm[x];
	}
	int dd = 0;
	for (int i = n - 2; i >= 2; --i) {
		dd -= a[i];
		while (mm.begin()->first + dd < 0) {
			pair<int, int> tmp = *mm.begin();
			mm.erase(mm.begin());
			tmp.first = abs(tmp.first + dd) - dd;
			if (mm.count(tmp.first)) {
				fl[tmp.second] = 1;
				go[tmp.second] = mm[tmp.first];
			}
			else {
				mm[tmp.first] = tmp.second;
			}
		}
	}
	for (auto i: mm)
		ans[i.second] = a[0] - a[1] + i.first + dd;
	for (int i = 0; i < m; ++i)
		if (fl[i])
			ans[i] = get(i);
	for (int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}


