#include<bits/stdc++.h>
using namespace std;
pair<int, int>l[100009], q[200009];
bool cmp(pair<int, int>&a, pair<int, int>&b) { return a.first < b.first; }
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", &l[i].first, &l[i].second);
	for (int i = 1; i <= n; i++)q[i].first = q[i].second = i;
	sort(l + 1, l + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int k = l[i].second;
		q[k].first = q[k + 1].first = min(q[k].first, q[k + 1].first);
		q[k].second = q[k + 1].second = max(q[k].second, q[k + 1].second);
	}
	for (int i = 1; i <= n; i++)printf("%d%c", q[i].second - q[i].first + 1, i == n ? '\n' : ' ');
}