#include <cstdio>
int main()
{
	int a[25];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	int cnt = 0;
	for (int i = 1; i < n - 1; i++) {
		if ((a[i] - a[i - 1]) * (a[i] - a[i + 1]) < 0)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}