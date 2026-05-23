#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
struct ii
{
	long long x,y,id;
}num[100005];
long long n,m,i,j,ans,fa[100005];
struct bian
{
	long long x,y,z;
}bi[200005];
bool cmp(ii x,ii y){return x.x<y.x;}
bool cmp2(ii x,ii y){return x.y<y.y;}
bool cmp3(ii x,ii y){return x.id<y.id;}
bool cmp4(bian x,bian y){return x.z<y.z;}
int find(int x){if (x==fa[x]) return x;return fa[x]=find(fa[x]);}
long long dis(long long x,long long y)
{
	return min(abs(num[x].x-num[y].x),abs(num[x].y-num[y].y));
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>num[i].x>>num[i].y;
		num[i].id=i;
	}
	sort(num+1,num+n+1,cmp);
	for (i=1;i<n;i++)
	{
		bi[i]=(bian){num[i].id,num[i+1].id,0};
	}
	sort(num+1,num+n+1,cmp2);
	for (i=1;i<n;i++)
	{
		bi[i+n-1]=(bian){num[i].id,num[i+1].id,0};
	}
	sort(num+1,num+n+1,cmp3);
	for (i=1;i<=2*n-2;i++)
	{
		bi[i].z=dis(bi[i].x,bi[i].y);
	}
	sort(bi+1,bi+n+n-1,cmp4);
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=n+n-2;i++)
	{
		if (find(bi[i].x)!=find(bi[i].y))
		{
			fa[find(bi[i].x)]=find(bi[i].y);
			ans+=bi[i].z;
		}
	}
	cout<<ans;
	return 0;
}