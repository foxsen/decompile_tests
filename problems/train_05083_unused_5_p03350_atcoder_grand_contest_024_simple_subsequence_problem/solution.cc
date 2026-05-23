/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-02 08:23:29
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=22,M=(1<<20)|10;
int f[N][M],F[N][M],S[N][M],n,m0[N][M],m1[N][M],m,Ans,ans;
char s[M];
int main()
{
	n=read(); m=read();
	fr(i,0,n)
	{
		scanf("%s",s);
		fr(j,0,(1<<i)-1) f[i][j]=(s[j]=='1');
	}
	fr(i,0,n) fr(j,0,(1<<i)-1)
	{
		m0[i][j]=m1[i][j]=-1;
		fr(k,0,i-1)
			if((j>>k)&1) m1[i][j]=k;
			else m0[i][j]=k;
	}
	fr(i,0,n)
	{
		fr(j,0,n-i) fr(k,0,(1<<(i+j))-1){ F[j][k]=f[j][k]; f[j][k]=0; }
/*		fr(j,0,n-i) fr(k,0,(1<<(i+j))-1) if(F[j][k])
		{
			printf("%d\n ",F[j][k]);
			fd(l,i-1,0) putchar(((k>>(l+j))&1)+48); putchar('|');
			fd(l,j-1,0) putchar(((k>>l)&1)+48); putchar(10);
		}
		putchar(10);*/
		fr(j,0,n-i) fr(k,0,(1<<(i+j))-1)
		{
			S[i][k>>j]+=F[j][k];
			int p=m0[j][k&((1<<j)-1)];
			if(p!=-1) f[p][((k>>j)<<(p+1))|(k&((1<<(p+1))-1))]+=F[j][k];
			p=m1[j][k&((1<<j)-1)];
			if(p!=-1) f[p][((k>>j)<<(p+1))|(k&((1<<(p+1))-1))]+=F[j][k];
		}
	}
	fr(i,1,n) fd(j,(1<<i)-1,0) if(S[i][j]>=m){ Ans=i; ans=j; }
//	fr(i,1,n) fd(j,(1<<i)-1,0) printf("%d %d  %d\n",i,j,S[i][j]);
	fd(i,Ans-1,0) putchar(((ans>>i)&1)+'0');
	putchar(10);
	return 0;
}