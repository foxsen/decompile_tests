#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[100000];
int a[100000], b[100000], c[100000];

int t[100000];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n - 1; i++){
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}
	
	
	for (int i = 0; i < m - 1; i++){
		int fr = min(p[i], p[i + 1]);
		int to = max(p[i], p[i + 1]);
		t[fr]++;
		t[to]--;
	}
	
	for (int i = 0; i < n - 1; i++){
		t[i + 1] += t[i];
	}
	
	long long res = 0;
	for (int i = 0; i < n; i++){
		long long A = (long long)a[i] * t[i];
		long long B = (long long)b[i] * t[i] + c[i];
		res += min(A, B);
	}
	
	printf("%lld\n", res);
	
	return 0;
}