#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <cassert>
#define SIZE 200005
#define INF 1000000000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char S[SIZE],T[SIZE];
int A[SIZE],B[SIZE],C[SIZE],D[SIZE];
int dw[SIZE],de[SIZE],dw2[SIZE],de2[SIZE];
int ds[SIZE],dn[SIZE],ds2[SIZE],dn2[SIZE];
int rs[SIZE],re[SIZE];
int ans[SIZE];
int n,m,q;

//South : +1
//East  : +1
void solve()
{
	for(int i=0;i<m;i++)
	{
		dw[i]=de[i]=-1;
		if(i>0)
		{
			if(dw[i-1]!=-1) dw[i]=dw[i-1]+1;
			if(de[i-1]!=-1) de[i]=de[i-1]+1;
		}
		if(T[i]=='E') de[i]=0;
		else dw[i]=0;
	}
	for(int i=m-1;i>=0;i--)
	{
		dw2[i]=de2[i]=-1;
		if(i+1<m)
		{
			if(dw2[i+1]!=-1) dw2[i]=dw2[i+1]+1;
			if(de2[i+1]!=-1) de2[i]=de2[i+1]+1;
		}
		if(T[i]=='E') de2[i]=0;
		else dw2[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		ds[i]=dn[i]=-1;
		if(i>0)
		{
			if(ds[i-1]!=-1) ds[i]=ds[i-1]+1;
			if(dn[i-1]!=-1) dn[i]=dn[i-1]+1;
		}
		if(S[i]=='S') ds[i]=0;
		else dn[i]=0;
	}
	for(int i=n-1;i>=0;i--)
	{
		ds2[i]=dn2[i]=-1;
		if(i+1<n)
		{
			if(ds2[i+1]!=-1) ds2[i]=ds2[i+1]+1;
			if(dn2[i+1]!=-1) dn2[i]=dn2[i+1]+1;
		}
		if(S[i]=='S') ds2[i]=0;
		else dn2[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		rs[i]=(S[i]=='S');
		if(i>0) rs[i]+=rs[i-1];
	}
	for(int i=0;i<m;i++)
	{
		re[i]=(T[i]=='E');
		if(i>0) re[i]+=re[i-1];
	}
	for(int i=0;i<q;i++)
	{
		if(A[i]<=C[i]&&B[i]<=D[i])
		{
			ans[i]=-1;
			if(A[i]==C[i]&&S[A[i]]=='S') ans[i]=D[i]-B[i];
			else if(B[i]==D[i]&&T[B[i]]=='E') ans[i]=C[i]-A[i];
			else
			{
				int ms=-1;
				if(S[A[i]]=='S') ms=0;
				else if(dw[B[i]]!=-1&&ds[A[i]]!=-1) ms=(dw[B[i]]+ds[A[i]])*2;
				int me=-1;
				if(T[B[i]]=='E') me=0;
				else if(de[B[i]]!=-1&&dn[A[i]]!=-1) me=(de[B[i]]+dn[A[i]])*2;
				int ms2=-1;
				if(S[C[i]]=='S') ms2=0;
				else if(dw2[D[i]]!=-1&&ds2[C[i]]!=-1) ms2=(dw2[D[i]]+ds2[C[i]])*2;
				int me2=-1;
				if(T[D[i]]=='E') me2=0;
				else if(de2[D[i]]!=-1&&dn2[C[i]]!=-1) me2=(de2[D[i]]+dn2[C[i]])*2;
				int now=INF;
				if(ms>=0&&me2>=0) now=min(now,ms+me2+C[i]+D[i]-A[i]-B[i]);
				if(me>=0&&ms2>=0) now=min(now,me+ms2+C[i]+D[i]-A[i]-B[i]);
				int cs=rs[C[i]]-(A[i]==0?0:rs[A[i]-1]);
				int ce=re[D[i]]-(B[i]==0?0:re[B[i]-1]);
				if(me>=0&&me2>=0&&cs>0) now=min(now,me+me2+C[i]+D[i]-A[i]-B[i]);
				if(ms>=0&&ms2>=0&&ce>0) now=min(now,ms+ms2+C[i]+D[i]-A[i]-B[i]);
				
				if(T[B[i]]=='E'&&T[D[i]]=='E')
				{
					//printf("%d %d %d\n",ds2[A[i]],dw2[B[i]],ds[A[i]]);
					if(ds2[A[i]]!=-1&&dw2[B[i]]!=-1&&B[i]+dw2[B[i]]<D[i]&&ds[A[i]]!=-1)
					{
						now=min(now,ds2[A[i]]*2+ds[A[i]]*2+C[i]+D[i]-A[i]-B[i]);
					}
				}
				if(S[A[i]]=='S'&&S[C[i]]=='S')
				{
					if(de2[B[i]]!=-1&&dn2[A[i]]!=-1&&A[i]+dn2[A[i]]<C[i]&&de[B[i]]!=-1)
					{
						now=min(now,de2[B[i]]*2+de[B[i]]*2+C[i]+D[i]-A[i]-B[i]);
					}
				}
				
				if(now!=INF) ans[i]=now;
			}
			//printf("* %d %d %d %d\n",A[i],B[i],C[i],D[i]);
			//printf("%s %s -> %d\n",S,T,ans[i]);
		}
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	scanf("%s",&S);
	scanf("%s",&T);
	for(int i=0;i<n;i++)
	{
		if(S[i]=='E') S[i]='S';
		else S[i]='N';
	}
	for(int i=0;i<m;i++)
	{
		if(T[i]=='S') T[i]='E';
		else T[i]='W';
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %d %d",&A[i],&B[i],&C[i],&D[i]);
		A[i]--,B[i]--,C[i]--,D[i]--;
	}
	solve();
	for(int l=0,r=n-1;l<r;l++,r--) swap(S[l],S[r]);
	for(int i=0;i<m;i++)
	{
		if(T[i]=='E') T[i]='W';
		else T[i]='E';
	}
	for(int i=0;i<q;i++) A[i]=n-A[i]-1,C[i]=n-C[i]-1;
	solve();
	for(int l=0,r=m-1;l<r;l++,r--) swap(T[l],T[r]);
	for(int i=0;i<n;i++)
	{
		if(S[i]=='N') S[i]='S';
		else S[i]='N';
	}
	for(int i=0;i<q;i++) B[i]=m-B[i]-1,D[i]=m-D[i]-1;
	solve();
	for(int l=0,r=n-1;l<r;l++,r--) swap(S[l],S[r]);
	for(int i=0;i<m;i++)
	{
		if(T[i]=='E') T[i]='W';
		else T[i]='E';
	}
	for(int i=0;i<q;i++) A[i]=n-A[i]-1,C[i]=n-C[i]-1;
	solve();
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	return 0;
}
