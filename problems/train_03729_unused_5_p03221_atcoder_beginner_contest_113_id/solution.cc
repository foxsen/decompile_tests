#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<pair<int,int>,pair<int,int>>P;
bool c(P&f,P&s){return f.s.s<s.s.s;}
int main()
{
	int i,n,m,p,y;
	P a[100010];
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>p>>y;
		a[i].f.f=p;
		a[i].f.s=y;
		a[i].s.f=0;
		a[i].s.s=i;
	}
	sort(a,a+m);
	p=a[0].f.f;
	for(y=i=0;i<m;i++)
	{
		if(p!=a[i].f.f)p=a[i].f.f,y=0;
		a[i].s.f=++y;
	}
	sort(a,a+m,c);
	for(i=0;i<m;i++)printf("%012ld\n",(long)(a[i].f.f*1e6+a[i].s.f));
}