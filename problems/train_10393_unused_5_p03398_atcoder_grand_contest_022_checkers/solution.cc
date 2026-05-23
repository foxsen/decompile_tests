#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define CL fclose(stdin),fclose(stdout)
namespace io
{
	int F()
	{
		int n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
	long long G()
	{
		long long n=0,F=1;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=0:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=(n<<1)+(n<<3)+ch-'0';
		return F?n:-n;
	}
}
int c[555][555];
int f[555][555][2];
int main()
{
	//freopen("rabbit.in","r",stdin);
	//freopen("rabbit.out","w",stdout);
	int n=io::F(),M=1000000007;
	for(register int i=0;i<=n;++i)c[i][0]=c[i][i]=1;
	for(register int i=2;i<=n;++i)
		for(register int j=1;j<i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
	f[1][0][0]=c[n][1];
	f[1][1][0]=c[n][1];
	#define register 
	for(register int i=1;i<n;++i)
		for(register int j=0;j<=i;++j)
			for(register int k=0;k<=1;++k)
				if(f[i][j][k])
				{
					long long F=f[i][j][k];
					for(register int x=0;x+i<=n;++x)
					{
						register int y=x==0?1:0;
						if((x+y^j)&1)++y;
						for(;x+y+i<=n;y+=2)
						{
							int cnt=x+y;
							if(cnt<j)continue;
							int ck=j+(cnt-j)/2,ct=cnt-ck;
							if(ck>x)
								f[i+cnt][ck-x][k]=(f[i+cnt][ck-x][k]+F*c[n-i][x]%M*c[n-i-x][y])%M;
								else if(ck<x)
									f[i+cnt][x-ck][!k]=(f[i+cnt][x-ck][!k]+F*c[n-i][x]%M*c[n-i-x][y])%M;
									else f[i+cnt][0][0]=(f[i+cnt][0][0]+F*c[n-i][x]%M*c[n-i-x][y])%M;
						}
					}
				}
	printf("%d\n",f[n][0][0]);
	return 0;
}

