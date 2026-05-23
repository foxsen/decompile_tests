#include <bits/stdc++.h>
#ifdef _WIN32
#include "debug.hpp"
#endif
using namespace std;

#define rep(i, N)  for(int i = 0; i < (N); i++)
#define reps(i, N) for(int i = 1; i <= (N); i++)
#define repr(i, N) for(int i = (N) - 1; i >= 0; i--)
#define pub push_back

template<typename T> 
void chmax(T &a, T b){ a = max(a, b); };
template<typename T> 
void chmin(T &a, T b){ a = min(a, b); };

typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;
const ll LINF = 10000000000000000;
const int MOD = 1000000007;
const int dx[9] = { 0, 1,  0, -1, 1,  1, -1, -1, 0};
const int dy[9] = { 1, 0, -1,  0, 1, -1, -1,  1, 0};
//--------------------------------------//
int N;
int D[51];

int b[24];
void solve(){
	sort(D, D + N);
	rep(i, N){
		if(i % 2)
			b[D[i]]++;
		else
			b[(24 - D[i]) % 24]++;
	}
	//da(b, 24);
	int ans = INF;
	int c = INF;
	rep(i, 24){
		if(b[i] > 1){
			cout << 0 << endl;
			return;
		}
		else if(b[i]){
			chmin(ans, c);
			c = 1;
		}
		else
			c++;
	}
	cout << ans << endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	rep(i, N) {
		cin >> D[i];
	}
	N++;
	solve();
	return 0;
}
