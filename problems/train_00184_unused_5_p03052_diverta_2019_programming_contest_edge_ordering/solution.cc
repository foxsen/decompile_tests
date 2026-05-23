#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=20,mod=1000000007;

int add(int a,int b,int p=mod){return a+b>=p?a+b-p:a+b;}
int sub(int a,int b,int p=mod){return a-b<0?a-b+p:a-b;}
int mul(int a,int b,int p=mod){return (LL)a*b%p;}
void sadd(int &a,int b,int p=mod){a=add(a,b,p);}
void ssub(int &a,int b,int p=mod){a=sub(a,b,p);}
void smul(int &a,int b,int p=mod){a=mul(a,b,p);}

int n,m;
struct side0{
  int x,y;
}a[N*N+9];
int to[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=0;i<m;++i){
	scanf("%d%d",&a[i].x,&a[i].y);
	--a[i].x;--a[i].y;
	to[a[i].x]|=1<<a[i].y;
	to[a[i].y]|=1<<a[i].x;
  }
}

int inv[N*N+9],fac[N*N+9],ifac[N*N+9];

void Get_inv(){
  inv[1]=1;
  fac[0]=fac[1]=1;
  ifac[0]=ifac[1]=1;
  for (int i=2;i<=m;++i){
	inv[i]=mul(mod-mod/i,inv[mod%i]);
	fac[i]=mul(fac[i-1],i);
	ifac[i]=mul(ifac[i-1],inv[i]);
  }
}

int c[(1<<N)+9],ce[(1<<N)+9];

void Get_e(){
  for (int s=0;s<1<<n;++s){
	c[s]=c[s>>1]+(s&1);
	for (int i=0;i<n;++i)
	  if (s>>i&1){
		int t=to[i]&s;
		ce[s]=ce[s^1<<i]+c[t];
	    break;
	  }
  }
}

struct side{
  int y,next;
}e[N*2+9];
int lin[N+9],cs;

void Ins(int x,int y){e[++cs].y=y;e[cs].next=lin[x];lin[x]=cs;}
void Ins2(int x,int y){Ins(x,y);Ins(y,x);}

int vis[N+9];

int Dfs_vis(int k){
  int res=1<<k;
  vis[k]=1;
  for (int i=lin[k];i;i=e[i].next)
	if (!vis[e[i].y]) res|=Dfs_vis(e[i].y);
  return res;
}

int num[(1<<N)+9];

void Get_num(){
  for (int s=0;s<1<<n-1;++s){
	cs=0;
	for (int i=0;i<n;++i) lin[i]=vis[i]=0;
    for (int i=0;i<n-1;++i)
	  if (s>>i&1) Ins2(a[i].x,a[i].y);
    for (int i=0;i<n;++i)
	  if (!vis[i]){
		int t=Dfs_vis(i);
	    num[s]+=ce[t]-c[t]+1;
	  }
  }
}

struct state{
  int c,cnt,sum;
}dp[(1<<N)+9];

void Get_dp(){
  dp[0].cnt=1;dp[0].sum=0;
  for (int s=0;s<1<<n-1;++s)
	for (int i=0;i<n-1;++i){
      if (s>>i&1) continue;
	  int delta=num[(1<<n-1)-1^s]-num[(1<<n-1)-1^s^1<<i];
	  dp[s|1<<i].c=dp[s].c+delta+1;
	  int cnt=mul(dp[s].cnt,mul(fac[dp[s].c+delta],ifac[dp[s].c]));
	  int sum=mul(dp[s].sum,mul(fac[dp[s].c+delta+1],ifac[dp[s].c+1]));
	  sadd(dp[s|1<<i].cnt,cnt);
	  sadd(dp[s|1<<i].sum,add(sum,mul(cnt,c[s]+1)));
	}
}

void work(){
  Get_inv();
  Get_e();
  Get_num();
  Get_dp();
}

void outo(){
  printf("%d\n",dp[(1<<n-1)-1].sum);
}

int main(){
  into();
  work();
  outo();
  return 0;
}