#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int x,y,n,Max[N],Max2[N],l[N],z[N];
vector<int>G[N];
char s[N];
long long ans;
inline void upd(int x,int y){
	if (y>Max[x])Max2[x]=Max[x],Max[x]=y;
	else if (y>Max2[x])Max2[x]=y;
}
inline void dfs1(int x,int y){
	l[x]=N;
	if (s[x]=='1')l[x]=0,z[x]=1;
	for (int i:G[x])
		if (i!=y){
			dfs1(i,x);
			int d=Max[i]+1;
			upd(x,d);
			if (z[i]){
				l[x]=min(l[x],d);
				z[x]+=z[i];
			}
		}
}
inline void dfs2(int x,int y){
	if (y){
		int d=Max[x]+1==Max[y]?Max2[y]+1:Max[y]+1;
		upd(x,d);
		if (z[1]>z[x])l[x]=min(l[x],d);
	}
	for (int i:G[x])
		if (i!=y)dfs2(i,x);
	int L=l[x],R=min(Max2[x]+1,Max[x]-1);
	if (L<=R)ans+=R-L+1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	scanf("%s",s+1);
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld\n",ans+1);
	return 0;
}
