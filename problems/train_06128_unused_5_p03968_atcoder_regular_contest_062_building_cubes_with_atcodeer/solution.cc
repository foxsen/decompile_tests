#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define LL long long
#define MAXN 400
LL F(LL a,LL b,LL c,LL d)
{
	return a<<30|b<<20|c<<10|d;
}
map<LL,int> G;
void A(LL a,int v)
{
	for(int i=0;i<4;i++)
	{
		G[a]+=v;
		a=(a>>10)|((a&1023)<<30);
	}
}
int a[MAXN][8],n;
LL r,ans,u[4];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j+4]=a[i][j];
		}
		A(F(a[i][0],a[i][1],a[i][2],a[i][3]),1);
	}
	for(int i=0;i<n;i++)
	{
		A(F(a[i][0],a[i][1],a[i][2],a[i][3]),-1);
		for(int j=i+1;j<n;j++)
		{
			A(F(a[j][0],a[j][1],a[j][2],a[j][3]),-1);
			for(int k=0;k<4;k++)
			{
				r=1;
				u[0]=F(a[j][k+1],a[j][k+0],a[i][1],a[i][0]);
				u[1]=F(a[j][k+0],a[j][k+3],a[i][2],a[i][1]);
				u[2]=F(a[j][k+3],a[j][k+2],a[i][3],a[i][2]);
				u[3]=F(a[j][k+2],a[j][k+1],a[i][4],a[i][3]);
				if(G[u[0]]&&G[u[1]]&&G[u[2]]&&G[u[3]])
				{
					r*=G[u[0]];
					A(u[0],-1);
					r*=G[u[1]];
					A(u[1],-1);
					r*=G[u[2]];
					A(u[2],-1);
					r*=G[u[3]];
					ans+=r;
					A(u[0],1);
					A(u[1],1);
					A(u[2],1);
				}
			}
			A(F(a[j][0],a[j][1],a[j][2],a[j][3]),1);
		}
	}
	printf("%lld\n",ans);
}