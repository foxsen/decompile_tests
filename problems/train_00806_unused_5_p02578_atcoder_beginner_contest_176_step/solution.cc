#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,ma;
	
	cin>>n>>ma;
	ll ans=0;
	for(int i=1;i<n;i++){
		ll x;
		cin>>x;
		if(ma>x)ans+=ma-x;
		ma=max(ma,x);
	}
	cout<<ans;
	return 0;
}
