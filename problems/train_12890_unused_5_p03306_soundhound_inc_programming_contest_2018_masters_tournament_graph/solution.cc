#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<cmath>
#include<vector>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
#define MAXN 200000
#define INF 0x3f3f3f3f
int n,m;
struct node{
	int v,w;
	node(){}
	node(int V,int W){v=V,w=W;}
};
LL Min=1,Max=INF;
int vis[MAXN+5],dis[MAXN+5];
vector<node> G[MAXN+5];
void DFS(int u,int f,int x,int fa){
	if(x<=0){
		if(!f) Min=max(Min,(-x+2)*1ll);
		else printf("0\n"),exit(0);
	}
	if(f) Max=min(Max,x*1ll);
 	dis[u]=x,vis[u]=f+1;
	int siz=G[u].size();
	for(int i=0;i<siz;i++){
		int v=G[u][i].v,w=G[u][i].w;
		if(v==fa) continue;
		if(vis[v]){
			if(vis[u]==vis[v]){
				if(((dis[u]+dis[v])%2+4)%2!=w%2)
					printf("0\n"),exit(0);
				if(vis[v]==1)
					Min=max(Min,(1+(w-(dis[u]+dis[v]))/2)*1ll),
					Max=min(Max,(1+(w-(dis[u]+dis[v]))/2)*1ll);
				else 
					Min=max(Min,(1+((dis[u]+dis[v])-w)/2)*1ll),
					Max=min(Max,(1+((dis[u]+dis[v])-w)/2)*1ll);
				if(Min!=Max)
					printf("0\n"),exit(0);
			}
			else//vis[u]=0
				if(dis[u]+dis[v]!=w)
						printf("0\n"),exit(0);
			continue;
		}
		DFS(v,(f+1)%2,w-dis[u],u);
	}
	return ;
}
int main(){
	//freopen("graph.in ","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		G[u].push_back(node(v,w));
		G[v].push_back(node(u,w));
	}
	dis[1]=1,DFS(1,0,1,0);
	if(Min>Max)
		printf("0\n");
	else printf("%lld\n",Max-Min+1);
	return 0;
}
