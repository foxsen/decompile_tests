#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
int d[111111],n,m,s,a,b,c;
vector<P>v[111111];
int main(){
	for(int i=0;i<111111;i++) d[i]=2e9;
	cin>>n>>m>>s;
	while(m--){
		cin>>a>>b>>c;
		v[a].emplace_back(P(b,c));
	}
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(0,s));
	d[s]=0;
	while(!q.empty()){
		P p=q.top();q.pop();
		int cur=p.second;
		int cost=p.first;
		if(d[cur]<cost) continue;
		for(auto &e:v[cur]){
			int nex=e.first;
			int ncos=cost+e.second;
			if(d[nex]<=ncos) continue;
			d[nex]=ncos;
			q.push(P(ncos,nex));
		}
	}
	for(int i=0;i<n;i++){
		if(d[i]==2e9)cout<<"INF"<<endl;
		else cout<<d[i]<<endl;
	}
}
