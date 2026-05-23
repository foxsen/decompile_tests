#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int ans = 0;
	for(int i=1;i<n;i++){
		int aa = min(a[i-1], a[i]);
		int b = max(a[i-1], a[i]);
		int c = b / aa;
		if(c < 2) continue;
		while(aa * 2 < b) ans++, aa *= 2;
	}
	cout<<ans<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
