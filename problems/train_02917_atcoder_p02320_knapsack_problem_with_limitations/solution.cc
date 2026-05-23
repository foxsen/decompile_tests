#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n, W; cin >> n >> W;
	vector<int> v(n);
	vector<int> w(n);
	vector<int> m(n);
	for(int i = 0; i < n; i++) cin >> v[i] >> w[i] >> m[i];

	vector<int> dp(W + 1, 0);
	for(int i = 0; i < n; i++){

		//take key goods each
		for(int k = 0; m[i] > 0; k++){
			int key = min(m[i], (int)(1<<k));
			m[i] -= key;
			for(int j = W; j >= 0; j--){
				if(j + key * w[i] <= W) dp[j + key * w[i]] = max(dp[j + key * w[i]], dp[j] + key * v[i]);
			}
		}
	}

	int ans = 0;
	for(int j = 0; j <= W; j++) ans = max(ans, dp[j]);
	cout << ans << endl;
	return 0;
}

