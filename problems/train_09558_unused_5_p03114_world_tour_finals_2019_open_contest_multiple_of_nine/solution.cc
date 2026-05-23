#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

const char lf = '\n';

namespace ae86
{
	const int bufl = 1<<15;

	char buf[bufl],*s=buf,*t=buf;

	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}

	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

#define pick(a,b) (((a)>>(b))&1)

const int _ = 17 , __ = _ + _ , _s = 1 << 16 , mo = 1000000007;

inline lint powa(lint a,lint t)
{
	lint b=1;
	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}
	return b;
}

inline lint inva(lint a)
{
	return powa(a,mo-2);
}

const lint inv9 = inva(9);

int bfa[__]={0},col[__]={0},ccnt=0,cc;
int findbfa(int x){return bfa[x]==x?x:bfa[x]=findbfa(bfa[x]);}
inline void linka(int a,int b){bfa[findbfa(b)]=findbfa(a);}

int n,m,ql[_],qr[_],xl[__],xr[__],ha[__],lha;
lint val[__]={0},f[9][_s]={0},coef[_s]={0};

int main()
{
	ios::sync_with_stdio(0),cout.tie(nullptr);

	n=ty(),m=ty(),lha=0;
	for(int i=0;i<m;i++)ha[lha++]=ql[i]=ty()-1,ha[lha++]=qr[i]=ty();
	
	ha[lha++]=0,sort(ha,ha+lha),lha=unique(ha,ha+lha)-ha;

	for(int i=0;i<lha;i++)bfa[i]=i;
	for(int i=0;i<m;i++)
	{
		ql[i]=lower_bound(ha,ha+lha,ql[i])-ha;
		qr[i]=lower_bound(ha,ha+lha,qr[i])-ha;
		linka(ql[i],qr[i]);
	}

	for(int i=0;i<lha;i++)if(findbfa(i)==i)col[i]=ccnt++;
	for(int i=0;i<lha;i++)col[i]=col[findbfa(i)];
	
	lint bas=inv9;
	for(int i=1;i<lha;i++)
	{
		xl[i]=col[i],xr[i]=col[i-1];
		lint temp=(powa(10,ha[i]-ha[i-1])-1+mo)%mo*inv9%mo;
		bas=bas*temp%mo,val[i]=(temp+1)*inva(temp)%mo;
	}
	if(ha[lha-1]<n)bas=bas*powa(10,n-ha[lha-1])%mo;
	
	cc=1<<ccnt;
	for(int i=0;i<cc;i++)
	{
		coef[i]=1;
		for(int j=1;j<lha;j++)if(pick(i,xl[j]) && pick(i,xr[j]))coef[i]=coef[i]*val[j]%mo;
		f[0][i]=coef[i];
	}

	for(int i=0;i<8;i++)
		for(int j=0;j<cc;j++)
			for(int k=cc-1-j;k>=0;k=(k-1)&(cc-1-j))
			{
				f[i+1][j+k]=(f[i+1][j+k]+f[i][j]*coef[k]%mo)%mo;
				if(k<=0)break;
			}
	
	cout<<bas*f[8][cc-1]%mo<<lf;
	
	return 0;
}
