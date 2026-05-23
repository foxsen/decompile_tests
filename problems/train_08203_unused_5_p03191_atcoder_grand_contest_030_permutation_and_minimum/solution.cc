#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const LL mod = 1e9 + 7;

int main(){
	int N; cin >> N;
	vector<int> b(2*N,0);
	int g = 0, z = 0, c = 0;
	repp(i,0,N){
		int A,B; cin >> A >> B;
		if(A == -1 && B == -1){
			g += 2;
			++c;
		} else if(A == -1){
			b[B-1] = 1;
			++g;
			++z;
		} else if(B == -1){
			b[A-1] = 1;
			++g;
			++z;
		} else {
			b[A-1] = b[B-1] = 2;
		}
	}
	vector<vector<LL>> dp(N+1,vector<LL>(N+1,0));
	dp[c][0] = 1;
	repp(i,0,2*N){
		if(b[i] == 2) continue;
		vector<vector<LL>> nx(N+1,vector<LL>(N+1,0));
		repp(j,0,N+1) repp(k,0,N+1){
			int r = 2*j+k+z-g;
			if(r < 0) continue;
			if(b[i] == 1){
				if(r > 0) (nx[j][k] += dp[j][k]*r) %= mod;
				if(k < N) (nx[j][k+1] += dp[j][k]) %= mod;
			} else {
				if(j > 0 && k < N) (nx[j-1][k+1] += dp[j][k]*j) %= mod;
				if(k > 0) (nx[j][k-1] += dp[j][k]) %= mod;
				(nx[j][k] += dp[j][k]) %= mod;
			}
		}
		swap(dp,nx);
		if(b[i] == 0) --g;
		if(b[i] == 1) --z;
	}
	cout << dp[0][0] << endl;
	return 0;
}
/*
j : (-1,-1)
k : (*,-1) (外からのみ追加可能)
r : (*,-1) を要求
z : (*,-1) の残り
g : -1 の残り個数

2j+k+z=g+s
*/
