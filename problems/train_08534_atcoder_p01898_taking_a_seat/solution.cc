#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"
#define REP(i,a,b) for(i=a;i<b;++i)
#define rep(i,n) REP(i,0,n)
#define ll long long
#define ull unsigned ll
typedef long double ld;
#define ALL(a) begin(a),end(a)
#define ifnot(a) if(not a)
#define dump(x)  cerr << #x << " = " << (x) << endl
using namespace std;

// #define int ll
bool test = 0;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
#define INF (1 << 28)
ull mod = (int)1e9 + 7;
//.....................
#define MAX (int)1e6 + 5

int M, N;
char a[105][105];

signed main(void) {
	int i, j, k, l;
	cin >> M >> N;
	rep(i, M) {
		cin >> a[i];
	}
	int cnt = 0;
	REP(i, 1, M) {
		rep(j, N) {
			if (a[i][j] != '-') continue;
			if (j - 1 > -1) {
				if (a[i][j - 1] != '-') continue;
			}
			if (j + 1 < N) {
				if (a[i][j + 1] != '-') continue;
			}

			int dx, dy;
			REP(dy, -1, 2) REP(dx, -1, 2) {
				int ny = i + dy;
				int nx = j + dx;
				if (ny < 0 || M <= ny) continue;
				if (nx < 0 || N <= nx) continue;

				if (a[ny][nx] == 'x') goto next;
			}
			cnt++;
		next:;
		}
	}
	cout << cnt << endl;
	return 0;
}