#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
using namespace std;
typedef long long LL;
const int N=2010;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
bool o[N][N];
int U[N][N],L[N][N],s[N][N];
int main()
{
	int n=gi(),m=gi(),Q=gi(),i,j,lx,rx,ly,ry,ans;char c;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++) {
			while ((c=getchar())!='0'&&c!='1');
			o[i][j]=c-'0';

			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+o[i][j];
			U[i][j]=U[i-1][j]+U[i][j-1]-U[i-1][j-1]+(o[i][j]&&o[i-1][j]);
			L[i][j]=L[i-1][j]+L[i][j-1]-L[i-1][j-1]+(o[i][j]&&o[i][j-1]);
		}
	while (Q--) {
		lx=gi(),ly=gi(),rx=gi(),ry=gi();
		
		ans=s[rx][ry]-s[lx-1][ry]-s[rx][ly-1]+s[lx-1][ly-1];
		ans-=L[rx][ry]-L[lx-1][ry]-L[rx][ly]+L[lx-1][ly];
		ans-=U[rx][ry]-U[lx][ry]-U[rx][ly-1]+U[lx][ly-1];
		
		printf("%d\n",ans);
	}
	
		
	return 0;
}
