#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn=1e5+10;
const int mo=1e9+7;

int n,m,x[maxn];

struct matrix{
	int v[3][3];

	void init(int a,int b,int c,int d,int e,int f,int g,int h,int i)
	{
		v[0][0]=a; v[0][1]=b; v[0][2]=c;
		v[1][0]=d; v[1][1]=e; v[1][2]=f;
		v[2][0]=g; v[2][1]=h; v[2][2]=i;
	}

	matrix operator * (const matrix &m) const
	{
		matrix Ans;
		memset(Ans.v,0,sizeof(Ans.v));
		int i,j,k;
		for (i=0;i<3;i++)
		for (j=0;j<3;j++)
		for (k=0;k<3;k++)
			(Ans.v[i][j]+=(LL)v[i][k]*m.v[k][j]%mo)%=mo;
		return Ans;
	}
}mat,mat0,mat1,one;

matrix power(matrix x,int k)
{
	matrix res=one;
	while (k)
	{
		if (k&1) res=res*x;
		x=x*x;
		k>>=1;
	}
	return res;
}

int main()
{
#ifdef h10
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	one.init(1,0,0,0,1,0,0,0,1);
	mat0.init(1,2,1,0,1,1,0,0,1);
	mat1.init(1,2,1,0,1,1,1,2,2);
	mat=one;
	int i;
	scanf("%d%d",&m,&n);
	for (i=1;i<=n;i++) scanf("%d",&x[i]);
	x[++n]=m;
	for (i=n;i>=1;i--) x[i]-=x[i-1];
	for (i=1;i<=n;i++)
		mat=mat*mat0*power(mat1,x[i]-1);
	printf("%d\n",mat.v[0][2]);
}
