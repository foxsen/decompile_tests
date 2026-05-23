#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e4+20;
const int mod=998244353;

int n,m;

int f[maxn][maxn],jc[maxn],jcn[maxn],inv[maxn];

inline void init()
{
	jc[0]=jc[1]=jcn[0]=jcn[1]=inv[1]=1;
	REP(i,2,1e4)jc[i]=(ll)i*jc[i-1]%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jcn[i]=(ll)jcn[i-1]*inv[i]%mod;
	char A[maxn],B[maxn];
	scanf("%s",A+1);
	int len=strlen(A+1);
	scanf("%s",B+1);
	REP(i,1,len)if(A[i]=='1')
	{
		if(B[i]=='1')n++;
		else m++;
	}
}

inline void doing()
{
	f[0][0]=1;
	REP(i,0,n)REP(j,0,m)
	{
		if(i)
		{
			//f[i][j]=(f[i][j]+(ll)f[i-1][j]*i)%mod;
			if(j)f[i][j]=(f[i][j]+(ll)f[i-1][j]*i*j)%mod;
		}
		if(j)f[i][j]=(f[i][j]+(ll)f[i][j-1]*j*j)%mod;
	}
	int ans=0;
	REP(i,0,n)
	{
		ans=(ans+(ll)jc[n]*jcn[i]%mod*jcn[n-i]%mod*jc[i]%mod*jc[i]%mod*jc[n+m]%mod*jcn[i]%mod*jcn[n+m-i]%mod*f[n-i][m])%mod;
	}
	printf("%d\n",ans);
}

int main()
{
	init();
	doing();
	return 0;
}
