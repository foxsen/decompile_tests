#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 500 + 5;
const int M = 20;
const int V = 500 * 15 + 5;
const int MOD = (int)1e9 + 7;

struct Matrix
{
	long long a[V][M * 3];
	long long& getEntry(int x, int y) {
		return a[x][y - x + M];
	}
	bool haveEntry(int x, int y) {
		return 0 <= y - x + M && y - x + M < M * 3;
	}
	void clear() {
		memset(a, 0, sizeof a);
	}
} a;

int n, m;
char c[N][M];
int id[N][M];

#define getId(x,y) (id[x][y])

long long modPow(long long a, long long p, long long MOD)
{
	long long ret = 1;
	for( ; p; p >>= 1, a = a * a % MOD) {
		if (p & 1) {
			ret = ret * a % MOD;
		}
	}
	return ret;
}


void solve()
{
	a.clear();
	int v = 0;
	for(int i = 0; i < n; ++ i) {
		scanf("%s", c[i]);
		for(int j = 0; j < m; ++ j) {
			if (c[i][j] == '.') {
				id[i][j] = v ++;
			}
		}
	}
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < m; ++ j) {
			if (c[i][j] == '.') {
				if (i + 1 < n && c[i + 1][j] == '.') {
					a.getEntry(getId(i, j), getId(i, j)) ++;
					a.getEntry(getId(i + 1, j), getId(i + 1, j)) ++;
					a.getEntry(getId(i, j), getId(i + 1, j)) --;
					a.getEntry(getId(i + 1, j), getId(i, j)) --;
				}
				if (j + 1 < m && c[i][j + 1] == '.') {
					a.getEntry(getId(i, j), getId(i, j)) ++;
					a.getEntry(getId(i, j + 1), getId(i, j + 1)) ++;
					a.getEntry(getId(i, j), getId(i, j + 1)) --;
					a.getEntry(getId(i, j + 1), getId(i, j)) --;
				}
			}
		}
	}
	--v;
	long long ret = 1;
	for(int col = 0; col < v; ++ col) {
		if (a.getEntry(col, col) == 0) {
			for(int i = col + 1; a.haveEntry(i, col) && i < v; ++ i) {
				if (a.getEntry(i, col)) {
					for(int j = col; a.haveEntry(col, j) && a.haveEntry(i, j) && j < v; ++ j) {
						swap(a.getEntry(col, j), a.getEntry(i, j));
					}
					ret = -ret;
					break;
				}
			}
		}
		if (a.getEntry(col, col)) {
			ret = ret * a.getEntry(col, col) % MOD;
			long long inv = modPow(a.getEntry(col, col), MOD - 2, MOD);
			for(int i = col + 1; a.haveEntry(i, col) && i < v; ++ i) {
				if (a.getEntry(i, col)) {
					long long by = -a.getEntry(i, col) * inv % MOD;
					for(int j = col; a.haveEntry(col, j) && a.haveEntry(i, j) && j < v; ++ j) {
						(a.getEntry(i, j) += a.getEntry(col, j) * by) %= MOD;
					}
				}
			}
		} else {
			ret = 0;
			break;
		}
	}
	cout << (ret + MOD) % MOD << endl;
}

int main()
{
	int t = 0;
	for( ; scanf("%d%d", &n, &m) == 2 && (n || m); ) {
		printf("Case %d: ", ++ t);
		solve();
	}
	return 0;
}