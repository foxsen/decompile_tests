#include <algorithm>
#include <cstdio>
int arr[200005];
int main()
{
	// freopen("AGC032-E.in", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n << 1; i++)
		scanf("%d", arr + i);
	std::sort(arr, arr + (n << 1));
	int l = 0, r = n, res = -1;
	while (l <= r)
	{
		int x = l + r >> 1;
		bool flg = true;
		for (int i = 0; i < x; i++)
			flg &= arr[n * 2 - x + i] + arr[n * 2 - x - i - 1] >= m;
		if (flg)
		{
			res = x;
			l = x + 1;
		}
		else
			r = x - 1;
	}
	int ans = 0;
	for (int i = 0; i < n - res; i++)
		ans = std::max(ans, arr[i] + arr[n * 2 - res * 2 - i - 1]);
	for (int i = 0; i < res; i++)
		ans = std::max(ans, arr[n * 2 - res + i] + arr[n * 2 - res - i - 1] - m);
	printf("%d\n", ans);
	return 0;
}
