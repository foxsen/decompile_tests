#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=200,A=20;
char s[N][N];
int f[N][N][N],g[N][N][N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(len,1,n)
	rep(u,1,n-len+1)
	{
		int d=u+len-1;
		f[u][d][m+1]=m;
		per(l,m,1)
		{
			if(len==1)f[u][d][l]=s[u][l]==s[u][l+1]?f[u][d][l+1]:l;
			else f[u][d][l]=(s[u][l]==s[u+1][l]&&f[u+1][d][l]>=l)?
					(s[u][l]==s[u][l+1]?f[u][d][l+1]:l):l-1;
		}
	}
	int ans=0;
while(f[1][n][1]<m)
{
	++ans;
	swap(f,g);
	
	rep(len,1,n)
	rep(u,1,n-len+1)
	{
		int d=u+len-1;
		f[u][d][m+1]=m;
		per(l,m,1)
		{
				f[u][d][l]=g[u][d][g[u][d][l]+1];
				if(f[u][d][l]==m)continue;
				int l1=u,r1=d-1;
				if(len>5)
				while(l1+1!=r1)
				{
					int m=(l1+r1)/2;
					if(g[u][m][l]>=g[m+1][d][l])l1=m;
					else r1=m;
				}
			//	if(u==1&&d==6&&l==1)
			//		int yyx=1;
				rep(i,l1,r1)chmax(f[u][d][l],min(g[u][i][l],g[i+1][d][l]));
		}
	}
}
	cout<<ans;
}