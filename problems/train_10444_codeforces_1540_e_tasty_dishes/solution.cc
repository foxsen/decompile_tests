#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
const int MAXN=330;
const int mod=1e9+7;
const int inf=1<<30;
int pw[MAXN][MAXN+1000];
int inv[MAXN],a[MAXN],h[MAXN],d[MAXN];
int A[MAXN][MAXN],e[MAXN][MAXN],sum[MAXN][MAXN],num[MAXN][MAXN];
int n;
 
int add(int a,int b)
{
	return a+b>=mod?a+b-mod:a+b;
}
 
int dec(int a,int b)
{
	return a-b<0?a-b+mod:a-b;
}
 
int mul(int a,int b)
{
	return 1ll*a*b%mod;
}
 
int MOD(int x)
{
	x%=mod;
	if(x<0)
		x+=mod;
	return x;
}
 
void addBIT(int *t,int x,int d)
{
	while(x<=n)
	{
		t[x]=add(t[x],d);
		x+=x&(-x);
	}
}
 
int query(int *t,int x)
{
	int ret=0;
	while(x)
	{
		ret=add(ret,t[x]);
		x-=x&(-x);
	}
	return ret;
}
 
void build()
{
	memset(sum,0,sizeof(sum));
	int i,j;
	for(i=n;i>=1;i--)
	{
		if(a[i]>0)
			d[i]=0;
		else
			d[i]=inf;
		for(j=i+1;j<=n;j++)
		{
			if(A[i][j])
				d[i]=min(d[i],d[j]+1);
		}
		if(d[i]!=inf)
		{
			for(j=1;j<=i;j++)
			{
				if(num[i][j])
					sum[j][d[i]+1]=add(sum[j][d[i]+1],
						mul(mul(pw[j][n-d[i]],num[i][j]),MOD(a[i])));
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			sum[i][j]=add(sum[i][j-1],sum[i][j]);
		for(j=n;j>=1;j--)
			sum[i][j]=dec(sum[i][j],sum[i][j^(j&(-j))]);
	}
}
 
void debug(int arr[][MAXN])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}
 
int main()
{
	int i,j,k,sz,q,op,l,r,id,x,t,tmp,ans;
	scanf("%d",&n);
	inv[0]=inv[1]=1;
	//O(N)????? 
	for(i=2;i<=n;i++)
		inv[i]=mul(mod-mod/i,inv[mod%i]);
	for(i=1;i<=n;i++)
	{
		pw[i][n]=1;
		for(j=n-1;j>=0;j--)
			pw[i][j]=mul(pw[i][j+1],inv[i]);
		for(j=n+1;j<=n+1000;j++)
			pw[i][j]=mul(pw[i][j-1],i);
	}
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&sz);
		A[i][i]=i;
		while(sz--)
		{
			scanf("%d",&j);
			A[i][j]=j;
		}
	}
	for(i=1;i<=n;i++)
	{
		e[i][i]=1;
		for(j=i-1;j>=1;j--)
		{
			t=dec(i,j);
			tmp=0;
			for(k=j+1;k<=i;k++)
				tmp=add(tmp,mul(e[i][k],A[j][k]));
			e[i][j]=mul(tmp,inv[t]);
		}
	}
	for(i=1;i<=n;i++)
	{
		h[i]=1;
		for(j=i;j>=1;j--)
		{
			if(h[j])
			{
				num[i][j]=h[j];
				t=h[j];
				for(k=1;k<=j;k++)
					h[k]=dec(h[k],mul(t,e[j][k]));
			}
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			e[i][j]=add(e[i][j-1],e[i][j]);
	build();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&x,&l,&r);
			ans=0;
			for(i=1;i<=n;i++)
			{
				tmp=query(sum[i],min(x+1,n));
				ans=add(ans,mul(mul(tmp,pw[i][x+n]),dec(e[i][r],e[i][l-1])));
			}
			for(i=l;i<=r;i++)
			{
				if(d[i]>x)
					ans=add(ans,MOD(a[i]));
			}
			printf("%d\n",ans); 
		}
		else
		{
			scanf("%d%d",&id,&x);
			if(a[id]<=0&&a[id]+x>0)
			{
				a[id]+=x;
				build();
			}
			else
			{
				a[id]+=x;
				if(d[id]!=inf)
				{
					for(i=1;i<=id;i++)
					{
						if(num[id][i])
							addBIT(sum[i],d[id]+1,mul(mul(num[id][i],x),pw[i][n-d[id]]));
					}
				}
			}
		}
	}
}
