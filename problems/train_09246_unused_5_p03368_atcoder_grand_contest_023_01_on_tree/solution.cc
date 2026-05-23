#include<queue>
#include<cstdio>
#include<cctype>
using i64=long long;
const int N=200007;
int p[N],fa[N],vis[N];
struct node{int a,b,id;}a[N],t;
int operator<(const node&a,const node&b){return 1ll*a.a*b.b<1ll*a.b*b.a;}
int read(){int x=0,c=getchar();while(isspace(c))c=getchar();while(isdigit(c))(x*=10)+=c&15,c=getchar();return x;}
int find(int x){return x==fa[x]? x:fa[x]=find(fa[x]);}
std::priority_queue<node>q;
int main()
{
    int n=read();i64 ans=0;vis[1]=1;
    for(int i=2;i<=n;++i) p[i]=read();
    for(int i=1,x;i<=n;++i) x=read(),q.push(a[fa[i]=i]={!x,x,i});
    for(int x,y;q.size();)
    if(x=(t=q.top()).id,q.pop(),!vis[x]&&t.a==a[x].a&&t.b==a[x].b)
        vis[x]=1,y=find(p[x]),ans+=1ll*a[y].b*t.a,fa[x]=y,a[y].a+=t.a,a[y].b+=t.b,q.push(a[y]);
    printf("%lld",ans);
}