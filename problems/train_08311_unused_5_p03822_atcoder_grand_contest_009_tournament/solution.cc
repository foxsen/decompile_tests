#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k;
int f[100005],son[100005],Next[100005];
int id[100005];

inline bool cmp(const int &a,const int &b){return f[a]>f[b];}

void dfs(int x)
{
	if(!son[x])return;
	int i,j,k=0;
	for(i=son[x];i;i=Next[i])dfs(i);
	for(i=son[x];i;i=Next[i])id[++k]=i;
	sort(id+1,id+k+1,cmp);
	for(i=1;i<=k;++i)
	{
		j=f[id[i]]+i;
		if(j>f[x])f[x]=j;
	}
}

int main()
{
	scanf("%d",&n);
	for(i=2;i<=n;++i)scanf("%d",&k),Next[i]=son[k],son[k]=i;
	dfs(1);
	printf("%d\n",f[1]);
}