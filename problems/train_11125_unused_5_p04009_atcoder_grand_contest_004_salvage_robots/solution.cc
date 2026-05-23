#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define si short int
#define MAX 101
si f[MAX][MAX][MAX][MAX],s[MAX][MAX];
si sum(int a,int b,int c,int d)
{
	if(a>c)swap(a,c);if(b>d)swap(b,d);
	return s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
}
si n,m,X,Y,ans;
char g[MAX][MAX];
void upd(si &x,si y){if(x<y)x=y;}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%s",g[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(g[i][j]=='E')X=i,Y=j;
			else if(g[i][j]=='o')s[i][j]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int a=X;a;--a)
		for(int b=Y;b;--b)
			for(int c=X;c<=n;++c)
				for(int d=Y;d<=m;++d)
				{
					ans=max(ans,f[a][b][c][d]);
					int L=d-Y+1,R=m-Y+b,U=c-X+1,D=n-X+a;
					if(a>U)upd(f[a-1][b][c][d],f[a][b][c][d]+sum(a-1,max(b,L),a-1,min(d,R)));
					if(b>L)upd(f[a][b-1][c][d],f[a][b][c][d]+sum(max(a,U),b-1,min(c,D),b-1));
					if(c<D)upd(f[a][b][c+1][d],f[a][b][c][d]+sum(c+1,max(b,L),c+1,min(d,R)));
					if(d<R)upd(f[a][b][c][d+1],f[a][b][c][d]+sum(max(a,U),d+1,min(c,D),d+1));
				}
	cout<<ans<<endl;
	return 0;
}
