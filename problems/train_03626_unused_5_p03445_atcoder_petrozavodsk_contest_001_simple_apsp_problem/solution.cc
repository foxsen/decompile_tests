#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,iv=(mod+1)/2;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int h,w,n,x[33],y[33],prex[1111111],prey[1111111],ans,arrx[111],arry[111],cntx,cnty,dist[111][111],res;
int fx[111],fy[111];
bool ex[1111111],ey[1111111],ff[111][111];
map<pair<int,int>,int> mp;
bool In(int x,int y)
{
	return (x>=1 && x<=cntx && y>=1 && y<=cnty);
}
void bfs(int i,int j)
{
	memset(dist,-1,sizeof(dist));
	dist[i][j]=0;
	queue<pair<int,int> > q;
	q.push(make_pair(i,j));
	while(!q.empty())
	{
		int xx=q.front().first,yy=q.front().second;
		q.pop();
		for (int i=0;i<4;i++)
		{
			int xxx=xx+dx[i],yyy=yy+dy[i];
			if (!In(xxx,yyy) || ff[xxx][yyy]) continue;
			if (!~dist[xxx][yyy])
			{
				dist[xxx][yyy]=dist[xx][yy]+1;
				q.push(make_pair(xxx,yyy));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);x[i]++;y[i]++;
		ex[x[i]]=ey[y[i]]=1;
		mp[make_pair(x[i],y[i])]=1;
		prex[x[i]]++;prey[y[i]]++;
	}
	for (int i=1;i<=h;i++) prex[i]+=prex[i-1];
	for (int i=1;i<=w;i++) prey[i]+=prey[i-1];
	for (int i=1;i<h;i++)
	{
		if (!ex[i] && !ex[i+1])
		{
			ans=(1ll*(1ll*w*i-prex[i])%mod*((1ll*w*(h-i)-(n-prex[i]))%mod)+ans)%mod;
		}
	}
	for (int i=1;i<w;i++)
	{
		if (!ey[i] && !ey[i+1])
		{
			ans=(1ll*(1ll*h*i-prey[i])%mod*((1ll*h*(w-i)-(n-prey[i]))%mod)+ans)%mod;
		}
	}
	for (int i=1;i<=h;i++)
	{
		if (ex[i] || ex[i-1] || i==1) 
		{
			arrx[++cntx]=i;
			if (ex[i]) fx[cntx]=1;
			else
			{
				for (int j=i;j<=h && !ex[j];j++)
				{
					fx[cntx]++;
				}
			}
		}
	}
	for (int i=1;i<=w;i++)
	{
		if (ey[i] || ey[i-1] || i==1) 
		{
			arry[++cnty]=i;
			if (ey[i]) fy[cnty]=1;
			else
			{
				for (int j=i;j<=w && !ey[j];j++)
				{
					fy[cnty]++;
				}
			}
		}
	}
	for (int i=1;i<=cntx;i++)
	{
		for (int j=1;j<=cnty;j++)
		{
			ff[i][j]=mp[make_pair(arrx[i],arry[j])];
		}
	}
	for (int i=1;i<=cntx;i++)
	{
		for (int j=1;j<=cnty;j++)
		{
			if (ff[i][j]) continue;
			bfs(i,j);
			for (int k=1;k<=cntx;k++)
			{
				for (int h=1;h<=cnty;h++)
				{
					if (!ff[k][h]) res=(1ll*dist[k][h]*fx[i]%mod*fy[j]%mod*fx[k]%mod*fy[h]+res)%mod;
				}
			}
		}
	}
	ans=(1ll*res*iv+ans)%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}