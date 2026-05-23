#include<cstdio>
#define neko 100010
#define f(i,a,b) for(register int i=(a);i<=(b);i=-(~i))
#define travel(i,u,v) for(register int i=head[u],v=e[i].v;i;i=e[i].nex,v=e[i].v)
typedef long long ll;
int n,m,t,flag;
typedef int arr[neko];
arr head,col,book;
struct edge
{
	int v,tp,nex;
}e[neko<<1];
ll ans,tot,cnt[5];
void dfs(int u)
{
	book[u]=1,++cnt[0],++cnt[col[u]];
	travel(i,u,v)
	{
		if(e[i].tp==1)++tot;
		if(!book[v])
		{
			col[v]=(col[u]+e[i].tp+2)%3+1;//反正这样就是对的我不管啦
			dfs(v);
		}
		else if(col[v]^((col[u]+e[i].tp+2)%3+1))flag=1;
	}
}
void add(int x,int y)
{
	e[++t].v=y,e[t].tp=1,e[t].nex=head[x],head[x]=t;
	e[++t].v=x,e[t].tp=-1,e[t].nex=head[y],head[y]=t;
}
int main()
{
	int x,y;
	scanf("%d%d",&n,&m);
	f(i,1,m)scanf("%d%d",&x,&y),add(x,y);
	f(i,1,n)col[i]=1;
	f(i,1,n)
	{
		if(book[i])continue;
		cnt[0]=tot=cnt[1]=cnt[2]=cnt[3]=0;
		dfs(i);
		if(flag)ans+=cnt[0]*cnt[0],flag=0;
		else if(!(cnt[1]&&cnt[2]&&cnt[3]))ans+=tot;
		else ans+=cnt[1]*cnt[2]+cnt[2]*cnt[3]+cnt[3]*cnt[1];
	}return printf("%lld\n",ans),0;
}