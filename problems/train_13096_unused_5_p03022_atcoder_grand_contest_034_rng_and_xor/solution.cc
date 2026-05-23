#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 5555555
const int MOD=998244353;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
int n,a[SZ];
const int r2=(MOD+1)/2;
void fwt(int*t)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<(1<<n);++j) if(j&(1<<i))
		{
			int p=(t[j^(1<<i)]+t[j])%MOD,
			q=(t[j^(1<<i)]-t[j])%MOD;
			t[j^(1<<i)]=p;
			t[j]=q;
		}
}
int w0[SZ];
ll f0[SZ],f1[SZ];
int main()
{
	scanf("%d",&n); int ss=0;
	for(int i=0;i<(1<<n);++i)
		scanf("%d",a+i),ss+=a[i];
	ss=qp(ss,MOD-2);
	for(int i=0;i<(1<<n);++i)
		a[i]=a[i]*(ll)ss%MOD;
	for(int i=0;i<(1<<n);++i)
		w0[i]=-a[i];
	fwt(w0);
	for(int i=0;i<(1<<n);++i)
		if(i==0) w0[i]=0;
		else w0[i]=qp(1+w0[i],MOD-2);
	fwt(w0);
	for(int i=0;i<(1<<n);++i)
	{
		ll t=w0[0]-w0[i];
		t=(t%MOD+MOD)%MOD;
		printf("%d\n",int(t));
	}
}
