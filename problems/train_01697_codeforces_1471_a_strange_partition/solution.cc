#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll x;
	    cin>>x;
	    vector<ll> a(n);
	    ll sum = 0;
	    ll ans =0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        ans += a[i];
	        sum += (a[i]/x);
	        if(a[i]%x != 0){
	            sum += 1;
	        }
	    }
	   ll ans2 = ans/x;
	    if(ans%x != 0){
	            ans2 += 1;
	   }
	   cout<<min(ans2,sum)<<" "<<max(ans2,sum)<<'\n';
	}
	return 0;
}
