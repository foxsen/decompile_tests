#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,k,m;
	cin>>n>>m>>k;
	ll a[n],b[m];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	for(int i=1;i<n;i++)a[i]+=a[i-1];
	for(int i=1;i<m;i++)b[i]+=b[i-1];
	ll ans=0;
	auto l=lower_bound(a,a+n,k);
	ans=max(ans,(a[l-a]==k)?((ll)(l-a)+1):(ll)(l-a));
	for(int i=0;i<m;i++){
		ll z=k-b[i];
		if(z>=0){
			auto u=lower_bound(a,a+n,z);
			ans=max(ans,((a[u-a]==z)?((ll)(u-a)+1):(ll)(u-a))+i+1);
		}
	}
	cout<<ans<<endl;
}
