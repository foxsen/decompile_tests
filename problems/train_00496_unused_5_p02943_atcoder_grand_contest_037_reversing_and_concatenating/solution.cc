#include<cstdio>
#include<cstring>
#define N 10005
int i,j,k,l,n;char c[N],x[N],y[N];
inline void solve()
{
	for(i=j=1;i<=n;i=j)
	{
		while(c[i]==c[j])j++;
		if(k>12||j-i<<k>=n)
		{
			memset(x,c[i],n);
			if(strcmp(x,y)<0)memcpy(y,x,n);
		}
		else if((j-i<<k)+(n<<1)-j+1>=n)
		{
			memset(x,c[i],j-i<<k),memcpy(x+(j-i<<k),c+j,n-(j-i<<k));
			if(strcmp(x,y)<0)memcpy(y,x,n);
		}
	}
}
int main()
{
	scanf("%d%d%s",&n,&k,c+1),k--;
	for(i=1,j=n<<1;i<=n;c[j--]=c[i++])y[i-1]='z';
	solve();
	if(k>1)
	{
		for(i=1,j=n<<1;i<=n;i++,j--)c[i]^=c[j]^=c[i]^=c[j];
		solve();
	}
	return 0*printf("%s\n",y);
}