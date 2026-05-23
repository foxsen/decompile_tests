#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	int W[110] = {}; int S[110] = {}; 
	for(int i = 1; i <= N; i++){
		cin >> W[i]; S[i] = S[i-1] + W[i]; 
	}
	int ans = 1145141919; 
	for(int i = 1; i <= N; i++){
		ans = min(ans, abs(S[N] - 2 * S[i])); 
	}
	cout << ans << endl; 
}