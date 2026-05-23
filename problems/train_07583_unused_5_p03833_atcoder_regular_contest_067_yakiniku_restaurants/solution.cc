#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 5005;
typedef long long ll; 
using namespace std;

int n, m, a[N], b[N][N], r[N], l[N], q[N][N]; 
ll c[N], sum[N], ans; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

void add(int l, int r, ll x) { c[l] += x, c[r + 1] -= x; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin);
#endif
	n = read <int> (), m = read <int> ();
	for(int i = 1; i < n; i++) a[i] = read <int> ();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) b[i][j] = read <int> ();
	for(int i = 1; i <= m; i++) r[i] = 0, l[i] = 1; 
	for(int i = n; i >= 1; i--)
	{
		for(int pos, j = 1; j <= m; j++)
		{
			pos = i + 1; 
			while(l[j] <= r[j] && b[i][j] >= b[q[j][r[j]]][j])
				add(pos, (r[j] > l[j] ? q[j][r[j] - 1] - 1 : n), -b[q[j][r[j]]][j]), r[j]--, pos = q[j][r[j]]; 
			add(i, pos - 1, b[i][j]), r[j]++, q[j][r[j]] = i; 
		}
		add(i + 1, n, -a[i]); 
		for(int j = i; j <= n; j++) sum[j] = sum[j - 1] + c[j], ans = max(ans, sum[j]); 
	}
	printf("%lld\n", ans); 
	return 0; 
}
