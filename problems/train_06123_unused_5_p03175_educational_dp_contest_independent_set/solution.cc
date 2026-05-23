#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector<int> adj[100001];
vector<ll> w(100001);
vector<ll> b(100001);
void dfs(int i,int par){
	ll z1=1,z2=1;
	for(int j=0;j<adj[i].size();j++){
		if(adj[i][j]==par)
		continue;
		dfs(adj[i][j],i);
		z1=(z1*w[adj[i][j]])%mod;
		z2=(z2*(w[adj[i][j]]+b[adj[i][j]]))%mod;
	}
	w[i]=z2;
	b[i]=z1;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	cout<<(w[1]+b[1])%mod;
	return 0;
}