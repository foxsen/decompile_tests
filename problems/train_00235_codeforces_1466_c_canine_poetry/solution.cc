#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, st, n) for (int i = st; i < n; i++)
const int INF = 1e9+100;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while (t--){
		string s;
		cin>>s;
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n-1; i++){
			if (i < n-2 && s[i] == s[i+1] && s[i] == s[i+2]){
				ans+=2;
				i += 2;
			}else if(s[i] == s[i+1]){
				ans++;
				i++;
			}else if(i < n-2 && s[i] == s[i+2]){
				ans++;
				if (i < n-3 && s[i+1] == s[i+3]){
					ans++;
					i+=3;
				}else{
					i+=2;
				}
			}
		}
		cout<<ans<<'\n';

	}

	return 0;
}
