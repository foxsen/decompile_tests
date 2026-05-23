#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

vector<int>E[200000];
int id[200000];
int d[200000];

void dfs(int v,int k){
	id[v]=k;
	for(int u:E[v]){
		if(id[u]==-1){
			if(d[v]!=-1)d[u]=!d[v];
			dfs(u,k);
		}
		else{
			if(d[u]==d[v]){
				d[u]=-1;
			}
		}
	}
}
vector<int>v[200000];

int main(){
	int n,m;cin>>n>>m;
	rep(i,m){
		int a,b;scanf("%d%d",&a,&b);a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	memset(id,-1,sizeof(id));
	int cnt=0;
	rep(i,n){
		if(id[i]==-1){
			dfs(i,cnt++);
		}
		v[id[i]].push_back(i);
	}
	ll c1=0,c2=0,c3=0;
	rep(i,cnt){
		if(v[i].size()==1){
			c1++;
			continue;
		}
		c2++;
		bool flag=true;
		for(int j:v[i]){
			if(d[j]==-1)flag=false;
		}
		if(flag)c3++;
	}
	cout<<c1*(n-c1)*2+c1*c1+c2*c2+c3*c3<<endl;
}