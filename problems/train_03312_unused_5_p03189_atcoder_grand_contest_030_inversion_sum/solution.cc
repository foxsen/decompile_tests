#include<cstdio>

const int mod=1000000007;
const int inv2=(mod+1)/2;
int n,m,a[5010],x,y,i,j;

long long p[5010][5010],t;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)p[i][j]=a[i]>a[j];
	for (int k=0;k<m;k++) {
		scanf("%d%d",&x,&y);
		p[x][y]=p[y][x]=(p[x][y]+p[y][x])*inv2%mod;
		for(i=1;i<=n;++i)if(i!=x&&i!=y) p[i][x]=p[i][y]=(p[i][x]+p[i][y])*inv2%mod,
			p[x][i]=p[y][i]=(p[x][i]+p[y][i])*inv2%mod;
	}
	for(i=1;i<=n;++i)for(j=n;j>i;--j)t=(t+p[i][j])%mod;
	for (i=0;i<m;++i) t=t*2%mod;
	printf("%lld\n",t);
}