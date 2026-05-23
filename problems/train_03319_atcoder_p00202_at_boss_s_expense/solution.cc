#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)

const int N = 1000001;
bool isP[N], dp[N];
int main(){
	FOR(i, 2, N) isP[i] = 1;
	FOR(i, 2, N){
		if(isP[i]) for(int j = i*2; j < N; j += i) isP[j] = false;
	}
	int n, x;
	while(cin >> n >> x, n|x){
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		dp[0] = 1;
		rep(i, n){
			int val;
			cin >> val;
			rep(j, x+1-val){
				if(dp[j]){
					dp[j+val] = 1;
					if(isP[j+val]) ans = max(ans, j+val);
				}
			}
		}
		if(ans) cout << ans << endl;
		else cout << "NA" << endl;
	}

	return 0;
}