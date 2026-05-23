#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

const ll MOD = 998244353;

typedef vector<vi> mat;

int get_rank(mat A) //mod 2
{
	const int n = A.size(), m = A[0].size();
	int r = 0;
	for (int i = 0; r < n && i < m; ++i) {
		int pivot = r;
		for (int j = r+1; j < n; ++j) {
			if (A[j][i]) {
				pivot = j;
				break;
			}
		}
		swap(A[pivot], A[r]);
		if (A[r][i] == 0) continue;
		for (int j = r+1; j < n; ++j) {
			if (A[j][i]) {
				for (int k = i; k < m; ++k) {
					A[j][k] ^= A[r][k];
				}       
			}
		}
		++r;
	}
	return r;
}

int main() {
	int N, M;
	cin >> N >> M;
	mat A(N, vi(M));

	rep(i, N) {
		rep(j, M) {
			cin >> A[i][j];
		}
	}

	int r = get_rank(A);

	ll all = 1, dec = 1;
	rep(i, N+M-1) all = all * 2 % MOD;
	rep(i, N+M-r-1) dec = dec * 2 % MOD;
	cout << (all - dec + MOD) % MOD << endl;
	return 0;
}