#include <bits/stdc++.h>
using namespace std;

int t[100005];

int main()
{
	int n, c, k;
	scanf("%d%d%d", &n, &c, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
	}

	sort(t, t + n);

	int ans = 0;

	for (int i = 0, r; i < n; i = r)
	{
		for (r = i + 1; r < n && r - i < c && t[r] <= t[i] + k; r++)
			;
		++ans;
	}
	printf("%d\n", ans);
}