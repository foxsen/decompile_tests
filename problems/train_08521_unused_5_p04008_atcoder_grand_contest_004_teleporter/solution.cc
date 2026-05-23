#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
#define N 100005
int n,m,fa[N],cnt,head[N],dep[N],f[N],ans;
struct edge{int to,nxt;}e[N<<1];
void adde(int x,int y){e[++cnt].to=y;e[cnt].nxt=head[x];head[x]=cnt;}
void dfs(int u,int pr){
	f[u]=1;
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		dfs(v,u);
		f[u]=max(f[u],f[v]+1);
	}
	if (f[u]>=m&&fa[u]!=1) ans++,f[u]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	rep (i,1,n){
		scanf("%d",&fa[i]);
		if (i>1) adde(fa[i],i);
	}
	if (fa[1]!=1) ans++,fa[1]=1;
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}