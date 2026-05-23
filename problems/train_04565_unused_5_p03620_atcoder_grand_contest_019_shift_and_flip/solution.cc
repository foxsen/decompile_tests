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
const int N=2000+5,inf=N*10;
char qa[N*2],*a=qa+N,b[N];
int need[N],need2[N],q[N],nq[N];
int ans=inf;
int n;

bool need_xiao(int a,int b)
{
	return need[a]<need[b];
}

void solve(char *a)
{
	need[0]=inf;
	rep(i,1,n)need[i]=b[i]=='1'?0:need[i-1]+1;
	need[0]=need[n];
	rep(i,1,n)need[i]=b[i]=='1'?0:need[i-1]+1;
	need2[n+1]=inf;
	per(i,n,1)need2[i]=b[i]=='1'?0:need2[i+1]+1;
	need2[n+1]=need2[1];
	per(i,n,1)need2[i]=b[i]=='1'?0:need2[i+1]+1;
	rep(i,1,n)q[i]=i;
	sort(q+1,q+n+1,need_xiao);
	need[0]=0;
	rep(tmp,0,n-1)
	{
		int top=0;
		rep(i,1,n)
		if(a[q[i]]!=b[q[i]])nq[++top]=q[i];
		int suf=0,mn=max(0,need[nq[top]]-tmp);
		per(i,top,1)
		{
			if(suf<need2[nq[i]])suf=need2[nq[i]];
			if(mn>max(0,need[nq[i-1]]-tmp)+suf)mn=max(0,need[nq[i-1]]-tmp)+suf;
		}
		chmin(ans,tmp+top+mn*2);
		a[0]=a[n];
		--a;
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	scanf("%s%s",a+1,b+1);n=strlen(a+1);
	solve(a);
	reverse(a+1,a+n+1);reverse(b+1,b+n+1);
	solve(a);
	if(ans==inf)puts("-1");
	else cout<<ans;
}