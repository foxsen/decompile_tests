#include <bits/stdc++.h>
const int B=200;
typedef long long ll;
using namespace std;
int T,n,m,l;
map<string,vector<string> >V;
map<string,bool>vis;
string s,t;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;t=s;
		sort(t.begin(),t.end());
		V[t].push_back(s);
	}
	l=s.size();
	ll ans=0,sum=0;
	for(auto it:V){
		auto &v=it.second;
		m=v.size(),ans+=sum*m*1337,sum+=m;
		if(m<=200*l){
			for(int i=0;i<m;i++) for(int j=i+1;j<m;j++){
				int L=0,R=l-1;
				while(v[i][L]==v[j][L]&&L<=R) L++;
				while(v[i][R]==v[j][R]&&L<=R) R--;
				int f1=1,f2=1;
				for(int k=L;k<R;k++){
					f1&=(v[i][k]<=v[i][k+1]);
					f2&=(v[j][k]<=v[j][k+1]);
				}
				if(f1||f2) ans++;
				else ans+=2;
			}
			continue;
		}
		ll nw=m*(m-1ll);
		vis.clear();
		for(auto &s:v) vis[s]=true;
		for(auto &s:v){
			for(int i=0;i<l;i++) for(int j=i+2;j<=l;j++){
				t=s,sort(t.begin()+i,t.begin()+j);
				if(t[i]!=s[i]&&t[j-1]!=s[j-1]&&vis.count(t)) nw--;
			}
		}
		ans+=nw;
	}
	cout<<ans<<"\n";
}
