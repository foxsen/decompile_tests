#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,x;
map<int,int> M;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		M[x]++;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		if(!M[x])	
		{
			puts("NO");
			return 0;
		}
		else M[x]--;
	}
	puts("YES");
	return 0;
}