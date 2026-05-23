#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge{
	int t,next,v;
}g[400001];
int i,j,k,n,m,a[200001],f[200001],d[200001],tot,h[200001];
void addedge(int x,int y){
	g[++tot].t=y;g[tot].next=h[x];h[x]=tot;
	g[++tot].t=x;g[tot].next=h[y];h[y]=tot;
	d[x]++;d[y]++;
}
bool work(int x,int fa){
	if (d[x]==1){
		f[x]=a[x];return 1;
	}
	ll i,j,k;
	for (j=k=0,i=h[x];i;i=g[i].next)
	 if (fa!=g[i].t){
	 	if (!work(g[i].t,x)) return 0;
	 	j+=f[g[i].t];k=max(k,(ll)f[g[i].t]);
	 }
	if (2*a[x]<j||k>a[x]||2*a[x]-j>a[x]) return 0;
	f[x]=2*a[x]-j;
	return 1;
}
int main(){
	scanf("%d",&n);tot=0;memset(h,0,sizeof(h));memset(d,0,sizeof(d));
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<n;i++) scanf("%d%d",&j,&k),addedge(j,k);
	if (n==2){
		puts(a[1]==a[2]?"YES":"NO");
		return 0;
	}
	for (i=1;d[i]==1;i++);
	puts(work(i,0)&&f[i]==0?"YES":"NO");
	return 0;
}