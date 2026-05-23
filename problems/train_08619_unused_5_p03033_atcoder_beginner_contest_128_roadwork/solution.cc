#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
typedef long long ll;
vector<pair<int,pair<int,int> > > roadwork;
set<pair<ll,ll> > peo;
ll ans[N];
int main(){
	ll n,q;
	ll s,t,x,d;
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s>>t>>x;
		roadwork.push_back({x,{s-x,t-1-x}});
	}
	for(ll i=1;i<=q;i++){
		cin>>d;
		peo.insert({d,i});
		ans[i]=-1;
	}
	sort(roadwork.begin(),roadwork.end());
	for(auto work:roadwork){
		ll L=work.second.first;
		ll R=work.second.second;
		if(peo.empty()) continue;
		auto it=peo.lower_bound({L,-1});
		while(!peo.empty()&&it!=peo.end()&&(*it).first<=R){
			ans[(*it).second]=work.first;
			peo.erase(it++);
		}
	} 
	for(ll i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
