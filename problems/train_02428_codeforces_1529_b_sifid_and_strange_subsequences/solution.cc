#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define vii vector<ll>
#define pii pair<ll,ll>
#define mii map<ll,ll>
#define fastio() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int main() {
    fastio();
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        ll a[n]; 
	    for(auto &x : a) cin>>x;
	    sort(a,a+n);
		for(ll i=0;i<n-1;i++)
			if(a[i+1]-a[i]<a[n-1])
				n--,i--;
        cout<<n<<"\n";
	}
    return 0;
}