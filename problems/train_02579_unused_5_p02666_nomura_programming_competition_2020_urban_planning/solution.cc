#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000
vector<long long>e[N];
bool emp[N];
bool used[N];
vector<long long>a;
long long cnt;
long long b[N];
long long c[N];
long long k[N];
long long r[N];

void dfs(int k) {
	if (used[k])return;
	used[k] = true;
	cnt++;
	long long sz = e[k].size();
	f(i, sz)dfs(e[k][i]);
	return;
}

int main() {
	long long n, cc;
	long long x, y, z;
	long long s, ans;
	f(i, N) {
		emp[i] = false;
		used[i] = false;
	}
	scanf("%lld", &n);
	f(i, n) {
		scanf("%lld", &x);
		x--;
		if (x >= 0) {
			e[x].push_back(i);
			e[i].push_back(x);
		}
		else emp[i] = true;
	}
	cc = 0;
	f(i, n) {
		if (emp[i]) {
			cnt = 0;
			dfs(i);
			a.push_back(cnt);
		}
	}
	f(i, n) {
		if (!used[i]) {
			cc++; 
			dfs(i);
		}
	}
	k[0] = 1;
	f(i, N - 1) {
		x = k[i] * (i + 1);
		x %= MOD;
		k[i + 1] = x;
	}
	r[0] = 1;
	f(i, N - 1) {
		r[i + 1] = (r[i] * (n - 1)) % MOD;
	}
	f(i, N) {
		b[i] = 0;
		c[i] = 0;
	}
	b[0] = 1;
	long long sz = a.size();
	ans = 0;
	f(i, sz) {
		s = ((a[i] - 1)*r[sz - 1]) % MOD;
		ans = (ans + s) % MOD;
		f(j, i) {
			s = (a[i] * b[j + 1]) % MOD;
			s = (s*k[j + 1]) % MOD;
			s = (s*r[sz - j - 2]) % MOD;
			ans = (ans + s) % MOD;
		}
		c[0] = 1;
		f(j, i + 1)c[j + 1] = ((b[j] * a[i]) + b[j + 1]) % MOD;
		f(j, i + 2)b[j] = c[j];
	}
	s = n - cc;
	s = (s*r[sz]) % MOD;
	ans = (s - ans + MOD) % MOD;
	printf("%lld\n", ans);

	return 0;
}