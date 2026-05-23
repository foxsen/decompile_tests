#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 200005
using namespace std;
inline int in(){
    int x=0;bool f=0;char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
struct edge{
	int to,nxt;
}e[MN];
int head[MN],a[MN],p[MN],ot[MN],q[MN];
int n,x,cnt;
bool vis[MN];
inline void ins(int x,int y){
	e[++cnt].to=y;e[cnt].nxt=head[x];head[x]=cnt;
}
inline void gmex(int u){
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;vis[a[v]]=1;
	}
	for (int i=0;;++i) if (!vis[i]) {a[u]=i;break;}
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;vis[a[v]]=0;
	}
}
inline bool check(int u){
	for (int i=p[u];i!=u;i=p[i]) gmex(i);
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;vis[a[v]]=1;
	}bool mk=1;
	for (int i=0;;++i) if (!vis[i]) {if (a[u]!=i) mk=0;break;}
	for (int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;vis[a[v]]=0;
	}return mk;
}
int main()
{
	n=in();memset(a,-1,sizeof(a));
	for (int i=1;i<=n;++i){
		p[i]=in();ins(p[i],i);++ot[p[i]];
	}int hd=1,tl=0;
	for (int i=1;i<=n;++i) if (!ot[i]) q[++tl]=i;
	while (hd<=tl){
		int u=q[hd++];gmex(u);
		if (!(--ot[p[u]])) q[++tl]=p[u];
	}
	for (int i=1;i<=n;++i) if (a[i]==-1) x=i;
	gmex(x);if (check(x)) {printf("POSSIBLE");return 0;}vis[a[x]]=1;
	gmex(x);if (check(x)) printf("POSSIBLE");else printf("IMPOSSIBLE");return 0;
}